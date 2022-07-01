/**
 * Add two polynomials
 * Using Linked List
 * @author Swashata
 * @for Dearest Froggie
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * The structure for the polynomial
 * This is a linked list with two variable
 * int coeff The Coefficient
 * int pow The power of x
 */
typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} poly;

/** The prototypes */
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
    int flag; // A flag to control the menu
    int coeff, pow;
    poly *tmp_node;                             // To hold the temporary last address
    tmp_node = (poly *)malloc(sizeof(poly)); // create the first node
    *node = tmp_node;                              // Store the head address to the reference variable
    do
    {
        // Get the user data
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;
        // Done storing user data

        // Now increase the Linked on user condition
        tmp_node->next = NULL;

        // Ask user for continuation
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        // printf("\nFLAG: %c\n", flag);
        // Grow the linked list on condition
        if (flag)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly)); // Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}

/**
 * The show polynomial function
 * Prints the Polynomial in user readable format
 * @param poly * node The polynomial linked list
 * @return void
 */
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

/**
 * The polynomial add function
 * Adds two polynomial to a given variable
 * @param poly ** result Stores the result
 * @param poly * poly1 The first polynomial expression
 * @param poly * poly2 The second polynomial expression
 * @return void
 */
void addpoly(poly **result, poly *poly1, poly *poly2)
{
    poly *tmp_node; // Temporary storage for the linked list
    tmp_node = (poly *)malloc(sizeof(poly));
    tmp_node->next = NULL;
    *result = tmp_node; // Copy the head address to the result linked list

    // Loop while both of the linked lists have value
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

        // Grow the linked list on condition
        if (poly1 && poly2)
        {
            tmp_node->next = (poly *)malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }

    // Loop while either of the linked lists has value
    while (poly1 || poly2)
    {
        // We have to create the list at beginning
        // As the last while loop will not create any unnecessary node
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