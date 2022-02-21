// PRINT NUMBERS 1-10 USING RECURSION
#include<stdio.h>
void  display(int);

int main()
{
int limit;
scanf("%d",&limit);
display(limit);    
}

void display(int n)
{
 if(n>=1)
 {
display(n-1);
printf("%d ",n); 
 }
}

