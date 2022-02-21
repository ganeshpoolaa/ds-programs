//DSOE 5C: Infix expression to postfix expression

/*
Input Format

Single line input, a string that denotes the infix expression, containing all small case letters

Output Format

Print the string after converting infix to postfix

Sample Input 0

a+b
Sample Output 0

ab+
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char stack[100];
int top=-1;

void push(char c)
{
    top++;
    stack[top]=c;
}

char pop()
{
    char c=stack[top];
    top--;
    return c;
}

int pre(char c)
{
    if(c=='^')
        return 3;
    if(c=='*' || c=='/' || c=='%')
        return 2;   
    if(c=='+' || c=='-')
        return 1;
    return 0;
}

int main() 
{
    char infix[100],postfix[100],c;
    int i=0,j=0;
    scanf("%s",infix);
    while(infix[i])
    {
        if(infix[i]>='a' && infix[i]<='z')
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(top==-1)
            push(infix[i]);  
        else if(infix[i]=='(')
            push(infix[i]);     
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j]=pop();
                j++;
            } //inner while close
            c=pop();
        } //else close
        else if(pre(infix[i]) <= pre(stack[top]) && stack[top]!='(')
        {
            while(top!=-1 && stack[top]!='(' && pre(infix[i]) <= pre(stack[top]))
                   {
                       postfix[j]=pop();
                       j++;
                   }//inner while close
                  push(infix[i]); 
        } // else cose  
        else
        {
            push(infix[i]); 
        }
        i++;
    } //while close
    
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;              
    }
    postfix[i]='\0';
    printf("%s\n",postfix);
    return 0;
}

