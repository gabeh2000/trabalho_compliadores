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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MIN = 258,
    PLUS = 259,
    AST = 260,
    BAR = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    TEXT = 265,
    SEMICOLON = 266,
    INC = 267,
    DEC = 268,
    COMA = 269,
    ATRIB = 270,
    COLON = 271,
    PERIOD = 272,
    BRAKCLOSE = 273,
    BRAKOPN = 274,
    PARCLOSE = 275,
    PAROPN = 276,
    KOPN = 277,
    KCLOSE = 278,
    INT = 279,
    DOUBLE = 280,
    FLOAT = 281,
    CHAR = 282,
    QUOTE = 283,
    DQUOTE = 284,
    LE = 285,
    GE = 286,
    EQ = 287,
    NE = 288,
    IF = 289,
    THEN = 290,
    ELSE = 291,
    WHILE = 292,
    FOR = 293,
    CLASS = 294,
    PUBLIC = 295,
    PRIVATE = 296,
    PROTECTED = 297,
    VOID = 298,
    NUL = 299,
    CONST = 300,
    STATIC = 301,
    LESS = 302,
    GREAT = 303,
    STRING = 304,
    IDF = 305,
    INT_LIT = 306,
    F_LIT = 307
  };
#endif
/* Tokens.  */
#define MIN 258
#define PLUS 259
#define AST 260
#define BAR 261
#define AND 262
#define OR 263
#define NOT 264
#define TEXT 265
#define SEMICOLON 266
#define INC 267
#define DEC 268
#define COMA 269
#define ATRIB 270
#define COLON 271
#define PERIOD 272
#define BRAKCLOSE 273
#define BRAKOPN 274
#define PARCLOSE 275
#define PAROPN 276
#define KOPN 277
#define KCLOSE 278
#define INT 279
#define DOUBLE 280
#define FLOAT 281
#define CHAR 282
#define QUOTE 283
#define DQUOTE 284
#define LE 285
#define GE 286
#define EQ 287
#define NE 288
#define IF 289
#define THEN 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define CLASS 294
#define PUBLIC 295
#define PRIVATE 296
#define PROTECTED 297
#define VOID 298
#define NUL 299
#define CONST 300
#define STATIC 301
#define LESS 302
#define GREAT 303
#define STRING 304
#define IDF 305
#define INT_LIT 306
#define F_LIT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "nico.y"

	char* cadeia;
	struct _node * no;

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
