// PRINT FOLLOWING USING RECURSION
1
1 2 
1 2 3
1 2 3 4 

#include <stdio.h>

int printpattern(int n) 
{
   if(n>0) 
   {
      printpattern(n-1);
      //printf("*");
      printf("%d ",n);
   }
}

int pattern(int n) 
{
   if(n>0) 
   {
      pattern(n-1); //will recursively print the pattern
   }
   printpattern(n); //will reduce the n recursively.
   printf("\n"); 
}

int main() 
{
   int n;
   scanf("%d",&n);
   pattern(n);
   return 0;
}
