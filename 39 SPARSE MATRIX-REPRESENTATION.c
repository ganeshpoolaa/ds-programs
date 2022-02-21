// SPARSE MATRIX REPRESENTATION

#include <stdio.h>  
int main()  
{  
    int nonzero_count = 0,i,j,k=0;  
	// Sparse matrix having size 4*5  
    int sparse_matrix[4][5] =  
    {  
        {0 , 0 , 10 , 0 , 20 },  
        {0 , 0 , 30 , 40 , 0 },  
        {0 , 0 , 0 , 0 , 0 },  
        {0 , 50 , 60 , 0 , 0 }  
    };  
  
    for(i=0; i<4; i++)  
    {  
        for(j=0; j<5; j++)  
        {  
            if(sparse_matrix[i][j]!=0)  
            {  
                nonzero_count++;  
            }  
        }  
    }  
  
   // Defining final matrix  
    int result_matrix[3][nonzero_count];   
       
   // Computing final matrix  
    for(i=0; i<4; i++)  
    {  
        for(j=0; j<5; j++)  
        {  
            if(sparse_matrix[i][j]!=0)  
            {  
                result_matrix[0][k] = i;  
                result_matrix[1][k] = j;  
                result_matrix[2][k] = sparse_matrix[i][j];  
                k++;  
            }  
      }  
    }  
  
   // Displaying the final matrix
   printf(" ROW------> \n COLUMN ---->\n VALUE----->\n");  
    for(i=0 ;i<3; i++)  
    {  
        for(j=0; j<nonzero_count; j++)  
        {  
            printf("%d ", result_matrix[i][j]);  
            printf("\t");  
        }  
        printf("\n");  
    }  
    return 0;  
}  

/*
OUTPUT:

 ROW------>
 COLUMN ---->
 VALUE----->
0       0       1       1       3       3
2       4       2       3       1       2
10      20      30      40      50      60

*/
