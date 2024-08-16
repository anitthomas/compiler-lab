Exp. 2.4 :Write a lex program to find out total number of vowels and consonants from the given input sting.

i/P:

Hello

Vowels=2

Consonants=3
--------------------------------------------------------------------------------------------------------------
%{
 #include <stdio.h>
 int vowel=0,consonant=0;
%}

%%

[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonant++;}
[\n] {return 0;}

%%  

int main()
{
 yylex();
 printf("Number of vowels : %d\n",vowel);
 printf("Number of consonants : %d\n",consonant);
 return 0;
}

int yywrap()
{
return 1;
}
