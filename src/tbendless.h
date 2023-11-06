#ifndef TERMINAL_BATTLE_ENDLESS_H
#define TERMINAL_BATTLE_ENDLESS_H

//USED FOR BOOLEAN ONLY - contains information on whether player has a spell
typedef struct Spells{
     int firaga; //boolean (player has firaga)
     int thundaga; //boolean (player has thundaga)
     int blizzaga; //boolean (player has bizaga)
}spellStat;

//amount of each type of potion
typedef struct Potions{
     int healthPotions; //amount of potions to replenish health
     int manaPotions; //amount of potions to replenish mana for spells
}potionCount;

//player information
typedef struct Player{
     char name[100]; //the name the player inputs
     float damMult; //damage multiplier for player PHYSICAL attacks
     float spellMult;
     int health; //player health
     int baseAttack; //base PHYSICAL attack. multiplied by multiplier for final physical attack output
     int experience; //player experience. can be used to upgrade stats or unlock spells
     int mana; //player mana. constains the amount of spells the player can use
     spellStat spells; //boolean states describing whether player can use a spell. can be unlocked with experience
     potionCount potions; //amount of the different potions the player has

}player;

//common enemy information
typedef struct enemyComm{
     char name[100]; //enemy name. randomly selected from a text file
     int damMult; //damage multiplier for enemy. increases with every wave
     int health; //enemy health
     int baseAttack; //base attack. multiplied by damage multiplier
     int freezeStat; //boolean status effect of the enemy freeze.
     int burnStat; //boolean status effect of the enemy burn
     char attackName[100]; //name of the enemy attack.

}grunt;

//boss information. includes specialAttack damage
typedef struct enemyBoss{
     char name[100]; //boss name. randomly selected from a text file
     int damMult; //damage multiplier for boss. increases with every wave
     int health; //boss health
     int baseAttack; //base attack. multiplied by damage multiplier
     int special; //boss special attack damage
     int freezeStat; //boolean status effect of the boss freeze.
     int burnStat; //boolean status effect of the boss burn
     char attackName[100]; //name of the boss attack.
     char specName[100]; //name of boss special attack
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
void createPlayer(char *name[], char *class[]);
void playerAttack();
void useSpell();
void usePotion();
void upgrade();


#endif