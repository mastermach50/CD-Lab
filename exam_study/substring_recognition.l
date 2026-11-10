%{
#include <stdio.h>
%}

%%

.*[tT][eE][sS][tT].* {
    printf("Contains substring\n");
    return 0;
}

.* {
    printf("Does not contain substring\n");
    return 0;
}

%%

void main() {
    printf("Enter string: ");
    yylex();
}