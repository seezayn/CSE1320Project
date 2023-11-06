#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void createPlayer(char *name[], char *class[]){
    player hero;
    if(strcmp(*class,"Knight")==0){
        strcpy(hero.name,*name);
        hero.health = 1250;
        hero.damMult = 1.1;
        hero.spellMult = 1.0;
        hero.baseAttack = 50;
        hero.experience = 0;
        hero.mana = 25;
        hero.spells.firaga = 0;
        hero.spells.thundaga = 0;
        hero.spells.blizzaga = 0;
        hero.potions.healthPotions = 8;
        hero.potions.manaPotions = 2;

    }
    else if(strcmp(*class,"Mage")==0){
        strcpy(hero.name,*name);
        hero.health = 900;
        hero.damMult = 1;
        hero.spellMult = 1.5;
        hero.baseAttack = 20;
        hero.experience = 0;
        hero.mana = 100;
        hero.spells.firaga = 1;
        hero.spells.thundaga = 1;
        hero.spells.blizzaga = 1;
        hero.potions.healthPotions = 3;
        hero.potions.manaPotions = 7;

    }
    else if(strcmp(*class,"Rogue")==0){
        strcpy(hero.name,*name);
        hero.health = 1000;
        hero.damMult = 1.05;
        hero.spellMult = 1.25;
        hero.baseAttack = 35;
        hero.experience = 0;
        hero.mana = 60;
        hero.spells.firaga = 1;
        hero.spells.thundaga = 0;
        hero.spells.blizzaga = 0;
        hero.potions.healthPotions = 5;
        hero.potions.manaPotions = 5;

    }

}