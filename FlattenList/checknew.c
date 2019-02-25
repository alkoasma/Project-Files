#include <stdio.h>
#include <stdlib.h>

    /* Node in a singly linked list */
    struct SLnode {
        int key ;
        struct SLnode *next ; /* pointer to the next item in a list */
    };
    typedef struct SLnode *SLnodePtr ;

    /* Node in the "horizontal" list */
    struct HBnode {
        int key ;
        struct HBnode *next; /* pointer to the next item in the
        horizontal list */
        SLnodePtr bottom ; /* pointer to the bottom list */
    };
    typedef struct HBnode *HBnodePtr;
    
int main(){
    int i,j,n,m;
    int A[9] = {1,2,3,4,5,6,7,8,9};



    for(i = 0; i < 3; i++){
        HBnodePtr = malloc(sizeof(struct node));
        HBnode -> key = A[i];  // Check if rand is correct? //
        HBnode -> next = HBnode;  // Points to the beginning of the list
        SLnodePtr = HBnode; // Makes the begining at the new node added
        SLnodePtr = HBnode; // Points a vector down to the new_node
        for (j = 0; j < 3; j++){  // Check how to randomize between range 0 to n//
            HBnode = malloc(sizeof(struct node));
            HBnode -> key = A[i+j+1];  // Check if rand is correct? //
            SLnodePtr -> bottom = HBnode;  // Bottom of the new_node = new node already created
            SLnodePtr = HBnode;  // Check if down or first //  //Updates value to the one added at the bottom
        }
    }
}