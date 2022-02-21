//DSOE 4 A2 : Double Linked List Operations

/*
Input Format

First line an integer N

Next N lines each line contain one operation each:1 X denotes insert X value
 at begin, 2 X denotes insert X value at end,3 denotes delete at begin, 
 4 denotes delete at end,5 P X denotes insert X value in P position and 
 6 denotes display the list elements

Output Format

Display the Double Linked List elements every time for every 6 type operation if elements presents otherwise print "Empty" and if you are unable to delete or insert the element then print "Invalid".

Sample Input 0

10
1 10
2 20
6
1 30
5 2 40
6
2 50
3
4
6
Sample Output 0

10<==>20
30<==>40<==>10<==>20
40<==>10<==>20

*/



//DSOE 4 A2 : Double Linked List Operations

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

void deleteatend()
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
        struct node *temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
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
        int ch,v,p;
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
                scanf("%d %d",&p,&v);
                insertatpos(p,v);
                break;
            case 6:
                display();
                break;
            default:
                printf("Invalid\n");
                
        }
    }
    return 0;
}


