#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = 0, i = 0;

// Terminals supported by our grammar
char terminals[] = {'+', '*', 'i', '$'};

// Operator Precedence Table
// Rows: Stack top terminal | Columns: Current input token
char prec[4][4] = {
    /*         +    *    i    $  */
    /* + */  {'>', '<', '<', '>'},
    /* * */  {'>', '>', '<', '>'},
    /* i */  {'>', '>', 'e', '>'},
    /* $ */  {'<', '<', '<', 'A'} // 'A' = Accept, 'e' = Error
};

// Helper function to find the table index of a terminal
int get_index(char c) {
    for (int j = 0; j < 4; j++) {
        if (terminals[j] == c) return j;
    }
    return -1;
}

int main() {
    printf("Enter expression (use 'i' for ID, '+' and '*', end with '$'): ");
    scanf("%s", input);

    stack[top] = '$';
    stack[top + 1] = '\0';

    printf("\nStack\t\tInput\t\tAction\n");
    printf("--------------------------------------------\n");

    while (1) {
        int s = get_index(stack[top]);
        int in = get_index(input[i]);

        // Check for invalid characters
        if (s == -1 || in == -1) {
            printf("%s\t\t%s\t\tRejected (Invalid Symbol)\n", stack, &input[i]);
            break;
        }

        char relation = prec[s][in];

        if (relation == 'A') {
            printf("%s\t\t%s\t\tAccepted!\n", stack, &input[i]);
            break;
        } 
        else if (relation == '<' || relation == '=') {
            printf("%s\t\t%s\t\tShift %c\n", stack, &input[i], input[i]);
            stack[++top] = input[i++];
            stack[top + 1] = '\0';
        } 
        else if (relation == '>') {
            printf("%s\t\t%s\t\tReduce (Pop %c)\n", stack, &input[i], stack[top]);
            top--; // Pop the top terminal
            stack[top + 1] = '\0';
        } 
        else {
            printf("%s\t\t%s\t\tRejected (Syntax Error)\n", stack, &input[i]);
            break;
        }
    }

    return 0;
}