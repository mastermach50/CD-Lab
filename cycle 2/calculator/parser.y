%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    double dval;
}

%token <dval> NUMBER
%type <dval> expr

/* Precedence rules (lowest to highest precedence) */
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS /* Unary minus operator precedence */

%%

statement:
    expr { printf("Result = %g\n", $1); }
    ;

expr:
    NUMBER          { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { 
        if ($3 == 0) {
            yyerror("Error: Division by zero!");
            exit(1);
        }
        $$ = $1 / $3; 
    }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'  { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    printf("Enter expression: ");
    yyparse();
    return 0;
}