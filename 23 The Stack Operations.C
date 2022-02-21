//DSOE 5D: The Stack Operations



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *stack,top=-1;
int *MinStack,*MaxStack,mintop=-1,maxtop=-1;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    int x=stack[top];
    top--;
    return x;
}

void ipush(int x)
{
    MinStack[++mintop]=x;
}

void xpush(int x)
{
    MaxStack[++maxtop]=x;
}

void ipop()
{
    mintop--;
}

void xpop()
{
    maxtop--;
}

void isEmpty()
{
    if(top==-1)
        printf("1\n");
    else 
        printf("0\n");
}

void Top()
{
    if(top==-1)
        printf("Invalid\n");
    else 
        printf("%d\n",stack[top]);
}

void minTop()
{
    if(top==-1)
        printf("Invalid\n");
    else
        printf("%d\n",MinStack[mintop]);
}

void maxTop()
{
    if(top==-1)
        printf("Invalid\n");
    else
        printf("%d\n",MaxStack[maxtop]);
}


int main() 
{
    stack=(int*)malloc(100*sizeof(int)); //Dynamic Array
    MinStack=(int*)malloc(100*sizeof(int)); //Dynamic Array
    MaxStack=(int*)malloc(100*sizeof(int)); //Dynamic Array
   
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int x;
            scanf("%d",&x);
            if(top==-1)
            {
               ipush(x);
               xpush(x);
            }
            else
            {
                if(x <= MinStack[mintop])
                    ipush(x);
                if(x >= MaxStack[maxtop])
                    xpush(x);
            }
            push(x);
        }
        else if(ch==2)
        {
            if(top==-1)
            {
                printf("Invalid\n");
            }
            else 
            {
                int x=pop();
                if(MinStack[mintop]==x)
                    ipop();
                if(MaxStack[maxtop]==x)
                    xpop();
            }
        }
        else if(ch==3)
            Top();
        else if(ch==4) 
            isEmpty();
        else if(ch==5)
            minTop();
        else 
            maxTop();
    }
    
    return 0;
}

