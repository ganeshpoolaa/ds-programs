//DSOE 5B: Stack using Linked List

/*
Your task is to implement the following Stack operations using linked list: - 1.push(x):insert x at top of the stack - 2.pop():remove top of the element if exist, otherwise print “Invalid” - 3.top():print top of the element if exist, otherwise print “Invalid” - 4.isEmpty():if stack is empty print 1 otherwise print 0

Note: All operations should be performed in O(1) time complexity.

Input Format

First line an integer N

Next N lines each line contain one operation each:1 X denotes push X value to stack, 2 denotes pop the top element,3 denotes print top element and 4 denotes check the stack is empty or not

Constraints

1 <= N < = 25

Output Format

For every 3 type operations print the top element from the stack if exist otherwise print “Invalid”

Sample Input 0

10
1 10
1 20
1 30
3
4
2
2
3
2
4
Sample Output 0

30
0
10
1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*top;

void push(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(top==NULL)
        top=newnode;
    else 
    {
        newnode->next=top;
        top=newnode;
    }
}

//****************************************
void pop()
{
    if(top==NULL)
        printf("Invalid\n");
    else
    {
        struct node *temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}

//****************************************
void isEmpty()
{
    if(top==NULL)
        printf("1\n");
    else 
        printf("0\n");
}

//****************************************
void Top()
{
    if(top==NULL)
        printf("Invalid\n");
    else 
        printf("%d\n",top->data);
}

//****************************************
int main() 
{
    int n;
	scanf("%d",&n);
    while(n--)
    {
        int ch;
		scanf("%d",&ch);
        if(ch==1)
        {
            int data;
			scanf("%d",&data);
            push(data);
        }
        else if(ch==2)
            pop();
        else if(ch==3)
            Top();
        else 
            isEmpty();
    }    
    return 0;
}


