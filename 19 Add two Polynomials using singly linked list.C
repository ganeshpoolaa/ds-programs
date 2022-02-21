//DSOE 4 A5 : Add two Polynomials using singly linked list

/*

A polynomial is an expression consisting of indeterminates 
(also called variables) and coefficients that involves only the 
operations of addition, subtraction, multiplication, and non-negative 
integer exponentiation of variables.

An example of a polynomial of a single indeterminate x is:

image

Your task is to implement addition of given two polynomials using 
single linked list

The node structure for single linked list for representing a term of

 polynomial can be defined as follows: 
 struct node { int coef; int expo; struct node *next; };

Input Format

First line an integer N denotes number of terms in first polynomial
Next N lines each line contain two positive integers separated by space: first integer denotes coefficient and second integer denotes exponent of first polynomial

Next line an integer M denotes number of terms in second polynomial

Next M lines each line contain two positive integers separated by space: first integer denotes coefficient and second integer denotes exponent of second polynomial
Note: For easy implementation read the polynomial in descending order of exponent

Constraints

1<= N <= 20

Output Format

Line1: Display the first polynomial
Line2: Display the second polynomial
Line3: Display the result polynomial
Sample Input 0

3
3 3
2 2
1 1
3
5 5
3 2
7 0
Sample Output 0

First polynomial is:3x^3+2x^2+1x^1

Second polynomial is:5x^5+3x^2+7

The sum Polynomial is:5x^5+3x^3+5x^2+1x^1+7

*/


//DSOE 4 A5 : Add two Polynomials using singly linked list

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    int c,e;
    struct node *next;
}*p1,*p2,*p3;

struct node* insertatend(struct node *head,int c,int e)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->c=c;
    newnode->e=e;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else 
    {
        struct node* x=head;
        while(x->next)
            x=x->next;
        x->next=newnode;
    }
    return head;
}


void display(struct node *head)
{
     struct node* x=head;
    //5x^3+4x^2+7x+8
    while(x!=NULL)
    {
        printf("%d",x->c);
        if(x->e!=0)
         printf("x^%d",x->e);
        if(x->next!=NULL)
         printf("+");
        x=x->next;
    }
}

struct node* add()
{
    while(p1 && p2)
    {
        
        if(p1->e==p2->e)
        {
            p3=insertatend(p3,p1->c+p2->c,p1->e);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->e > p2->e)
        {
            p3=insertatend(p3,p1->c,p1->e);
            p1=p1->next;
        }
        else 
        {
            p3=insertatend(p3,p2->c,p2->e);
            p2=p2->next;
        }
    }

    while(p1)
    {
        p3=insertatend(p3,p1->c,p1->e);
        p1=p1->next;
    }
    
    while(p2)
    {
        p3=insertatend(p3,p2->c,p2->e);
        p2=p2->next;
    }
    return p3;
}


int main() 
{
    int m,n,c,e;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&c,&e);
        p1=insertatend(p1,c,e);
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&c,&e);
        p2=insertatend(p2,c,e);
    }
    printf("\nFirst polynomial is:");
    display(p1);
    printf("\n");
    printf("\nSecond polynomial is:");
    display(p2);
    printf("\n");
    printf("\nThe sum Polynomial is:");
    p3=add();
    display(p3);
    return 0;
}

