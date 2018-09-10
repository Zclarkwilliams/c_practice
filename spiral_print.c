/*
*   Spiral print a 2d array
*   Author: Zachary Clark-Williams
*   date last revised: 09/08/18
*/

#include <stdio.h>

void SpiralPrint(int *A[], int m, int n){
    int t_row = 0;      // top most row boundary to follow
    int b_row = m-1;    // bottom most row
    int l_col = 0;      // left most column boundary to follow
    int r_col = n -1;   // right most column 
    int dir = 0;        // travel direction: 0 right, 1 down, 2 left, 3 up

    while (t_row <= b_row && l_col <= r_col){
        if (dir == 0){ // travel left -> right
            for(int i=l_col; i<r_col; i++){
                printf((*(A + t_row) + i));
            }
            t_row--;    // consolidate the boundary of the top row
            dir++;      // change the direction to going down
        }
        else if (dir == 1){ // travel top -> bottom
            for(int i=t_row; i<b_row; i++){
                printf((*(A + i) + r_col));
            }
            r_col--;    // consolidate the boundary of the right column
            dir++;      // change the direction to going left
        }
        else if (dir == 2){ // travel left <- right
            for(int i=r_col; i<l_col; i--){
                printf((*(A + b_row) + i));
            }
            b_row--;    // consolidate the boundary of the bottom row
            dir++;      // change the direction to going up
        }
        else if (dir == 1){ // travel top <- bottom
            for(int i=b_row; i<t_row; i--){
                printf((*(A + i) + l_col));
            }
            l_col--;    // consolidate the boundary of the left column
            dir = 0;      // change the direction to going right again
        }
        else{   // should never reach this point
            printf("ERROR: direction out of bounds on print.");
            return;
        }
    }
    return;
}

int main(int argc, char** argv){
    
    const int DEPTH = 3;
    const int HEIGHT = 3;

    //int *arry;
    int m, n;
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    //arry = A;

    m = HEIGHT;
    n = DEPTH;

    SpiralPrint((int *)A, m, n);
    return 0;
}