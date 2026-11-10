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
- yywrap: called on eol, 1 -> terminate, 0 -> continue scanning

Variables:
- yytext: matched text
- yyleng: length of matched text
- yylval: Global variable used to pass semantic values (attr data) to Yacc.

# Yacc
Yet Another Compiler Compiler
tokens -> validate -> generate ast or execute actions

Modern: Bison
File Extension: .y
Command to run: `yacc -d parser.y`
Output files generated: `y.tab.h`, `y.tab.c`

Functions:
- yyparse: main parsing routine
- yyerror: error handler called by yyparse on syntax error

Varibles:
- yylval: same as in lex
- $$: semantic value pseudo varible (yylval)

---

Final compilation command: `gcc y.tab.c y.tab.h lex.yy.c -lfl -ly`