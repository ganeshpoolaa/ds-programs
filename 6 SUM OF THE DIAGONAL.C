/* PROGRAM TO FIND SUM OF THE DIAGONAL ELEMENTS OF A GIVEN MATRIX */
#include<stdio.h>
#include<conio.h>

int main()
{
int a[4][4],i,j,sum=0;
//clrscr();

printf("Enter elements for 3x3 matrix\n\n");
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
scanf("%d",&a[i][j]);
}

printf("\nElements in matrix order\n");
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
printf("%5d",a[i][j]);
}
printf("\n");
}
printf("\nADDITION OF DIAGONAL ELEMENTS=");
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
if(i==j)
sum=sum+a[i][j];
}
}
printf("%d",sum);
getch();
return 0;
}
/* OUTPUT:
Enter elements for 3x3 matrix
10 5 4 98 25 30 2 56 11

Elements in matrix order
 10  5  4
 98 25 30
  2 56 11

ADDITION OF DIAGONAL ELEMENTS=46
*/

