#include <stdio.h> 
#include <stdlib.h> 

struct Stack
{
    int size;
    int top;            // top = -1
    int *s;
};

//Functions
void create();
void display();
void push();
int pop();
int isEmpty();
int isFull();
int peek();
int stackTop();

void main()
{
    struct Stack st;
    int ch, temp, index;
    do
    {
        printf("----------------------\n");
        printf("Menu driven program:\n");
        printf("1.Create stack\n");
        printf("2.Display the stack:\n");
        printf("3.Check if empty:\n");
        printf("4.Check if full:\n");
        printf("5.Push an element:\n");
        printf("6.Pop an element:\n");
        printf("7.Peek:\n");
        printf("8.Stack top:\n");
        printf("For EXIT press 0 \n");
        printf("----------------------\n");
        printf("\nEnter option no:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create(&st);
            break;
            case 2: display(st);
            break;
            case 3: if (isEmpty(st)==1)
                    printf("Stack is empty\n");
                    else
                    printf("Stack is NOT empty\n");
            break;
            case 4: if (isFull(st)==1)
                    printf("Stack is Full\n");
                    else
                    printf("Stack is NOT Full\n");
            break;
            case 5: printf("Enter no. to push:\n");
                    scanf("%d", &temp);
                    push(&st, temp);
            break;
            case 6: printf("Deleted element:\n");
                    printf("%d", pop(&st));
            break;
            case 7: printf("Enter index:\n");
                    scanf("%d", &index);
                    printf("Element at index %d is %d\n", index, peek(st, index));
            break;
            case 8: printf("Top element:\n");
                    printf("%d\n", stackTop(st));
            break;
            case 0: exit(0);
            default: printf("Invalid key!");
        }

    } while(ch!=20);
    printf("END OF PROGRAM\n");
}

void create(struct Stack *st)
{
    printf("Enter size of stack:\n");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void display(struct Stack st)
{
    printf("Display queue:-\n");
    for (int i=st.top; i>=0; i--)
    {
        printf("%d \n", st.s[i]);
    }
}

void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
    printf("Stack overflow\n");
    else
    {
    st->top++;
    st->s[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    printf("Stack Underflow\n");
    else
    {
    x=st->s[st->top--];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top==-1)
    return 1;
    else
    return 0;
}

int isFull(struct Stack st)
{
    return st.top==st.size-1;
    return 0;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
    return st.s[st.top];
    return -1;
}

int peek(struct Stack st,int index)
{
    int x=-1;
    if (st.top-index+1 < 0)
    printf("Invalid Index \n");
    x = st.s[st.top-index+1];
    return x;
}