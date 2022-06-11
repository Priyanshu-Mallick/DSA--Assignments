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
    int i, j, r, c, b[50][50];

    for ( i = 0; i < nr; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            b[i][j] = 0;
        }
    }
    r = a[0][0];
    c = a[0][1];
    int m, n;
    for ( i = 1; i<nr; i++)
    {
        m = a[i][0];
        n = a[i][1];
        b[m][n]=a[i][2];
    }
    

    printf("\nTraditional Matrix :\n");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}