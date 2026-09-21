%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int yylex(void);
void yyerror(const char *s);
ASTNode *root = NULL;
%}

/* Define the types held by YACC's semantic stack */
%union {
    int ival;
    struct ASTNode *node;
}

/* Map tokens and non-terminals to union members */
%token <ival> NUMBER
%type <node> expr term factor

%%

/* Grammar Rules converted from BNF */

calc:
    expr { root = $1; }
    ;

expr:
    expr '+' term { $$ = make_op_node(NODE_ADD, $1, $3); }
    | expr '-' term { $$ = make_op_node(NODE_SUB, $1, $3); }
    | term          { $$ = $1; }
    ;

term:
    term '*' factor { $$ = make_op_node(NODE_MUL, $1, $3); }
    | term '/' factor { $$ = make_op_node(NODE_DIV, $1, $3); }
    | factor        { $$ = $1; }
    ;

factor:
    '(' expr ')'    { $$ = $2; }
    | NUMBER        { $$ = make_num_node($1); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse Error: %s\n", s);
}

int main(void) {
    printf("Enter expression: ");
    if (yyparse() == 0 && root != NULL) {
        printf("\n--- Generated Abstract Syntax Tree (AST) ---\n");
        print_ast(root, 0);
    }
    return 0;
}