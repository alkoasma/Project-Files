#include <stdio.h>
#include <math.h>  

int main(void){

    double a, x0, e; 
    int n;
    
    // The three printf and scanf statements below is to attain the user's input for a, x0, and n. 
    printf("Enter the value for a, x0, and n: ");
    scanf("%le %le %d", &a, &x0, &n); 

    /* The for loop below iterates upto (n - 1) times in concordance with the assignement 
    specifications. The values of i increases until the assignement's instructions are reached.*/

    for (int i = 0; i <= n - 1 ; i++ ){
        x0 = x0*(1.5 - 0.5*a*x0*x0);    // Calculates x0 repeatedly as it's value changes. 
        e = fabs(x0 - (1/sqrt(a)))*sqrt(a);  // Calculates e as x0 changes. 
        printf("%d\t%.15le\t%.2le\n", i + 1, x0, e);  // Prints information in concordance to assignement specifications
    }
    return 0;
}

/* Note that the code includes the math.h library. To iterate in a Unix controlled
environement, an object file is created first that is linked to the library. */
