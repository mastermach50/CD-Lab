#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[]) {
    char *keywords[] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return", "void", "break"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    char ch, token[100];
    int j;

    printf("Enter the source file name: ");
    scanf("%99s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        /* Ignore spaces, tabs and newlines */
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        /* Identifier or Keyword */
        if (isalpha(ch) || ch == '_') {
            j = 0;
            token[j++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_')) {
                token[j++] = ch;
            }

            token[j] = '\0';

            if (isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* Number */
        else if (isdigit(ch)) {
            j = 0;
            token[j++] = ch;

            while ((ch = fgetc(fp)) != EOF && isdigit(ch)) {
                token[j++] = ch;
            }

            token[j] = '\0';
            printf("%s --> Number\n", token);

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* Operators */
        else if (strchr("+-*/=%<>!", ch)) {
            printf("%c --> Operator\n", ch);
        }

        /* Special Symbols */
        else if (strchr("(){}[],;#", ch)) {
            printf("%c --> Special Symbol\n", ch);
        }

        /* Invalid Characters */
        else {
            printf("%c --> Invalid Token\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
