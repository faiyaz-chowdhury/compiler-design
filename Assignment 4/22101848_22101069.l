%option noyywrap

%{

#include"symbol_info.h"

#define YYSTYPE symbol_info*

/* Include the parser header file */
#include "y.tab.h"

extern YYSTYPE yylval;

void yyerror(char *);

extern int line_count;

%}

/* Pattern definitions */
whitespace	 [ \t\v\r\f]
newline_char  \r?\n
ws_pattern		 {whitespace}+
letter_underscore	 [A-Za-z_]
numeric_digit	 [0-9]
identifier		 {letter_underscore}({letter_underscore}|{numeric_digit})*
integer_const {numeric_digit}+
float_const	 {numeric_digit}*(\.{numeric_digit}+)|{numeric_digit}*(\.{numeric_digit}+)?((E|e)[-]?{numeric_digit}+)

%%

{ws_pattern}		{ /* skip whitespace characters */ }
{newline_char}	{ line_count++; }

if          { return IF; }
else		{ return ELSE; }
for         { return FOR; }
while       { return WHILE; }
do          { return DO; }
break       { return BREAK; }
continue    { return CONTINUE; }
return      { return RETURN; }
int         { return INT; }
float       { return FLOAT; }
char        { return CHAR; }
void        { return VOID; }
double      { return DOUBLE; }
switch      { return SWITCH; }
case        { return CASE; }
default     { return DEFAULT; }
printf      { return PRINTLN; }

"+"|"-"	    {
                symbol_info *sym_obj = new symbol_info((string)yytext,"ADDOP");
                yylval = (YYSTYPE)sym_obj;
                return ADDOP;
		    }
"*"|"/"|"%"    {
                symbol_info *sym_obj = new symbol_info((string)yytext,"MULOP");
                yylval = (YYSTYPE)sym_obj;
                return MULOP;
            }
"++"        { return INCOP; }
"--"        { return DECOP; }
"<"|">"|"<="|">="|"=="|"!=" {
                symbol_info *sym_obj = new symbol_info((string)yytext,"RELOP");
                yylval = (YYSTYPE)sym_obj;
                return RELOP;
            }

"="         { return ASSIGNOP; }
"&&"|"||"   {
		   	symbol_info *sym_obj = new symbol_info((string)yytext,"LOGICOP");
			yylval = (YYSTYPE)sym_obj;
			return LOGICOP;
		    }

"!"        { return NOT; }
"("        { return LPAREN; }
")"        { return RPAREN; }
"{"        { return LCURL; }
"}"        { return RCURL; }
"["        { return LTHIRD; }
"]"        { return RTHIRD; }
";"        { return SEMICOLON; }
","        { return COMMA; }

{identifier}       {
                symbol_info *sym_obj = new symbol_info((string)yytext,"ID");
                yylval = (YYSTYPE)sym_obj;
                return ID;
            }
{integer_const} {
                symbol_info *sym_obj = new symbol_info((string)yytext,"INT");
                yylval = (YYSTYPE)sym_obj;
                return CONST_INT;
            }
{float_const}   {
                symbol_info *sym_obj = new symbol_info((string)yytext,"FLOAT");
                yylval = (YYSTYPE)sym_obj;
                return CONST_FLOAT;
            }
%%
