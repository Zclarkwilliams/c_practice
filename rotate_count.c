/*
*   Finding the number of times a sorted list is rotated
*   This is achieved through a binary tree search algorithm
*   Author: Zachary Clark-Williams
*   date last revised: 09/07/18
*/

#include <stdio.h>


int FindRotateCount(int A[], int n){
    
    int low = 0;
    int mid, next, prev;
    int high = n-1;

    while(low<=high){
        if (A[low] <= A[high]) return low; // this means there is only 1 element in the array

        // set positional pointers/trackers
        mid = (low+high)/2;
        next = (mid+1)%n;
        prev = (mid+n-1)%n;

        if (A[mid] <= A[next] && A[mid] <= A[prev]) //Case: reached start of sorted list aka lowest entry
            return mid;
        else if (A[mid] <= A[high])
            high = mid - 1;
        else if (A[mid] >= A[low])
            low = mid + 1;
    }
    return -1;
}

int main (int argc, char** argv){
    int A[] = {5,6,7,8,9,10,11,1,2,3,4};
    int B[] = {1,2,3,4,5,6,7,8,9,10,11};
    int count = FindRotateCount(B, 11);
    printf("This list has been rotated %d times", count);
    return 0;
}