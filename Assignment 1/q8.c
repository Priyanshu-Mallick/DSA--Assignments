/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q8. WAP in C to reverse a list of elements in an array using function
 **/
#include <stdio.h>

void rev(int a[], int);
int main()
{
    int a[20], n, i, r1, r2;
    printf("Enter the number of element in the array\n");
    scanf("%d", &n);
    printf("Enter the elements in array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    rev(a,n);
    return 0;
}
void rev(int a[], int n)
{
    int i, j, r[20];
    for ( j=n-1,i = 0; i < n; i++,j--)
    {
        r[j]=a[i];
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",r[i]);
    }   
}