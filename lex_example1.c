%{ 
#include <stdio.h> 
int c=0;
%}
%% 

[if|else]+ {printf("KEYWORD: %s\n",yytext);c++;}
[0-9]+    printf("NUMBER: %s\n", yytext); 
[a-zA-Z]+  printf("WORD: %s\n", yytext); 
[ \t]+ 
.          printf("UNKNOWN: %s\n", yytext);                     
[\n] {return 0;}

%%

 int main() 
  {
    yylex();
    printf("The number of keywords is %d",c);
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
