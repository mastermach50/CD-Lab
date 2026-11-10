%{
#include <stdio.h>
#include <stdlib.h>

int yyerror(const char[]);
int yylex(void);
%}

%token NUM ID
%left '+' '-'
%left '*' '/'
%right '^'

%%

expr:
    expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '^' expr
    | '(' expr ')'
    | ID
    | NUM
    ;

%%

int yyerror(const char[]) {
    printf("Invalid expression");
    exit(-1);
}

int main() {
    printf("Enter expression: ");
    yyparse();
    printf("Valid expression");
    return 0;
}