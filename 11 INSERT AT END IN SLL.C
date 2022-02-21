//INSERT AT END IN SLL

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head=NULL;

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
        while(p->next!=NULL)//while(p->next)
        {
            p=p->next;
        }
        p->next=newnode;
    } // else end
} 

//******************************************
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
        int x;
        scanf("%d",&x);
        insertAtEnd(x);
    }
    display();
    return 0;
}

