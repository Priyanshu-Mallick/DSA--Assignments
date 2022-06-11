// Name - Priyanshu Mallick, Roll No - 13
// Q4. WAP in C to sort the elements of an array using Selection Sort.
 #include <stdio.h>

void ssort(int a[], int);
int main()
{
    int a[10], n, i;   
    printf("Enter the number of element in array\n");
    scanf("%d", &n);    

    printf("Enter the Elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    ssort(a,n);
    
    return 0;
}
void ssort(int a[], int n)
{
    int i, j, temp, min;
    j = 0;
    while (j < n - 1)
    {
        min = j;
        i = j + 1;
        while (i < n)
        {
            if (a[i] < a[min])
            {
                min = i;
            }
            i++;
        }
        if (min != j)
        {
            temp = a[j];
            a[j] = a[min];
            a[min] = temp;
        }
        j++;
    }
    printf("After Sorting the array according to the ascending order\nNow the array become : {");
    for (i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("}");
}