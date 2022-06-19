// Write a program in C to implement Stack and its various operations using linked list.
//  The various operations with the stack are:
//  a)Create a stack
//  b)Check whether it is empty or not?
//  c)Check whetherit is full or not?
//  d)Insert operation (PUSH operation) with the stack.
//  e)Delete operation (POP operation) with the stack.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void create();
// void isFull();
void isEmpty();
void push(int value);
int pop();
void display();

int main()
{
    int ch, value;
    printf("\nImplementaion of Stack using Linked List\n");
    while (1)
    {
        printf("\t1) Create a stack\n");
        printf("\t2) Check wheather stack is full\n");
        printf("\t3) Check wheather stack is empty\n");
        printf("\t4) Insert operation in stack\n");
        printf("\t5) Delete operation in stack\n");
        printf("\t6) Display the stack\n");
        printf("\t7) Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            // isFull();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 5:
            printf("Popped element is :%d\n", pop());
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}

void create()
{
    int val, c, size;
    char ch;
    // printf("Enter the size of stack you want\n");
    // scanf("%d",&size);
    printf("Enter the value to be inserted\n");
    scanf("%d", &val);
    push(val);
    printf("Enter anykey to continue or q to exit\n");
    scanf(" %c", &ch);
    while (ch != 'q')
    {
        printf("Enter the value to be inserted\n");
        scanf("%d", &val);
        push(val);
        printf("Enter anykey to continue or q to exit\n");
        scanf(" %c", &ch);
    }
}
// void isFull()
// {
//     if (!node)
//     {
//         printf("Stack is full\n");
//         exit(-1);
//     }
// }
void isEmpty()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}
void push(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("node is Inserted\n\n");
}

int pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("The stack is \n");
        struct node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}