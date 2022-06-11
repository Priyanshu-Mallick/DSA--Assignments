// Name - Priyanshu Mallick, Roll No - 13
// Q3. WAP in C to sort the elements of an array using Bubble Sort.
 #include <stdio.h>

void bsort(int a[], int);
int main()
{
    int a[10], n, i, j, temp;    
    printf("Enter the number of element in array\n");
    scanf("%d", &n);    

    printf("Enter the Elements\n");
    for(i = 0; i < n; i++)

        scanf("%d", &a[i]);
    
    bsort(a,n);
    
    return 0;
}
void bsort(int a[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {       
        for(j = 0; j < n - 1; j++)
        {          
            if(a[j] > a[j + 1])
            {               
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array after implementing bubble sort: \n");

    for(i = 0; i < n; i++)
    {
          printf("%d, ", a[i]);
    }
}