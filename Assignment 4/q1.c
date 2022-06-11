// Name - Priyanshu Mallick, Roll no - 13
// WAP in C to implement Stack using array and perform its various operations.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int stk[SIZE];
int top = -1;
void push(int[], int);
int pop(int[]);
int IsFull(int[]);
int IsEmpty(int[]);
void display(int[]);

int main()
{
    int i, ch, ele;
    while (1)
    {
        printf("\n1: Push operation\n");
        printf("2: Pop operation\n");
        printf("3: IsFull() verification\n");
        printf("4: IsEmpty() verification\n");
        printf("5: Display Stack\n");
        printf("6: Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed:\n");
            scanf("%d", &ele);
            push(stk, ele);
            display(stk);
            break;
        case 2:
            pop(stk);
            display(stk);
            break;
        case 3:
            IsFull(stk);
            break;
        case 4:
            IsEmpty(stk);
            break; 
        case 5:
            display(stk);
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}
void push(int a[], int x)
{
    if (IsFull(a))
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    else
    {
        top++;
        a[top] = x;
    }
}
int pop(int a[])
{
    int y;
    if (IsEmpty(a))
    {
        printf("No element left\n");
        exit(0);
    }
    else
    {
        y = a[top];
        top--;
        return 0;
    }
}
int IsFull(int a[])
{
    if (top == (SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(int a[])
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(int a[])
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
}