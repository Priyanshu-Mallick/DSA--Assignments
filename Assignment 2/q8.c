// Name - Priyanshu Mallick, Roll No - 13
// Q8. WAP in C to multiply two matrices using function.
#include <stdio.h>

void mulmat(int first[10][10], int second[10][10], int, int, int, int);

int main()
{
    int m1, m2, n1, n2, i, j, k, first[10][10], second[10][10], multiply[10][10];

    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d%d", &m1, &n1);
    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d%d", &m2, &n2);

    if (n1 != m2)
    {
        printf("The Matrix multiplication is not possible !\nEnter valid input!!\n");
    }
    else
    {
        printf("Enter the elements of first matrix\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                scanf("%d", &first[i][j]);
            }
        }
        printf("Enter the elements of second matrix\n");
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                scanf("%d", &second[i][j]);
            }
        }
        mulmat(first, second, m1, n1, m2, n2);
    }
    return 0;
}
void mulmat(int first[10][10], int second[10][10], int m1, int n1, int m2, int n2)
{
    int i, j, k, multiply[20][20];
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            multiply[i][j] = 0;
            for (k = 0; k < m2; k++)
            {
                multiply[i][j] = multiply[i][j] + first[i][k] * second[k][j];
            }
        }
    }

    printf("Multiplication of entered matrices:-\n");

    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
            printf("%d\t", multiply[i][j]);

        printf("\n");
    }
}