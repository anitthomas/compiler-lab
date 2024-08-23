Write a program using YACC to recognise a valid arithmetic expression that uses operators such as +, -, * or /.
-------------------------------------------------------------------------------------------------------------------------------


yacc.y

%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double

int yylex(void);
void yyerror(const char *s);
%}

%token DIGIT ID NL
%left '-' '+'
%left '*' '/'

%%
stmt : exp NL {printf("Valid expression\n"); exit(0);} ;
exp : exp '+' exp
    | exp '-' exp
    | exp '*' exp
    | exp '/' exp
    | '(' exp ')'
    | ID
    | DIGIT
    ;
%%

void yyerror(const char *s)
{
    printf("Invalid string\n");
}

int main()
{
    printf("Enter the exp: ");
    yyparse();
    return 0;
}



lex.l

%{
#include "y.tab.h"
%}
%%
[0-9]+ { return DIGIT;}
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
\n { return NL;}
. { return yytext[0]; }
%%
