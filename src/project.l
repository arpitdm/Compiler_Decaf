%{
#include "project.h"
#include "project.tab.h"
%}

CHAR ([ !#-&\(-\[\]-~]|[\\][nt\"\'\\])
WS ([ \t\n])
COMMENTS ([/][/].*[\n])
%%
"Program"			return PROGRAM_;
"boolean"		 	{yylval.typ=strdup(yytext); return BOOLEAN_;}
"break"				return BREAK_;
"callout"			return CALLOUT_;
"class"				return CLASS_;
"continue"			return CONTINUE_;
"else"				{yylval.str=strdup(yytext);return ELSE_;}
"false"				{yylval.bol=strdup(yytext); return FALSE_;}
"for"				return FOR_;
"if"				return IF_;
"int"				{yylval.typ=strdup(yytext); return INT_;}
"return"			return RETURN_;
"true"				{yylval.bol=strdup(yytext); return TRUE_;}
"void"				{yylval.typ=strdup(yytext); return VOID_;}

[0-9]+				{yylval.inti=atoi(yytext);return DIGIT_;}
[_a-zA-Z][_a-zA-Z0-9]*		{yylval.str=strdup(yytext);return ID_;}
["]{CHAR}*["]			{yylval.str=strdup(yytext);return STRING_LITERAL;}
[']{CHAR}[']			{yylval.str=strdup(yytext);return CHAR_LITERAL;}
[<]				return LT_;
[>]				return GT_;
[<][=]				return LEQ_;
[>][=]				return GEQ_;
[=]				{yylval.str=strdup(yytext); return EQ_;}
[+]				return PLUS_;
[-]				return MINUS_;
[*]				return MULT_;
[/]				return DIV_;
[%]				return PERCENT_;
[+][=]				{yylval.str=strdup(yytext); return PLUS_EQ_;}
[(]				return ROUND_;
[-][=]				{yylval.str=strdup(yytext); return MINUS_EQ_;}
[=][=]				return EQEQ_;
[!][=]				return NEQ_;
[&][&]				return ANDAND_;
[|][|]				return OROR_;
[!]				return LOG_NOT_;
0x[0-9a-fA-F]+			{yylval.inti=(int)strtol(yytext,NULL,16);return HEX_DIGIT_;}
{WS}+				;
{COMMENTS}*			;
.				{return *yytext;}
%%

