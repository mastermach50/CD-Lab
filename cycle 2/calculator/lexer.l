%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+(\.[0-9]+)? {
    yylval.dval = atof(yytext);
    return NUMBER;
}

[ \t] ; /* Skip whitespace */

\n      { return 0; } /* End parsing on newline */

.       { return yytext[0]; } /* Return raw single characters like +, -, *, /, (, ) */

%%

int yywrap() {
    return 1;
}