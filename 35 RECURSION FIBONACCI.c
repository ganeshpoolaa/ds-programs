// FIBONACCI SERIES USING RECURSION

#include<stdio.h>
int  fib(int);

int main()
{
int max=4,n;
printf("\n FIBONACCI SERIES IS\n");
for(n=0;n<max;n++)
printf("%5d",fib(n));    
}

int fib(int n)
{
if(n==0 || n==1)
return n;
else 
return fib(n-1)+fib(n-2);
//fib(4-1)+fib(4-2);
//2+1=3
//return(3);
}


