#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int testcases,n,i;
    scanf("%d",&testcases);
    while(testcases--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            if(n % i == 0)
                printf("%d ",i);
        printf("\n");
    }
    return 0;
}
