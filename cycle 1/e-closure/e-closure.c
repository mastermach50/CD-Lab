#include <stdio.h>

#define MAX 10

int n;
int e[MAX][MAX];
int visited[MAX];

void epsilonClosure(int state)
{
    visited[state] = 1;
    printf("q%d ", state);

    for (int i = 0; i < n; i++)
    {
        if (e[state][i] && !visited[i])
            epsilonClosure(i);
    }
}

int main()
{
    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix (0 or 1):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }

    printf("\nEpsilon Closures:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[j] = 0;

        printf("ε-Closure(q%d) = { ", i);
        epsilonClosure(i);
        printf("}\n");
    }

    return 0;
}

