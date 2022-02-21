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
    printf("First polynomial is:");
    display(p1);
    
    printf("\nSecond polynomial is:");
    display(p2);
    
    printf("\nThe sum Polynomial is:");
    p3=add();
    display(p3);
    return 0;
}
