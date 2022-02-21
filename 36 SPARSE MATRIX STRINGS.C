//Sparse Arrays

/*

Problem Statement :

There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

Example:
strings=['ab', 'ab', 'abc']
queries=['ab', 'abc', 'bc']

There are  instances of 'ab', 1 of 'abc' and 0 of 'bc'. For each query, add an element to the return array, results=[2,1,0].


Function Description:

Complete the function matchingStrings in the editor below. The function must return an array of integers representing the frequency of occurrence of each query string in strings.

matchingStrings has the following parameters:

   1. string strings[n] - an array of strings to search
   2. string queries[q] - an array of query strings

Returns:
     1. int[q]: an array of results for each query


Input Format:

The first line contains and integer n, the size of strings[].
Each of the next n lines contains a string strings[i].
The next line contains q, the size of queries[].
Each of the next q lines contains a string queries[i].
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char A[1000][20],B[20];
    int N,i,Q,ans;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%s",A[i]);
    scanf("%d",&Q);
    while(Q--)
    {
        ans=0;
        scanf("%s",B);
        for(i=0;i<N;i++)
        {
            if(strcmp(B,A[i])==0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


