#include <stdio.h>
#include "tbendless.h"

void gameIntro(){
    FILE *fptr; 
    char c; 
  
    // Open file 
    fptr = fopen("title.txt", "r"); 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
}