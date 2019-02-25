#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

PIXEL * generate_random_image (int width , int height , int max_color){
    int i, k;
    PIXEL * data = malloc(width*height*sizeof(PIXEL));
    for (i = 0; i < width * height; i++){
        k = (rand() % (max_color + 1));
        data[i].r = k;
        k = (rand() % (max_color + 1));        
        data[i].g = k;
        k = (rand() % (max_color + 1));
        data[i].b = k;

    }    
    return data; 
}

Individual * generate_population ( int population_size , int width , int height , int max_color ){
    
    int i; 
    Individual * population = malloc(sizeof(Individual)*population_size); 
   
    for (i = 0; i < population_size; i++){

        population[i].image.width = width;
        population[i].image.height = height;
        population[i].image.max_color = max_color;

        population[i].image.data = generate_random_image(width, height, max_color);
        
    }
    return population; 
  
   

}

