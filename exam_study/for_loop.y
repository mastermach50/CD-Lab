%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token FOR ID NUM RELOP INC_DEC

%%

/* Grammar Rules for a C FOR statement */

stmt:
    FOR '(' init ';' cond ';' incr ')' body {
        printf("Valid FOR loop syntax!\n");
        exit(0);
    }
    ;

init:
    ID '=' expr
    | /* empty initialization */
    ;

cond:
    expr RELOP expr
    | expr
    | /* empty condition */
    ;

incr:
    ID INC_DEC
    | INC_DEC ID
    | ID '=' expr
    | /* empty increment */
    ;

body:
    stmt
    | expr ';'
    | '{' body_stmts '}'
    | ';'
    ;

body_stmts:
    body_stmts stmt
    | body_stmts expr ';'
    | /* empty */
    ;

expr:
    ID
    | NUM
    | expr '+' expr
    | expr '-' expr
    ;

%%

void yyerror(const char *s) {
    printf("Invalid FOR loop syntax!\n");
}

int main(void) {
    printf("Enter a FOR statement: ");
    yyparse();
    return 0;
}