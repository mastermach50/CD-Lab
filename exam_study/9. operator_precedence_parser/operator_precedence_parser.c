#include <stdio.h>

char stack[100];
int top = 0;
int i = 0;

char terminals[] = {'+', '*', 'i', '$'};

int indexof(char t) {
    for (int j = 0; j < 4; j++) {
        if (terminals[j] == t) {
            return j;
        }
    }

    return -1;
}

char prec[4][4] = {
    {'>', '<', '<', '>'},
    {'>', '>', '<', '>'},
    {'>', '>', 'e', '>'},
    {'<', '<', '<', 'A'},
};

int main() {
    char input[100];
    printf("Enter expression (i for ID, + and *, end with $): ");
    scanf("%s", input);

    stack[top] = '$';
    stack[top + 1] = '\0';

    printf("%-15s %-15s %-15s\n", "Stack", "Input", "Action");
    printf("---\n");

    while (1) {
        int s = indexof(stack[top]);
        int in = indexof(input[i]);

        if (s == -1 || in == -1) {
            printf("%-15s %-15s Rejected (Invalid symbol)\n", stack, &input[i]);
            break;
        }

        char rel = prec[s][in];

        if (rel == 'A') {
            printf("%-15s %-15s Accepted\n", stack, &input[i]);
            break;
        } else if (rel == '<' || rel == '=') {
            printf("%-15s %-15s Shift %c\n", stack, &input[i], input[i]);
            stack[++top] = input[i++];
            stack[top + 1] = '\0';
        } else if (rel == '>') {
            printf("%-15s %-15s Reduce (Pop %c)\n", stack, &input[i], stack[top]);
            top--;
            stack[top + 1] = '\0';
        } else {
            printf("%-15s %-15s Rejected (Syntax error)\n", stack, &input[i]);
            break;
        }
    }

    return 0;
}
