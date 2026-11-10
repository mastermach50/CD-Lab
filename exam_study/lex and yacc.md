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