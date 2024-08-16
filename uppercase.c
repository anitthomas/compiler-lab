Exp 2.3: Write a LEX Program to convert the substring abc to ABC from the given input string.
input: 

Hello abcWorld

its o/p will be Hello ABCWorld

i/P:  abchello-----> o/p:  ABChello
-------------------------------------------------------------------------------------------------
%{
 #include <stdio.h>
 #include <ctype.h>
%}

%%

abc printf("ABC");
. printf("%s",yytext);
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
