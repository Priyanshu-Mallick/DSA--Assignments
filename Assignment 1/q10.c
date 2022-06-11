/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q10. WAP in C to store the full marks secured by 5 students using array. Use functions for input, display, 
determining maximum, minimum, class sum and class average. Consider the following prototypes:
 **/
#include <stdio.h>

void input(int [], int);
void display(int [], int);
int class_max(int [], int);
int class_min(int [], int);
int class_sum(int [], int);
int class_avg(int [], int, int);
int main()
{
    int a[20], n, i;
    input(a,n);
    display(a,n);
    int max = class_max(a,n);
    printf("Highest mark is %d",max);
    int min = class_min(a,n);
    printf("Highest mark is %d",max);
    int sum = class_sum(a,n);
    printf("Totall student mark is %d",sum);
    int avg = class_avg(a,n,sum);
    printf("Average student mark is %d", avg);
    return 0;
}
void input(int a[], int n)
{
    int i;
    printf("Enter the number of student\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the mark of student 1:\n");
        scanf("%d", &a[i]);
    }
}
void display(int a[], int n)
{
    int i;
    printf("The array is:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",a[i]);
    }
}

int  class_max(int a[], int n)
{
    int i, max;
    max = a[0];
    for ( i = 0; i < n; i++)
    {
        if (max<a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int  class_min(int a[], int n)
{
    int i, min;
    min = a[0];
    for ( i = 0; i < n; i++)
    {
        if (min>a[i])
        {
            min = a[i];
        }
    }
    return min;
}
int class_sum(int a[], int n)
{
    int i, sum;
    sum = 0;
    for ( i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}
int class_avg(int a[], int n, int s)
{
    float avg;
    avg = s / n;
    return avg;
}