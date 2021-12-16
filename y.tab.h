/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PACKAGE = 258,
    ID = 259,
    SEMICOLON = 260,
    VAR = 261,
    LPAR = 262,
    RPAR = 263,
    INT = 264,
    FLOAT32 = 265,
    BOOL = 266,
    STRING = 267,
    FUNC = 268,
    COMMA = 269,
    LBRACE = 270,
    RBRACE = 271,
    ASSIGN = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    RETURN = 276,
    PRINT = 277,
    STRLIT = 278,
    BLANKID = 279,
    PARSEINT = 280,
    CMDARGS = 281,
    LSQ = 282,
    RSQ = 283,
    OR = 284,
    AND = 285,
    LT = 286,
    GT = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    PLUS = 292,
    MINUS = 293,
    STAR = 294,
    DIV = 295,
    MOD = 296,
    NOT = 297,
    INTLIT = 298,
    REALLIT = 299,
    RESERVED = 300,
    UNARY = 301
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define ID 259
#define SEMICOLON 260
#define VAR 261
#define LPAR 262
#define RPAR 263
#define INT 264
#define FLOAT32 265
#define BOOL 266
#define STRING 267
#define FUNC 268
#define COMMA 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define IF 273
#define ELSE 274
#define FOR 275
#define RETURN 276
#define PRINT 277
#define STRLIT 278
#define BLANKID 279
#define PARSEINT 280
#define CMDARGS 281
#define LSQ 282
#define RSQ 283
#define OR 284
#define AND 285
#define LT 286
#define GT 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define PLUS 292
#define MINUS 293
#define STAR 294
#define DIV 295
#define MOD 296
#define NOT 297
#define INTLIT 298
#define REALLIT 299
#define RESERVED 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "gocompiler.y"

        char* tkn;
        struct Node * node;

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
