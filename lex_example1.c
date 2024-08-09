%{ 
#include <stdio.h> 
%}
%% 
[0-9]+    printf("NUMBER: %s\n", yytext); 
[a-zA-Z]+  printf("WORD: %s\n", yytext); 
[ \t]+                               
.     printf("UNKNOWN: %s\n", yytext);
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
