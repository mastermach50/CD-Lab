%{
    #include <stdio.h>

    int yylex(void);
    void yyerror(const char *s);
%}

%token IDENTIFIER

%%

input:
    IDENTIFIER {
        printf("Valid variable name\n");
    };

%%

void yyerror(const char *s) {
    printf("Invalid variable name");
}

void main() {
    printf("Enter variable name:");
    yyparse();
}
