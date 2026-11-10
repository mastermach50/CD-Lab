#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char line[100], result[20], a[20], b[20], op;

    printf("Enter number of TAC instructions: ");
    scanf("%d", &n);
    getchar();

    printf("\n.model small\n.stack 100h\n.data\n");

    /* Declare variables used in your TAC here. */
    printf("a dw 0\n");
    printf("b dw 0\n");
    printf("c dw 0\n");
    printf("d dw 0\n");
    printf("t1 dw 0\n");
    printf("t2 dw 0\n");

    printf(".code\nmain proc\n");
    printf("mov ax, @data\n");
    printf("mov ds, ax\n");

    for (int i = 0; i < n; i++) {
        printf("\n; TAC instruction %d\n", i + 1);
        fgets(line, sizeof(line), stdin);

        if (sscanf(line, " %19s = %19s %c %19s",
                   result, a, &op, b) == 4) {
            if (op == '+') {
                printf("mov ax, %s\n", a);
                printf("add ax, %s\n", b);
                printf("mov %s, ax\n", result);
            }
            else if (op == '-') {
                printf("mov ax, %s\n", a);
                printf("sub ax, %s\n", b);
                printf("mov %s, ax\n", result);
            }
            else if (op == '*') {
                printf("mov ax, %s\n", a);
                printf("mul %s\n", b);
                printf("mov %s, ax\n", result);
            }
            else if (op == '/') {
                printf("mov ax, %s\n", a);
                printf("xor dx, dx\n");
                printf("div %s\n", b);
                printf("mov %s, ax\n", result);
            }
        }
        else if (sscanf(line, " %19s = %19s",
                        result, a) == 2) {
            printf("mov ax, %s\n", a);
            printf("mov %s, ax\n", result);
        }
    }

    printf("\nmov ah, 4ch\n");
    printf("int 21h\n");
    printf("main endp\nend main\n");

    return 0;
}