#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

PPM_IMAGE * read_ppm (const char * file_name){
    FILE *fp;
    fp = fopen(file_name, "r");
    int i;
    int red, green, blue;
    char a, b;
    PPM_IMAGE * photo = malloc(sizeof(PPM_IMAGE));

    fscanf(fp, "%c%c %d %d %d", &a, &b, &(photo->width), &(photo->height), &(photo->max_color));
    
    int product = photo -> height * photo -> width;
    
    PIXEL * image = malloc(sizeof(PIXEL)*product);
    photo -> data = image; 

    for(i = 0; i < product; i++){
        fscanf(fp, "%d %d %d", &red, &green, &blue);
        photo -> data[i].r = red; 
        photo -> data[i].g = green; 
        photo -> data[i].b = blue; 
    }   
    fclose(fp);   
    return photo; 

}

void write_ppm (const char * file_name , const PPM_IMAGE * image ){

    FILE *fp;
    fp = fopen(file_name, "w");
    int i;
    int red, green, blue;
    fprintf(fp, "P3\n%d %d\n%d\n", image->width, image->height, image->max_color);
   
    int product = image -> height * image -> width;
    for(i = 0; i < product; i++){
        red = image -> data[i].r; 
        green = image -> data[i].g; 
        blue = image -> data[i].b; 
        fprintf(fp, "%d %d %d ", red, green, blue);
        if ((i+1) % image->width == 0)
            fprintf(fp, "\n");
    }
    fclose(fp);

}

