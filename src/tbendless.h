#ifndef TERMINAL_BATTLE_ENDLESS_H
#define TERMINAL_BATTLE_ENDLESS_H

//spells and their probability of success
typedef struct Spell{
     char spellName[10];
     int spellDam;
     int spellEffect;
     int spellCost;
     float spellSucc;
}spell;

//amount items and their effectiveness
typedef struct Item{
     char itemName[10];
     int itemEffect;
     int itemAmount;
}item;

typedef struct Attack{
     char attackName[20];
     int attackDam;
     int attackCost;
     int isHeavy;
}attack;

typedef struct Action{
     char actionName[10];
     int actionEffect;
     int actionCost;
     int isHeavy;
}action;

//entity information
typedef struct Entity{
     char name[100]; //entity name
     int entityType; //0 for player, 1 for enemy, 2 for boss
     
     //variable entity data
     int HP; //current entity health
     int MP; //current entity mana
     int isBlock; //boolean for blocking

     //multipliers
     double damMult; //damage multiplier for entity PHYSICAL attacks
     double spellMult; //damage multiplier for spells

     //status effects
     int burnStat; //amount of burn
     int burnDamage; //burn effect
     int freezeStat; //amount of freeze
     int shockStat; //amount of shock
     int confuseStat; //amount of confusion

     //base data
     int maxHP; //max entity health
     int maxMP; //max entity mana

     //nested structures
     spell spells[5]; //spells the entity has and their damage
     item items[10]; //items the entity has and their damage
     attack attacks[10]; //list of attacks the entity has

     //game data
     int experience; //player experience. can be used to upgrade stats or unlock spells
     int G; //amount of player currency
     int levels; //amount of levels the player has defeated
     int waves; //amount of waves the player has defeated

}entity;

//cosmetic functions (printing)
void titleScreen(); //prints the title message of the game
void printEnemy(); //prints enemy sprite boss sprite from a random selection of files
void printBoss(); //prints boss sprite from a random selection of files

//game functions
void statShop(); //status shop between wave ending and beginning
void loss(); //deals with losing
void roundFinish(); //deals with the upkeep of defeating an enemy

//instantiation
int createEnemy(); //instantiates values of common enemy
void createBoss(); //instantiates values of boss enemy
void createPlayer(char *name, char class); //instantiates player values

//sequences
void enemySequence(); //function for the entire sequence of an enemy
void bossSequence(); //function for the entire sequence of a boss
void playerSequence(); //function for the entire player move

//menu functions
void playerMenu(); //prints the menu of options for the player
void attackMenu();
void spellMenu();
void itemMenu();

//status check
int statusCheck(); //checks status of entity

//attack functions
void entityAttack(entity attacker, entity victim, int attack);

//spell functions
void playerSpell(); //function when player uses a spell

//item functions
void usePotion(); // function when player uses potion

#endif