// Addition of polynomial using linked list

#include <stdio.h>
#include <stdlib.h>


typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} poly;


void createpoly(poly **);
void showpoly(poly *);
void addpoly(poly **, poly *, poly *);


int main(void)
{
    int ch;
    do
    {
        poly *poly1, *poly2, *poly3;

        printf("\nCreate 1st expression\n");
        createpoly(&poly1);
        printf("\nStored the 1st expression");
        showpoly(poly1);

        printf("\nCreate 2nd expression\n");
        createpoly(&poly2);
        printf("\nStored the 2nd expression");
        showpoly(poly2);

        addpoly(&poly3, poly1, poly2);
        showpoly(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}


void createpoly(poly **node)
{
    int flag; 
    int coeff, pow;
    poly *tmp_node;                             
    tmp_node = (poly *)malloc(sizeof(poly));
    *node = tmp_node;                            
    do
    {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;

        tmp_node->next = NULL;

        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        if (flag)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly)); 
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}

void showpoly(poly *node)
{
    printf("\nThe polynomial expression is:\n");
    while (node != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL)
            printf(" + ");
    }
}


void addpoly(poly **result, poly *poly1, poly *poly2)
{
    poly *tmp_node; 
    tmp_node = (poly *)malloc(sizeof(poly));
    tmp_node->next = NULL;
    *result = tmp_node;

    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow)
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (poly1 && poly2)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }

    while (poly1 || poly2)
    {
        tmp_node->next = (poly *)malloc(sizeof(poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;

        if (poly1)
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2)
        {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nAddition Complete");
}