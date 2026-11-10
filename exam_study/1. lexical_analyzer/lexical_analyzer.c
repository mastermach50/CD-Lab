#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE* fp;
char token[100];

const char *c_keywords[] = {
    "auto",     "break",    "case",     "char",
    "const",    "continue", "default",  "do",
    "double",   "else",     "enum",     "extern",
    "float",    "for",      "goto",     "if",
    "int",      "long",     "register", "return",
    "short",    "signed",   "sizeof",   "static",
    "struct",   "switch",   "typedef",  "union",
    "unsigned", "void",     "volatile", "while"
};

int gettoken() {
    memset(token, '\0', sizeof(token));
    int tn = 0;
    char c;

    // Ignore preceeding whitespace
    do {
        c = fgetc(fp);
    } while (c == ' ' || c == '\n' || c == '\t');

    if (c == EOF) {
        return 0;
    }

    // keywords and tokens
    if (isalpha(c) || c == '_') {
        do {
            token[tn++] = c;
        } while (isalnum(c = fgetc(fp)) || c == '_');
        ungetc(c, fp);
        return 1;
    }

    // numbers
    if (isdigit(c)) {
        do {
            token[tn++] = c;
        } while (isdigit(c = fgetc(fp)));
        ungetc(c, fp);
        return 1;
    }

    // Special characters and operators
    if (strchr("{}()[]<>#,;+-*/=!", c)) {
        token[tn++] = c;
        return 1;
    }

    return 0;
}

int iskeyword() {
    for (int i = 0 ; i < sizeof(c_keywords)/sizeof(c_keywords[0]); i++) {
        if (strcmp(token, c_keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    printf("Filename: %s\n", argv[1]);
    fp = fopen(argv[1], "r");

    while (gettoken()) {
        if (iskeyword()) {
            printf("KEYWORD     -> %s\n", token);
        } else if (isdigit(token[0])) {
            printf("NUMBER      -> %s\n", token);
        } else if ((strchr("+-*/=!#", token[0]))) {
            printf("OPERATOR    -> %s\n", token);
        } else if ((strchr("{}()[]<>,;", token[0]))) {
            printf("SPECIAL     -> %s\n", token);
        } else {
            printf("IDENTIFIER  -> %s\n", token);
        }
    }

    return 0;
}
