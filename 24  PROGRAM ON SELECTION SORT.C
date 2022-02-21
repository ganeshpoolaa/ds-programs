// PROGRAM ON SELECTION SORT

/*

Sample Input 
5
4 8 1 3 7
Sample Output 

1 3 4 7 8

*/


#include<stdio.h>
#define MAXSIZE 500

void ssort(int elements[], int maxsize);
int arr[MAXSIZE],n;

int main()
{
int i;
//printf("\nHow many arr you want to sort: ");
scanf("%d",&n);
//printf("\nEnter the values one by one: ");
for (i = 0; i<n; i++)
{
//printf ("\nEnter element %i :",i);
scanf("%d",&arr[i]);
}

//calling selection sort
ssort(arr, n);

//printf("\nArray after sorting:\n");
for (i = 0; i <n; i++)
printf("%d ", arr[i]);

return 0;
}

// selection sort definition
void ssort(int arr[], int array_size)
{
int i, j, k;
int min, temp;
for(i=0; i<n-1; i++)
{
min=i;
for(j=i+1; j<n; j++)
{
if(arr[j]<arr[min])
min=j;
}
temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
}
}

