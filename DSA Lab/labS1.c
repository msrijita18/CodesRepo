/* C Program to check Matrix is a Sparse Matrix or Not */
 
#include<stdio.h>
 
int main()
{
 	int i, j, m, n, smat[10][10], Total = 0;
  
 	printf("\n Please Enter Number of rows and columns  :  ");
 	scanf("%d %d", &m, &n);
 
 	printf("\n Please Enter the Matrix Elements \n");
 	for(i = 0; i < m; i++)
  	{
   		for(j = 0; j < n; j++)
    	{
      		scanf("%d", &smat[i][j]);
    	}
  	}

    for(i = 0; i < m; i++)
  	{
   		for(j = 0; j < n; j++)
    	{
      		if(smat[i][j] == 0)
    		{
    			Total++;    		
			}
    	}
  	} 
 	
  	if(Total > (m * n)/2)
  	{
  		printf("The Matrix that you entered is a Sparse Matrix \n");
	}
    printf("Matrix in triplet format\n");
    int k, size = 0;
    for (i = 0; i < m; i++)
    {    for (j = 0; j < n; j++)
         {   
             if (smat[i][j] != 0)
                size++;
        }
    }

    int sm[size+1][n];
    k = 0;

    sm[k][0] = m; sm[k][1] = n; sm[k][2] = size;
    k++;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
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

    for (int i=0; i<=size; i++) 
    {
        for (int j=0; j<n; j++)
        {
            printf("%d ", sm[i][j]);
            
        }printf("\n");
    }

	if (Total <= (m * n)/2)
	{
		printf("\n The Matrix that you entered is Not a Sparse Matrix ");
	}
  	
 	return 0;
}
