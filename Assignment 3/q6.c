// Name - Priyanshu Mallick, Roll No - 13
// Q4.WAP in C to add two Sparse Matrices (given in triplet form)
// and show the Resultant Sparse Matrix (in triplet form).

#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], nr1, nr2, i, j;
    printf("Enter the number of non zero elements in matrix 1\n");
    scanf("%d", &nr1);

    printf("Enter the elements in array\n");
    for (i = 0; i <=nr1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of non zero elements in matrix 2\n");
    scanf("%d", &nr2);

    printf("Enter the elements in array\n");
    for (i = 0; i <=nr2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    add(a, b);
    return 0;
}
int add(int spm1[20][3], int spm2[20][3])
{
    int spm[20][3], i = 1, j = 1, k = 1;
    while (i <=spm1[0][2] && j <=spm2[0][2])
    {
        if (spm1[i][0] == spm2[j][0] && spm1[i][1] == spm2[j][1])
        {
            spm[k][0] = spm1[i][0];
            spm[k][1] = spm1[j][1];
            spm[k][2] = spm1[i][2] + spm2[j][2];
            i++;
            j++;
            k++;
        }
        else if (spm[i][0] == spm2[j][0])
        {
            if (spm1[i][1] > spm2[j][1])
            {
                spm[k][0] = spm2[j][0];
                spm[k][1] = spm2[j][1];
                spm[k][2] = spm2[j][2];
                k++;
                j++;
            }
            else
            {
                spm[k][0] = spm1[i][0];
                spm[k][1] = spm1[i][1];
                spm[k][2] = spm1[i][2];
                k++;
                i++;
            }
        }
        else
        {
            if (spm1[i][0] > spm2[j][0])
            {
                spm[k][0] = spm2[j][0];
                spm[k][1] = spm2[j][1];
                spm[k][2] = spm2[j][2];
                k++;
                j++;
            }
            else
            {
                spm[k][0] = spm1[i][0];
                spm[k][1] = spm1[i][1];
                spm[k][2] = spm1[i][2];
                k++;
                i++;
            }
        }
    }
    spm[0][0] = spm1[0][0];
    spm[0][1] = spm1[0][1];
    spm[0][2] = k;
    printf("after addition:\n");
    for (i = 0; i <= k; i++)
    {
        printf("%d %d %d ", spm[i][0], spm[i][1], spm[i][2]);
        printf("\n");
    }
}
