//Implementing queues using  singly list lists
#include<stdio.h>
#include <stdlib.h>
#define EC -1
 struct Node
{
    int n;
    struct Node *pNext;
};
struct Node *front=NULL,*rear=NULL;

int empty(void)
    {
        if(front==NULL&&rear==NULL)
            return 1;
        else
            return 0;
    }
int front_val(void)
  {
        return front->n;
 }
int rear_val(void){
        return rear->n;
 }
void Enqueue(int x)
{
   struct  Node *Temp;
    Temp=(struct Node*)malloc(sizeof(struct Node));
    if(front==NULL)
    {
        front=Temp;
        Temp->n=x;
        Temp->pNext=NULL;
        rear=Temp;
        return;
    }
    if(rear!=NULL)
        rear->pNext=Temp;
    Temp->n=x;
    Temp->pNext=NULL;
    rear=Temp;
    
}
int Dequeue(void)
{
    if(front==NULL)
    {
        //cout<<"Queue is empty!"<<endl;
        return EC;
    }
    int ans=front->n;
   struct Node *temp=front;
    front=front->pNext;
    //delete temp;
    return ans;
}

int main()
{
    int ch,k;
    int t;
   // cin >> t;
    scanf("%d",&t);
    while(t--)
    {
        //cout<<"select 1.Enqueue 2.Dequeue 3.Display 4.Exit"<<endl;
        //cin>>ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
             //   cout<<"enter element to be enqueued-";
                //cin>>k;
                scanf("%d",&k);
                Enqueue(k);
                // if(m==EC)
                //     cout<<"Enqueuing error"<<endl;
                // else
                //     cout<<"Enqueued successfully"<<endl;
                break;
            case 2:
                if(empty()){
                    //cout << "invalid" << endl;
                    printf("invalid\n");
                }
                else
                    Dequeue();
                // if(m==EC)
                // {
                //     cout<<"Dequeuing error"<<endl;
                // }
                // else
                //     cout<<"m="<<m;
                break;
            case 3:
                // cout<<"The queue is-\n";
                // Q1.Display();
               // int var=front_val();
                if(empty())
                   printf("invalid\n");
                else
                    printf("%d\n",front_val());
                break;
            case 4:
                //int var=rear_val();
                if( empty())
                    printf("invalid\n" );
                else
                    printf("%d\n",rear_val());
                break;
            case 5:
                printf("%d\n",empty());
                break;
            default:
                printf("invalid\n");
                break;
        }
    }
    return 0;
}
