#include <stdio.h>
#include <string.h>

#define MAX 10

int n, m;
int e[MAX][MAX];                 // epsilon transitions
int trans[MAX][MAX][MAX];        // transitions for each symbol
int closure[MAX][MAX];           // epsilon closures
int csize[MAX];

void findClosure(int s)
{
    int stack[MAX], top = -1;
    int visited[MAX] = {0};

    stack[++top] = s;
    visited[s] = 1;

    while (top != -1)
    {
        int u = stack[top--];
        closure[s][csize[s]++] = u;

        for (int v = 0; v < n; v++)
        {
            if (e[u][v] && !visited[v])
            {
                visited[v] = 1;
                stack[++top] = v;
            }
        }
    }
}

int main()
{
    int i, j, k, l;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("\nEnter epsilon transition matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&e[i][j]);

    for(k=0;k<m;k++)
    {
        printf("\nTransition matrix for symbol %d:\n",k);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&trans[k][i][j]);
    }

    /* Find epsilon closures */
    for(i=0;i<n;i++)
    {
        csize[i]=0;
        findClosure(i);
    }

    printf("\nEpsilon Closures:\n");
    for(i=0;i<n;i++)
    {
        printf("E(%d) = { ",i);
        for(j=0;j<csize[i];j++)
            printf("%d ",closure[i][j]);
        printf("}\n");
    }

    printf("\nNFA without epsilon transitions:\n");

    for(k=0;k<m;k++)
    {
        printf("\nFor symbol %d:\n",k);

        for(i=0;i<n;i++)
        {
            printf("State %d -> { ",i);

            int result[MAX]={0};

            for(j=0;j<csize[i];j++)
            {
                int p=closure[i][j];

                for(l=0;l<n;l++)
                {
                    if(trans[k][p][l])
                    {
                        for(int x=0;x<csize[l];x++)
                            result[closure[l][x]]=1;
                    }
                }
            }

            for(j=0;j<n;j++)
                if(result[j])
                    printf("%d ",j);

            printf("}\n");
        }
    }

    return 0;
}
