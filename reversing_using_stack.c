/*
*   Reversing a string or linked list using the stack
*   Recursive and Iterative method
*   Author: Zachary Clark-Williams
*   date last revised: 09/09/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    unsigned Capacity;
    int Top;
    int* Array;
};

bool isFull (struct Stack* stack){ // full if index of top = capcity size
    return stack->Top == stack->Capacity -1;
};

bool IsEmpty(struct Stack* stack){
    return stack->Top == -1; // stack is empty when top => -1
};

void Push(struct Stack* stack, int item){
    if(isFull(stack)){ // check to see if the stack is already full
        printf("Stack full."); // full notify user and return
        return;
    }
    stack->Array[++stack->Top] = item; // push item to top of stack array
    //printf("%d pushed to stack \r\n", item);
};

int Pop(struct Stack* stack){
    if(IsEmpty(stack))
        return 0;
    // return the array indexed value then dec. index Top
    return stack->Array[stack->Top--];
};

struct Stack* CreateStack(unsigned capacity){

    // allocate the memory for the stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    
    // assign the capcity of the stack
    stack->Capacity = capacity;

    // set the index of the top of the stack to -1 (empty)
    stack->Top = -1;

    // set the size of the array of the stack to be capcity of int sized registers
    stack->Array = (int*)malloc(stack->Capacity * sizeof(int));

};

// Need a function that can get the length of a char array without using std string library
int StrSize(char *str){
    return ( (*str) ? StrSize(++str)+1 : 0);
};

char *ReverseString(char *str){
    // get the length of the string
    int n = StrSize(str);

    // create the stack to match length of the string
    struct Stack* stack = CreateStack(n);

    // push the string onto the stack
    for(int i=0; i<n ; i++){
        Push(stack, str[i]);
    }

    // pop the stack to an array, now backwards
    for(int j=0; j<n; j++){
        str[j] = Pop(stack);
    }

    // free up the stack allocated memory
    free(stack);

    // return backwards string
    return str;
}
char *GetString(){
    unsigned int max_len = 128;
    unsigned int curr_size = max_len;

    // allocate memory for max length size for char array
    char *str = malloc(max_len);

    // clean the output window
    fflush(stdin); 
    
    printf("Enter String: ");

    // get the input of length buff => 4096
    //fgets(buff, sizeof(buff), stdin); // not so great, too long. Need dynamic allocation.

    if(str != NULL){
        int c = EOF; // end of file == -1
        unsigned int i = 0;

        // accept user input till hit enter or reach eof
        while((c = getchar()) != '\n' && c != EOF){
            str[i++] = (char)c;
            
            // if i reaches max_length of buffer reallocate size
            if(i == curr_size){
                curr_size = i+max_len; // add one to the memory size
                str = realloc(str, curr_size); // reallocate the memory to fit larger size
            }
        }
    }
    // return point to the buff
    return str;
};

void PrintStr(char *str){
    // get the length of the string to print
    int n = StrSize(str);

    // put a new line before
    printf("\r\n");

    // cycle through the array string to print char's
    for(int i=0; i<n; i++){
        printf("%c", str[i]);
    }

    // put a new line after
    printf("\r\n");
};

int main(int argc, char** argv){
    char *str;
    
    // get user string
    str = GetString();

    // print normal string
    PrintStr(str);

    // reverse the users string
    str = ReverseString(str);

    // print reversed string
    PrintStr(str);

    // free the memory allocated for the string buffer
    free(str);

    return 0;
}