#ifndef TERMINAL_BATTLE_ENDLESS_H
#define TERMINAL_BATTLE_ENDLESS_H

//USED FOR BOOLEAN ONLY - contains information on whether player has a spell
typedef struct Spells{
     int firaga;
     int thundaga;
     int blizzaga;
}spellStat;

//amount of each type of potion
typedef struct Potions{
     int healthPotions;
     int manaPotions;
}potionCount;

//player information
typedef struct Player{
     char name[100];
     int damageMultiplier;
     int health;
     int baseAttack;
     int experience;
     int mana;
     spellStat spells;
     potionCount potions;

}player;

//common enemy information
typedef struct enemyComm{
     char name[100];
     int damMult;
     int health;
     int base;
     int freezeStat;
     int burnStat;
     char attackName[100];

}grunt;

//boss enemy information. includes specialAttack damage
typedef struct enemyBoss{
     char name[100];
     int damMult;
     int health;
     int base;
     int special;
     int freezeStat;
     int burnStat;
     char attackName[100];
     char specName[100];
}boss;

//game functions
void gameIntro();

//functions dealing with common enemies
void createEnemy();
void enemyAttack();

//functions dealing with boss enemies
void createBoss();
void bossAttack();

//functions dealing with player
void createPlayer();
void playerAttack();
void usePotion();
void upgrade();


#endif