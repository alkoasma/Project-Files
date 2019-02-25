#include <stdio.h>
#include <stdlib.h>


#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H


/* Node in a singly linked list */
struct SLnode {
int key ;
struct SLnode *next ; /* pointer to the next item in a list */
};
typedef struct SLnode * SLnodePtr ;

/* Node in the "horizontal" list */
struct HBnode {
int key ;
struct HBnode * next; /* pointer to the next item in the
horizontal list */
SLnodePtr bottom ; /* pointer to the bottom list */
};
typedef struct HBnode *HBnodePtr;

typedef struct HBnode * HBnodePtr ;
HBnodePtr createHBlist ( int n , int m ) ;
SLnodePtr flattenList ( const HBnodePtr L ) ;
void freeSLlist ( SLnodePtr L ) ;
void freeHBlist ( HBnodePtr L ) ;
void printHBlist ( const HBnodePtr L ) ;
void printSLlist ( const SLnodePtr L ) ;
#endif /* ASSIGNMENT3_H */

static int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

HBnodePtr createHBlist (int n , int m){
    HBnodePtr new_node, first = NULL;
    SLnodePtr down = NULL;
    if (n == 0){
        new_node = NULL;
        return new_node; 
    }
    
    int i, j, k, c=0, size;
    if (m == 0)
        size = n;
    else    
        size = m*n;

    int a[size];
    for (i = 0; i < size; i++)
        a[i] = rand()%1000;
    qsort(a, size, sizeof(int), cmpfunc);
    for (i = 0; i < size; i++)
        printf("%d\n",a[i]); 

    for(i = 1; i <= n; i++){
        k = (rand() % (m + 1)); 
        new_node = (HBnodePtr)malloc(sizeof(struct HBnode));
        new_node -> key = a[size-k-1-c];  // Check if rand is correct?
        new_node -> next = first;
        first = new_node;
        printf("This is K = %d", k);
        printf("Value of the top node: %d\n", new_node -> key);
        printf("Value of the bottom nodes are:\n");
        for (j = 0; j < k; j++){  // Check how to randomize between range 0 to n
            new_node -> bottom = (SLnodePtr)malloc(sizeof(struct SLnode)); 
            if (k > 0)
                new_node -> bottom -> key = a[size-1-c];  // Check if rand is correct?
            else
                new_node -> bottom = NULL;
            new_node -> bottom -> next = down;  // Check if down or not.
            down = new_node -> bottom;   
                printf("%d\n", new_node -> bottom -> key);
            c=c+1;
            }
        down = NULL;
        c=c+1;
        }
    printf("\n\n");
    return new_node; 

}


// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
static void append(SLnodePtr *head_ref, int new_data) 
{ 
    /* 1. allocate node */
    SLnodePtr new_node = (SLnodePtr)malloc(sizeof(struct SLnode));
  
    SLnodePtr last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->key  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next  
          of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
   
    /* 6. Change the next of last node */
    last->next = new_node; 
    return;     
}



SLnodePtr flattenList (const HBnodePtr L){
    HBnodePtr top = NULL;
    SLnodePtr below = NULL, SLlist = NULL;
    top = L;
    while(top != NULL){
        append(&SLlist, top -> key);
        printf("This is top key %d\n", top -> key);
        if (top -> bottom != NULL){
            append(&SLlist, top -> bottom -> key);
            printf("This is topbottom key %d\n", top -> bottom -> key);
            below = top -> bottom -> next; 
            while(below != NULL){
                append(&SLlist, below -> key);
                printf("This is below key %d\n", below -> key);
                below = below -> next;

            }
        }
        top = top -> next; 
        
    }
    // SLlist -> next = NULL; CHECK
    return SLlist; //Check if this is right in relation to pointer!!

}
//Find out why gdb is giving line 111 as wrong!!


void freeSLlist(SLnodePtr left)
{
   
   SLnodePtr pointer;
   while (left != NULL)
    {
       
       pointer = left;
       left = left -> next;
       free(pointer);
    }
    

}


void freeHBlist(HBnodePtr top)
{
   
   HBnodePtr horizontal;
   while (top != NULL)
    {
       
       horizontal = top;
       freeSLlist(top -> bottom);
       top = top -> next; 
       free(horizontal);
    }

}



void printHBlist(const HBnodePtr L){
    HBnodePtr top = NULL;
    SLnodePtr below = NULL;
    top = L;
    while(top != NULL){
        printf("This is top key %d\n", top -> key);
        if (top -> bottom != NULL){
            printf("%d\n", top -> bottom -> key);
            below = top -> bottom -> next;
            while(below != NULL){
                printf("this is next SL key %d\n", below -> key);
                below = below -> next;
            }
            printf("This is end\n");
        }
        top = top -> next; 
        
    }

}

void printSLlist(const SLnodePtr L){

    SLnodePtr value = NULL;
    value = L;
    while (value != NULL){
        printf("%d\n", value -> key);
        value = value -> next;}
}






#include <stdio.h>

int main ()
    {
    int n = 5, m = 8;
    HBnodePtr L = createHBlist (n , m ) ;
    printf ( "HB list\n " ) ;
    printHBlist ( L ) ;
    printf ( "\n" ) ;
    printf ( "SLlist\n" ) ;
    SLnodePtr P = flattenList ( L ) ;
    printSLlist ( P ) ;
    printf ( "\n" ) ;
    freeSLlist ( P ) ;
    freeHBlist ( L ) ;
    return 0;
}




