#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void main() {
FILE *input = fopen("input.txt","r");
char buffer[100];
int n=0,i;
char myString[100];
fgets(myString, 100, input);
printf("File Content : %s", myString);
fclose(input);
input = fopen("input.txt","r");
printf("Output of lexical analyzer is : \n");
char c;
do {
c = fgetc(input);
if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='='||c==';'||c==','||c==' '||c=='>') {
if(strncmp("int",buffer,3)==0||strncmp("float",buffer,5)==0||strncmp("if",buffer,2)==0||strncmp("else",buffer,4)==0||strncmp("printf",buffer,6)==0) {
printf("%s is a keyword\n",buffer);
}
else {
printf("%s is a identifier\n",buffer);
}
for(i=0;i<10;i++) {
buffer[i]='\0';
}
n=0;
if(c!=' ') {
printf("%c is an operator\n",c);
}
}
else if(isalnum(c)) {
buffer[n++]=c;
}
        if(feof(input))
            break;
           
}while(1);
if(buffer[0]!='\0')
printf("%s is a identifier\n\n",buffer);

}
