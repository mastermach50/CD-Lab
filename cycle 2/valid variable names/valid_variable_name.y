%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token IDENTIFIER

%%
input:
    IDENTIFIER { printf("Valid variable name\n"); }
    ;
%%

void yyerror(const char *s) {
    printf("Invalid variable name\n");
}

int main(void) {
    printf("Enter variable name: ");
    yyparse();
    return 0;
}