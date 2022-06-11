/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q4. WAP in C to compute and display the frequency of a given element in an array using function.
 **/
#include <stdio.h>

void frequency(int a[], int, int);
int main()
{
    int a[20], n, i, key, pos;
    printf("Enter the number of element in the array\n");
    scanf("%d", &n);
    printf("Enter the elements in array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element\n");
    scanf("%d",&key);

    frequency(a, n, key);
    return 0;
}
void frequency(int a[], int n, int key)
{
    int i, c=0;
    for ( i = 0; i < n; i++)
    {
        if(a[i]==key)
        {
            c++;
        }
    }
    printf("The frequency of element in array is: %d\n",c);
}