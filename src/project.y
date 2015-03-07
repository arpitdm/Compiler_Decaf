%{
#include <stdio.h>
#include "project.h"
#include <string>
#include <iostream>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace std;
using namespace llvm;

int yydebug=1;
int yylex();
void yyerror (char const *s) {}

program_node *root;
%}

%union
{
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
}

%start program
%token BOOLEAN_
%token BREAK_
%token CALLOUT_
%token CLASS_
%token CONTINUE_
%token ELSE_
%token FALSE_
%token FOR_
%token IF_
%token INT_
%token RETURN_
%token TRUE_
%token VOID_
%token PROGRAM_
%token DIGIT_
%token ID_
%token HEX_DIGIT_
%token STRING_LITERAL
%token CHAR_LITERAL
%token LT_
%token GT_
%token LEQ_
%token GEQ_
%token EQ_
%token PLUS_EQ_
%token MINUS_EQ_
%token PLUS_
%token MINUS_
%token MULT_
%token DIV_
%token PERCENT_
%token EQEQ_
%token NEQ_
%token ANDAND_
%token OROR_
%token LOG_NOT_
%token ROUND_

%left LOC_
%left ROUND_
%left OROR_
%left ANDAND_
%left EQEQ_ NEQ_
%left LT_ LEQ_ GEQ_ GT_
%left PLUS_ MINUS_
%left MULT_ DIV_ PERCENT_
%left LOG_NOT_
%left UN_MINUS_
%type <prognode> program
%type <methodnode> method_decl
%type <methodnodelist> method_
%type <fieldnodelist> new_field_decl
%type <fld> field_decl
%type <fldlist> field_
%type <argnodelist> multi_type_id
%type <argnodelist> multi_type_id2
%type <str> assign_op
%type <str> EQ_
%type <str> PLUS_EQ_
%type <str> MINUS_EQ_
%type <str> ID_
%type <str> CHAR_LITERAL
%type <str> STRING_LITERAL
%type <str> ELSE_
%type <typ> type
%type <typ> INT_
%type <typ> BOOLEAN_
%type <typ> VOID_
%type <bol> TRUE_
%type <bol> FALSE_
%type <bol> bool_literal
%type <inti> int_literal
%type <inti> DIGIT_
%type <inti> HEX_DIGIT_
%type <blocknode> block
%type <variablenode> var_decl
%type <variablenodelist> var_
%type <idnodelist> var_decl_ 
%type <statementnode> statement_decl
%type <statementnodelist> statement_
%type <literalnode> literal
%type <exprnode> expr
%type <exprnode> expr_
%type <exprnodelist> expr_plus
%type <exprnodelist> expr_sq
%type <elseblocknode> else_block
%type <locationnode> location
%type <methodcallnode> method_call
%type <calloutargnodelist> callout_arg_sq
%type <calloutargnodelist> callout_arg_
%type <calloutargnode> callout_arg
%%

program:	  CLASS_ PROGRAM_ '{' field_ method_ '}'				{ $$ = new program_node($4,$5); root = $$;/*arguments*/ }	
;

field_:		  field_ field_decl							{ $$ = $1; $1->push_front($2); }
		| 									{ $$ = new list<field *>(); }
;

field_decl:	  type new_field_decl							{ $$ = new field($1, $2); /*need to send data*/}
;

new_field_decl:	  ID_ ';'								{ field_node_single *s = new field_node_single($1);
											  list<field_node *> *b = new list<field_node *>();
											  b->push_front(s);
											  $$ = b; }
		| ID_ '[' int_literal ']' ';'						{ field_node_array *s = new field_node_array($1, $3);
											  list<field_node *> *b = new list<field_node *>();
											  b->push_front(s);
											  $$ = b; }
		| ID_ ',' new_field_decl						{ field_node_single *n = new field_node_single($1);
											  $3->push_front(n);
											  $$ = $3; }
		| ID_ '[' int_literal ']' ',' new_field_decl				{ field_node_array *m = new field_node_array($1, $3);
											  $6->push_front(m);
											  $$ = $6; }
;

method_:	  method_decl method_							{ $$ = $2; $2->push_front($1); }
		| 									{ $$ = new list<method_node *>(); }
;

method_decl:	  type ID_ ROUND_ multi_type_id ')' block				{ $$ = new method_node($1,$2,$4,$6); /* arguments */ }
		| VOID_ ID_ ROUND_ multi_type_id ')' block				{ $$ = new method_node($1,$2,$4,$6); /* arguments */ }
;		  

multi_type_id:	  multi_type_id2							{ $$ = $1;}
		| 									{ $$ = new list<arg_node *>();}
;

multi_type_id2:   type ID_								{ arg_node *a = new arg_node($1,$2);
											  list<arg_node *> *l = new list<arg_node *>(); /*send type and id ar arg*/
											  l->push_front(a);
											  $$ = l; }
		| type ID_ ',' multi_type_id2						{ arg_node *b = new arg_node($1,$2);
											  $4->push_front(b);
											  $$ = $4; }
;

block:		  '{' var_ statement_ '}'						{ $$ = new block_node($2,$3); }
;

var_:		  var_decl var_								{ $$ = $2; $2->push_front($1); }
		| 									{ $$ = new list<variable_node *>(); }
;

var_decl: 	  type var_decl_							{ $$ = new variable_node($1, $2); /* send $1 and $2*/ }
;

var_decl_:	  ID_ ';'								{ id_node *i = new id_node($1);
											  list<id_node *> *c = new list<id_node *>(); 
											  c->push_front(i);
											  $$ = c; }
		| ID_ ',' var_decl_							{ id_node *d = new id_node($1);
											  $3->push_front(d);
											  $$ = $3; }
