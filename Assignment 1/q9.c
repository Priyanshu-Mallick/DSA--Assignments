/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q9. WAP in C to read an array, then segregate all the even and odd numbers using function. Copy the 
even and odd integers to two different arrays and show them.
 **/
#include <stdio.h>

void seg(int a[], int);
int main()
{
    int a[20], n, i;
    printf("Enter the number of element in the array\n");
    scanf("%d", &n);
    printf("Enter the elements in array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    seg(a,n);
    return 0;
}
void seg(int a[], int n)
{
    int i, j, k, e[20], o[20];
    for ( j=0,k=0,i = 0; i < n; i++,j++,k++)
    {
        if (a[i]%2==0)
        {
            e[j] = a[i];
        }
        else
        {
            o[k] = a[i];
        }
    }
    printf("Even element array is:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",e[i]);
    }
    printf("\n");
    printf("Odd element array is:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",o[i]);
    }
}