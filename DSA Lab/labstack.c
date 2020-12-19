#include <stdio.h> 
#include <stdlib.h> 

#define STACK_SIZE 100 /* maximum stack size */
int stack[STACK_SIZE];
int top = -1;

//Functions
//void create();
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
    if (top==-1)
    printf("Stack is empty\n");
    else
    printf("Stack is NOT empty\n");
}
   

void display()
{
    if (top==-1)
    {
        printf("Empty stack!\n");
    }
    else
    {
        printf("Displaying stack:-\n");
        for (int i=top; i>=0; i--)
        {
            printf("%d \n", stack[i]);
        }
    } 
}

void push(int item) 
{
    /* add an item to the global stack */
    if (top == STACK_SIZE-1) 
    {
        printf("Stack is Full");
        return;
    }
    top++;
    stack[top] = item;
}

int pop() 
{
    /* return the top element from the stack */
    if (top == -1) 
    {
        printf("Stack is Empty");
    }
    return stack[top--];
}