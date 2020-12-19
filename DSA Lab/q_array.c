#include <stdio.h> 
#include <stdlib.h> 

struct Queue
{
int size;
int front;
int rear;
int *Q;
};

//Functions
void create();
void display();
int isEmpty();
int isFull();
void enqueue();
int dequeue();


void main()
{
    struct Queue q;
    int ch;
    int temp;
    int size1;
    do
    {
        printf("----------------------\n");
        printf("Menu driven program:\n");
        printf("1.Create queue\n");
        printf("2.Display the queue:\n");
        printf("3.Check if empty:\n");
        printf("4.Check if full:\n");
        printf("5.Enqueue element:\n");
        printf("6.Dequeue element:\n");
        printf("For EXIT press 0 \n");
        printf("----------------------\n");
        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter size:\n");
                    scanf("%d", &size1);
                    create(&q, size1);
            break;
            case 2: printf("Display\n-------\n");
                    display(q);
            break;
            case 3: if (isEmpty(q)==1)
                    {
                        printf("Its empty!\n");
                    }
                    else
                    {
                        printf("Its NOT empty!\n");
                    }
            break;
            case 4: if (isFull(q)==1)
                    {
                        printf("Its full!\n");
                    }
                    else
                    {
                        printf("Its NOT full!\n");
                    }
            break;
            case 5: printf("Enter no. to push:\n");
                    scanf("%d", &temp);
                    enqueue(&q, temp);
            break; 
            case 6: dequeue(&q);
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

int isEmpty(struct Queue q)
{
    if (q.rear==q.front)
        return 1;
    else
        return 0;
}

int isFull(struct Queue q)
{
    if (q.rear==q.size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("Queue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    printf("%d ",q.Q[i]);
    printf("\n");
}