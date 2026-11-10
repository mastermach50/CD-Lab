#include <stdio.h>
#include <stdlib.h>

void E();
void F();
void T();
void error();


char input[100];
int i = 0;

void E() {
    T();
    while (input[i] == '+') {
        i++;
        T();
    }
}

void T() {
    F();
    while (input[i] == '*') {
        i++;
        F();
    }
}

void F() {
    if (input[i] == 'a') {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error();
        }

    } else {
        error();
    }
}

void error() {
    printf("Invalid expression");
    exit(-1);
}

int main() {
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0') {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    };

    return 0;
}
