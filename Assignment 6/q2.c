/*
 Program for creating and doing the operations using the single linked list.
 */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct sll
{
    int val;
    struct sll *next;
};
void create(struct sll *);
void display(struct sll *);
struct sll * insrt_frst(struct sll *);
void insrt_lst(struct sll *);
struct sll *  insrt_pos(struct sll *,int);
void insrt_aftr_pos(struct sll *,int);
struct sll * dlt_frst(struct sll *);
void dlt_lst(struct sll *);
struct sll * dlt_pos(struct sll *,int);
void dlt_aftr_pos(struct sll *,int );
int srch(struct sll *,int);
int maxf(struct sll *);
int minf(struct sll *);
void asc_sort(struct sll *);
void desc_sort(struct sll *);
struct sll * revf(struct sll *);
struct sll * merge(struct sll *,struct sll *);
void create(struct sll *node)
{
    char ch;
    printf("\nEnter the Value : ");
    scanf("%d",&node->val);
    node->next=NULL;
    printf("\nEnter any character to continue Except 'q' : ");
    scanf(" %c",&ch);
    while(ch!='q')
    {
        node->next=(struct sll *)malloc(sizeof(struct sll));
        if(node==NULL)
        {
            printf("\nMEMORY NOT ALLOCATED !\n ");
            exit(0);
        }
        node=node->next;
        printf("\nEnter the Value : ");
        scanf("%d",&node->val);
        node->next=NULL;
        printf("\nEnter any character to continue Except 'q' : ");
        scanf(" %c",&ch);
    }
}
void display(struct sll *node)
{
    printf("\nLinked List Elements are : ");
    while(node!=NULL)
    {
        printf("%d ",node->val);
        node=node->next;
    }
    printf("\n");
}
struct sll * insrt_frst(struct sll *node)
{
    struct sll *start;
    start=(struct sll *)malloc(sizeof(struct sll));
    if(start==NULL)
    {
        printf("\nMemory Not Allocated !");
        exit(0);
    }
    printf("\nEnter the Value : ");
    scanf("%d",&start->val);
    start->next=node;
    return start;
}
void insrt_lst(struct sll *node)
{
    struct sll *new;
    new=(struct sll *)malloc(sizeof(struct sll));
    while(node->next!=NULL)
        node=node->next;
    new->next=NULL;
    printf("\nEnter the Value : ");
    scanf("%d",&new->val);
    node->next=new;
}
struct sll * insrt_pos(struct sll *node,int n)
{
    struct sll *new,*temp;
    temp=node;
    int i,sz;
    for(sz=1; temp->next!=NULL; sz++)
        temp=temp->next;
    temp=node;
    if(n>1 && n<=sz)
    {
        for(i=1; i<n-1; i++)
            node=node->next;
        new=(struct sll *)malloc(sizeof(struct sll));
        if(new==NULL)
        {
            printf("\nMemory not allocated Properly !\n");
            exit(0);
        }
        printf("\nEnter the Value : ");
        scanf("%d",&new->val);
        (new->next)=(node->next);
        node->next=new;
    }
    else if(n==sz+1)
        insrt_lst(node);
    else if(n==1)
        temp=insrt_frst(node);
    else
        printf("\nINVALID POSITION !\n");
    return temp;
}
void insrt_aftr_pos(struct sll *node,int key)
{
    struct sll *new,*temp;
    temp=node;
    int i,sz,n;
    n=srch(node,key);
    n++;
    for(sz=1; temp->next!=NULL; sz++)
        temp=temp->next;
    if(n>1 && n<=sz)
    {
        for(i=1; i<n-1; i++)
            node=node->next;
        new=(struct sll *)malloc(sizeof(struct sll));
        if(new==NULL)
        {
            printf("\nMemory not allocated Properly !\n");
            exit(0);
        }
        printf("\nEnter the Value : ");
        scanf("%d",&new->val);
        (new->next)=(node->next);
        node->next=new;
    }
    else if(n==sz+1)
        insrt_lst(node);
    else
        printf("\nNode Not Found !\n");
}
struct sll * dlt_frst(struct sll *node)
{
    struct sll *tmp;
    tmp=node;
    node=node->next;
    free(tmp);
    return node;
}
void dlt_lst(struct sll *node)
{
    struct sll *prev;
    if(node->next==NULL)
    {
        free(node);
        node=NULL;
    }
    while(node->next!=NULL)
    {
        prev=node;
        node=node->next;
    }
    free(node);
    node=prev;
    node->next=NULL;
}
struct sll * dlt_pos(struct sll *node,int n)
{
    int sz;
    struct sll *temp,*prev;
    temp=node;
    for(sz=1; temp->next!=NULL; sz++)
        temp=temp->next;
    temp=node;
    if(n==1)
        temp=dlt_frst(node);
    else if(n==sz)
        dlt_lst(node);
    else if(n>1 && n<sz)
    {
        int i;
        for(i=1; i<n; i++)
        {
            prev=node;
            node=node->next;
        }
        (prev->next)=(node->next);
        free(node);
    }
    return temp;
}
void dlt_aftr_pos(struct sll *node,int key)
{
    struct sll *temp;
    int n,sz;
    temp=node;
    for(sz=1; temp->next!=NULL; sz++)
        temp=temp->next;
    n=srch(node,key);
    n++;
    if(n==sz)
        dlt_lst(node);
    else if(n>1 && n<sz)
    {
        int i;
        for(i=1; i<n; i++)
        {
            temp=node;
            node=node->next;
        }
        (temp->next)=(node->next);
        free(node);
    }
    else if(n==sz+1)
        printf("\nNo element is present !\n");
    else
        printf("\nNode is Absent !\n");

}
int srch(struct sll *node,int key)
{
    int i;
    for(i=1; node!=NULL; i++)
    {
        if((node->val)==key)
            return i;
        node=node->next;
    }
    return 0;
}
int maxf(struct sll *node)
{
    int max;
    max=node->val;
    while(node!=NULL)
    {
        if((node->val)>max)
            max=node->val;
        node=node->next;
    }
    return max;
}
int minf(struct sll *node)
{
    int min;
    min=node->val;
    while(node!=NULL)
    {
        if((node->val)<min)
            min=node->val;
        node=node->next;
    }
    return min;
}
void asc_sort(struct sll * node)
{
    struct sll *i,*j;
    int temp;
    for(i=node; i!=NULL; i=i->next)
    {
        for(j=i; j!=NULL; j=j->next)
        {
            if(j->val<i->val)
            {
                temp=i->val;
                i->val=j->val;
                j->val=temp;
            }
        }
    }
}
void desc_sort(struct sll *node)
{
    struct sll *i,*j;
    int temp;
    for(i=node; i!=NULL; i=i->next)
    {
        for(j=i; j!=NULL; j=j->next)
        {
            if(j->val>i->val)
            {
                temp=i->val;
                i->val=j->val;
                j->val=temp;
            }
        }
    }
}
struct sll * revf(struct sll *node)
{
    struct sll *cur,*prev,*ptr;//In list first element = cur , 2nd = prev , 3rd = ptr
    if(node->next!=NULL)
    {
        cur=node;
        prev=cur->next;
        while(prev->next!=NULL)
        {
            ptr=prev->next;
            prev->next=cur;
            cur=prev;
            prev=ptr;
        }
        prev->next=cur;
        node->next=NULL;
        node=prev;
        return node;
    }
    return node;
}
struct sll * merge(struct sll *node,struct sll *node2)
{
    struct sll *node3,*tmp,*start;
    node3=(struct sll *)malloc(sizeof(struct sll));
    start=node3;
    if(node3==NULL)
    {
        printf("\nMemory not allocated !\n");
        exit(0);
    }
    node3->val=node->val;
    node3->next=NULL;
    if(node->next==NULL)
    {
        tmp=(struct sll *)malloc(sizeof(struct sll));
        if(tmp==NULL)
        {
            printf("\nMemory not allocated !\n");
            exit(0);
        }
        node3->next=tmp;
        node3=tmp;
    }
    while(node->next!=NULL)
    {
        node=node->next;
        tmp=(struct sll *)malloc(sizeof(struct sll));
        if(tmp==NULL)
        {
            printf("\nMemory not allocated !\n");
            exit(0);
        }
        node3->next=tmp;
        tmp->val=node->val;
        tmp->next=NULL;
        node3=tmp;
    }
    node3->val=node2->val;
    node3->next=NULL;
    while(node2->next!=NULL)
    {
        node2=node2->next;
        tmp=(struct sll *)malloc(sizeof(struct sll));
        if(tmp==NULL)
        {
            printf("\nMemory not allocated !\n");
            exit(0);
        }
        node3->next=tmp;
        tmp->val=node2->val;
        tmp->next=NULL;
        node3=tmp;
    }
    return start;
}
int main()
{
    system("clear");
    struct  sll *node,*start,*node2;
    int ch,pos,key;
    node=(struct sll *)malloc(sizeof(struct sll));
    start=node;
    if(node==NULL)
    {
        printf("\nMemopry not allocated !\n");
        exit(0); 
    }
    printf("\n 0: Exit !");
    printf("\n 1: Create a Single Linked List .");
    printf("\n 2: Display The Elements .");
    printf("\n 3: Insert a new node At Begining .");
    printf("\n 4: Insert a new node At the End .");
    printf("\n 5: Insert a new node At Given Position .");
    printf("\n 6: Insert a new node After a given Node .");
    printf("\n 7: Delete the first node .");
    printf("\n 8: Delete the Last Node .");
    printf("\n 9: Delete the node at a given position .");
    printf("\n10: Delete the node after the given Node .");
    printf("\n11: Search an Element .");
    printf("\n12: Find Maximum .");
    printf("\n13: Find Minimum .");
    printf("\n14: Sort in ascending order .");
    printf("\n15: Sort in descending Order .");
    printf("\n16: Reverse the list .");
    printf("\n17: Merge Two Lists .\n");
    while(1)
    {
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            create(node);
            break;
        case 2:
            display(node);
            break;
        case 3:
            node=insrt_frst(node);
            start=node;
            break;
        case 4:
            insrt_lst(node);
            break;
        case 5:
            printf("\nEnter the Position : ");
            scanf("%d",&pos);
            node=insrt_pos(node,pos);
            start=node;
            break;
        case 6:
            printf("\nEnter the Node Value : ");
            scanf("%d",&key);
            insrt_aftr_pos(node,key);
            break;
        case 7:
            node=dlt_frst(node);
            start=node;
            break;
        case 8:
            dlt_lst(node);
            break;
        case 9:
            printf("\nEnter the position : ");
            scanf("%d",&pos);
            node=dlt_pos(node,pos);
            start=node;
            break;
        case 10:
            printf("\nEnter the Node value : ");
            scanf("%d",&key);
            dlt_aftr_pos(node,key);
            break;
        case 11:
            printf("\nEnter the Value :");
            scanf("%d",&key);
            pos=srch(node,key);
            if(pos)
                printf("\nKey found at Position : %d\n",pos);
            else
                printf("\nKey Not Found !");
            break;
        case 12:
            key=maxf(node);
            printf("\nMaximum Element = %d\n",key);
            break;
        case 13:
            key=minf(node);
            printf("\nMinimum Element = %d\n",key);
            break;
        case 14:
            asc_sort(node);
            break;
        case 15:
            desc_sort(node);
            break;
        case 16:
            node=revf(node);
            break;
        case 17:
            node2=(struct sll *)malloc(sizeof(struct sll));
            if(node2==NULL)
            {
                printf("\nMemory Not allocted !\n");
                exit(0);
            }
            asc_sort(node);
            printf("\nFor Merging create a new list ! \n");
            create(node2);
            asc_sort(node2);
            node=merge(node,node2);
            break;
        default:
            printf("\nINVALID CHOICE !\n");
        }
    }
}
