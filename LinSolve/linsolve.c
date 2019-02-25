#include <math.h>
#include <stdio.h>

int linsolve ( int n , double A [] , double b [] , double x []){
    
    int p, r, c;
    double div;

    for (int p=0; p <= n-1; p++){ // Moves pivot
        for(int r = p+1; r <= n-1; r++){ // Changes rows
            div = A[r*n+p]/A[p*n+p];
            for (int c = 0; c<n; c++){ // Changes couloums
               A[r*n+c+p] = A[r*n+p+c] - A[p*n+p+c]*div;
               if ((r*n+c+p) > (n*n-1))
                   break;
            }
            b[r] = b[r] - b[p]*div; 
        }
    }
  
    x[n-1]=b[n-1]/A[n*n-1];

    int xc = n-1;
    int vc = (n*(n-1) - 1); // First value at end of last row
    c = 1;
    double sum = 0;
    int rowc = (n*(n-1) - 1);
    int i,j,k;

    for (k = (n - 2); k>=0; k--){ // Controls how result is inputed into x array
    
        sum = 0;
        for(j = 1; j <= c ; j++)
        {   
            sum=sum+A[rowc]*x[xc];
            xc = xc - 1;
            rowc = rowc - 1;
        }

        x[k] = (b[k]-sum)/A[rowc]; 
        xc = n - 1;
        vc = vc - n;
        rowc = vc; 
        c = c + 1;
    }

    for(i=0; i<=n-1; i++)
        {
            if (x[i] != x[i] || x[i] == INFINITY || x[i] == -INFINITY)
                return 0;
        }
    return 1;
}