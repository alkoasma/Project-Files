#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ){
    double total = 0;
    int i;
    for (i = 0; i < image_size; i++){// < or <=???
        total += (A[i].r-B[i].r)*(A[i].r-B[i].r) + (A[i].g-B[i].g)*(A[i].g-B[i].g) + (A[i].b-B[i].b)*(A[i].b-B[i].b);
    }    
    return sqrt(total);
}

void comp_fitness_population ( const PIXEL *image , Individual * individual , int population_size ){
    for (int i = 0; i < population_size; i++){  // < or <=???        
        individual[i].fitness = comp_distance(image, individual[i].image.data, individual[i].image.width * individual[i].image.height); 
    }
}



