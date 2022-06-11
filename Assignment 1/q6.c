/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q6. WAP in C to determine the number of elements present within certain range in an array using function.
 **/
#include <stdio.h>

void dis(int a[], int, int, int);
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
    printf("Enter the range that is value of x and y\n");
    scanf("%d%d",&r1,&r2);

    dis(a,n,r1,r2);
    return 0;
}
void dis(int a[], int n, int r1, int r2)
{
    int i, p, q;
    for ( i = 0; i < n; i++)
    {
        if (a[i]==r1)
        {
            p=i;
            break;            
        }
    }
    for ( i = 0; i < n; i++)
    {
       if(a[i]==r2)
        {
            q=i;
            break;
        }
    }
    printf("The element between given range is\n");
    for ( i = p+1; i < q; i++)
    {
        printf("%d, ",a[i]);
    }
    
}