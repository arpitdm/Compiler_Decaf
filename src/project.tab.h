/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_PROJECT_TAB_H_INCLUDED
# define YY_YY_PROJECT_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLEAN_ = 258,
     BREAK_ = 259,
     CALLOUT_ = 260,
     CLASS_ = 261,
     CONTINUE_ = 262,
     ELSE_ = 263,
     FALSE_ = 264,
     FOR_ = 265,
     IF_ = 266,
     INT_ = 267,
     RETURN_ = 268,
     TRUE_ = 269,
     VOID_ = 270,
     PROGRAM_ = 271,
     DIGIT_ = 272,
     ID_ = 273,
     HEX_DIGIT_ = 274,
     STRING_LITERAL = 275,
     CHAR_LITERAL = 276,
     LT_ = 277,
     GT_ = 278,
     LEQ_ = 279,
     GEQ_ = 280,
     EQ_ = 281,
     PLUS_EQ_ = 282,
     MINUS_EQ_ = 283,
     PLUS_ = 284,
     MINUS_ = 285,
     MULT_ = 286,
     DIV_ = 287,
     PERCENT_ = 288,
     EQEQ_ = 289,
     NEQ_ = 290,
     ANDAND_ = 291,
     OROR_ = 292,
     LOG_NOT_ = 293,
     ROUND_ = 294,
     LOC_ = 295,
     UN_MINUS_ = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 23 "project.y"

	char *str;
	char *typ;
	char *bol;
	int inti;
	program_node *prognode;
	method_node *methodnode;
	list<method_node *> *methodnodelist;
	field_node *fieldnode;
	field *fld;
	list<field *> *fldlist;
	list<field_node *> *fieldnodelist;
	arg_node *argnode;
	list<arg_node *> *argnodelist;
	block_node *blocknode;
	variable_node *variablenode;
	list<variable_node *> *variablenodelist;
	id_node *idnode;
	list<id_node *> *idnodelist;
	statement_node *statementnode;
	list<statement_node *> *statementnodelist;
	literal_node *literalnode;
	expr_node *exprnode;
	list<expr_node *> *exprnodelist;
	else_block_node *elseblocknode;
	location_node *locationnode;
	method_call_node *methodcallnode;
	callout_arg_node *calloutargnode;
	list<callout_arg_node *> *calloutargnodelist;


/* Line 2058 of yacc.c  */
#line 130 "project.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PROJECT_TAB_H_INCLUDED  */
