%{
#include "ast.h"
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+  {
    yylval.ival = atoi(yytext);
    return NUMBER;
}

[ \t\n] { /* Ignore whitespace */ }

.       { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}