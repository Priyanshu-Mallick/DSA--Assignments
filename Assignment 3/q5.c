#include <stdio.h>
void triplet(int[30][30], int, int, int);
int main()
{
    int n, m, i, j, sprs[30][30], nzero;
    printf("Enter the no.of rows of sparse matrix :\n");
    scanf("%d", &n);
    printf("Enter the no.of cols of sparse matrix :\n");
    scanf("%d", &m);
    printf("Enter the elements of the sparse matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &sprs[i][j]);
            if (sprs[i][j] != 0)
                nzero++;
        }
    }
    triplet(sprs, nzero, n, m);
}
void triplet(int sprs[][30], int nzero, int n, int m)
{
    int i, j, tmp = 1, tripl[30][3], trans[30][3];
    tripl[0][0] = n;
    tripl[0][1] = m;
    tripl[0][2] = nzero;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (sprs[i][j] != 0)
            {
                tripl[tmp][0] = i;
                tripl[tmp][1] = j;
                tripl[tmp][2] = sprs[i][j];
                tmp++;
            }
        }
    }
    for (i = 0; i < nzero + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", tripl[i][j]);
        }
        printf("\n");
    }
    tmp = 1;
    trans[0][0] = m;
    trans[0][1] = n;
    trans[0][2] = nzero;
    for (j = 0; j < 3; j++)
    {
        for (i = 1; i < nzero + 1; i++)
        {
            if (tripl[i][1] == j)
            {
                trans[tmp][0] = j;
                trans[tmp][1] = i;
                trans[tmp][2] = tripl[i][2];
                tmp++;
            }
        }
    }
    for (i = 0; i < nzero + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", trans[i][j]);
        }
        printf("\n");
    }
}
