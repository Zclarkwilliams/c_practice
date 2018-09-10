/*
*   Counting the number of occurances of a number in a sorted list
*   This is achieved through a binary tree search algorithm
*   Author: Zachary Clark-Williams
*   date last revised: 09/07/18
*/


#include <stdio.h>
#include <stdbool.h>

int BinarySearch(int A[], int n, int x, bool searchFirst)
{
    int result;
    int low_idx  = 0;
    int high_idx = n-1;

    while(low_idx <= high_idx){
        //set the middle of the entered list to root
        int mid = (low_idx+high_idx)/2;

        if (A[mid] == x){
            result = mid;
            if (searchFirst) 
                high_idx = mid-1;   // for finding the high index of a number in a list
            else 
                low_idx = mid+1; // for finding the low index of a number in a list
        }
        else if (x < A[mid]) 
            high_idx = mid-1; // x is now less than the mid point so set high index to midpoint... shrink list in half
        else 
            low_idx = mid+1; //increase lower index as we step up the list 
    }
    return(result);
}

int main(int argc, char** argv)
{
    int A[] = {1,1,3,3,5,5,5,5,5,9,9,11};
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    int firstIndex = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, true);
    if (firstIndex == -1){
        printf("Count of %d is %d", x, 0);
    }
    else{
        int lastIndex = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, false);
        printf("Count of %d is %d \r\nStarting at %d and ending at %d", x, lastIndex - firstIndex + 1, firstIndex, lastIndex);
    }
    return 0;
}