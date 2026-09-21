%{
#include "y.tab.h"
%}

%%

"for"                   { return FOR; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }
[0-9]+                  { return NUM; }

"++"                    { return INC_DEC; }
"--"                    { return INC_DEC; }
"<="                    { return RELOP; }
">="                    { return RELOP; }
"=="                    { return RELOP; }
"!="                    { return RELOP; }
"<"                     { return RELOP; }
">"                     { return RELOP; }

[ \t\n]                 { /* Ignore whitespace */ }
.                       { return yytext[0]; } /* Return single characters like (, ), ;, =, +, - */

%%

int yywrap(void) {
    return 1;
}