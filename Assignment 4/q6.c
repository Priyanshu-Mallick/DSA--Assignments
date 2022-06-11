// Name - Priyanshu Mallick, Roll No - 13
// WAP in C to convert an infix expression to prefix expression using Stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];

int isFull();
int isEmpty();
void push(char item);
int pop();
int peek();
int checkIfOperand(char ch);
int precedence(char ch);
int getPostfix(char* expression);
void reverse(char *exp);
void brackets(char* exp);
void InfixtoPrefix(char *exp);

int main()
{    
    char expression[100];
    printf("Enter the expression\n");
    scanf("%s",expression);

    InfixtoPrefix(expression); 
    
    printf("The prefix is: ");
    printf("%s\n",expression);

    return 0; 
}
// checking if stack is full
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// checking is stack is empty
int isFull()
{
    if (top == 100 - 1)
        return 1;
    else
        return 0;
}

// Push function here, inserts value in stack and increments stack top by 1
void push(char item) {
    if (isFull()) 
        return; 
	top++;
	stack[top] = item;
}

// Function to remove an item from stack.  It decreases top by 1 
int pop() { 
    if (isEmpty()) 
        return 0; 
        
    // decrements top and returns what has been popped      
    return stack[top--]; 
} 

// Function to return the top from stack without removing it 
int peek(){ 
    if (isEmpty()) 
        return 0; 
    return stack[top]; 
} 

// A utility function to check if the given character is operand 
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

// Fucntion to compare precedence
// If we return larger value means higher precedence 
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

// The driver function for infix to postfix conversion 
int getPostfix(char* expression) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output. 
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        // Here, if we scan character ‘(‘, we need push it to the stack. 
        else if (expression[i] == '(') 
            push(expression[i]); 

        // Here, if we scan character is an ‘)’, we need to pop and print from the stack  
        // do this until an ‘(‘ is encountered in the stack. 
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                expression[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1; // invalid expression              
            else
                pop(stack); 
        } 
        else // if an opertor
        { 
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
                expression[++j] = pop(stack); 
            push(expression[i]); 
        } 

    } 

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty(stack)) 
        expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    //change brackets
    brackets(exp);
    //get postfix
    getPostfix(exp);
    // reverse string again
    reverse(exp);
}