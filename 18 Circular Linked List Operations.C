
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;

void insertatbegin(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=tail=newnode;
    else{
        newnode->next=head;
        head=newnode;
        tail->next=head;
    }
}

void insertatend(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=tail=newnode;
    else
    {
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}


void deleteatbegin()
{
    if(head==NULL)
        printf("Invalid\n");
    else if(head->next==head)
    {
        struct node *temp=head;
        head=tail=NULL;
        free(temp);
    }
    else 
    {
        struct node *temp=head;
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        free(temp);
    }
}

void deleteatend()
{
    if(head==NULL)
        printf("Invalid\n");
    else if(head->next==head)
    {
        struct node *temp=head;
        head=tail=NULL;
        free(temp);
    }
    else 
    {
        struct node *x=head;
        struct node *temp=tail;
        while(x->next!=tail)
            x=x->next;
        tail=x;
        tail->next=head;
        temp->next=NULL;
        free(temp);
    }
}

void display()
{
    if(head==NULL)
        printf("Empty\n");
    else 
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
        printf("->%d->\n",temp->data);
    }
}


int main() 
{

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int ch,v;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                scanf("%d",&v);
                insertatbegin(v);
                break;
            case 2:
                scanf("%d",&v);
                insertatend(v);
                break;
            case 3:
                deleteatbegin();
                break;
            case 4:
                deleteatend();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid\n");
         }
    }
    return 0;
}
