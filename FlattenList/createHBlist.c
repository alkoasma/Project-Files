#include <stdio.h>
#include <stdlib.h>

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

static int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

HBnodePtr createHBlist (int n , int m){
    HBnodePtr new_node, first;
    SLnodePtr down;
    
    int i, j, k, c=0;

    int a[m*n];
    for (i = 0; i < m*n; i++)
        a[i] = rand();
    qsort(a, m*n, sizeof(int), cmpfunc);
    for (i = 0; i < m*n; i++)
        printf("%d\n",a[i]); 

    for(i = 1; i <= n; i++){
        k = (rand() % (m + 1)); 
        new_node = (HBnodePtr)malloc(sizeof(struct HBnode));
        new_node -> key = a[n*m-k-1-c];  // Check if rand is correct?
        new_node -> next = first;
        first = new_node;
        printf("This is K = %d", k);
        printf("Value of the top node: %d\n", new_node -> key);
        printf("Value of the bottom nodes are:\n");
        for (j = 1; j < k+1; j++){  // Check how to randomize between range 0 to n
            new_node -> bottom = (SLnodePtr)malloc(sizeof(struct SLnode)); 
            if (k > 1)
                new_node -> bottom -> key = a[n*m-1-c];  // Check if rand is correct?
            else
                new_node -> bottom = NULL;
            new_node -> bottom -> next = down;  // Check if down or not. 
            down = new_node -> bottom;   
                printf("%d\n", new_node -> bottom -> key);
            c=c+1;
            }
        c=c+1;
        }

    return new_node; 

}

// Check how Null values are incorporated!!!


