/* PROGRAM TO FIND MINIMUM,MAXIMUM NUMBER FROM  A GIVEN 1-D ARRAY */

#include<stdio.h>
//#include<conio.h>

int main()
{
int n,i,min,max,a[10];
//clrscr();
//printf("Enter maximum size of an array:");
scanf("%d",&n);
//printf("\nEnter %d numbers\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

min=a[0];
max=a[0];

for(i=0;i<n;i++)
{
if(a[i]<min)
min=a[i];
else if(a[i]>max)
max=a[i];
}

printf("%d\n%d",max,min);
//getch();
return 0;
}
/* OUTPUT:
Enter max range
5

Enter 5 numbers
10 20 30 40 50

 Minimum value=10
 Maximum value=50
 */
