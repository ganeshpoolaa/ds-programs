//DSOE 4 A4 : Circular Linked List Operations

/*
Circular linked list is a linear data structure same as linked list except last node is points to first node Your task is to implement the following five operations to CLL:

insert at begin
insert at end
delete at begin
delete at end
display
Note: From 1 to 4 functions must have an O(1) running time complexity.

Input Format

First line an integer N

Next N lines each line contain one operation each:1 X denotes insert X value at begin, 2 X denotes insert X value at end,3 denotes delete at begin, 4 denotes delete at end and 5 denotes display the list elements

Constraints

1<= N <= 20

Output Format

Display the Circular Linked List elements every time for every 5 type operation and if you are unable to delete the element print “Invalid” without double codes

Sample Input 0

12
5
1 10
2 20
1 30
5
4
5
3
4
3
4
5
Sample Output 0

Empty
->30->10->20->
->30->10->
Invalid
Invalid
Empty

*/

//DSOE 4 A4 : Circular Linked List Operations

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

