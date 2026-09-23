%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *s);
%}

%token ID NUM
%left '+' '-'
%left '*' '/'
%right '^'

%%
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '^' expr
    | '(' expr ')'
    | ID
    | NUM
    ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Rejected\n");
    exit(1);
}

int main() {
    printf("Enter expression: ");
    yyparse();
    printf("Accepted (Valid Operator Precedence)\n");
    return 0;
}
