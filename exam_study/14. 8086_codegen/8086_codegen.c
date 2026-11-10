#include <stdio.h>

int main() {
    int num_tac;
    char line[100], result[20], a[20], b[20], op;

    printf("Enter number of TAC instructions: ");
    scanf("%d", &num_tac);

    for (int i = 0; i < num_tac; i++) {

        scanf("%s = %s %c %s", result, a, &op, b);
        switch (op) {

            case '+':
                printf("mov ax, %s\n", a);
                printf("add ax, %s\n", b);
                printf("mov %s, ax\n", result);
                break;
            case '-':
                printf("mov ax, %s\n", a);
                printf("sub ax, %s\n", b);
                printf("mov %s, ax\n", result);
                break;
            case '*':
                printf("mov ax, %s\n", a);
                printf("mul %s\n", b);
                printf("mov %s, ax\n", result);
                break;
            case '/':
                printf("mov ax, %s\n", a);
                printf("div %s\n", b);
                printf("mov %s, ax\n", result);
                break;
        }
    }

    return 0;
}
