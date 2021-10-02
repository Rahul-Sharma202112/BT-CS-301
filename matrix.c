#include<stdio.h>
#define R1 2
#define C1 2
#define R2 2
#define C2 2
void Sum_mat(int mat1[][C1], int mat2[][C2]);
void Substraction_mat(int mat1[][C1], int mat2[][C2]);
void multiplication_Mat(int mat1[][C1], int mat2[][C2]);
void Transpose_mat(int mat1[][C1], int mat2[][C2]);
int main()
{
	int i,j,choice,flag=1;
	int mat1[R1][C1],mat2[R2][C2];
	printf("Enter matrix 1\n");
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C1;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter matrix 2\n");
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C1;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}

	while(flag)
	{
		printf("\nchoose the following option\n\n");
		printf("press 1 to Add two matrices\n");
		printf("press 2 to Substract two matrices\n");
		printf("press 3 to Multiply two matrices\n");
		printf("press 4 to find transpose of given matrices\n");
		printf("press 0 to EXIT...\n\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				Sum_mat(mat1, mat2);
				break;
			case 2:
				Substraction_mat(mat1, mat2);
				break;
			case 3:
				multiplication_Mat(mat1, mat2);
				break;
			case 4:
				Transpose_mat(mat1,mat2);
				break;
			default:
				flag=0;
		}
	}
}

void Sum_mat(int mat1[][C1], int mat2[][C2])
{
	int i,j;
	int sum[R1][C1];
	for (i = 0; i < R1; i++)  
	    {  
	        for (j = 0; j < C1; j++)  
	        {  
	            sum[i][j] = mat1[i][j] + mat2[i][j];  
	            printf("%d\t", sum[i][j]);  
	        }  
	        printf("\n");  
	    } 
}

void Substraction_mat(int mat1[][C1], int mat2[][C2])
{
	int i,j;
	int result[R1][C1];
	for (i = 0; i < R1; i++)  
	    {  
	        for (j = 0; j < C1; j++)  
	        {  
	            result[i][j] = mat1[i][j] - mat2[i][j];  
	            printf("%d\t", result[i][j]);  
	        }  
	        printf("\n");  
	    } 
}

void multiplication_Mat(int mat1[][C1], int mat2[][C2])
{
	int rslt[R1][C2],i,j,k;

	printf("Multiplication of given two matrices is:\n\n");

	for (i = 0; i < R1; i++) {
		for (j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (k = 0; k < R2; k++) {
				rslt[i][j] =rslt[i][j]+ mat1[i][k] * mat2[k][j];
			}

		}

		printf("\n");
	}
	for(i=0;i<R1;i++)
		{
			for(j=0;j<C2;j++)
			{
				printf("%d\t", rslt[i][j]);
			}
			printf("\n");
		}
}

void Transpose_mat(int mat1[][C1], int mat2[][C2])
{
	int transpose1[R1][C1],transpose2[R2][C2],i,j;
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < C1; j++) 
	  	{
	  	    transpose1[j][i] = mat1[i][j];
	  	}
	 }
	  
	for (i = 0; i < R2; i++)
	  {
	  	for (j = 0; j < C2;j++) 
	  		  {
	  		    transpose2[j][i] = mat2[i][j];
	  		  }
	  }

	  for(i=0;i<R1;i++)
	  {
	  		for(int j=0;j<C1;j++)
	  		{
	  			printf("%d\t",transpose1[i][j]);
	  		}
	  		printf("\n");
	  }
	   for(i=0;i<R2;i++)
	  		{
	  			for(int j=0;j<C2;j++)
	  			{
	  				printf("%d\t",transpose2[i][j]);
	  			}
	  			printf("\n");
	  		}
	  
}
