#include <stdio.h>
#include <string.h>

char stack[100], inp[100];
int top = -1;
int i = 0;

void pop() {
    stack[top--] = '\0';
}

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

int match(const char pat[]) {
    int len = strlen(pat);

    if (top < len - 1)
        return 0;

    for (int k = 0; k<len; k++) {
        if (stack[top-k] != pat[k])
            return 0;
    }

    return 1;
}

int reduce() {
    // E -> i
    if (match("i")) {
        pop();
        push('E');
        return 1;
    }
    // E -> E+E
    if (match("E+E")) {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    // E -> E-E
    if (match("E-E")) {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    // E -> E*E
    if (match("E*E")) {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    // E -> (E) — top is ')', top-1 is 'E', top-2 is '('
    if (match(")E(")) {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", inp);

    printf("%-15s %-15s %-15s\n", "STACK", "INPUT", "ACTION");

    while (inp[i] != '\0') {

        // Shift
        push(inp[i]);
        i++;
        printf("%-15s %-15s SHIFT\n", stack, inp + i);

        // Reduce
        while (reduce()) {
            printf("%-15s %-15s REDUCE\n", stack, inp + i);
        }
    }

    // Reduce
    while (reduce()) {
        printf("%-15s %-15s REDUCE\n", stack, inp + i);
    }

    if (stack[top] == 'E' && top == 0) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
