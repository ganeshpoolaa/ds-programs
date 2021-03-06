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
void insertatbeg(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=tail=newnode;
    else{
        newnode->next=head;
        newnode->prev=tail;
        head=newnode;
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
            printf("%d ",temp->data);
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
        int x;
        scanf("%d",&x);
        insertatbeg(x);
    }
    display();
    return 0;
}
