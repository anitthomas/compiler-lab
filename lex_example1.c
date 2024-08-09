%{ 
#include <stdio.h> 
%}
%% 

if|else|int|switch|char printf("KEYWORD: %s\n",yytext);
[a-z_][a-z0-9_]*  printf("IDENTIFIER: %s\n", yytext); 
[0-9]+    printf("NUMBER: %s\n", yytext); 
[=+*/^<>-]+  printf("OPERATOR: %s\n", yytext); 
[0-9][a-zAZ0-9]+ printf("NOT AN IDENTIFIER: %s\n", yytext); 
[ \t]+ 
.          printf("UNKNOWN: %s\n", yytext);                     
[\n] {return 0;}

%%

 int main() 
  {
    yylex();
    return 0; 
   }
   
 int yywrap()
 {
  return 1;
  }

--------------------------------------------------------
  lex lexex.l
  gcc lex.yy.c
  ./a.out
