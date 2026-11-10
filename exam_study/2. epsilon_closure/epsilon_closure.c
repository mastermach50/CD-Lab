#include <stdio.h>
#include <string.h>

#define MAX 10

int num_states;
int epsilon_transitions[MAX][MAX];
int visited[MAX];

void epsilon_closure(int state) {
    // Mark current state as visited and print it since every state appears in
    // its own epsilon closure
    visited[state] = 1;
    printf("q%d ", state);

    // For every state i if it can be reached from the current state and
    // if it hasn't been visited yet then print it
    // Then run epsilon_closure on i
    for (int i = 0; i < num_states; i++) {
        if (epsilon_transitions[state][i] == 1 && !visited[i]) {
            printf("q%d ", i);
            epsilon_closure(i);
        }
    }

}

int main() {
    // Get the number of states
    printf("Enter number of states: ");
    scanf("%d", &num_states);

    // Get the epsilon transitions
    printf("Enter epsilon transition matrix (0/1):\n");
    for (int i = 0; i < num_states; i++)
        for (int j = 0; j < num_states; j++)
            scanf("%d", &epsilon_transitions[i][j]);

    printf("\n");

    // For each state call the epsilon closure function
    for (int i = 0; i < num_states; i++) {

        // Reset visited
        memset(visited, 0, sizeof(visited));

        // Run epsilon closure on each state
        printf("e closure of q%d { ", i);
        epsilon_closure(i);
        printf("}\n");
    }

    return 0;
}
