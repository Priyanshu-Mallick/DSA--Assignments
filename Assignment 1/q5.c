/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q5. WAP in C to increase each element to its five times in an array using function.
 **/
#include <stdio.h>

void mul(int a[], int);
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
    mul(a,n);
    return 0;
}
void mul(int a[], int n)
{
    int i;
    printf("After modification array is\n");
    for ( i = 0; i < n; i++)
    {
        a[i]=a[i]*5;
        printf("%d, ",a[i]);   
    }
}