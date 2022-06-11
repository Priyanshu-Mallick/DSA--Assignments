// Name - Priyanshu Mallick, Roll No - 13
// Q2. WAP in C to insert an element in a sorted array using function. 
#include <stdio.h>

void insert(int a[], int, int);
int main()
{
    int a[10], i, n, key;
    printf("Enter the number of element in aeray\n");
    scanf("%d",&n);
    printf("Enter the element in array\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the element that you want to insert\n");
    scanf("%d",&key);

    insert(a,n,key);
    
    return 0;
}
void insert(int a[], int n, int key)
{
    int i,j, pos;
    for ( i = 0; i < n; i++)
    {
        if (a[i]>key )
        {
            for(j=n;j>i;j--)
               a[j]=a[j-1];
            a[i]=key;
            break;
        }
    }
    for(i=0;i<=n;i++)
        printf("%d ",a[i]);
}