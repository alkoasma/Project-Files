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
    struct HBnode * next; /* pointer to the next item in the horizontal list */

    SLnodePtr bottom ; /* pointer to the bottom list */
    };
    typedef struct HBnode *HBnodePtr;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
    
int main(){
    
    int distance, max, min, anyRandom, x, value;

    HBnodePtr first, new_node;
    SLnodePtr down;

    int i, j, m=8,n = 11, a[m*n], k=0;

    for (i = 0; i < n+(m*n); i++)
        a[i] = rand();
    
    qsort(a, m*n, sizeof(int), cmpfunc);

    for (i = 0; i < n+(m*n); i++)
        printf("Value %d = %d\n", i, a[i]);


    for(i = 1; i <= n; i++){
        new_node = (HBnodePtr)malloc(sizeof(struct HBnode));
        new_node -> key = a[k+n+(m*n)-1];  // Check if rand is correct?
        k--;
        new_node -> next = first;
        first = new_node;


        printf("Value of the top node: %d\n", new_node -> key);
        printf("Value of the bottom nodes are:\n");
        if (m > n){
            max = m;
            min = n;}
        else if(m = n){
            min = m - 1;
            max = n;
        }
         else{
            max = n;
            min = m;}
          
 
        int range, result, cutoff;
        range = max-min+1;
        cutoff = (rand()%(max-min))+min;

        for (j = 1; j <= cutoff; j++){  // Check how to randomize between range 0 to n    
            new_node -> bottom = (SLnodePtr)malloc(sizeof(struct SLnode));
            new_node -> bottom -> key = a[k+n+(m*n)-1];  // Check if rand is correct?
            k--;
            new_node -> bottom -> next = down;
            down = new_node -> bottom;
            printf("%d\n", new_node -> bottom -> key);
        }
    }

}


