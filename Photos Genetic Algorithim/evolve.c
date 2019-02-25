#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "a4.h"
		
static int cmpfunc(const void *a, const void *b) {
  		return ((Individual *)a)->fitness - ((Individual *)b)->fitness;
	}

PPM_IMAGE * evolve_image (const PPM_IMAGE *image , int num_generations , 
	int population_size , double rate ){
    srand(time(NULL));
    int width = image->width, height = image->height, max_color = image->max_color; 
    int gen, i, product;
    Individual * population = generate_population (population_size , width , height , max_color);

    PIXEL * photo = image->data;

    comp_fitness_population(photo, population, population_size);


  	qsort(population, population_size, sizeof(Individual), cmpfunc);

   
    for (gen=0; gen<num_generations; gen++){
		crossover(population, population_size);
		mutate_population(population , population_size , rate);
		comp_fitness_population(photo, population, population_size);
	
    qsort(population, population_size, sizeof(Individual), cmpfunc);
	}

    PPM_IMAGE * final = malloc(sizeof(PPM_IMAGE));
	(* final).width = population[0].image.width;
	(* final).height = population[0].image.height;
	(* final).max_color = population[0].image.max_color;

	product = final->height * final->width;
	
	PIXEL * finalp = malloc(sizeof(PIXEL)*product);
	final->data = finalp; 

	for(i = 0; i < product; i++){
		(* final).data[i].r = population[0].image.data[i].r;
		(* final).data[i].g = population[0].image.data[i].g;
		(* final).data[i].b = population[0].image.data[i].b;
	}


	for (i = 0; i < population_size; i++){
		free((population[i].image.data));
	}
	free(population);
    
	return final; 
}

void free_image(PPM_IMAGE *p) {
	free(p -> data);
	free(p);
  }


