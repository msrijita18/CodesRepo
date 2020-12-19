#include<stdio.h>
#include<stdlib.h>
void readsparse(int sp[10][3]) 
{
    int r,c,i,j,k,t;
    printf("\nEnter r and c : ");
    scanf("%d %d", &r, &c);
    printf("\nEnter the data \n");
    k=1;
    for(i=0;i < r;i++) 
    {
        for(j=0;j<c;j++) 
        {
            scanf("%d", &t);
            if( t != 0 ) 
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = t;
                k++;
            }   
        }
    }
    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = k-1;
    }

int addsparse(int sp1[10][3],int sp2[10][3],int sp3[10][3]) 
{
    int r, c, i, j, k1, k2, k3, tot1 ,tot2;
    if( sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1] ) 
    {
    printf("Invalid matrix size ");
    exit (0);
    }
    
    tot1 = sp1[0][2]; tot2 = sp2[0][2];
    k1 = k2 = k3 = 1;
    while ( k1 <= tot1 && k2 <= tot2) 
    {
    if ( sp1[k1][0] < sp2[k2][0] ) 
    {
    sp3[k3][0] = sp1[k1][0];
    sp3[k3][1] = sp1[k1][1];
    sp3[k3][2] = sp1[k1][2];
    k3++; k1++;
    }
    else
    if ( sp1[k1][0] > sp2[k2][0] ) 
    {
    sp3[k3][0] = sp2[k2][0];
    sp3[k3][1] = sp2[k2][1];
    sp3[k3][2] = sp2[k2][2];
    k3++;k2++;
    }
    else
    if(sp1[k1][1] < sp2[k2][1]) 
    {
    sp3[k3][0]=sp1[k1][0];
    sp3[k3][1]=sp1[k1][1];
    sp3[k3][2]=sp1[k1][2];
    k1++; k3++;
    }
    else
    if(sp1[k1][1] > sp2[k2][1]) 
    {
    sp3[k3][0]=sp2[k2][0];
    sp3[k3][1]=sp2[k2][1];
    sp3[k3][2]=sp2[k2][2];
    k2++;
    k3++;
    }
    else //if ( sp1[k1][0] == sp2[k2][0] )
    {
    sp3[k3][0] = sp2[k2][0];
    sp3[k3][1] = sp2[k2][1];
    sp3[k3][2] = sp1[k1][2] + sp2[k2][2];
    k3++;k2++;k1++;
    }
    }
    while ( k1 <=tot1 ) 
    {
    sp3[k3][0] = sp1[k1][0];
    sp3[k3][1] = sp1[k1][1];
    sp3[k3][2] = sp1[k1][2];
    k3++;k1++;
    }
    while ( k2 <= tot2 ) 
    {
    sp3[k3][0] = sp2[k2][0];
    sp3[k3][1] = sp2[k2][1];
    sp3[k3][2] = sp2[k2][2];
    k3++;k2++;
    }
    sp3[0][0] = sp1[0][0];
    sp3[0][1] = sp1[0][1];
    sp3[0][2] = k3-1;
}

void main()
{
    int b1[20][3],b2[20][3],b3[20][3];
    
    printf("\nFirst matirx:\n");
    readsparse(b1);
    printf("\nSecond matirx:\n");
    readsparse(b2);
    
    printf("\nSum matirx:\n");
    addsparse(b1,b2,b3);

}
