// Name - Priyanshu Mallick, Roll No - 13
// Q5. WAP in C to sort the elements of an array using Insertion Sort.
#include <stdio.h>

void isort(int a[], int);
int main()
{
    int a[10], n, i;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    isort(a,n);
    
    return 0;
}
void isort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
    printf("After Sorting the array according to the ascending order\nNow the array become : {");
    for (i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("}");
}