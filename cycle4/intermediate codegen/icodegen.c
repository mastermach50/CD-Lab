#include <stdio.h>
#include <ctype.h>
#include <string.h>

char opstack[100], postfix[100];
int top = -1, p = 0, temp = 1;

int prec(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char expr[100], lhs;
    char a, b, op;
    char tac[100][100];
    int n = 0;

    printf("Enter expression: ");
    scanf("%99s", expr);

    lhs = expr[0];

    for (int i = 2; expr[i]; i++) {
        char c = expr[i];

        if (isalnum((unsigned char)c))
            postfix[p++] = c;
        else if (c == '(')
            opstack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && opstack[top] != '(')
                postfix[p++] = opstack[top--];
            if (top >= 0) top--;
        }
        else {
            while (top >= 0 && opstack[top] != '(' &&
                   prec(opstack[top]) >= prec(c))
                postfix[p++] = opstack[top--];
            opstack[++top] = c;
        }
    }

    while (top >= 0)
        postfix[p++] = opstack[top--];

    postfix[p] = '\0';

    char values[100][20];
    int vtop = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isalnum((unsigned char)c)) {
            values[++vtop][0] = c;
            values[vtop][1] = '\0';
        } else {
            char right[20], left[20], result[20];

            strcpy(right, values[vtop--]);
            strcpy(left, values[vtop--]);

            sprintf(result, "t%d", temp++);
            sprintf(tac[n++], "%s = %s %c %s",
                    result, left, c, right);

            strcpy(values[++vtop], result);
        }
    }

    printf("\nThree Address Code:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", tac[i]);

    printf("%c = %s\n", lhs, values[vtop]);

    return 0;
}