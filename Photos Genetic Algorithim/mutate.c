#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"

void mutate (Individual * individual , double rate ){
    int i, k, m;
    int product = individual->image.width * individual->image.height; 
    int max_color = individual->image.max_color;
    int runtime = (rate/100*product); 
    for (i = 0; i < runtime; i++){
        k = (rand() % (product + 1));

        m = (rand() % (max_color + 1));
        individual->image.data[k].r = m; 

        m = (rand() % (max_color + 1));
        individual->image.data[k].g = m; 

        m = (rand() % (max_color + 1));
        individual->image.data[k].b = m;  
    }
}

void mutate_population ( Individual * individual , int population_size , double rate ){

    int i; 
    int index = population_size/4;
    for (i = index; i <= (population_size-1); i++){
        mutate (individual + i, rate);
    }
}