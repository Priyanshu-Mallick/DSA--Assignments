// Name - Priyanshu Mallick, Roll No - 13
// Q6. WAP in C to merge two sorted arrays into a single sorted array and display it using function.
#include <stdio.h>

void merge(int a[], int, int b[], int);
int main()
{
    int a[10], b[10], n, m, i;

    printf("Enter number of elements in array1\n");
    scanf("%d", &n);

    printf("Enter the elements in array1\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements in array2\n");
    scanf("%d", &m);

    printf("Enter the elements in array2\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    merge(a,n,b,m);

    return 0;
}
void merge(int a[], int n, int b[], int m)
{
    int c[40], i, j, o;
    o = n+m;
    for ( i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for ( j = 0; j < m; j++, i++)
    {
        c[i] = b[j];
    }
    printf("After merging the new array is:\n");
    for ( i = 0; i < o; i++)
    {
        printf("%d, ", c[i]);
    }
}