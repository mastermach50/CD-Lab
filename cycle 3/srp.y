%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *s);
%}

%token ID NUM

%%
S   : E '\n' { printf("Successfully parsed using Shift-Reduce\n"); exit(0); }
    ;
E   : E '+' T  { printf("Reduce: E -> E + T\n"); }
    | T        { printf("Reduce: E -> T\n"); }
    ;
T   : T '*' F  { printf("Reduce: T -> T * F\n"); }
    | F        { printf("Reduce: T -> F\n"); }
    ;
F   : '(' E ')'{ printf("Reduce: F -> ( E )\n"); }
    | ID       { printf("Reduce: F -> ID\n"); }
    | NUM      { printf("Reduce: F -> NUM\n"); }
    ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Syntax Error\n");
    exit(1);
}

int main() {
    printf("Enter expression (Shift-Reduce): ");
    yyparse();
    return 0;
}
