/*
 *  MICO --- a free CORBA implementation
 *  Copyright (C) 1997-98 Kay Roemer & Arno Puder
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Send comments and/or bug reports to:
 *                 mico@informatik.uni-frankfurt.de
 */

 %{

#include "corto/ext/idl/idl.h"

/* Forward declarations of yacc functions */
void yyerror(const char *str);
int yylex(void);
int yylex_destroy(void);
int yy_scan_string(const char* str);

#define YYERROR_VERBOSE

extern corto_threadKey IDL_PARSER_KEY;

/* Obtain parser */
idl_Parser idl_yparser(void) {
    return (idl_Parser)corto_threadTlsGet(IDL_PARSER_KEY);
}

%}


%token T_AMPERSAND
%token T_ANY
%token T_ASTERISK
%token T_ATTRIBUTE
%token T_BOOLEAN
%token T_CASE
%token T_CHAR
%token T_CHARACTER_LITERAL
%token T_CIRCUMFLEX
%token T_COLON
%token T_COMMA
%token T_CONST
%token T_CONTEXT
%token T_DEFAULT
%token T_DOUBLE
%token T_ENUM
%token T_EQUAL
%token T_EXCEPTION
%token T_FALSE
%token T_FIXED
%token T_FIXED_PT_LITERAL
%token T_FLOAT
%token T_FLOATING_PT_LITERAL
%token T_GREATER_THAN_SIGN
%token T_IDENTIFIER
%token T_IN
%token T_INOUT
%token T_INTEGER_LITERAL
%token T_INTERFACE
%token T_LEFT_CURLY_BRACKET
%token T_LEFT_PARANTHESIS
%token T_LEFT_SQUARE_BRACKET
%token T_LESS_THAN_SIGN
%token T_LONG
%token T_MINUS_SIGN
%token T_MODULE
%token T_OCTET
%token T_ONEWAY
%token T_OUT
%token T_PERCENT_SIGN
%token T_PLUS_SIGN
%token T_PRINCIPAL
%token T_RAISES
%token T_READONLY
%token T_RIGHT_CURLY_BRACKET
%token T_RIGHT_PARANTHESIS
%token T_RIGHT_SQUARE_BRACKET
%token T_SCOPE
%token T_SEMICOLON
%token T_SEQUENCE
%token T_SHIFTLEFT
%token T_SHIFTRIGHT
%token T_SHORT
%token T_SOLIDUS
%token T_STRING
%token T_STRING_LITERAL
%token T_PRAGMA
%token T_STRUCT
%token T_SWITCH
%token T_TILDE
%token T_TRUE
%token T_OBJECT
%token T_TYPEDEF
%token T_UNION
%token T_UNSIGNED
%token T_VERTICAL_LINE
%token T_VOID
%token T_WCHAR
%token T_WSTRING
%token T_UNKNOWN
%token T_ABSTRACT
%token T_VALUETYPE
%token T_TRUNCATABLE
%token T_SUPPORTS
%token T_CUSTOM
%token T_PUBLIC
%token T_PRIVATE
%token T_FACTORY
%token T_NATIVE
%token T_VALUEBASE

/* Parser-types */
%union {
    /* Literals */
    corto_bool Boolean;
    corto_char Character;
    corto_uint64 Integer;
    corto_int64 SignedInteger;
    corto_float64 FloatingPoint;
    corto_string String;
    corto_object Reference;
    corto_type Type;

    /* Grammer objects */
    idl_Declarator Declarator;
    idl_DeclaratorList Declarators;
    corto_parameterList Parameters;
    corto_uint32List ArraySizes;
    corto_int32List Int32List;
    corto_stringList Enumerators;
    corto_typeList TypeList;
    idl_InheritanceSpec InheritanceSpec;
    corto_parameter Parameter;

    /* Constants */
    corto_value Constant;
}

