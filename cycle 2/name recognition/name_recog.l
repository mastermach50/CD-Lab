%{
#include <stdio.h>
#include <string.h>
%}

%%
.*[Mm][Aa][Tt][Hh].*\n {
    printf("String contains substring \"MATH\".\n");
    return 0;
}
.* {
    printf("String does NOT contain substring \"MATH\".\n");
    return 0;
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string: ");
    yylex();
    return 0;
}
