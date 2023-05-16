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
    MIN = 258,
    PLUS = 259,
    AST = 260,
    BAR = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    IDF = 265,
    VALOR = 266,
    INT = 267,
    DOUBLE = 268,
    FLOAT = 269,
    CHAR = 270,
    IF = 271,
    ELSE = 272,
    FOR = 273,
    WHILE = 274,
    ATRIB = 275,
    PAROPN = 276,
    PARCLOSE = 277,
    KOPN = 278,
    KCLOSE = 279,
    SEMICOLON = 280,
    GREAT = 281,
    LESS = 282,
    EQ = 283,
    LE = 284,
    GE = 285,
    NE = 286
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
#define IDF 265
#define VALOR 266
#define INT 267
#define DOUBLE 268
#define FLOAT 269
#define CHAR 270
#define IF 271
#define ELSE 272
#define FOR 273
#define WHILE 274
#define ATRIB 275
#define PAROPN 276
#define PARCLOSE 277
#define KOPN 278
#define KCLOSE 279
#define SEMICOLON 280
#define GREAT 281
#define LESS 282
#define EQ 283
#define LE 284
#define GE 285
#define NE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "nico.y"

	char* cadeia;
	struct _node * no;

#line 124 "y.tab.h"

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