/* Valuetoken-types */
%type <String> T_IDENTIFIER T_PRAGMA enumerator
%type <Declarator> declarator simple_declarator complex_declarator array_declarator
%type <Declarators> declarators simple_declarators
%type <ArraySizes> fixed_array_sizes
%type <Integer> T_INTEGER_LITERAL fixed_array_size
%type <Character> T_CHARACTER_LITERAL
%type <FloatingPoint> T_FLOATING_PT_LITERAL T_FIXED_PT_LITERAL
%type <Boolean> T_TRUE T_FALSE
%type <String> T_string_literal T_STRING_LITERAL
%type <Enumerators> enumerators
%type <Type> type_spec simple_type_spec constr_type_spec base_type_spec template_type_spec scoped_name value_name
%type <Type> value_inheritance_bases floating_pt_type integer_type char_type wide_char_type boolean_type octet_type any_type
%type <Type> object_type value_base_type principal_type sequence_type string_type wide_string_type fixed_pt_type
%type <Type> struct_type union_type enum_type signed_int unsigned_int signed_long_int signed_short_int op_type_spec
%type <Type> signed_longlong_int unsigned_long_int unsigned_short_int unsigned_longlong_int value_header param_type_spec
%type <Type> switch_type_spec
%type <Constant> const_exp or_expr xor_expr and_expr shift_expr add_expr mult_expr
%type <Constant> unary_expr primary_expr literal positive_int_const
%type <TypeList> scoped_names interface_names
%type <Parameters> parameter_dcls param_dcls
%type <InheritanceSpec> value_inheritance_spec
%type <Parameter> param_attribute param_dcl
%type <Int32List> case

%%

/*1*/
specification
    : /*empty*/
    | definitions
    ;


definitions
    : definition
    | definition definitions
    ;

/*2*/
definition
    : type_dcl T_SEMICOLON
    | const_dcl T_SEMICOLON
    | except_dcl T_SEMICOLON
    | interface T_SEMICOLON
    | module T_SEMICOLON
    | value T_SEMICOLON
    | pragma
    | error {
        if (!idl_yparser()->errors) {
            corto_error("idl:%s:%d: %s",
                idl_yparser()->filename,
                idl_yparser()->line,
                corto_lasterr());
            idl_yparser()->errors++;
        }
    }
    ;

