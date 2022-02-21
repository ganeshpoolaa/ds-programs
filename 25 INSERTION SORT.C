// INSERTION SORT
/*
Sample Input 0

5
4 8 1 3 7
Sample Output 0

1 3 4 7 8
*/


#include <stdio.h>  
void inssort(int arr[10],int n);

    int main()
    {
    int arr[10],i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    
// CALLING INSERTION SORT
    inssort(arr,n);

    for(i=0;i<n;i++)
    printf("%d ",arr[i]);

    return 0;
    }
    
//***************************************
void inssort(int arr[10],int n)
    {
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
 /* Move elements of arr[0..i-1], that are greater than key, to one 
 position ahead  of their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    } // for loop end
}
  
