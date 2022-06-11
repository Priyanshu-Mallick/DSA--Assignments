// Name - Priyanshu Mallick, Roll No - 13
// Q1.WAP in C to convert a matrix of order m x n into a Sparse 
// Matrix (i.e in Triplet form).
#include<stdio.h>

void contrip(int a[][10], int, int);
int main()
{
    int a[10][10], nr, nc, i, j;
    printf("Enter the number of rows in matrix\n");
    scanf("%d",&nr);
    printf("Enter the number of coloumns in matrix\n");
    scanf("%d",&nc);
    printf("Enter the elements in array\n");
    for ( i = 0; i < nr; i++)
    {
        for ( j = 0; j < nc; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    contrip(a,nr,nc);

    return 0;
}
void contrip(int a[][10], int nr, int nc)
{
    int b[10][10], i, j, non=0;
    for ( i = 0; i < nr; i++)
    {
        
        for ( j = 0; j < nc; j++)
        {
            if (a[i][j]!=0)
            {
                non++;
            }
        }
    }

    b[0][0] = nr;
    b[0][1] = nc;
    b[0][2] = non;
    int k = 1;
    for ( i = 0; i < nr; i++)
    {
        for ( j = 0; j < nc; j++)
        {
            if (a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("\nSparse Matrix :\n");
    for ( i = 0; i < non+1; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}