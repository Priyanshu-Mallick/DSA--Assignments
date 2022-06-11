/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q1. WAP in C to search the presence of an element within an array using function.
**/
#include <stdio.h>

void search(int a[], int, int);
int main()
{
    int a[20], n, i, key;
    printf("Enter the number of element in the array\n");
    scanf("%d",&n);
    printf("Enter the elements in array\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key that you want to search\n");
    scanf("%d",&key);

    search(a,n,key);
    return 0;
}
void search(int a[], int n, int key)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (a[i]==key)
        {
            printf("Element found at %d index\n",i);
            break;            
        }
    }
    if(i==n)
    {
        printf("Element is not found\n");
    }
}