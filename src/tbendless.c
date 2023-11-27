#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include "tbendless.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//COSMETIC FUNCTIONS
void titleScreen(){
    FILE *fptr;   
    fptr = fopen("title.txt", "r"); 

    char c = fgetc(fptr);
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 


    char answer;
    printf("\n\n\nWould you like to enter the battle? (Y/N)\n");
    scanf("%c", &answer);

    if(strcmp(answer, 'Y') == 0){
        printf("blah blah blah game message\n");
    }
    else if(strcmp(answer, 'N') == 0){
        printf("Well... bye\n");
        return 0;
    }

}

void printEnemy(int randEn){
    char enemyFile[20];
    switch(randEn){
        case 0:
            strcpy(enemyFile, "gremmy.txt");
        case 1:
            strcpy(enemyFile, "slapcat.txt");
        case 2:
            strcpy(enemyFile, "spicypickle.txt");

    }

    FILE *fptr;   
    fptr = fopen(enemyFile, "r"); 

    char c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 

}

void printBoss(int randBoss){
    char bossFile[20];
    switch(randBoss){
        case 0:
            strcpy(bossFile, "kingremmy.txt");
        case 1:
            strcpy(bossFile, "slaptiger.txt");
        case 2:
            strcpy(bossFile, "picklejar.txt");

    }

    FILE *fptr;   
    fptr = fopen(bossFile, "r"); 

    char c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 

}

void printHealth(entity person){
    double health = (double) person.HP;
    double maxHealth = (double) person.maxHP;

    double proportion = (health/maxHealth)*50;
    printf("\n██████████████████████████████████████████████████\n");
    if(proportion >= 35){
        for(int i=0; i< proportion; i++)
            printf(ANSI_COLOR_GREEN"█"ANSI_COLOR_RESET);
    }
    else if(15 <= proportion || proportion < 35){
        for(int i=0; i< proportion; i++)
            printf(ANSI_COLOR_YELLOW"█"ANSI_COLOR_RESET);
    }
    else if(proportion < 15){
        for(int i=0; i< proportion; i++)
            printf(ANSI_COLOR_RED"█"ANSI_COLOR_RESET);
    }
    printf("\n██████████████████████████████████████████████████\n\n");
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//status check
int statusEffectCheck(entity person){
    int count = 0;
    if(!person.burnStat)
        count += 1;
    if(!person.freezeStat)
        count +=2;
    if(!person.shockStat)
        count += 4;
    if(!person.confuseStat)
        count += 8;

    return count;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sequences
void enemySequence(entity enemy){

}

void playerSequence(entity player){
    int status = statusEffectCheck(player);



}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//attack functions
void entityAttack(entity attacker, entity victim, int attackChoice){
    int attackDamage = attacker.attacks[attackChoice].attackDam * attacker.damMult;

    if(!attacker.entityType){
        printf("%s used %s!\n", attacker.name, attacker.attacks[attackChoice].attackName);
        if(!victim.isBlock){
            printf("You blocked the attack!\n");
        }
        victim.isBlock = 0;
    }
    else{
        printf("You used %s!", attacker.attacks[attackChoice].attackName);
        victim.HP -= attacker.attacks[attackChoice].attackDam;
    }


}

void entitySpell(entity caster, entity victim, int spellChoice){
    int initial = statusEffectCheck(victim);

}

void entityAction(entity actor, entity enemy, int actionChoice){
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//menu functions
void attackMenu(entity player, entity enemy){
    int i = 0, attackChoice;

    printf("---------------------\n");
    while(player.attacks[i].attackName != NULL){
        printf("[%d] %s\n", i+1, player.attacks[i].attackName);
        i++;
    }
    printf("---------------------\n");
    scanf("%d", &attackChoice);

    entityAttack(player, enemy, attackChoice);

}


void playerMenu(entity player, entity enemy){
    char action;
    printf("----------------------------------------\n");
    printf("Moves:\n");
    printf("ATTACK (A)\tMAGIC (M)\tITEM (I)\tACTION (C)\n");
    printf("----------------------------------------\n\n");
    scanf("%c", &action);

    switch(action){
        case 'A':
            printf("\nYou've decided to attack!");
            attackMenu(player, enemy);
        case 'M':

        case 'I':

        case 'C':

        default:
            printf("That's not a move!\n");

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//instantiation

spell createSpell(char *name, int damage, int effect, int cost, float success){
    spell newSpell;
    strcpy(newSpell.spellName,name);
    newSpell.spellDam = damage;
    newSpell.spellEffect = effect;
    newSpell.spellCost = cost;
    newSpell.spellSucc = success;

    return newSpell;
}

item createItem(char *name, int effect, int amount){
    item newItem;
    strcpy(newItem.itemName, name);
    newItem.itemEffect = effect;
    newItem.itemAmount = amount;

    return newItem;
}

attack createAttack(char *name, int damage, int cost, int heavy){
    attack newAttack;
    strcpy(newAttack.attackName, name);
    newAttack.attackDam = damage;
    newAttack.attackCost = cost;
    newAttack.isHeavy = heavy;
}

action createAction(char *name, int effect, int cost, int heavy){
    action newAction;
    strcpy(newAction.actionName, name);
    newAction.actionEffect = effect;
    newAction.actionCost = cost;
    newAction.isHeavy = heavy;

}

void createPlayer(char *name, char class){
    entity Pl;
}


int createEnemy(entity player){
    float level = player.levels;

    int randEn = rand()%3;
    char enemyFile[20];
    char attackFile[10];
    entity En;
    En.entityType = 1;

    switch(randEn){
        case 0:
            strcpy(enemyFile, "gremmyStat.txt");
            strcpy(En.name, "Gremmy");
        case 1:
            strcpy(enemyFile, "slapcatStat.txt");
            strcpy(En.name, "Slap Cat");
        case 2:
            strcpy(enemyFile, "spicypickleStat.txt");
            strcpy(En.name, "Spicy Pickle");
    }

    FILE *fptr;   
    fptr = fopen(enemyFile, "r");
    double value[8];
    char buffer[8];

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        if(strchr(buffer, '*') != NULL)
            value[i] = atoi(buffer);
            i++;
    }

    fclose(fptr);

    //base stats
    En.maxHP = value[0];
    En.maxMP = value[1];
    En.HP = value[2];
    En.MP = value[3];

    //spell instantiation


    return randEn;
}