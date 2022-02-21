#include<stdio.h>
/*

1
01
101
0101
10101

*/
int main() 
{
int row,col,n;
scanf("%d",&n);
for(row=1;row<=n;row++)
{
	for(col=1;col<=row;col++)
	{
		if((row+col)%2==0)
		printf("1");
		else
		printf("0");
	}
	printf("\n");
}
return 0;
}

