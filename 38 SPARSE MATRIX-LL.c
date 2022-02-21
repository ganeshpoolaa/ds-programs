//Sparse Matrix representation using singly Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
int rows, cols, value;
struct list *next;
}list;

// CREATE FUNCTION

list *create()
{
list *temp = (list *)malloc(sizeof(list));
if(temp==NULL)
{
printf("Unable to allot Memory");
exit(1);
}
return temp;
}

// CREATING NODE AND ADJUSTING VALUES

list *makenode(int r, int c, int val)
{
list *temp = create();
temp->rows = r;
temp->cols = c;
temp->value = val;
temp->next = NULL;
printf("\n in makenode temp=%u",temp);
return temp;
}

//INSERTING VALUES

list *insert(list *head, int r, int c, int val)
{
list *ptr, *temp = head;
if(head == NULL)
head = makenode(r,c,val);
else
{
while(temp->next != NULL)
temp = temp->next;
ptr = makenode(r,c,val);
printf("\n in insert temp=%u",temp);
printf("\n in insert ptr=%u",ptr);
temp->next = ptr;
}
return head;
}

//DISPLAY NODE VALUES

void display(list *head)
{
list *temp;
if(head == NULL)
{
printf("List is empty");
exit(1);
}
temp = head;
while(temp != NULL)
{
printf("[%d,%d,%d->]->",temp->rows,temp->cols,temp->value);
temp = temp->next;
}
}


int main()
{
int arr[3][4],i,j,m,n,nonzero_count=0;
list *head = NULL;
for(i=0; i<3; i++)
{
printf("\n Enter 4 values for row %d:", i+1);
for(j=0;j<4;j++)
{
scanf("%d",&arr[i][j]);
if(arr[i][j] != 0)
nonzero_count++;
}
}

head = makenode(3,4,nonzero_count);
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{ 
if(arr[i][j] != 0) 
head = insert(head,i,j,arr[i][j]); 
} 
} 
printf("\n List representation of Sparse Matrix is:"); 
printf("\n Row Number, Column Number, Value  of node"); 
display(head); 
getch(); 
}
