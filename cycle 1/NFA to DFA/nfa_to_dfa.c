#include <stdio.h>
#include <string.h>

#define MAX 10

int n, m;
int trans[MAX][MAX][MAX];
int dfaStates[100][MAX];
int dfaCount = 0;

int equal(int a[], int b[])
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int findState(int state[])
{
    for (int i = 0; i < dfaCount; i++)
        if (equal(state, dfaStates[i]))
            return i;
    return -1;
}

int main()
{
    int i, j, k;

    printf("Enter number of NFA states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("\nEnter transition table:\n");
    printf("(Enter 1 if transition exists, otherwise 0)\n");

    for (k = 0; k < m; k++)
    {
        printf("\nFor symbol %d:\n", k);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &trans[k][i][j]);
    }

    /* Initial DFA state = {0} */
    memset(dfaStates, 0, sizeof(dfaStates));
    dfaStates[0][0] = 1;
    dfaCount = 1;

    printf("\nDFA Transition Table:\n");

    for (i = 0; i < dfaCount; i++)
    {
        printf("\nState { ");
        for (j = 0; j < n; j++)
            if (dfaStates[i][j])
                printf("%d ", j);
        printf("}\n");

        for (k = 0; k < m; k++)
        {
            int newState[MAX] = {0};

            for (j = 0; j < n; j++)
            {
                if (dfaStates[i][j])
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (trans[k][j][l])
                            newState[l] = 1;
                    }
                }
            }

            int pos = findState(newState);

            if (pos == -1)
            {
                memcpy(dfaStates[dfaCount], newState, sizeof(newState));
                pos = dfaCount;
                dfaCount++;
            }

            printf("On symbol %d --> { ", k);
            for (j = 0; j < n; j++)
                if (newState[j])
                    printf("%d ", j);
            printf("}\n");
        }
    }

    return 0;
}
