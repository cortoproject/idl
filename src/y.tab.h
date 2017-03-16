/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AMPERSAND = 258,
    T_ANY = 259,
    T_ASTERISK = 260,
    T_ATTRIBUTE = 261,
    T_BOOLEAN = 262,
    T_CASE = 263,
    T_CHAR = 264,
    T_CHARACTER_LITERAL = 265,
    T_CIRCUMFLEX = 266,
    T_COLON = 267,
    T_COMMA = 268,
    T_CONST = 269,
    T_CONTEXT = 270,
    T_DEFAULT = 271,
    T_DOUBLE = 272,
    T_ENUM = 273,
    T_EQUAL = 274,
    T_EXCEPTION = 275,
    T_FALSE = 276,
    T_FIXED = 277,
    T_FIXED_PT_LITERAL = 278,
    T_FLOAT = 279,
    T_FLOATING_PT_LITERAL = 280,
    T_GREATER_THAN_SIGN = 281,
    T_IDENTIFIER = 282,
    T_IN = 283,
    T_INOUT = 284,
    T_INTEGER_LITERAL = 285,
    T_INTERFACE = 286,
    T_LEFT_CURLY_BRACKET = 287,
    T_LEFT_PARANTHESIS = 288,
    T_LEFT_SQUARE_BRACKET = 289,
    T_LESS_THAN_SIGN = 290,
    T_LONG = 291,
    T_MINUS_SIGN = 292,
    T_MODULE = 293,
    T_OCTET = 294,
    T_ONEWAY = 295,
    T_OUT = 296,
    T_PERCENT_SIGN = 297,
    T_PLUS_SIGN = 298,
    T_PRINCIPAL = 299,
    T_RAISES = 300,
    T_READONLY = 301,
    T_RIGHT_CURLY_BRACKET = 302,
    T_RIGHT_PARANTHESIS = 303,
    T_RIGHT_SQUARE_BRACKET = 304,
    T_SCOPE = 305,
    T_SEMICOLON = 306,
    T_SEQUENCE = 307,
    T_SHIFTLEFT = 308,
    T_SHIFTRIGHT = 309,
    T_SHORT = 310,
    T_SOLIDUS = 311,
    T_STRING = 312,
    T_STRING_LITERAL = 313,
    T_PRAGMA = 314,
    T_STRUCT = 315,
    T_SWITCH = 316,
    T_TILDE = 317,
    T_TRUE = 318,
    T_OBJECT = 319,
    T_TYPEDEF = 320,
    T_UNION = 321,
    T_UNSIGNED = 322,
    T_VERTICAL_LINE = 323,
    T_VOID = 324,
    T_WCHAR = 325,
    T_WSTRING = 326,
    T_UNKNOWN = 327,
    T_ABSTRACT = 328,
    T_VALUETYPE = 329,
    T_TRUNCATABLE = 330,
    T_SUPPORTS = 331,
    T_CUSTOM = 332,
    T_PUBLIC = 333,
    T_PRIVATE = 334,
    T_FACTORY = 335,
    T_NATIVE = 336,
    T_VALUEBASE = 337
  };
#endif
/* Tokens.  */
#define T_AMPERSAND 258
#define T_ANY 259
#define T_ASTERISK 260
#define T_ATTRIBUTE 261
#define T_BOOLEAN 262
#define T_CASE 263
#define T_CHAR 264
#define T_CHARACTER_LITERAL 265
#define T_CIRCUMFLEX 266
#define T_COLON 267
#define T_COMMA 268
#define T_CONST 269
#define T_CONTEXT 270
#define T_DEFAULT 271
#define T_DOUBLE 272
#define T_ENUM 273
#define T_EQUAL 274
#define T_EXCEPTION 275
#define T_FALSE 276
#define T_FIXED 277
#define T_FIXED_PT_LITERAL 278
#define T_FLOAT 279
#define T_FLOATING_PT_LITERAL 280
#define T_GREATER_THAN_SIGN 281
#define T_IDENTIFIER 282
#define T_IN 283
#define T_INOUT 284
#define T_INTEGER_LITERAL 285
#define T_INTERFACE 286
#define T_LEFT_CURLY_BRACKET 287
#define T_LEFT_PARANTHESIS 288
#define T_LEFT_SQUARE_BRACKET 289
#define T_LESS_THAN_SIGN 290
#define T_LONG 291
#define T_MINUS_SIGN 292
#define T_MODULE 293
#define T_OCTET 294
#define T_ONEWAY 295
#define T_OUT 296
#define T_PERCENT_SIGN 297
#define T_PLUS_SIGN 298
#define T_PRINCIPAL 299
#define T_RAISES 300
#define T_READONLY 301
#define T_RIGHT_CURLY_BRACKET 302
#define T_RIGHT_PARANTHESIS 303
#define T_RIGHT_SQUARE_BRACKET 304
#define T_SCOPE 305
#define T_SEMICOLON 306
#define T_SEQUENCE 307
#define T_SHIFTLEFT 308
#define T_SHIFTRIGHT 309
#define T_SHORT 310
#define T_SOLIDUS 311
#define T_STRING 312
#define T_STRING_LITERAL 313
#define T_PRAGMA 314
#define T_STRUCT 315
#define T_SWITCH 316
#define T_TILDE 317
#define T_TRUE 318
#define T_OBJECT 319
#define T_TYPEDEF 320
#define T_UNION 321
#define T_UNSIGNED 322
#define T_VERTICAL_LINE 323
#define T_VOID 324
#define T_WCHAR 325
#define T_WSTRING 326
#define T_UNKNOWN 327
#define T_ABSTRACT 328
#define T_VALUETYPE 329
#define T_TRUNCATABLE 330
#define T_SUPPORTS 331
#define T_CUSTOM 332
#define T_PUBLIC 333
#define T_PRIVATE 334
#define T_FACTORY 335
#define T_NATIVE 336
#define T_VALUEBASE 337

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 127 "src/idl.y" /* yacc.c:1909  */

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

#line 244 "src/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
