// PRINT FACTORIAL OF A NUMBER USING RECURSION

#include<stdio.h>
int  factorial(int);

int main()
{
int n,result;
scanf("%d",&n);
result=factorial(n);
printf("%d",result);    
}

int factorial(int n)
{
 if(n==0 || n==1)
return 1;
else 
n=n*factorial(n-1);
 return n;
}