pragma
    : T_PRAGMA {
        if (idl_Parser_parsePragma(idl_yparser(), $1)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    ;

/*3*/
module
    : T_MODULE T_IDENTIFIER {
        if (!idl_Parser_pushModule(idl_yparser(), $2)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    } T_LEFT_CURLY_BRACKET definitions {
        idl_Parser_popModule(idl_yparser());
    } T_RIGHT_CURLY_BRACKET
    ;

/*4*/
interface
    : interface_dcl
    | forward_dcl
    ;

/*5*/
interface_dcl
    : interface_header T_LEFT_CURLY_BRACKET interface_body
                                         T_RIGHT_CURLY_BRACKET
    ;

/*6*/
forward_dcl
    : T_INTERFACE T_IDENTIFIER
    | T_ABSTRACT T_INTERFACE T_IDENTIFIER
    ;

/*7*/
interface_header
    : T_INTERFACE T_IDENTIFIER
    | T_INTERFACE T_IDENTIFIER interface_inheritance_spec
    | T_ABSTRACT T_INTERFACE T_IDENTIFIER
    | T_ABSTRACT T_INTERFACE T_IDENTIFIER interface_inheritance_spec
    ;

/*8*/
interface_body
    : /*empty*/
    | exports
    ;

exports
    : export
    | export exports
    ;

/*9*/
export
    : type_dcl T_SEMICOLON
    | const_dcl T_SEMICOLON
    | except_dcl T_SEMICOLON
    | attr_dcl T_SEMICOLON
    | op_dcl T_SEMICOLON
    ;

/*10*/
interface_inheritance_spec
    : T_COLON interface_names
    ;

interface_names
    : scoped_names
    ;

scoped_names
    : scoped_name { $$ = corto_llNew(); corto_typeListInsert($$, $1); }
    | scoped_name T_COMMA scoped_names { $$ = $3; corto_typeListInsert($$, $1); }
    ;

/*12*/
scoped_name
    : T_IDENTIFIER {
        $$ = corto_resolve(idl_yparser()->scope, $1);
        if (!$$) {
            corto_seterr("unresolved identifier '%s'", $1);
            YYERROR;
        }
    }
    | T_SCOPE T_IDENTIFIER {
        $$ = corto_resolve(NULL, $2);
        if (!$$) {
            corto_seterr("unresolved identifier '%s'", $2);
            YYERROR;
        }
    }
    | scoped_name T_SCOPE T_IDENTIFIER {
        if (!$1) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
        $$ = corto_resolve($1, $3); corto_release($1);
        if (!$$) {
            corto_seterr("unresolved identifier '%s'", $3);
            YYERROR;
        }
    }
    ;

/*13*/
value
    : value_dcl
    | value_abs_dcl
    | value_box_dcl
    | value_forward_dcl
    ;

/*14*/
value_forward_dcl
    : T_VALUETYPE T_IDENTIFIER
    | T_ABSTRACT T_VALUETYPE T_IDENTIFIER
    ;

/*15*/
value_box_dcl
    : T_VALUETYPE T_IDENTIFIER type_spec
    ;

/*16*/
value_abs_dcl
    : T_ABSTRACT T_VALUETYPE T_IDENTIFIER
        T_LEFT_CURLY_BRACKET value_body T_RIGHT_CURLY_BRACKET
    | T_ABSTRACT T_VALUETYPE T_IDENTIFIER value_inheritance_spec
        T_LEFT_CURLY_BRACKET value_body T_RIGHT_CURLY_BRACKET
    ;

value_body
    : /*empty*/
    | exports
    ;

/*17*/
value_dcl
    : value_header T_LEFT_CURLY_BRACKET value_elements T_RIGHT_CURLY_BRACKET {
        if (idl_Parser_defineValueType(idl_yparser(), $1)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    | value_header T_LEFT_CURLY_BRACKET T_RIGHT_CURLY_BRACKET {
        if (idl_Parser_defineValueType(idl_yparser(), $1)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    ;

value_elements
    : value_element
    | value_element value_elements
    ;

/*18*/
value_header
    : T_VALUETYPE T_IDENTIFIER value_inheritance_spec {
        $$ = corto_type(idl_Parser_declareValueType(idl_yparser(), $2, &$3));
        if (!$$) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    | T_CUSTOM T_VALUETYPE T_IDENTIFIER value_inheritance_spec { $$ = NULL; corto_seterr("custom not supported"); YYERROR; }
    | T_VALUETYPE T_IDENTIFIER {
        idl_InheritanceSpec spec = {NULL, NULL};
        $$ = corto_type(idl_Parser_declareValueType(idl_yparser(), $2, &spec));
        if (!$$) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    | T_CUSTOM T_VALUETYPE T_IDENTIFIER { $$ = NULL; corto_seterr("custom not supported"); YYERROR; }
    ;

/*19*/
value_inheritance_spec
    : T_COLON value_inheritance_bases { $$.base = corto_interface($2); $$.supports = NULL; }
    | T_COLON value_inheritance_bases T_SUPPORTS interface_names { $$.base = corto_interface($2); $$.supports = $4; }
    | T_SUPPORTS interface_names { $$.base = NULL; $$.supports = $2; }
    ;

value_inheritance_bases
    : value_name
    | value_name T_COMMA value_names { corto_seterr("multiple inheritance is not allowed"); YYERROR; }
    | T_TRUNCATABLE value_name { corto_seterr("truncatable unsupported"); YYERROR; }
    | T_TRUNCATABLE value_name T_COMMA value_names { corto_seterr("truncatable unsupported"); YYERROR; }
    ;

value_names
    : scoped_names
    ;

/*20*/
value_name
    : scoped_name
    ;

/*21*/
value_element
    : export
    | state_member
    | init_dcl
    ;

/*22*/
state_member
    : T_PUBLIC type_spec declarators T_SEMICOLON
    | T_PRIVATE type_spec declarators T_SEMICOLON
    ;

/*23*/
init_dcl
    : T_FACTORY T_IDENTIFIER
        T_LEFT_PARANTHESIS init_param_decls T_RIGHT_PARANTHESIS
        T_SEMICOLON
    ;

/*24*/
init_param_decls
    : init_param_decl
    | init_param_decl T_COMMA init_param_decls
    ;

/*25*/
init_param_decl
    : init_param_attribute param_type_spec simple_declarator
    ;

/*26*/
init_param_attribute
    : T_IN
    ;

/*27*/
const_dcl
    : T_CONST const_type T_IDENTIFIER T_EQUAL const_exp
    ;

/*28*/
const_type
    : integer_type
    | char_type
    | wide_char_type
    | boolean_type
    | floating_pt_type
    | string_type
    | wide_string_type
    | fixed_pt_const_type
    | scoped_name
    | octet_type
    ;

/*29*/
const_exp
    : or_expr
    ;

/*30*/
or_expr
    : xor_expr
    | or_expr T_VERTICAL_LINE xor_expr { corto_value_binary(CORTO_OR, &$1, &$3, &$$); }
    ;

/*31*/
xor_expr
    : and_expr
    | xor_expr T_CIRCUMFLEX and_expr { corto_value_binary(CORTO_XOR, &$1, &$3, &$$); }
    ;

/*32*/
and_expr
    : shift_expr
    | and_expr T_AMPERSAND shift_expr { corto_value_binary(CORTO_AND, &$1, &$3, &$$); }
    ;

/*33*/
shift_expr
    : add_expr
    | shift_expr T_SHIFTRIGHT add_expr { corto_value_binary(CORTO_SHIFT_RIGHT, &$1, &$3, &$$); }
    | shift_expr T_SHIFTLEFT add_expr { corto_value_binary(CORTO_SHIFT_LEFT, &$1, &$3, &$$); }
    ;

/*34*/
add_expr
    : mult_expr
    | add_expr T_PLUS_SIGN mult_expr { corto_value_binary(CORTO_ADD, &$1, &$3, &$$); }
    | add_expr T_MINUS_SIGN mult_expr { corto_value_binary(CORTO_SUB, &$1, &$3, &$$); }
    ;

/*35*/
mult_expr
    : unary_expr
    | mult_expr T_ASTERISK unary_expr { corto_value_binary(CORTO_MUL, &$1, &$3, &$$); }
    | mult_expr T_SOLIDUS unary_expr { corto_value_binary(CORTO_DIV, &$1, &$3, &$$); }
    | mult_expr T_PERCENT_SIGN unary_expr { corto_value_binary(CORTO_MOD, &$1, &$3, &$$); }
    ;

/*36*/
/*37*/
unary_expr
    : T_MINUS_SIGN primary_expr { corto_value_unary(CORTO_SUB, &$2, &$$); }
    | T_PLUS_SIGN primary_expr { $$ = $2; }
    | T_TILDE primary_expr { corto_value_unary(CORTO_NOT, &$2, &$$); }
    | primary_expr
    ;

/*38*/
primary_expr
    : scoped_name {$$ = corto_value_object($1, NULL);}
    | literal
    | T_LEFT_PARANTHESIS const_exp T_RIGHT_PARANTHESIS {$$ = $2;}
    ;

/*39*/
/*40*/
literal
    : T_INTEGER_LITERAL {$$ = corto_value_int($1); }
    | T_string_literal {$$ = corto_value_string($1); }
    | T_CHARACTER_LITERAL {$$ = corto_value_char($1); }
    | T_FIXED_PT_LITERAL {$$ = corto_value_float($1); }
    | T_FLOATING_PT_LITERAL {$$ = corto_value_float($1); }
    | T_TRUE  {$$ = corto_value_bool(TRUE); }
    | T_FALSE {$$ = corto_value_bool(FALSE); }
    ;

/*41*/
positive_int_const
    : const_exp
    ;

/*42*/
/*43*/
type_dcl
    : T_TYPEDEF type_spec declarators {idl_Parser_parseTypedef(idl_yparser(), $2, $3);}
    | struct_type
    | union_type
    | enum_type
    | T_NATIVE simple_declarator
    ;

/*44*/
type_spec
    : simple_type_spec
    | constr_type_spec
    ;

/*45*/
simple_type_spec
    : base_type_spec
    | template_type_spec
    | scoped_name
    ;

/*46*/
base_type_spec
    : floating_pt_type
    | integer_type
    | char_type
    | wide_char_type
    | boolean_type
    | octet_type
    | any_type
    | object_type
    | value_base_type
    | principal_type  /*New*/
    ;

/*47*/
template_type_spec
    : sequence_type
    | string_type
    | wide_string_type
    | fixed_pt_type
    ;

/*48*/
constr_type_spec
    : struct_type
    | union_type
    | enum_type
    ;

/*49*/
declarators
    : declarator { $$ = corto_llNew(); corto_llInsert($$, $1); }
    | declarator T_COMMA declarators {$$ = $3; corto_llInsert($$, $1); }
    ;

/*50*/
declarator
    : simple_declarator
    | complex_declarator
    ;

/*51*/
simple_declarator
    : T_IDENTIFIER { $$ = idl_DeclaratorCreate($1, corto_llNew()); }
    ;

/*52*/
complex_declarator
    : array_declarator
    ;

/*53*/
floating_pt_type
    : T_FLOAT { $$ = corto_resolve(NULL, "float32"); }
    | T_DOUBLE { $$ = corto_resolve(NULL, "float64"); }
    | T_LONG T_DOUBLE { if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__); YYERROR; }
    ;

/*54*/
integer_type
    : signed_int
    | unsigned_int
    ;

/*55*/
signed_int
    : signed_long_int
    | signed_short_int
    | signed_longlong_int
    ;

/*56*/
signed_short_int
    : T_SHORT { $$ = corto_resolve(NULL, "int16"); }
    ;

/*57*/
signed_long_int
    : T_LONG { $$ = corto_resolve(NULL, "int32"); }
    ;

/*58*/
signed_longlong_int
    : T_LONG T_LONG { $$ = corto_resolve(NULL, "int64"); }
    ;

/*59*/
unsigned_int
    : unsigned_long_int
    | unsigned_short_int
    | unsigned_longlong_int
    ;

/*60*/
unsigned_short_int
    : T_UNSIGNED T_SHORT { $$ = corto_resolve(NULL, "uint16"); }
    ;

/*61*/
unsigned_long_int
    : T_UNSIGNED T_LONG { $$ = corto_resolve(NULL, "uint32"); }
    ;

/*62*/
unsigned_longlong_int
    : T_UNSIGNED T_LONG T_LONG { $$ = corto_resolve(NULL, "uint64"); }
    ;

/*63*/
char_type
    : T_CHAR { $$ = corto_resolve(NULL, "char"); }
    ;

/*64*/
wide_char_type
    : T_WCHAR { $$ = NULL; if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__); YYERROR; }
    ;

/*65*/
boolean_type
    : T_BOOLEAN { $$ = corto_resolve(NULL, "bool"); }
    ;

/*66*/
octet_type
    : T_OCTET { $$ = corto_resolve(NULL, "octet"); }
    ;

/*67*/
any_type
    : T_ANY { $$ = corto_resolve(NULL, "any"); }
    ;

/*68*/
object_type
    : T_OBJECT { $$ = corto_resolve(NULL, "object"); }
    ;

/*69*/
struct_type
    : T_STRUCT T_IDENTIFIER {
        $<Type>$ = corto_type(idl_Parser_declareStruct(idl_yparser(), $2));
    }
    T_LEFT_CURLY_BRACKET member_list T_RIGHT_CURLY_BRACKET {
        if (idl_Parser_defineStruct(idl_yparser(), $<Type>3)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
        $$ = $<Type>3;
    }
    ;

/*70*/
member_list
    : member
    | member member_list
    ;

/*71*/
member
    : type_spec declarators T_SEMICOLON {
        if (idl_Parser_parseMember(idl_yparser(), $1, $2, FALSE)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    ;

/*72*/
union_type
    : T_UNION T_IDENTIFIER T_SWITCH T_LEFT_PARANTHESIS switch_type_spec T_RIGHT_PARANTHESIS
    {
        $<Type>$ = corto_type(idl_Parser_declareUnion(idl_yparser(), $2, $5));
        if (!$<Type>$) {
            YYERROR;
        }
    }
    T_LEFT_CURLY_BRACKET switch_body T_RIGHT_CURLY_BRACKET
    {
        if (idl_Parser_defineUnion(idl_yparser(), $<Type>7)) {
            YYERROR;
        }
    }
    ;

/*73*/
switch_type_spec
    : integer_type
    | char_type
    | boolean_type
    | enum_type
    | scoped_name
    ;

/*74*/
switch_body
    : case
    | case switch_body
    ;

/*75*/
case
    : case_label case
    | case_label element_spec T_SEMICOLON
    ;

/*76*/
case_label
    : T_CASE const_exp T_COLON
    | T_DEFAULT T_COLON
    ;

/*77*/
element_spec
    : type_spec declarator
    ;

/*78*/
enum_type
    : T_ENUM T_IDENTIFIER T_LEFT_CURLY_BRACKET enumerators T_RIGHT_CURLY_BRACKET {
        $$ = corto_type(idl_Parser_parseEnum(idl_yparser(), $2, $4));
    }
    ;

enumerators
    : enumerator { $$ = corto_llNew(); corto_llInsert($$, $1); }
    | enumerator T_COMMA enumerators { $$ = $3; corto_llInsert($$, $1); }
    ;

/*79*/
enumerator
    : T_IDENTIFIER
    ;

/*80*/
sequence_type
    : T_SEQUENCE T_LESS_THAN_SIGN simple_type_spec T_COMMA positive_int_const T_GREATER_THAN_SIGN {
        $$ = corto_type(corto_sequenceCreate($3, *(corto_int32*)corto_value_ptrof(&$5)));
    }
    | T_SEQUENCE T_LESS_THAN_SIGN simple_type_spec T_GREATER_THAN_SIGN { $$ = corto_type(corto_sequenceCreate($3, 0)); }
    ;

/*81*/
string_type
    : T_STRING T_LESS_THAN_SIGN positive_int_const T_GREATER_THAN_SIGN {
        $$ = corto_type(corto_textCreate(CORTO_WIDTH_8, *(corto_int32*)&$3));
    }
    | T_STRING { $$ = corto_resolve(NULL, "string"); }
    ;

/*82*/
wide_string_type
    : T_WSTRING T_LESS_THAN_SIGN positive_int_const T_GREATER_THAN_SIGN {$$ = NULL; YYERROR; }
    | T_WSTRING { $$ = NULL; YYERROR; }
    ;

/*83*/
array_declarator
    : T_IDENTIFIER fixed_array_sizes { $$ = idl_DeclaratorCreate($1, $2); }
    ;

fixed_array_sizes
    : fixed_array_size {$$ = corto_llNew(); corto_uint32ListInsert($$, $1); }
    | fixed_array_size fixed_array_sizes { $$ = $2; corto_uint32ListInsert($$, $1); }
    ;

/*84*/
fixed_array_size
    : T_LEFT_SQUARE_BRACKET positive_int_const T_RIGHT_SQUARE_BRACKET {
        $$ = *(corto_int32*)corto_value_ptrof(&$2);
    }
    ;

/*85*/
attr_dcl
    : T_ATTRIBUTE param_type_spec simple_declarators {
        if (idl_Parser_parseMember(idl_yparser(), $2, $3, FALSE)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    | T_READONLY T_ATTRIBUTE param_type_spec simple_declarators {
        if (idl_Parser_parseMember(idl_yparser(), $3, $4, TRUE)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    ;

simple_declarators
    : simple_declarator { $$ = corto_llNew(); idl_DeclaratorListInsert($$, $1); }
    | simple_declarator T_COMMA simple_declarators { $$ = $3; idl_DeclaratorListInsert($$, $1); }
    ;

/*86*/
except_dcl
    : T_EXCEPTION T_IDENTIFIER T_LEFT_CURLY_BRACKET members
                                          T_RIGHT_CURLY_BRACKET
    ;

members
    : /*empty*/
    | member members
    ;

/*87*/
op_dcl
    : op_attribute op_type_spec T_IDENTIFIER parameter_dcls
                                       raises_expr context_expr {
        if (idl_Parser_parseMethod(idl_yparser(), $2, $3, $4)) {
            if (!corto_lasterr()) corto_seterr("unknown error at %s:%d", __FILE__, __LINE__);
            YYERROR;
        }
    }
    ;

/*88*/
op_attribute
    : /*empty*/
    | T_ONEWAY { corto_seterr("oneway not supported"); YYERROR; }
    ;

/*89*/
op_type_spec
    : param_type_spec
    | T_VOID { $$ = corto_resolve(NULL, "void"); }
    ;

/*90*/
parameter_dcls
    : T_LEFT_PARANTHESIS param_dcls T_RIGHT_PARANTHESIS { $$ = $2; }
    | T_LEFT_PARANTHESIS T_RIGHT_PARANTHESIS { $$ = NULL; }
    ;

param_dcls
    : param_dcl { $$ = corto_llNew(); corto_parameterListInsert($$, &$1);}
    | param_dcl T_COMMA param_dcls { $$ = $3; corto_parameterListInsert($$, &$1); }
    ;

/*91*/
param_dcl
    : param_attribute param_type_spec simple_declarator {
        $$ = $1;
        $$.type = $2;
        $$.name = $3->identifier;
    }
    ;

/*92*/
param_attribute
    : T_IN { $$.passByReference = FALSE; }
    | T_OUT { $$.passByReference = TRUE; }
    | T_INOUT { $$.passByReference = TRUE; }
    ;

/*93*/
raises_expr
    : /*empty*/
    | T_RAISES T_LEFT_PARANTHESIS scoped_names T_RIGHT_PARANTHESIS
    ;

/*94*/
context_expr
    : /*empty*/
    | T_CONTEXT T_LEFT_PARANTHESIS string_literals T_RIGHT_PARANTHESIS
    ;

string_literals
    : T_string_literal
    | T_string_literal T_COMMA string_literals
    ;

T_string_literal
    : T_STRING_LITERAL
    | T_STRING_LITERAL T_string_literal
    ;

/*95*/
param_type_spec
    : base_type_spec
    | string_type
    | wide_string_type
    | scoped_name
    ;

/*96*/
fixed_pt_type
    : T_FIXED T_LESS_THAN_SIGN positive_int_const T_COMMA T_INTEGER_LITERAL T_GREATER_THAN_SIGN {
        corto_seterr("fixed point not supported");
        YYERROR;
    }
    ;

/*97*/
fixed_pt_const_type
    : T_FIXED { corto_seterr("fixed point not supported"); YYERROR; }
    ;

/*98*/
value_base_type
    : T_VALUEBASE { corto_seterr("valuebase not supported"); YYERROR; }
    ;

/* New production for Principal */
principal_type
    : T_PRINCIPAL { corto_seterr("principal not supported"); YYERROR; }
    ;

%%

void yyerror(const char *str)
{
    corto_string err = corto_lasterr();
    if (err) {
        corto_error("idl:%s:%d: %s", idl_yparser()->filename, idl_yparser()->line, err);
    } else {
        corto_error("idl:%s:%d: %s", idl_yparser()->filename, idl_yparser()->line, str);
        abort();
    }
    idl_yparser()->errors++;
}

int idl_yparse(idl_Parser p) {
    corto_threadTlsSet(IDL_PARSER_KEY, p);

    /* Set pointer to source */
    yy_scan_string((char *) p->source);
    yyparse();

    return 0;
}
