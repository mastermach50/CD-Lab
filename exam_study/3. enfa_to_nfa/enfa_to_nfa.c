#include <stdio.h>
#include <string.h>

#define MAX 100

int num_states, num_inputs;
int transitions[MAX][MAX][MAX] = {0}; // [start][sym][end] | epsilon = 0 | states 0,1,2,3,... | input 1,2,3,...
int e_closure[MAX][MAX] = {0};
int e_closure_size[MAX] = {0};

int e_closure_caller;
int visited[MAX] = {0};

void find_e_closure(int state) {
    visited[state] = 1;
    e_closure[e_closure_caller][e_closure_size[e_closure_caller]++] = state;
    printf("q%d ", state);

    for (int i = 0; i < num_states; i++) {
        if (transitions[state][0][i] == 1 && !visited[i]) {
            find_e_closure(i);
        }
    }
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &num_states);

    printf("Enter number of input symbols: ");
    scanf("%d", &num_inputs);

    int num_trans;
    printf("Enter number of transitions: ");
    scanf("%d", &num_trans);

    printf("Enter transitions (start_state symbol end_state)[epsilon as 0]:\n");
    for (int i = 0; i < num_trans; i++) {
        int start, sym, end;
        scanf("%d %d %d", &start, &sym, &end);
        transitions[start][sym][end] = 1;
    }

    for (int i = 0; i < num_states; i++) {
        printf("e closure of q%d { ", i);
        memset(visited, 0, sizeof(visited));
        e_closure_caller = i;
        find_e_closure(i);
        printf("}\n");
    }

    printf("New transitions:\n");
    for (int s0 = 0; s0 < num_states; s0++) {
        for (int i = 1; i <= num_inputs; i++) {
            printf("d(q%d, %d) => { ", s0, i);

            int start_states[MAX] = {0};
            for (int cs = 0; cs < e_closure_size[s0]; cs++) {
                start_states[e_closure[s0][cs]] = 1;
            }

            int end_states[MAX] = {0};
            for (int s1 = 0; s1 < num_states; s1++) {
                if (start_states[s1]) {
                    for (int s2 = 0; s2 < num_states; s2++) {
                        if (transitions[s1][i][s2]) {
                            for (int cs = 0; cs < e_closure_size[s2]; cs++) {
                                end_states[e_closure[s2][cs]] = 1;
                            }
                        }
                    }
                }
            }

            for (int k = 0; k < num_states; k++) {
                if (end_states[k]) {
                    printf("q%d ", k);
                }
            }

            printf("}\n");
        }
    }

    return 0;
}
