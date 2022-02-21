#include<stdio.h>
/*

	1
   12
  123
 1234
12345

*/
int main() 
{
int i,j,n,k;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	k=1;
	for(j=n;j>=1;j--)
	{
		if(j<=i)
		printf("%d",k++);
		else
		printf(" ");
	}
	printf("\n");
}
return 0;
}
