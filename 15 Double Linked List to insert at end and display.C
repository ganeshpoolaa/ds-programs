//DSOE 4 A1 : Double Linked List to insert at end and display

/*
Input Format

Two Lines - Line 1: Length of the Double Linked List N - Line 2: N integers

Output Format

Display the Double Linked List

Sample Input 0

5
10 20 30 40 50
Sample Output 0

10<==>20<==>30<==>40<==>50

*/



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


void insertatend(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=tail=newnode;
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
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
            printf("%d<==>",temp->data);
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
        insertatend(x);
    }
    display();
    return 0;
}
