%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*   {
    return IDENTIFIER;
}
\n {
    return 0; /* Stop parsing on newline */
}
. {
    return yytext[0];
}
%%

int yywrap() {
    return 1;
}