;

statement_:	  statement_decl statement_						{ $$ = $2; $2->push_back($1); }
		| 									{ $$ = new list<statement_node *>(); }
;

statement_decl:	  location assign_op expr ';'						{ $$ = new assign_stmt($1,$2,$3); /*send arguments*/}
		| method_call ';'							{ $$ = new method_call_stmt($1);/* send arguments*/}
		| IF_ ROUND_ expr ')' block else_block					{ $$ = new if_else_stmt($3,$5,$6); /*send arguments*/}
		| FOR_ ID_ EQ_ expr ',' expr block					{ $$ = new for_stmt($2,$4,$6,$7); /*send arguments*/}
		| RETURN_ expr_ ';'							{ $$ = new return_stmt($2); /*send arguments*/}
		| BREAK_ ';'								{ $$ = new break_stmt(); /*send arguments*/}
		| CONTINUE_ ';'								{ $$ = new continue_stmt(); /*send arguments*/}
		| block									{ $$ = $1; }
;

else_block:	  ELSE_ block								{ $$ = new else_block_node_1($1,$2);
											}
		| 									{ $$ = new else_block_node_2();
											}
;

expr_:		  expr									{ $$ = $1;}
		| 									{ $$ = new dummy_node();}
;

assign_op:	  EQ_									{ $$ = $1; }
		| PLUS_EQ_								{ $$ = $1; }
		| MINUS_EQ_								{ $$ = $1; }
;

location:	  ID_ %prec LOC_							{ $$ = new location_node_single($1);}
		| ID_ '[' expr ']' 							{ $$ = new location_node_expr($1,$3);}
;

method_call: 	  ID_  ROUND_ expr_sq ')'						{ $$ = new method_call_node_1($1,$3); 
											}
		| CALLOUT_ ROUND_ STRING_LITERAL callout_arg_sq ')'			{ $$ = new method_call_node_2($3,$4); 
											}
;

callout_arg_sq:	  ',' callout_arg_							{ $$ = $2; 
											}
		| 									{ $$ = new list<callout_arg_node *>(); 
											}
;

callout_arg_:	  callout_arg								{// callout_arg_node *f = new callout_arg_node();
											  list<callout_arg_node *> *g = new list<callout_arg_node *>();
											  g->push_front($1);
											  $$ = g; 
											}
		| callout_arg_ ',' callout_arg						{// callout_arg_node *h = new callout_arg_node();
											  $1->push_front($3);
											  $$ = $1;
											}
;
			  
callout_arg: 	  expr									{ $$ = new callout_expr_arg_node($1); 
											}
		| STRING_LITERAL							{ $$ = new callout_strlit_arg_node($1); 
											}
;

expr_plus:	  expr									{ 
											  list<expr_node *> *u = new list<expr_node *>();
											  u->push_front($1);
											  $$ = u; 
											}
		| expr ',' expr_plus							{/* expr_node *r = new expr_node();*/
											  $3->push_front($1);
											  $$ = $3;
											}
;

expr_sq:	  expr_plus								{ $$ = $1;
											}
		| 									{ $$ = new list<expr_node *>(); 
											}
;
		
expr:		  location								{ $$ = $1; }
		| method_call								{ $$ = new method_call_expr($1); }
		| literal								{ $$ = $1; }
		| expr PLUS_ expr							{ $$ = new plus_node($1,$3); }
		| expr MINUS_ expr							{ $$ = new minus_node($1, $3); }
		| expr MULT_ expr							{ $$ = new mult_node($1, $3) ; }
		| expr DIV_ expr							{ $$ = new div_node($1, $3); }
		| expr PERCENT_ expr							{ $$ = new percent_node($1, $3); }
		| expr LT_ expr								{ $$ = new less_node($1, $3); }
		| expr GT_ expr								{ $$ = new greater_node($1, $3); }
		| expr GEQ_ expr							{ $$ = new geq_node($1, $3); }
		| expr LEQ_ expr							{ $$ = new leq_node($1, $3); }
		| expr EQEQ_ expr							{ $$ = new eqeq_node($1, $3); }
		| expr NEQ_ expr							{ $$ = new neq_node($1, $3); }
		| expr ANDAND_ expr							{ $$ = new andand_node($1, $3); }
		| expr OROR_ expr							{ $$ = new oror_node($1, $3); }
		| MINUS_ expr	%prec UN_MINUS_						{ $$ = new uminus_node($2); } 
		| LOG_NOT_ expr								{ $$ = new lognot_node($2); }
		| ROUND_ expr ')'							{ $$ = new paren_node($2); }
;

literal: 	  int_literal								{$$ = new int_literal_node($1);}
		| CHAR_LITERAL								{$$ = new char_literal_node($1);}
		| bool_literal								{$$ = new bool_literal_node($1);}
;

bool_literal:	  TRUE_									{$$ = $1;}
		| FALSE_								{$$ = $1;}
; 	
		
int_literal: 	DIGIT_									{ $$ = $1;}
		| HEX_DIGIT_								{ $$ = $1;}
;
 
type: 		  INT_									{ $$ = $1;}
		| BOOLEAN_								{ $$ = $1;}
;

%%

int main()
{
		int a = yyparse();

//        if(a==0)
//                printf("Syntactically Correct\n");
//        else
//                printf("Syntactically Incorrect\n");
	root->print_();

		LLVMContext &Context = getGlobalContext();
		TheModule = new Module("Decaf Compiler", Context);
        return 0;
}

