// Name - Priyanshu Mallick, Roll No - 13
// Write a menu driven program with functions for transpose and inverse of a matrix and
// addition, subtraction, and multiplication of two matrices.
#include <stdio.h>

float determinant(float[][10], float);
void cofactor(float[10][10], float);
void transpos(float[10][10], float[10][10], float);

void transpose();
void inverse();
void addition();
void substact();
void multiply();
int main()
{
    printf("Enter corresponding number from following menu for your desire function\n");
    printf("1. Transpose of a matrix\n2. Inverse of a matrix\n3. Addition of two matrix\n4. Substraction of two matrix\n5. Multiplication of two matrix\n");
    int m;
    scanf("%d", &m);
    switch (m)
    {
    case 1:
        transpose();
        break;
    case 2:
        inverse();
        break;
    case 3:
        addition();
        break;
    case 4:
        substact();
        break;
    case 5:
        multiply();
        break;

    default:
        printf("Invalid Input!\n");
        break;
    }
    return 0;
}
void transpose()
{
    int arr[20][20], tr[20][20], i, j, m, n;
    printf("\nEnter the Number of Rows and Coloumns : \n");
    scanf("%d%d", &m, &n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &arr[i][j]);
            tr[j][i] = arr[i][j];
        }
    }
    printf("The transpose of entered matrix is: \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", tr[i][j]);
        }
    }
}
void inverse()
{
    float a[10][10], k, d;
    int i, j;
    printf("Enter the order of the Matrix : ");
    scanf("%f", &k);
    printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    d = determinant(a, k);
    if (d == 0)
        printf("\nInverse of Entered Matrix is not possible\n");
    else
        cofactor(a, k);
}
void addition()
{
    int nr1, nr2, nc1, nc2, i, j, first[10][10], second[10][10], sum[10][10];

    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d%d", &nr1, &nc1);
    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d%d", &nr2, &nc2);

    if (nr1 != nr2 || nc1 != nc2)
    {
        printf("The Matrix addition is not possible !\nEnter valid input!!\n");
    }
    else
    {
        printf("Enter the elements of first matrix\n");
        for (i = 0; i < nr1; i++)
        {
            for (j = 0; j < nc1; j++)
            {
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &first[i][j]);
            }
        }
        printf("Enter the elements of second matrix\n");
        for (i = 0; i < nr2; i++)
        {
            for (j = 0; j < nc2; j++)
            {
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &second[i][j]);
            }
        }
        printf("Sum of entered matrices:-\n");

        for (i = 0; i < nr1; i++)
        {
            for (j = 0; j < nc1; j++)
            {
                sum[i][j] = first[i][j] + second[i][j];
                printf("%d\t", sum[i][j]);
            }
            printf("\n");
        }
    }
}
void substact()
{
    int nr1, nr2, nc1, nc2, i, j, first[10][10], second[10][10], sum[10][10];

    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d%d", &nr1, &nc1);
    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d%d", &nr2, &nc2);

    if (nr1 != nr2 || nc1 != nc2)
    {
        printf("The Matrix addition is not possible !\nEnter valid input!!\n");
    }
    else
    {
        printf("Enter the elements of first matrix\n");
        for (i = 0; i < nr1; i++)
        {
            for (j = 0; j < nc1; j++)
            {
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &first[i][j]);
            }
        }
        printf("Enter the elements of second matrix\n");
        for (i = 0; i < nr2; i++)
        {
            for (j = 0; j < nc2; j++)
            {
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &second[i][j]);
            }
        }
        printf("Sum of entered matrices:-\n");

        for (i = 0; i < nr1; i++)
        {
            for (j = 0; j < nc1; j++)
            {
                sum[i][j] = first[i][j] - second[i][j];
                printf("%d\t", sum[i][j]);
            }
            printf("\n");
        }
    }
}
void multiply()
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
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &first[i][j]);
            }
        }
        printf("Enter the elements of second matrix\n");
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                printf("element - [%d],[%d] : ", i, j);
                scanf("%d", &second[i][j]);
            }
        }

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
}
float determinant(float a[10][10], float k)
{
    float s = 1, det = 0, b[10][10];
    int i, j, m, n, c;
    if (k == 1)
    {
        return (a[0][0]);
    }
    else
    {
        det = 0;
        for (c = 0; c < k; c++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    b[i][j] = 0;
                    if (i != 0 && j != c)
                    {
                        b[m][n] = a[i][j];
                        if (n < (k - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * determinant(b, k - 1));
            s = -1 * s;
        }
    }

    return (det);
}

void cofactor(float num[10][10], float f)
{
    float b[25][25], fac[10][10];
    int p, q, m, n, i, j;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
        }
    }
    transpos(num, fac, f);
}
/*Finding transpose of matrix*/
void transpos(float num[10][10], float fac[10][10], float r)
{
    int i, j;
    float b[10][10], inverse[10][10], d;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant(num, r);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            inverse[i][j] = b[i][j] / d;
        }
    }
    printf("\nThe inverse of matrix is : \n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%.2f  ", inverse[i][j]);
        }
        printf("\n");
    }
}