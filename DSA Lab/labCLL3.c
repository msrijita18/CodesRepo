#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
};
 
struct node *head = NULL, *x, *y, *z;
 
void create();
void traverse();
void ins_at_pos();
void del_at_pos();
void rev_traverse(struct node *p);
 
void main()
{
    int ch;
 
    printf("\n 1.Creation \n 2.traverse ");
    printf("\n3.insert \n4.Deletion");
    printf("\n5.Rev_traverse\n0.Exit\n");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            create(); 
            break;
        case 2:
            traverse(); 
            break;
        case 3:
            ins_at_pos(); 
            break;
        case 4:
            del_at_pos();
            break;
        case 5:
            rev_traverse(head); 
            break;
        default:
            exit(0);
        }
    }
}
 
/*Function to create a new circular linked list*/
void create()
{
    int c;
 
    x = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("\n If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &y->data);
        x->link = y;
        y->link = head;
        x = y;
        printf("\n If you wish to continue press 1 otherwise 0:");
        scanf("%d", &c); 
    }
}
 
/*Function to insert an element at any position the list*/
 
void ins_at_beg()
{
    x = head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    while (x->link != head)
    {
        x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
}

void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;
 
    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    if (pos==1)
    {
        ins_at_beg();
        return;
    }
    else 
    {
        x = head;
        ptr = head;
        while (ptr->link != head)
        {
            count++;
            ptr = ptr->link;
        }
        count++;
        if (pos > count)
        {
            printf("OUT OF BOUND");
            return;
        }
        while (c < pos)
        {
            z = x;
            x = x->link;
            c++;
        }
        y->link = x;
        z->link = y;
    }
}
 
/*Function to delete an element at any position the list*/
 
void del_at_beg()
{
    if (head == NULL) 
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->link !=  head)
        {
            x = x->link;
        }
        head = y->link;
        x->link = head;
        free(y);
    }
}

void del_at_pos()
{
    if (head == NULL)
        printf("\n List is empty");
    
    else
    {
        int c = 1, pos;
        printf("\n Enter the position to be deleted:");
        scanf("%d", &pos);
        if (pos==1)
        {
            del_at_beg();
            return;
        } 
        else
        {
            x = head;
            while (c < pos)
            {
                y = x;
                x = x->link;
                c++;
            }
            y->link = x->link;
            free(x);
        }
    }
}
 
/*Function to display the elements in the list*/
 
void traverse()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        while (x->link !=  head)
        { 
            printf(" %d", x->data);
            x = x->link;
        }
        printf(" %d", x->data);
    }
}
 

 
void rev_traverse(struct node *p)
{
    int i = 0;
 
    if (head == NULL)
    {
        printf("empty linked list");
    }
    else
    {
        if (p->link !=  head)
        {
            i = p->data;
            rev_traverse(p->link);
            printf(" %d", i);
        }
        if (p->link == head)
        {
            printf(" %d", p->data);
        }
    }
}
/*
$ cc circular_singly_ll.c
$ a.out
1.Creation
2.Insertion at beginning
3.Insertion at remaining
4.Deletion at beginning
5.Deletion at remaining
6.traverse
7.Search
8.sort
9.update
10.Exit
Enter your choice:6
List is empty
Enter your choice:5
List is empty
Enter your choice:9
empty list
Enter your choice:7
enter the element to search
12
List is empty nothing to search
Enter your choice:1
Enter the data:10
If you wish to continue press 1 otherwise 0:0
Enter your choice:3
Enter the data:20
Enter the position to be inserted:5
OUT OF BOUND
Enter your choice:2
Enter the data:12
Enter your choice:6
12->10
Enter your choice:3
Enter the data:13
Enter the position to be inserted:3
Enter your choice:3
Enter the data:14
Enter the position to be inserted:4
Enter your choice:6
12->10->13->14
Enter your choice:3
Enter the data:24
Enter the position to be inserted:4
Enter your choice:6
12->10->13->24->14
Enter your choice:3
Enter the data:10
Enter the position to be inserted:100
OUT OF BOUND
Enter your choice:4
Enter your choice:6
10->13->24->14
Enter your choice:5
Enter the position to be deleted:4
Enter your choice:6
10->13->24
Enter your choice:5
Enter the position to be deleted:2
Enter your choice:6
10->24
Enter your choice:9
enter the value to be edited
23
enter the value to be replace
24
update not successful
Enter your choice:9
enter the value to be edited
24
enter the value to be replace
26
UPdate sucessful
Enter your choice:6
10->26
Enter your choice:7
enter the element to search
26
element found at postion 1
element not found
Enter your choice:7
enter the element to search
27
element not found
Enter your choice:8
Enter your choice:6
10->26
Enter your choice:10
26 10
Enter your choice:11
*/