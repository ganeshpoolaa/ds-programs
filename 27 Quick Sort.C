//DSOE 8A: Quick Sort
/*
Input Format

First line contains an integer T(1 <= T <= 100), denoting the number of test cases

First line of each test case contains an integer N(1 <= N <= 100000), denoting the size of the array

Second line contains N space separated integers, denoting the array elements Ai(1 <= Ai <= 1000000000)

Output Format

For each test case, print the sorted array

Sample Input 0

2
5
4 8 1 3 7
7
1 4 2 6 5 3 8
Sample Output 0

1 3 4 7 8
1 2 3 4 5 6 8
*/

/*PROGRAM FOR QUICK SORT WITH RECURSION*/

#include<stdio.h>

int qsort(int arr[],int left,int right);

int main()
{
int arr[10],i,n,cases,j;
scanf("%d",&cases);
for(j=1;j<=cases;j++)
{
//printf("\n Enter the elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
//printf("\n Numbers before sort");
//for(i=0;i<n;i++)
//printf("%4d",arr[i]);
qsort(arr,0,n-1);
//printf("\n Numbers after sort");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
printf("\n");
}
}

int qsort(int arr[],int left,int right)  
{
int i,j,p,temp;

if(left<right)
{
i=left;
j=right;
p=left;
while(i<j)
{
 while((arr[i]<=arr[p])&&(i<right))
 i++;
 while(arr[j]>arr[p])
 j--;
if(i<j)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}//while close


temp=arr[p];
arr[p]=arr[j];
arr[j]=temp;

qsort(arr,left,j-1);
qsort(arr,j+1,right);
}
    return 0;
}




