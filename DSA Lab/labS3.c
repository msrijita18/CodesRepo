#include<stdio.h>
#include<stdlib.h>

struct sparse
{
 int r;          // row number
 int c;          // column number
 struct sparse *rptr;   // row pointer
 struct sparse *cptr;   // column header
 int data;       // actual data
} *s;

int create(struct sparse *h)
{
    printf("\nEnter the no. of rows ::");
    scanf("%d", &s->r);
    printf("\nEnter the no. of columns ::");
    scanf("%d", &s->c);

    // create the head node
    h=(struct sparse*)malloc(sizeof(struct sparse));
    h->r=s->r;
    h->c=s->c;
    h->rptr=h;
    h->cptr=h;
    h->data=0;

    // create column headers
    struct sparse *ptr;
    int i,j,d;
    ptr=h;
    for(i=1;i<=s->c;i++)
    {
    struct sparse *node;
    node=(struct sparse*)malloc(sizeof(struct sparse));
    node->r=0;
    node->c=i;
    node->data=0;
    node->rptr=h;
    node->cptr=node;

    ptr->rptr=node;
    ptr=node;
    }

    // create row headers
    ptr=h;
    for(i=1;i<=s->r;i++)
    {
    struct sparse *node;
    node=(struct sparse*)malloc(sizeof(struct sparse));
    node->r=i;
    node->c=0;
    node->data=0;
    node->rptr=node;
    node->cptr=h;

    ptr->cptr=node;
    ptr=node;
    }
    
    printf("“\n now enter the non zero elements one by one\n”");
    printf("“\n Enter row number,column number,data”");
    printf("“\n Enter (0 0 0) to stop ::”");
    scanf("%d %d %d", &i, &j, &d);
    if(i>s->r || j>s->c ||i<1 ||j<1)
    {
    printf("“\n Error input”");
    exit(1);
    }
    while(i&&j&&d)
    {
    struct sparse *row_header, *column_header;
    row_header=h->cptr;
    column_header=h->rptr;

    // find the correct row header and column header
    while (row_header->r < i)
        row_header=row_header->cptr;

    while(column_header->c<j)
        column_header=column_header->rptr;

    struct sparse *ptr1;
    struct sparse *ptr2;

    // find the correct position to insert
    struct sparse *row_ptr=row_header;
    while(row_ptr->c<j)
    {
    ptr1=row_ptr;
    row_ptr=row_ptr->rptr;
    if(row_ptr==row_header)
        break;
    }

    struct sparse *column_ptr=column_header;
    while(column_ptr->r<i)
    {
    ptr2=column_ptr;
    column_ptr=column_ptr->cptr;
    if(column_ptr==column_header)
        break;
    }

    struct sparse *node;
    node=(struct sparse*)malloc(sizeof(struct sparse));
    node->r=i;
    node->c=j;
    node->data=d;

    ptr1->rptr=node;
    ptr2->cptr=node;
    node->rptr=row_ptr;
    node->cptr=column_ptr;

    printf("“\n Enter row number,column number,data”");
    printf("“\n Enter (0 0 0) to stop ::”");
    scanf("%d %d %d", &i, &j, &d);
    if(i>s->r || j>s->c)
    {
    printf("“\n Error input”");
    exit(1);
    }
    return 0;
}
}

void display(struct sparse *h)
{
 struct sparse *right = h->cptr;
 
 while(right!=h)
 {
  struct sparse *r1=right;
  right=right->rptr;
  while(right!=r1)
  {
   printf("%d %d %d ",right->r, right->c,right->data);
   right=right->rptr;
  }
  right=right->cptr;
 }
}

void add(struct sparse *h1, struct sparse*h2)
{
 if (h1->r==h2->r && h1->c==h2->c)
  printf("“The addition of the two given sparse matrices is ::\n”");
 else
 {
  printf("“addition is not possible:\n”");
  exit(1);
 }
 struct sparse *r1;
 r1=h1->cptr;
 struct sparse *r2;
 r2=h2->cptr;
 
 while(r1!=h1)
 {
  struct sparse *p1=r1;
  r1=r1->rptr;

  struct sparse *p2=r2;
  r2=r2->rptr;

  while(r1!= p1 && r2!=p2)
  {
   if(r1->c==r2->c)
   {
    printf("%d %d %d" ,r1->r, r1->c, (r1->data+r2->data));
    r1=r1->rptr;
    r2=r2->rptr;
   }
   else if(r1->c>r2->c)
   {
    printf("%d %d %d" ,r2->r, r2->c, r2->data);
    r2=r2->rptr;
   }
   else
   {
       printf("%d %d %d" ,r1->r, r1->c, r1->data);
    r1=r1->rptr;
   }
  }
  while(r1!=p1)
  {
      printf("%d %d %d" ,r1->r, r1->c, r1->data);
   r1=r1->rptr;
  }
  while(r2!=p2)
  {
   printf("%d %d %d" ,r1->r, r1->c, r1->data);
   r2=r2->rptr;
  }
  r1=r1->cptr;
  r2=r2->cptr;
 }
}

void main()
{
 struct sparse *h1=NULL,*h2=NULL;
 //cout<<“Enter the values for sparse matrix 1 ::\n”;
 
 create(h1);
 display(h1);
 //cout<<“Enter the values for sparse matrix 2 ::\n”;
 create(h2);
 display(h2);
 add(h1,h2);
}



