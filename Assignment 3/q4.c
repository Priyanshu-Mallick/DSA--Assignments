// Name - Priyanshu Mallick, Roll No - 13
// Q2.WAP in C to convert a matrix of order m x n into a Sparse 
// Matrix (i.e in Triplet form).
#include<stdio.h>

void trad(int a[][10], int);
int main()
{
    int a[10][10], nr, nc, i, j;
    printf("Enter the number of rows in matrix\n");
    scanf("%d",&nr);
    printf("Enter the elements in array\n");
    for ( i = 0; i < nr; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    trad(a,nr);

    return 0;
}
void trad(int a[][10], int nr)
{
    int i, j,trans[50][50];

    int tmp = 1;
    trans[0][0] = a[0][0];
    trans[0][1] = a[0][1];
    trans[0][2] = a[0][2];
    for (j = 0; j < 3; j++)
    {
        for (i = 1; i < a[0][2] + 1; i++)
        {
            if (a[i][1] == j)
            {
                trans[tmp][0] = j;
                trans[tmp][1] = i;
                trans[tmp][2] = a[i][2];
                tmp++;
            }
        }
    }
    

    printf("\nTransposed matrix is  :\n");
    for ( i = 0; i < nr; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
}