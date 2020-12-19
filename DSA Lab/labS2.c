#include<stdio.h>

int main()
{
    int b2[20][3];
    int n, m;
    // Assume 4x5 sparse matrix
    int smat[4][5] ={ 
                    {0 , 0 , 3 , 0 , 4 },
                    {0 , 0 , 5 , 7 , 0 },
                    {0 , 0 , 0 , 0 , 0 },
                    {0 , 2 , 6 , 0 , 0 }
                    };

    int i, j, k, size = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (smat[i][j] != 0)
            size++;
        }
    }
    int sm[size+1][3];
    k = 0;
    sm[k][0] = 4; sm[k][1] = 5; sm[k][2] = size;
    k++;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
        if (smat[i][j] != 0) 
        {
        sm[k][0] = i; 
        sm[k][1] = j;
        sm[k][2] = smat[i][j];
        k++;
        }
        }
    }
    printf("Matrix in triplet format\n");
    printf("Before transpose\n");
    for (int i=0; i<=size; i++) 
    {
        for (int j=0; j<3; j++)
        {
        printf("%d ", sm[i][j]);
        }
        printf("\n");
    }

	b2[0][0]=sm[0][1];
	b2[0][1]=sm[0][0];
	b2[0][2]=sm[0][2];
	
	k=1;
    m=sm[0][1];
	n=sm[0][2];
	
	for(i=0; i<m ;i++)
	{	
        for(j=1;j<=n;j++)
		{	//if a column number of current triple==i then insert the current triple in b2
            if(i==smat[j][1])
            {
                b2[k][0]=i;
                b2[k][1]=sm[j][0];
                b2[k][2]=sm[j][2];
                k++;
            }
        }
    }

    printf("After transpose\n");
    for (int i=0; i<=size; i++) 
    {
        for (int j=0; j<3; j++)
        {
        printf("%d ", b2[i][j]);
        }
        printf("\n");
    }

    return 0;
}