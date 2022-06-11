// Name - Priyanshu Mallick, Roll No - 13
// WAP in C to check whether a given segment
// of code has both opening and closing brackets or not? i.e. check for balanced parentheses.

#include <stdio.h>
#include <stdlib.h>
char st[20];
int top = -1;
void psh(char);
char pop();
int main()
{
    char a[20], t;
    int i, f = 1;
    printf("Entrer the expression\n");
    scanf("%s", a);
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            psh(a[i]);
        if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            if (top == -1)
                f = 0;
            else
            {
                t = pop();
                if (a[i] == ')' && (t == '[' || t == '{'))
                    f = 0;
                if (a[i] == '}' && (t == '(' || t == '['))
                    f = 0;
                if (a[i] == ']' && (t == '{' || t == '('))
                    f = 0;
            }
        }
    }
    if (top >= 0)
        f = 0;
    if (f == 0)
        printf("Unbalanced\n");
    else
        printf("Balanced\n");
    return 0;
}
void psh(char a)
{
    st[++top] = a;
}
char pop()
{
    return st[top--];
}
