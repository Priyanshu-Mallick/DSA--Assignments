// Name - Priyanshu Mallick, Roll No - 13
// Q3.WAP in C to convert a Sparse Matrix (in triplet form)
// to its Transpose Matrix (Triplet form)

#include <stdio.h>

void trans(int a[][10], int);
int main()
{
    int a[10][10], i, j, nr;
    printf("Enter the number of rows of the triplet matrix\n");
    scanf("%d", &nr);

    printf("Enter the element in matrix\n");
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    trans(a, nr);
    return 0;
}
void trans(int a[][10], int nr)
{
    int b[50][50];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    int i, j, temp, k=1,te,t;
    int n = a[0][2];
    for ( i = 0; i < a[0][1]; i++)
    {
        for ( j = 1; j < n; j++)
        {
            if (i==a[j][1])
            {
                b[k][0]=i;
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }   
        }
    }
    
    // for (i = 1; i < nr; i++)
    // {
    //     b[i][0] = a[i][1];
    //     b[i][1] = a[i][0];
    //     b[i][2] = a[i][2];
    // }

    // for (i = 1; i < nr; i++)
    // {
    //     for (j = 1; j < nr - i; j++)
    //     {
    //         if (b[j][0] > b[j + 1][0])
    //         {
    //             temp = b[j][0];
    //             b[j][0] = b[j + 1][0];
    //             b[j + 1][0] = temp;

    //             t = b[j][1];
    //             b[j][1] = b[j + 1][1];
    //             b[j + 1][1] = t;

    //             te = b[j][2];
    //             b[j][2] = b[j + 1][2];
    //             b[j + 1][2] = te;
    //         }
    //     }
    // }
    printf("The transposed matrix is: \n");
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}