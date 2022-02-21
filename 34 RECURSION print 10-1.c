// PRITING NATURAL NUMBERS IN REVERSE ORDER USING RECURSION

#include<stdio.h>
int  display(int);

int main()
{
//int n = 10;
int n=1;
printf("\n Natural numbers in reverse order using recursion\n");	
display(n);
    
}

/*int display(int n)
{
 if(n>=1)
 {
 printf("%5d ",n);
 display(n-1);
    }
}*/


int display(int n)
{
 if(n<=4)
 
 display(n+1);
 printf("%5d ",n);
 
}


