// Name - Priyanshu Mallick, Roll No - 13
// Q1. WAP in C to find an element in an array using Binary Search technique. 
#include <stdio.h>

void search(int a[], int, int);
int main()
{
    int a[100], i, n, key;
    printf("Enter size of the array : \n");
    scanf("%d", &n);
    
    printf("Enter Elements in array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element that to search! : \n");
    scanf("%d", &key);
    
    search(a,n,key);
    return 0;
}
void search(int a[], int n, int key)
{
    int low, high, mid, flag =0;
    low = 0;
    high = n - 1;
    
    while (low <= high)
    {
        // Checking wheather the inputed number is in array or not
        mid = (low + high) / 2;
        if (a[mid] < key)
        {
            low = mid + 1;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            printf("The key is found at index %d\n", mid);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("The element is not found\n");
    }
}