#include <stdio.h>

int main()
{
    int numsq, i, j, a, b;
    
    do {
        printf("Enter number of squares: "); 
        scanf("%d", &numsq);
    } while ((50 < numsq) || (numsq <= 0));  // Asks user for valid input between 0 and 50.
    
    char *square[3] = {"#","#","#"}; // Array of three squares. 
    
        
    for (; numsq > 0; numsq = numsq - 5){  // Decreases the value of numsq so a maximum of 5 squares print on each line.
        for (int a = numsq; a > (numsq - 3); a = a - 1){   //  The for loop allows a maximum of 3 lines for all the squares.
           for (int b = numsq; b > 0; b = b - 1){ // For loop iterates to print information below to specified number of squares.
               if (b <(numsq - 4)) // The if statement allows the for loop to print a maximum of 3 lines for each square.
                   continue; 
                  for(int i = 0; i < 3; i++) {    
                    printf("%s", square[i]); // Prints ### from an array.
                }
                printf(" ");  // Prints a space between coloumns of ###. 
            }      
            printf("\n");
            if (a == (numsq - 2)) // Prints a seperating line between each row of squares. 
                printf("\n");
            }
    }    

    return 0;
}




