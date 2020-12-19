#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node *next;
} *head=NULL;

//Functions
void Create(int);
void Display();
void Insert_start();
void Insert_end();
void Insert_loc();
void Insert_element();
void Delete_start();
void Delete_end();
void Delete_loc();
void Count();
int detectLoop();
void reverse();
void search();

//Main function
void main()
{
    int ch,n,i,data,a,pos;

    //Menu driven program:
    do
    {
        printf("\nMenu driven program for Linked list:\n");
        printf("1.Create\n");
        printf("2.Display:\n");
        printf("3.Insert at start\n");
        printf("4.Insert at end\n");
        printf("5.Insert at any location\n");
        printf("6.Insert after a specific element\n");
        printf("7.Delete a node at beginning\n");
        printf("8.Delete a node at end\n");
        printf("9.Delete a node at any position\n");
        printf("10.Count the total no. of nodes\n");
        printf("11.Detect loop\n");
        printf("12.Reverse\n");
        printf("13.Search element\n");
        printf("For EXIT press 0 \n");

        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("HOW MANY NODES U WANT TO CREATE\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("ENTER THE DATA\n");
                        scanf("%d",&data);
                        Create(data);
                    }
            break;
            case 2: Display();
            break;
            case 3: Insert_start();
            break;
            case 4: Insert_end();
            break;
            case 5: Insert_loc();
            break;
            case 6: Insert_element();
            break;
            case 7: Delete_start();
            break;
            case 8: Delete_end();
            break;
            case 9: Delete_loc();
            break;
            case 10: Count();
            break;
            case 11: detectLoop();
            break; 
            case 12: reverse();
            break; 
            case 13: search();
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }
    } while(ch!=20); 
    printf("END OF PROGRAM\n");
}

//Creating list
void Create(int data)
{
    struct Node *last,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->data=data;
    tmp->next=NULL;
    if (head==NULL)
    {
        head=tmp;
    }
    else
    {
    last=head;
    while(last->next!=NULL)
        last=last->next;
        last->next=tmp;
    }
}

//Displaying list
void Display()
{
    struct Node *last;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        last=head;
        printf("------------\nLINKED LIST:\n");

        while(last!=NULL)
        {
            printf("%d -> ",last->data);
            last=last->next;
        }
        printf("NULL");
    }
    printf("\n");
    free(last);
}

//Insert at START
void Insert_start()
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter new date:\n");
    scanf("%d", &newNode->data);

    if (head==NULL)
    {
        newNode->next=NULL;       //list is empty
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }   
} 

//Insert at END
void Insert_end()
{
    struct Node *last;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter new date:\n");
    scanf("%d", &newNode->data);
    newNode->next=NULL;
    last=head;
    if(head==NULL)        //If list is empty
    {
        head=newNode;
    }
    else
    {
        while (last->next!=NULL)  //we are traversing so that the second last node(3) point to new node(5)
        {
        last=last->next;
        }
        last->next=newNode;
        return;
    }
}

//INSERT AT A LOCATION
void Insert_loc()
{
    int pos,i;
    struct Node *tmp;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        printf("List is empty!");
    }
    printf("Enter new data:\n");
    scanf("%d",&newNode->data);
    printf("Enter position to insert:");
    scanf("%d",&pos);

    tmp=head;
    for(i=1;i<pos-1;i++)
    {
        if(tmp->next==NULL)
        {
            printf("There are less elements!");
        }
        tmp=tmp->next;
    }
    newNode->next = tmp->next;   //basically we are wanting what t is ..we want to equal it to new node
    tmp->next =  newNode;
}

//Insert after a specific element
void Insert_element()
{
    int element,i;
    struct Node *tmp;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        printf("List is empty!");
    }

    printf("Enter new data:\n");
    scanf("%d",&newNode->data);

    printf("Enter element after which to insert:");
    scanf("%d",&element);

    tmp=head;

    while (tmp->next!=NULL)
    {
        if(tmp->data==element)
        {
           newNode->next = tmp->next;
           tmp->next =  newNode; 
        }  
        tmp=tmp->next;  
    } 
}

//DELETE start
void Delete_start()
{   
    struct Node *tmp;
    tmp=head;
    if(head==NULL)
    {
        printf("List is empty!");
        return;
    }
    printf("Value of the deleted node = %d", tmp->data);
    head=head->next;
}

//DELETE end
void Delete_end()
{   
    struct Node *tmp, *prev;
    tmp=head;
    if(tmp==NULL)
    {
        printf("List is empty!");
        return;
    }
    if (tmp->next==NULL)
    {
         printf("List contains only node, Value of this node = %d", tmp->data);
         head=NULL;
         return;
    }
    while (tmp->next!=NULL)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    printf("Value of the deleted node = %d", tmp->data);
    prev->next=tmp->next;
}


//Delete a specific node
void Delete_loc()
{   
    struct Node *tmp, *prev;
    int key;
    printf("Enter the position:");
    scanf("%d", &key);
    tmp=head;
    if(tmp==NULL)
    {
        printf("List is empty!");
        return;
    }

    if (tmp!=NULL && tmp->data==key)
    {
        printf("Value of the deleted node = %d", tmp->data); 
        head=tmp->next;
    }
    while (tmp && tmp->data!=key)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    if (tmp==NULL)
    {
        printf("Value doesnt exist"); 
    }
    printf("Value of the deleted node = %d", tmp->data); 
    prev->next=tmp->next;
}


//Count
void Count() 
{ 
    struct Node *last;
    last=head;
    int count=0;
    while (last != NULL) 
    { 
        count++; 
        last = last->next; 
    } 
    printf("\nTotal no of nodes: %d", count);
} 

//
int detectLoop() 
{
    struct Node *slowp = head, *fastp = head;
    if (head == NULL || head->next == NULL) 
    {
        printf("\nEmpty list or list contains one node...");
        return 0;
    }
    while (slowp && fastp && fastp->next) 
    {
    slowp = slowp->next;
    fastp = fastp->next->next;
    if (slowp == fastp)
    return 1;
    }
    return 0;
}

//
void reverse() 
{
    struct Node* prev = NULL, *ptr;
    struct Node* curr = head;
    if(head == NULL) 
    {
        printf("\nEmpty List ...");
        return;
    }
    while (curr != NULL) 
    {
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }
    head = prev;
}

//Search element
void search()
{
    int ele;
    printf("ENTER THE ELEMENT FOR SEARCH\n");
    scanf("%d",&ele);
    struct Node *last,*tmp;
    last=head;
    while(last!=NULL)
    {
        if(last->data==ele)
            {
                printf("Element Found\n");
                break;
            }
        else
            {
                last=last->next;
            }
    }
    if(last==NULL)
        {
            printf("Element Not Found\n");
        }
}
