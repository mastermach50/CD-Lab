# Lex
Lexical analyzer generator
source code -> tokens

Modern: Flex
File Extension: .l
Command to run: `flex lexer.l`
Output files generated: `lex.yy.c`

Functions:
- yylex: returns id of token found or 0 on eof
lex will generate the code for yylex, what we define in lexer.l is what the tokens look like

Variables:
- yytext: 

# Yacc
Yet Another Compiler Compiler
tokens -> validate -> generate ast or execute actions

Modern: Bison
File Extension: .y
Command to run: `yacc -d parser.y`
Output files generated: `y.tab.h`, `y.tab.c`

Final compilation command: `gcc y.tab.c y.tab.h lex.yy.c -lfl -ly`