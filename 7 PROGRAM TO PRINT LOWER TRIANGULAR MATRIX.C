// PROGRAM TO PRINT LOWER TRIANGULAR MATRIX

#include<stdio.h>
int main()
{
int i,j,n,a[10][10];

scanf("%d",&n);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
//printf("Enter the A[%d][%d] location value:",i,j);
scanf("%d",&a[i][j]);
}


//printf("\n Lower triangular matrix:\n");
for ( i = 0; i < n; i++){
      for ( j = 0; j < n; j++){
         if( i < j )
            printf("0 ");
         else
            printf("%d ", a[i][j]);
      }
      printf("\n");
   }
return 0;
}

