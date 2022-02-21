// INSERT AT A GIVEN POSITION

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head=NULL;

void insertAtPos(int pos,int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL) 
        head=newnode;
    else if(pos==1) 
    {
        newnode->next=head;
        head=newnode;
    }
    else 
    {
        struct node *p=head;
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
    }
}

void display()
{
 struct node *temp=head;
    while(temp->next)  
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main() 
{
      int no_nodes,i;
    scanf("%d",&no_nodes);
    for(i=1;i<=no_nodes;i++)
    {
    int x,pos;
        scanf("%d %d",&pos,&x);
        insertAtPos(pos,x);
    }
    display();
    return 0;
}

