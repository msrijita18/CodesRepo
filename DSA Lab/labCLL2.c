#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *next;
} *Head=NULL;

void create(int item)
{
    struct Node *last,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->data=item;
    tmp->next=NULL;
    if (Head==NULL)
    {
        Head=tmp;
    }
    else
    {
    last=Head;
    while(last->next!=NULL)
        last=last->next;
        last->next=tmp;
    }
}

void Display()
{
    struct Node *h;
    h=Head;
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }
    while(h!=Head);
    printf("\n");
}
    

int Length(struct Node *p)
{
    int len=0;
    do
    {
    len++;
    p=p->next;
    }while(p!=Head);
    return len;
}


void Insert()
{
    struct Node *p, *t;
    int index, x, i;
    printf("Enter index: ");
    scanf("%d", &index);
    printf("Enter element to insert: ");
    scanf("%d", &x);

    if(index<1 || index > Length(p))
    return;
    else if (index==1)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while(p->next!=Head)
            p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}


int Delete()
{
    struct Node *p, *q;
    int index;
    printf("Enter index: ");
    scanf("%d", &index);
    int i,x;

    if(index <0 || index >Length(Head))
        return -1;
    if(index==1)
    {
        while(p->next!=Head)p=p->next;
            x=Head->data;
        if(Head==p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
        p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

void main()
{
    int ch,n,i,data,a,pos;
    do
    {
        printf("\nMenu driven program for Linked list:\n");
        printf("1.Create\n");
        printf("2.Display:\n");
        printf("3.Insert an element:\n");
        printf("4.Delete element at end:\n");

        printf("For EXIT press 0 \n");

        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("HOW MANY NODES U WANT TO CREATE\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("ENTER DATA FOR NODE %d\n", i+1);
                        scanf("%d",&data);
                        create(data);
                    } 
            break;
            case 2: Display();
            break;
            case 3: Insert();
            break; 
            case 4: Delete();
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}