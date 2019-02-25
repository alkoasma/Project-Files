#include <stdio.h>

int main()
{
    int n, Precede = 1, Succeed = 1, Next; 
    int d2 = 0, d3 = 0, d5 = 0, d6 = 0, d10 = 0, d15 = 0, nd = 0; // Counters for divisbility values

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("\n");

    printf("Fibonacci sequence up to %d: \n", n);

    while(Precede <= n) // Condition to print to a maximum of n. 
    {   
        printf("%d, ", Precede);  // Prints values of the sequence starting from Precede = 1.   
        
        if (Precede%2 == 0)   // Checks if value is divisible by 2 and adds to d2 counter. 
            d2 = d2 + 1;
        if (Precede%3 == 0) 
            d3 = d3 + 1; // Checks if value is divisible by 3 and adds to d3 counter. 
        if (Precede%5 == 0) 
            d5 = d5 + 1; // Checks if value is divisible by 5 and adds to d5 counter. 
        if (Precede%6 == 0) 
            d6 = d6 + 1; // Checks if value is divisible by 6 and adds to d6 counter. 
        if (Precede%10 == 0) 
            d10 = d10 + 1; // Checks if value is divisible by 10 and adds to d10 counter. 
        if (Precede%15 == 0) 
            d15 = d15 + 1; // Checks if value is divisible by 15 and adds to d15 counter. 
        if ((Precede%2 != 0) && (Precede%3 != 0) && (Precede%5 != 0) && (Precede%6 != 0) && (Precede%10 != 0) && (Precede%15 != 0) )  
            nd = nd + 1;  // Counter for all other values that are not divisible by the numbers above.
        
        Next = Precede + Succeed; // Adds the preceding and succeeding values of the sequence.
        Precede = Succeed;  // Moves the preceding value forward to the succeeding value. 
        Succeed = Next; // Moves the succeeding value to the sum of the previous two values. 
    }

    // The following code is for the table.
    // It follows the pattern   (Number divisble by      Counter of values divisble by)    

    printf("\n\ndivisibely by: \n");
    printf("2\t\t%d\n", d2);    
    printf("3\t\t%d\n", d3);
    printf("5\t\t%d\n", d5);
    printf("6\t\t%d\n", d6);
    printf("10\t\t%d\n", d10);
    printf("15\t\t%d\n", d15);
    printf("-\t\t%d\n", nd);
    
    return 0;
}