/*
*   Search for a number in a circularly sorted list
*   This is achieved through a binary tree search algorithm
*   Author: Zachary Clark-Williams
*   date last revised: 09/07/18
*/

#include <stdio.h>

int SearchFor(int A[], int n, int x){
    int low = 0;
    int high = n-1;
    int mid;

    while(low <= high){
        mid = (low+high)/2;

        if(x == A[mid])                 // Case : Found x!
            return mid;
        if (A[mid] <= A[high]){         // Case : right half is sorted
            if (x > A[mid] && x <= A[high])
                low = mid + 1;  // search right half
            else
                high = mid - 1; // search left half
        }
        else{                           // Case : left half is sorted
            if (A[low] <= x && x < A[mid])
                high = mid - 1; // search left half
            else
                low = mid + 1; // search right half
        }
    }
    return -1;
}


int main (int argc, char** argv){
    int A[] = {5,6,7,8,9,10,11,1,2,3,4};
    int B[] = {1,2,3,4,5,6,7,8,9,10,11};
    
    int x = 0;
    char arry = 'N';

    printf("Please enter a number and list A or B: ");
    scanf("%d %c", &x, &arry);

    int idx;

    switch(arry){
        case 'A': 
            printf("Chose array A, which is circularly sorted");
            idx = SearchFor(A, sizeof(A), x);
            break;
        case 'B': 
            printf("Chose array B, which is NOT circularly sorted");
            idx = SearchFor(B, sizeof(B), x);
            break;
        default: printf("ERROR: Invalid entry!");  
            return -1;
    }

    if (idx < 0)
        printf("\r\nNumber not found in list.");
    else
        printf("\r\nNumber found at index %d", idx);

    return 0;
}