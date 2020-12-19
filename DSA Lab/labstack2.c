#include <stdio.h> 
#include <stdlib.h> 

struct Node
{
int data;
struct Node *next;
} *top=NULL;

//Functions
void create();
void isEmpty();
void display();
void push();
int pop();

int main()
{
    int ch, temp;
    do
    {
        printf("\n----------------------\n");
        printf("Menu driven program:\n");
        printf("1.Display the stack:\n");
        printf("2.Check if empty:\n");
        printf("3.Push an element:\n");
        printf("4.Pop an element:\n");
        
        printf("For EXIT press 0 \n");
        printf("----------------------\n");
        
        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: display();
            break;
            case 2: isEmpty();
            break;
            case 3: printf("Enter no. to push:\n");
                    scanf("%d", &temp);
                    push(temp);
            break;
            case 4: printf("Deleted element:\n");
                    printf("%d", pop());
            break;

            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
    return 0;
}

void isEmpty()
{
    if (top==NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is NOT empty\n");
}

void display() 
{
    struct Node *temp;
    temp = top;
    if (top == NULL) 
    {
        printf("Empty stack");
        return;
    }
    else 
    {
        while (temp != NULL) 
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void push(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}