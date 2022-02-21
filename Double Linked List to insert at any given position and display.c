#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
void insertatbegin(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=tail=newnode;
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertatpos(int pos,int x)
{
    if(pos<1)
        printf("Invalid\n");
    else if(pos==1)
    {
        insertatbegin(x);
    }
    else if(head==NULL && pos>1)
    {
        printf("Invalid\n");
        return;
    }
    else 
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->prev=NULL;
        newnode->data=x;
        newnode->next=NULL;
        struct node *x=head;
        int i;
        for(i=1;i<=pos-2;i++)
        {
           if(x!=NULL)
               x=x->next;
            else 
            {
                printf("Invalid\n");
                return;
            }
        }
        struct node *y=x->next;
        x->next=newnode;
        newnode->prev=x;
        newnode->next=y;
        if(y!=NULL)
            y->prev=newnode;
    }
}
void display()
{
    if(head==NULL)
        printf("Empty\n");
    else 
    {
        struct node *temp=head;
        while(temp->next)
        {
            printf("%d<=>",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main() 
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int v,p;
        scanf("%d %d",&p,&v);
        insertatpos(p,v);
    }
    display();
    return 0;
}
