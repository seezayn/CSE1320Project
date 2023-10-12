#include <stdio.h>
#include "tbendless.h"

void gameIntro(){
    FILE *fptr;   
    fptr = fopen("title.txt", "r"); 

    char c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
}

void createPlayer(){
    
}