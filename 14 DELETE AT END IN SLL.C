//DELETE AT END IN SLL

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head;


void insertAtEnd(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL) 
        head=newnode;
    else 
    {
        struct node *p=head;
        while(p->next)
            p=p->next;
        p->next=newnode;
    }
}

//********************************
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


//********************************
void deleteAtEnd()
{
    struct node *temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    struct node *p=temp->next;
    temp->next=NULL;
    free(p);
}


int main() 
{
    int no_nodes,i;
    scanf("%d",&no_nodes);
    for(i=1;i<=no_nodes;i++)
    {
        int x;
        scanf("%d",&x);
        insertAtEnd(x);
    }
    int d;
    scanf("%d",&d);
    while(d--)
    {
        deleteAtEnd();
    }
    display();
    return 0;
}

