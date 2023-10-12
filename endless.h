#ifndef endless
#define endless

//player information
struct Player{
     char name[100];
     int damageMultiplier;
     int health;
     int baseAttack;
     int experience;
     int mana;
     Spells spells;
     Potions potions;

};

//common enemy information
struct enemyComm{
     char name[100];
     int damMult;
     int health;
     int base;
     int attack = base * damMult;
     int freezeStat;
     int burnStat;
     char attackName[100];

};

//boss enemy information. includes specialAttack damage
struct enemyBoss{
     char name[100];
     int damMult;
     int health;
     int base;
     int special;
     int attack = base * damMult;
     int specAttack = special * damMult;
     int freezeStat;
     int burnStat;
     char attackName[100];
     char specName[100];
};

//USED FOR BOOLEAN ONLY - contains information on whether player has a spell
struct Spells{
     int firaga;
     int thundaga;
     int blizzaga;
};

//amount of each type of potion
struct Potions{
     int healthPotions;
     int manaPotions;
};

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


#endif