Hint : In the rules section, you may add these or refer the examples section above

\n          { line_count++; char_count++; }
[ \t]       { char_count++; }
etc.. add some other rules also...

here for eg. [^ \t\n]+  means the action part Matches sequences of characters that are not spaces, tabs, or newlines, incrementing the word counter and adding the length of the sequence to the character counter. Also,

    yytext: A pointer to the matched string.
    yyleng: The length of the matched string.
    So, For example, if the lexer matches the word “hello”, yytext would contain “hello” and yyleng would be 5, indicating the length of the string.
    Reminder, all the variables should be declared in the Declaration section.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


%{
 #include <stdio.h>
 int line_count=0,word_count = 0,char_count=0;
%}

%%

[ \t] {word_count++;char_count++;}
[\n] {line_count++;word_count++;char_count;}
[\n][\n] {return 0;}
. {char_count++;}
%%

int main()
{
 yylex();
 printf("Number of lines: %d\n", ++line_count);
 printf("Number of words: %d\n", ++word_count);
 printf("Number of characters: %d\n", char_count);
 return 0;
}

int yywrap()
{
return 1;
}
