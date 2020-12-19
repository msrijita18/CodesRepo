#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int data;
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to previous node
} *head=NULL;

//Functions
void create(int);
void display();
void traverse_forward();
void traverse_backward();
void insert_beg();
void insert_end();
void insert_loc();
//void delete_beg();
//void delete_end();

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
        printf("3.Traverse forward:\n");
        printf("3.Traverse backward:\n");
        printf("5.Insert at start\n");
        printf("6.Insert at end\n");
        printf("7.Insert at any location\n");
        //printf("8.Insert after a specific element\n");
        //printf("8.Delete a node at beginning\n");
        //printf("9.Delete a node at end\n");
        //printf("10.Delete a node at any position\n");

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
            case 2: display();
            break;
            case 3: traverse_forward();
            break;
            case 4: traverse_backward();
            break;
            case 5: insert_beg();
            break;
            case 6: insert_end();
            break;
            case 7: insert_loc();
            break;
            //case 8: delete_beg();
            //break; 
            //case 9: delete_end();
            //break; 
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}

//Create DLL
void create(int data)
{
    struct Node *last,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->data=data;
    tmp->next=NULL;
    if(head==NULL)
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

//Display DLL
void display()
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
            //printf("%d -> ",last->data);
            printf("-->| %u || %d || %u |", last->prev, last->data, last->next);
            last=last->next;
        }
        printf("-->NULL");
    }
    printf("\n");
    free(last);
}

void traverse_forward()
{
    struct Node *last;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        last=head;

        while(last!=NULL)
        {
            printf("%d -> ",last->data);
            last=last->next;
        }
        printf("NULL");
    }
    printf("\n");
}
void traverse_backward()
{
    struct Node *last, *newNode;
    last = head;

    
    while (last->next != NULL) 
    { 
        last = last->next; 
    } 
    while (last != head) 
    { 
        printf("->");
        printf("%d", last->data);
        last = last->prev; 
    } 
    printf("%d", last->data);
}


//Double LL
//
// | H | N | P |->| 2 | N | P |->| 3 | N | P |->| 4 | N | P |
// 
// |   |->| H | N | newnode<-P |->| 2 | N | P |->| 3 | N | P |->| 4 | N | P |
//   ^
// New struct   
// |   |->| H | N | newnode<-P |->| 2 | N | P |->| 3 | N | P |->| 4 | N | P |
//   ^ 
// | D | N->Head | P=NULL |
// 

//Insert at start
void insert_beg()
{
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the new data: \n");
    scanf("%d", &newNode->data);
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
        head = newNode;
    }
}

//Double LL
//
// | H | N | P |->| 2 | N | P |->| 3 | N | P |->| L | N | P |
// 
// | H | N | P |->| 2 | N | P |->| 3 | N | P |->| L | N | P |
//                                                            ^
//                                                        New struct
// | H | N | P |->| 2 | N | P |->| 3 | N | P |->| L=head | N | P |
//                                                                  ^
//                                               New struct  | D | N=NULL | P=Last | 
// | 1 |  |  |  
// 

//Insert at end
void insert_end()
{
    struct Node *last = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the new data: \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return; 
    }
    while (last->next != NULL)
    {
        last = last->next;
        last->next = newNode;
        newNode->prev = last;
        return;
    }
}

//Insert element at position
void insert_loc()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int i = 1, pos;
    struct Node *curr;
    curr = head;

    if(head == NULL) 
    {
        printf("Empty list!\n");
        return;
    }

    printf("Enter the position at which it will be inserted: \n");
    scanf("%d", &pos);

    if(pos == 1) 
    {
        insert_beg(); 
        return;
    }
    while(i< pos-1 && curr!=NULL) 
    {
        curr = curr->next;
        i++; 
    }
    if(curr->next == NULL) 
    { 
        insert_end();
        return;
    }
    if(curr != NULL) 
    {
        printf("\nEnter the new data: ");
        scanf("%d", &newNode->data);
        newNode->next = curr->next;
        newNode->prev = curr;
        if(curr->next != NULL) 
        {
            curr->next->prev = newNode;
            curr->next = newNode;
        }
    }
    else 
    {
        printf("Invalid position!\n");
    }
}

//Delete start
void delete_beg()
{
    struct Node *temp;
    if(head == NULL) 
    {
        printf("Empty List, Delete not possible\n");
        return;
    }
    temp = head;
    head = head->next;
    if(head==NULL) 
    {
        head->prev = NULL;
    }
}

//Delete end
void delete_end()
{
    struct Node *temp;
    if(head == NULL) 
    {
        printf("Empty List, Delete not possible\n");
        return;
    } 
    temp = head;
    while(temp->next != NULL) 
    {
        temp=temp->next;
    }
    if(temp->prev != NULL) 
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
}

//Delete element at specified position/index

//Delete all even nodes



