#include <stdio.h>
#include <stdlib.h>

void genmatrix (int n , double A []){ 
    int r=0;
    int i; 
    for(i=0; i<(n*n); i++){
        A[r]=rand();
        r = r + 1;
    }
}

void genvector (int n , double b []){ 
    int r=0;
    int i;
    for(i=0; i<(n); i++){
        b[r]=rand();
        r = r + 1;
    }
}
