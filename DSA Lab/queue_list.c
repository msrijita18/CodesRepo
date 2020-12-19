#include <stdio.h> 
#include <stdlib.h> 

//Queue --> FIFO
//Front --> Deletion    dequeue
//Rear --> Insertion    enqueue

//Using a linked list
//    | | |-->| | |-->| |/|
//  -1 0       1       2
//  Front = Rear = -1
// ENQUEUE
// to insert add element arr[i] and rear++           O(1)
// DEQUEUE
// to delete pop element and front++                 O(1)
//    |1|2|3|4| | | |
//  -1 0 1 2 3 4 5 6
// Front=-1 && rear=3
//    | |2|3|4| | | |
//  -1 0 1 2 3 4 5 6
// Front=0 && rear=3

// condition for
// isEmpty if (front==NULL)
// isFull if (heap=full)
// if (temp==NULL)

// special case 
//when only one node both front and rear should point on it

struct Node
{
int data;
struct Node *next;
} *front=NULL,*rear=NULL;

//Functions=
void display();
void enqueue();
int dequeue();
void isEmpty();


void main()
{
    int ch;
    int temp;
    do
    {
        printf("----------------------\n");
        printf("Menu driven program:\n");
        printf("1.Enqueue element:\n");
        printf("2.Dequeue element:\n");
        printf("3.Display the queue:\n");
        printf("4.Is empty?:\n");
        printf("For EXIT press 0 \n");
        printf("----------------------\n");
        
        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter no. to insert:\n");
                    scanf("%d", &temp);
                    enqueue(temp);
            break; 
            case 2: printf("Deleted element= %d ",dequeue());
            break;
            case 3: display();
            break;
            case 4: isEmpty();
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}


void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node* t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void isEmpty()
{
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        printf("Not empty\n");
    }
    
}