#include <stdio.h>
#include <math.h>

int main(void){

    double a, x0, e;  // Types assigned to the values in the file. 

    
    // printf and scanf statements take in the user's input for the value of a. 
    printf("Enter a: ");
    scanf("%le", &a);
    
    x0 = 2/(1 + a); // Initial value of x0 according to assignement specifications. 

    e = 1; // Initiates the value of e. 
    
    // The while loop below iterates until the value of e goes over 1.00e-13. 
    while (e >= (1.00e-13)){  
        x0 = x0*(1.5 - 0.5*a*x0*x0);  // Calculates x0 repeatedly. 
        e = fabs(x0 - (1/sqrt(a)))*sqrt(a); // Calculates e repeatedly. 
        printf("%.15le\t%.2le\n", x0, e); // Prints x0 and e to 15 and 2 decimal points respectively. 
 

        
    }
    return 0;
}
