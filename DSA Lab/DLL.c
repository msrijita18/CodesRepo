#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{
    struct Node* prev; 
    int data;
    struct Node* next; 
} *head=NULL,*ptr;

//Functions
void create(int);
void display();
void traverse_forward();
void traverse_backward();
void insert_beg();
void insert_end();
void insert_loc();
void delete_beg();
void delete_end();
void delete_loc();


void main()
{
    int ch,n,i,data,a,pos;
    do
    {
        printf("\nMenu driven program for Linked list:\n");
        printf("1.Create\n");
        printf("2.Display:\n");
        printf("3.Traverse forward:\n");
        printf("4.Traverse backward:\n");
        printf("5.Insert at start:\n");
        printf("6.Insert at end:\n");
        printf("7.Insert at any location:\n");
        printf("8.Delete element at start:\n");
        printf("9.Delete element at end:\n");
        printf("10.Delete element at any location:\n");

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
            case 8: delete_beg();
            break;
            case 9: delete_end();
            break;
            case 10: delete_loc();
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}

//Create DLL
void create(int item)
{
	struct Node *curr;
	curr=(struct Node*)malloc(sizeof(struct Node));
	curr->next=NULL;
	curr->prev=NULL;
	curr->data=item;
    //printf("node= %d\n",curr->data);
	if(head == NULL)
	{
		head=curr;
		ptr=curr;	
	}
	else
	{
		curr->prev=ptr;
		ptr->next=curr;
		ptr=ptr->next;
	}
	//printf("node= %d \n",ptr->data);
}
//Display DLL
void display()
{
	struct Node *ptr;
	if (head==NULL)
	{
		printf("No node\n");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("| %u | %d | %u | <--> ",ptr->prev,ptr->data,ptr->next);
			ptr=ptr->next;
		}
	}
    printf("NULL");
}
   // printf("\n");
   // free(ptr);

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
    struct Node *last, *newNode,*ptr;
    last = head;
    
    while (last->next != NULL) 
    { 
        last = last->next; 
    } 
    while (last != head) 
    { 
        printf(" %d--> ", last->data);
        last = last->prev; 
    } 
    printf(" %d ", last->data);
    
}

//Insert at start
void insert_beg()
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
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
    }
     last->next = newNode;
     newNode->prev = last;
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
    while(i < pos-1 && curr!=NULL) 
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


//Delete at start
void delete_beg()
{
    struct Node *temp;
    if(head == NULL) 
    {
    printf("Empty List, Delete not possible\n");
    return;
    }
    else 
    {
        temp = head;
        head = head->next;
        if(head==NULL) 
            head->prev = NULL;
    }
    free(temp);
}

//Delete at end
void delete_end()
{
    struct Node *temp;
    if(head == NULL) 
    {
        printf("Empty List, Delete is not possible\n");
        return;
    } 
    else 
    {
        temp = head;
        while(temp->next != NULL) 
            temp=temp->next;
        if(temp->prev != NULL) 
            temp->prev->next = NULL;
        else head = NULL;
    }
    free(temp);
}

//Delete at any location
void delete_loc()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    struct Node *temp;
    int i;
    if(head == NULL) 
    {
        printf("Empty List, Delete not possible\n");
        return;
    }
    if (pos == 1)
    {
        delete_beg();
    }
    temp = head;
    i=1;
    while (i<pos && temp!=NULL) 
    {
        i++;
        temp=temp->next;
    }
    if (temp==NULL) 
        printf("Invalid Position\n");
    else if (temp->next == NULL) 
    {
        delete_end();
    }
    else 
    {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    }
}