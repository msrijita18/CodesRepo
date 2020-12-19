#include <stdio.h>
#include <stdlib.h>
struct Queue
{
 int size;
 int front;
 int rear;
 int *Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("Queue is Full");
    else
    {
    q->rear++;
    q->
    Q[q->rear]=x;
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

void Display(struct Queue q)
{
    int i;

    for(i=q.front+1;i<=q.rear;i++)
    printf("%d ",q.Q[i]);
    printf("\n");
}

int isEmpty(struct Queue *q)
{
    if(q->front==q->rear)
    return 1;
    else
    return 0;
}

void BFS(int G[][7], int start, int n) //user will put start=1 and maybe other than 1
{
    int i=start,j;
    struct Queue *q;
    int visited[7]={0};
    
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i);
    
    while(!isEmpty(q))
    {
        i=dequeue(q);
        for(j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
    
}

void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};
    int j;
    
    if(visited[start]==0)
     {
        printf("%d ",start);
        visited[start]=1;
        
        for(j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
        }
    }
}



int main()
{
    int G[7][7]={{0,0,0,0,0,0,0}, //00000000000
                 {0,0,1,1,0,0,0}, //0
                 {0,1,0,0,1,0,0}, //0
                 {0,1,0,0,1,0,0}, //0
                 {0,0,1,1,0,1,1}, //0
                 {0,0,0,0,1,0,0}, //0
                 {0,0,0,0,1,0,0}}; //0
    BFS(G,4,7);
    
    return 0;
}
