#include <stdio.h> 
#include <stdlib.h> 

/*
        5
        --
        4
        --
        3
        --
        2
        --
        1
        --
*/
struct Stack
{
    int size;
    int top;            
    int *s;
};


void main()
{
    //initialize stack
    struct Stack st;
    int n, temp;
    printf("Enter size of stack:\n");
    scanf("%d", &st.size);
    //create array-stack
    st.s = (int *)malloc(st.size * sizeof(int));
    st.top = -1;

    printf("Enter no of elements:\n");
    scanf("%d", &n);
    //Push elements
    for (int i=0; i<n; i++)
    {
        printf("Enter no. to push:\n");
        scanf("%d", &temp);
        if (st.top==st.size-1)
        {
            printf("Stack overflow\n");
        }
        else
        {
            st.top++;                        //increment top
            st.s[st.top]=temp;               //store the value or push it
        }
    }

    //Display
    printf("Display queue\n");
    for (int i=st.top; i>=0; i--)
    {
        printf("%d \n", st.s[i]);
    }
    printf("\n");

}