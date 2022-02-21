/* PROGRAM TO ADD GIVEN TWO MATRICES */

#include<stdio.h>


int main()
{
int row1,col1,row2,col2,i,j,a[3][3],b[3][3];
//printf("Enter number of rows and columns \n");
scanf("%d%d",&row1,&col1);
//printf("\n Enter %dX%d  A matrix values",row,col);
for(i=0;i<row1;i++)
{
for(j=0;j<col1;j++)
scanf("%d",&a[i][j]);
}

//printf("\n Enter %dX%d  B matrix values",row,col);
scanf("%d%d",&row2,&col2);
for(i=0;i<row2;i++)
{
for(j=0;j<col2;j++)
scanf("%d",&b[i][j]);
}

if(row1==row2&&col1==col2)
{
//printf("\n ADDITION OF A+B IS \n");
//printf("---------------------------\n");
for(i=0;i<row1;i++)
{
for(j=0;j<col1;j++)
{
printf("%d ",a[i][j]+b[i][j]); //For substraction replace + by -
}
printf("\n");
}
}
else
{
    printf("-1");
}
    return 0;
}


