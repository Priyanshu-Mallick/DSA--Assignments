/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q2. WAP in C to insert an element at ith position in an array using function.
 **/
#include <stdio.h>

void insert(int a[], int, int, int);
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
    printf("Enter the element that you want to insert\n");
    scanf("%d", &key);
    printf("Enter the position where you want to insert\n");
    scanf("%d", &pos);

    insert(a, n, key, pos);
    return 0;
}
void insert(int a[], int n, int key, int pos)
{
    int i = n-1;
    while (pos<i)
    {
        a[i+1] = a[i];
        i--;
    }
    a[pos] = key;
    
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",a[i]);
    }
    
}