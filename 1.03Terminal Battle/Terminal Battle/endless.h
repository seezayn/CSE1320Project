#ifndef endless
#define endless
//player information
void statShop();
struct Player{
     char name[100];
     
     int HP;
     int maxHP;
     int MP;
     int maxMP;
     int experience;
     int G;
     double expMulti;
     double GMulti;
     int bench;             //used as an indicator for inbetween rounds in endless
     int burned;
     int burnDamage;
     int frozen;
     int shocked;
     int shockSucc;
     int confused;
} Pl;
//common enemy information
struct Enemy
{
     char name[100];
     
     int HP;
     
     int burned;
     int frozen;
     int shocked;
     int confused;
} En;
struct Magic
{
     int firagaMP;
     int firagaMiss;
     int burnChance;
     
     int blizzagaMP;
     int blizzagaMiss;
     int freezeChance;
     
     int thundagaMP;
     int thundagaMiss;
     int shockChance;
     
     int aerogaMP;
     int aerogaMiss;
     int confuseChance;
     
     int curaga;
} Ma;
//amount of each type of potion
struct Items
{
     int potionC;
     int potionHeal;
     int etherC;
     int etherRest;
     int panaceaC;
     int defenseC;
     int defenseValue;
} It;
struct Attacks
{
    int lightBlock;
    int heavyBlock;
    int luckyMP;
    int luckyBlock;
    int sonicMP;
    int arsMP;
    int arsBlock;
    int zanteMP;
    int zanteBlock;
    int zanteSuc;
} At;
struct Unlocks
{
    int inEndless;
    int rounds;
    double battles;
} Un;
void initialize()
{
        snprintf(Pl.name, sizeof(Pl.name), "Player");
        snprintf(En.name, sizeof(Pl.name), "DEFAULT");
        Pl.HP = 750;
        Pl.maxHP = 750;
        Pl.MP = 100;
        Pl.maxMP = 100;
        Pl.experience = 0;
        Pl.bench = 0;
        Pl.G = 0;
        Pl.expMulti = 1.0;
        Pl.GMulti = 1.0;
        Pl.burned = 0;
        Pl.burnDamage = 0;
        Pl.frozen = 0;
        Pl.shocked = 0;
        Pl.shockSucc = 0;
        Pl.confused = 0;
        En.HP = 1000;
        It.potionC = 3; 
        It.etherC = 2,
        It.potionHeal = 250,
        It.etherRest = 40;
        It.panaceaC = 0;
        It.defenseC = 0;
        It.defenseValue = 500;
        Ma.firagaMP = 5;
        Ma.burnChance = 15;
        Ma.firagaMiss = 0;
        Ma.blizzagaMP = 10;
        Ma.blizzagaMiss = 15;
        Ma.freezeChance = 15;
        Ma.thundagaMP = 30;
        Ma.shockChance = 30;
        Ma.thundagaMiss = 45;
        Ma.aerogaMP = 20;
        Ma.aerogaMiss = 25;
        Ma.confuseChance = 20;
        
        At.lightBlock = 75;
        At.heavyBlock = 25;
        At.luckyMP = 15;
        At.luckyBlock = 33;
        At.sonicMP = 40;
        At.arsMP = 90;
        At.arsBlock = 90;
        At.zanteMP = 1;
        At.zanteBlock = 0;
        At.zanteSuc = 3;
        
        En.frozen = 0;
        En.burned = 0;
        En.shocked = 0;
        En.confused = 0;
        
        Un.inEndless = 0;
        Un.rounds = 1;
        Un.battles = 0.0;       //this gets changed to 1 as soon as the battle starts, so GMulti isn't multiplied by 0
}
#endif