#include <stdio.h>

#define MAX 10

int main()
{
    int n, m;
    int trans[MAX][MAX];
    int final[MAX];
    int mark[MAX][MAX] = {0};
    int group[MAX];

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("Enter transition table:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &trans[i][j]);

    printf("Enter final states (1=Final, 0=Non-final):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &final[i]);

    /* Step 1: Mark final/non-final pairs */
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (final[i] != final[j])
                mark[i][j] = 1;

    /* Step 2: Table filling */
    int changed;
    do
    {
        changed = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (mark[i][j])
                    continue;

                for (int k = 0; k < m; k++)
                {
                    int p = trans[i][k];
                    int q = trans[j][k];

                    if (p == q)
                        continue;

                    int a = (p < q) ? p : q;
                    int b = (p < q) ? q : p;

                    if (mark[a][b])
                    {
                        mark[i][j] = 1;
                        changed = 1;
                        break;
                    }
                }
            }
        }
    } while (changed);

    /* Step 3: Form groups */
    for (int i = 0; i < n; i++)
        group[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (!mark[i][j])
                group[j] = group[i];

    printf("\nMinimized DFA States:\n");
    for (int i = 0; i < n; i++)
    {
        if (group[i] == i)
        {
            printf("{ ");
            for (int j = 0; j < n; j++)
                if (group[j] == i)
                    printf("q%d ", j);
            printf("}\n");
        }
    }

    printf("\nTransition Table:\n");

    for (int i = 0; i < n; i++)
    {
        if (group[i] != i)
            continue;

        printf("{ ");
        for (int j = 0; j < n; j++)
            if (group[j] == i)
                printf("q%d ", j);
        printf("} : ");

        for (int k = 0; k < m; k++)
        {
            int next = trans[i][k];

            while (group[next] != next)
                next = group[next];

            printf("{ ");
            for (int j = 0; j < n; j++)
                if (group[j] == next)
                    printf("q%d ", j);
            printf("} ");
        }
        printf("\n");
    }

    return 0;
}
