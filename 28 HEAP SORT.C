// HEAP SORT

/*
Input Format

First line an integer N
Second line N integers

Output Format

Print the array after sorting

Sample Input 0

5
4 8 1 3 7
Sample Output 0

1 3 4 7 8
*/

 #include <stdio.h>
  
  // Function to swap the the position of two elements
  void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  //**************************************
  void heapify(int arr[], int n, int i)
   {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) 
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  //**************************************
  void heapSort(int arr[], int n) 
  {
      int i;
    // Build max heap
    for (i=n/2-1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (i=n-1; i >= 0; i--) 
    {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  //**************************************
  // Print an array
  void printArray(int arr[], int n) 
  {
      int i;
    for (i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
//**************************************
  int main() 
  {
    int arr[100],n,i;
      scanf("%d",&n);
      for(i=0;i<n;i++)
          scanf("%d",&arr[i]);
      
     
    heapSort(arr, n);
  
    //printf("Sorted array is \n");
    printArray(arr, n);
  }
