//DSOE 4 A3 : Double Linked List to delete at any position

/*
Given an integer N followed by N integers to insert into the double linked list at the end, followed by another integer K denoting the number of elements to be deleted any given positions, perform the insertion and deletion and print the remaining list Given positions are may not be valid positions Note: If deleted input position is invalid position then print "Invalid" without double codes

Input Format

Four lines: - Line 1: an integer N denoting the size of the list - Line 2: N integers to be inserted to the end of the list - Line 3: an integer K denoting the number of elements to be deleted - Line 4: K integers denoting the positions has to be deleted

Output Format

Display the remaining elements of the Double Linked List after deletion

Sample Input 0

6
10 20 30 40 50 60
3
3 1 4
Sample Output 0

20<=>40<=>50

*/



//DSOE 4 A3 : Double Linked List to delete at any position

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


void deleteatbegin()
{
    if(head==NULL)
        printf("Invalid\n");
    else if(head->next==NULL)
    {
        struct node *temp=head;
        head=tail=NULL;
        free(temp);
    }
    else 
    {
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}


void deleteatpos(int pos)
{
    if(pos<1)
        printf("Invalid\n");
    else if(head==NULL && pos>=1)
    {
        printf("Invalid\n");
        return;
    }
    else if(pos==1)
    {
        deleteatbegin();
    }
    else 
    {
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
        struct node *temp=x->next;
        struct node *y=temp->next;
        x->next=y;
        if(y!=NULL)
            y->prev=x;
        temp->prev=NULL;
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
        int x;
        scanf("%d",&x);
        insertatend(x);
    }
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int pos;
        scanf("%d",&pos);
        deleteatpos(pos);
    }
    display();
    return 0;
}


