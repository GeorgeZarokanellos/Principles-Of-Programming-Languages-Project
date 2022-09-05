/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    T_EOF = 0,                     /* T_EOF  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_U_INT = 258,                 /* "Unsigned Integer"  */
    T_U_FLOAT = 259,               /* "Unsigned Float"  */
    T_GAMEID = 260,                /* "GameID"  */
    T_FLOAT = 261,                 /* "Float"  */
    T_JSON_STRING = 262,           /* "JSON String"  */
    T_BOOLEAN = 263,               /* "Boolean"  */
    T_JSON_ARRAY = 264,            /* "JSON Array"  */
    T_L_BRACE = 265,               /* "Left Brace ({)"  */
    T_R_BRACE = 266,               /* "Right Brace (})"  */
    T_L_BRACKET = 267,             /* "Left Bracket ([)"  */
    T_R_BRACKET = 268,             /* "Right Bracket (])"  */
    T_DOT = 269,                   /* "Dot (.)"  */
    T_QUOTATIONS = 270,            /* "Quotations"  */
    T_ASSIGNMENT = 271,            /* "Assignment (:)"  */
    T_COMMA = 272,                 /* "Comma (,)"  */
    T_U_INT_ARRAY = 273,           /* "Unsigned Integer Array"  */
    T_LAST = 274,                  /* "Last"  */
    T_ACTIVE = 275,                /* "Active"  */
    T_DRAWID = 276,                /* "DrawID"  */
    T_DRAWTIME = 277,              /* "Draw Time"  */
    T_VISUALDRAW = 278,            /* "Visual Draw"  */
    T_PRICEPOINTS = 279,           /* "Price Points"  */
    T_AMOUNT = 280,                /* "Amount"  */
    T_WINNINGNUMBERS = 281,        /* "Winning Numbers"  */
    T_LIST = 282,                  /* "List"  */
    T_BONUS = 283,                 /* "Bonus"  */
    T_PRIZECATEGORIES = 284,       /* "Prize Categories"  */
    T_ID = 285,                    /* "ID"  */
    T_DIVIDENT = 286,              /* "Divident"  */
    T_WINNERS = 287,               /* "Winners"  */
    T_DISTRIBUTED = 288,           /* "Distributed"  */
    T_JACKPOT = 289,               /* "Jackpot"  */
    T_FIXED = 290,                 /* "Fixed"  */
    T_CATEGORYTYPE = 291,          /* "Category Type"  */
    T_GAMETYPE = 292,              /* "Game Type"  */
    T_MINIMUMDISTRIBUTED = 293,    /* "Minimum Distributed"  */
    T_WAGERSTATISTICS = 294,       /* "Wager Statistics"  */
    T_COLUMNS = 295,               /* "Columns"  */
    T_WAGERS = 296,                /* "Wagers"  */
    T_SORT = 297,                  /* "Sort"  */
    T_DIRECTION = 298,             /* "Direction"  */
    T_NUMBEROFELEMEMENTS = 299,    /* "Number of Elements"  */
    T_TOTALELEMENTS = 300,         /* "Total Elements"  */
    T_TOTALPAGES = 301,            /* "Total Pages"  */
    T_DRAWBREAK = 302,             /* "Draw Break"  */
    T_STATUS = 303,                /* "Status"  */
    T_CONTENT = 304,               /* "Content"  */
    T_ADDON = 305,                 /* "Addon"  */
    T_PROPERTY = 306,              /* "Property"  */
    T_IGNORE_CASE = 307,           /* "Ignore Case"  */
    T_NULL_HANDLING = 308,         /* "Null Handling"  */
    T_DESCENDING = 309,            /* "Descending"  */
    T_ASCENDING = 310,             /* "Ascending"  */
    T_FIRST = 311,                 /* "First"  */
    T_SIZE = 312,                  /* "Size"  */
    T_NUMBER = 313,                /* "Number"  */
    T_SIGN = 314                   /* "sign"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
