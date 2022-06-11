/**
 * Name - Priyanshu Mallick, Roll No - 13
 * Q7. WAP in C to left-rotate the elements of an array and display them using function
 **/
#include <stdio.h>

void rotate(int a[], int, int);
int main()    
{     
    int a[20], length, n, i, r1, r2;
    printf("Enter the number of element in the array\n");
    scanf("%d", &length);
    printf("Enter the elements in array\n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number of times array rotate\n");
    scanf("%d",&n);    
         
    printf("Original array: \n");    
    for (int i = 0; i < length; i++) {     
        printf("%d ", a[i]);     
    }      

    rotate(a,length,n);   
    return 0;    
}
void rotate(int a[], int length, int n)
{
    //Rotate the given array by n times toward left  
    for(int i = 0; i < n; i++){    
        int j, first;    
        //Stores the first element of the array    
        first = a[0];    
        
        for(j = 0; j < length-1; j++){    
            //Shift element of array by one    
            a[j] = a[j+1];    
        }    
        //First element of array will be added to the end    
        a[j] = first;    
    }     
    
    printf("\nArray after left rotation: \n");    
    for(int i = 0; i < length; i++){    
        printf("%d ", a[i]);    
    }    
}