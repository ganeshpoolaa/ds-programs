//  Program to check if a Matrix is a Sparse Matrix
 
#include <stdio.h>
void main ()
{
    int matrix[10][10];
    int i, j, rows, cols;
    int zero_counter = 0;
     printf("Enter number of rows and columns of the matix:");
    scanf("%d %d", &rows, &cols);
 
    printf("Enter the elements of the matix: \n");
    for (i=0; i<rows; ++i)
    {
        for (j=0; j<cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
            {
                zero_counter++;
            }
        }
    }
    
	if(zero_counter > ((rows * cols) / 2))
     printf("The given matrix is Sparse Matrix \n");
    else
        printf("The given matrix is not a Sparse Matrix \n");
    printf("There are %d number of Zeros.", zero_counter);
}
