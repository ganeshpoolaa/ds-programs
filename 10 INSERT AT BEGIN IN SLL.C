// INSERT AT BEGIN IN SLL
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head=NULL;

void insertAtBegin(int x)
{
    //Preparing a node 
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL) //case 1: there are no nodes in LL
        head=newnode;
    else // case 2: there are more nodes in LL
    {
        newnode->next=head;
        head=newnode;
    }
}

//**********************************************
void display()
{
 struct node *temp=head;
    while(temp!=NULL)  //while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main() 
{
    int no_nodes,i;
    scanf("%d",&no_nodes);
    for(i=1;i<=no_nodes;i++)
    {
        int x;
        scanf("%d",&x);
        insertAtBegin(x);
    }
    display();
    return 0;
}

