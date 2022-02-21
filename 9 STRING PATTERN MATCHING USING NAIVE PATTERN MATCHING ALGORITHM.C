// STRING PATTERN MATCHING USING NAIVE PATTERN MATCHING ALGORITHM

#include <stdio.h>
#include <string.h>
int main ()
{
   char txt[200];
   char pat[20];
   int i,j,M,N,k=0;
   
 fgets(txt,100,stdin);
 fgets(pat,100,stdin);
    M = strlen(pat);
    N = strlen(txt);
   // printf("\n M=%d N=%d",M,N);
   for(i = 0; i <= N - M; i++)
   {
      for(j = 0; j < M; j++)
      {
         if (txt[i + j] != pat[j])
      		break;
      }
      if(j == M)
        {
        printf("%d",i);
        k=1;
        break;
        }
   }
    if(k==0)
    printf("-1");
    return 0;
}

