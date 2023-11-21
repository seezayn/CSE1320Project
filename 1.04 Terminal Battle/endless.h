#ifndef endless
#define endless
//player information
void statShop();
void newMoves();
void mainMenu(int *playing,int *modified, int *titleChoi);
void randomizeItems(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[]);
void Items(int *blocked);
void reCalculate(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[]);
void learnMoves(int instrucChoi, int instrucOption[]);
struct Player
{
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
     int hasFire;
     int hasBlizzard;
     int hasThunder;
     int hasAero;
     int hasLucky;
     int hasQuick;
     int hasArs;
     int hasCritHit;
     float attackMulti;
     float magicMulti;
} Pl;
//common enemy information
struct Enemy
{
     char name[100];
     
     int HP;
     int maxHP;
     
     int burned;
     int frozen;
     int shocked;
     int confused;
     
     float enemyDamageMulti;
} En;
struct Boss
{
    char name[100];
    
    int HP;
    int maxHP;
    
    int burned;
    int frozen;
    int shocked;
    int confused;
    
    float bossDamageMulti;
} Bo;
struct Magic
{
     int fireMP;
     int fireMiss;
     int burnChance;
     
     int blizzardMP;
     int blizzardMiss;
     int freezeChance;
     
     int thunderMP;
     int thunderMiss;
     int shockChance;
     
     int aeroMP;
     int aeroMiss;
     int confuseChance;
     
     int curaga;
} Ma;
//amount of each type of potion
struct Items
{
     int potionC;
     int potionHeal;
     int potionUsed;
     int maxPotionCount;
     int etherC;
     int etherRest;
     int etherUsed;
     int maxEtherCount;
     int panaceaC;
     int panaceaUsed;
     int maxPanaceaCount;
} It;
struct Attacks
{
    int lightBlock;
    int heavyBlock;
    int luckyMP;
    int luckyBlock;
    int quickdrawMP;
    int arsMP;
    int arsBlock;
    int critHitMP;
    int critHitBlock;
    int critHitSuc;
} At;
struct Unlocks
{
    int inEndless;
    int rounds;
    double battles;
    int bossOrEnemy;
} Un;
void initialize()
{
        snprintf(Pl.name, sizeof(Pl.name), "Player");
        snprintf(En.name, sizeof(En.name), "Grunt");                //these three are the default names if the player doesn't rename anything
        snprintf(Bo.name, sizeof(Bo.name), "Boss");
        
        Pl.HP = 1000;
        Pl.maxHP = 1000;
        Pl.MP = 100;
        Pl.maxMP = 100;
        Pl.experience = 0;
        Pl.bench = 0;
        Pl.G = 0;
        Pl.expMulti = 1.0;
        Pl.GMulti = 1.0;
        
        Pl.burned = 0;
        Pl.burnDamage = 0;          //modifying this here won't change anything in the code
        Pl.frozen = 0;
        Pl.shocked = 0;
        Pl.shockSucc = 0;           //modifying this here won't change anything in the code
        Pl.confused = 0;
        
        Pl.hasFire = 0;
        Pl.hasBlizzard = 0;
        Pl.hasThunder = 0;
        Pl.hasAero = 0;
        Pl.hasLucky = 0;
        Pl.hasQuick = 0;
        Pl.hasArs = 0;
        Pl.hasCritHit = 0;
        
        Pl.attackMulti = 1.0;
        Pl.magicMulti = 1.0;
        
        It.potionC = 3;
        It.potionHeal = 400;
        It.potionUsed = 0;
        It.maxPotionCount = 3;
        It.etherC = 2;
        It.etherRest = 40;
        It.etherUsed = 0;
        It.maxEtherCount = 3;
        It.panaceaC = 0;
        It.panaceaUsed = 0;
        It.maxPanaceaCount = 3;
        
        Ma.fireMP = 5;
        Ma.burnChance = 15;
        Ma.fireMiss = 0;
        Ma.blizzardMP = 10;
        Ma.blizzardMiss = 15;
        Ma.freezeChance = 15;
        Ma.thunderMP = 30;
        Ma.shockChance = 30;
        Ma.thunderMiss = 45;
        Ma.aeroMP = 20;
        Ma.aeroMiss = 25;
        Ma.confuseChance = 20;
        
        At.lightBlock = 75;
        At.heavyBlock = 25;
        At.luckyMP = 15;
        At.luckyBlock = 33;
        At.quickdrawMP = 40;
        At.arsMP = 90;
        At.arsBlock = 90;
        At.critHitMP = 1;
        At.critHitBlock = 0;
        At.critHitSuc = 3;
        
        En.frozen = 0;
        En.burned = 0;
        En.shocked = 0;
        En.confused = 0;
        En.enemyDamageMulti = 1.0;
        
        Bo.burned = 0;
        Bo.frozen = 0;
        Bo.shocked = 0;
        Bo.confused = 0;
        Bo.bossDamageMulti = 1.0;
        
        En.HP = 600;
        En.maxHP = 600;
        Bo.HP = 1500;
        Bo.maxHP = 1500;
        
        Un.rounds = 1;
        Un.battles = 0.0;       //this gets changed to 1 as soon as the battle starts, so GMulti isn't multiplied by 0
        Un.bossOrEnemy = 0;     //0 = Enemy, 1 = Boss
}
void knight()
{
    char temp1[100],temp2[100],temp3[100];
    strcpy(temp1,Pl.name);
    strcpy(temp2,En.name);
    strcpy(temp3,Bo.name);
    initialize();
    strcpy(Pl.name,temp1);
    strcpy(En.name,temp2);
    strcpy(Bo.name,temp3);
    Pl.HP = 1250;
    Pl.MP = 75;
    Pl.hasLucky = 1;
    Pl.hasQuick = 1;
    Pl.hasArs = 1;
    Pl.hasCritHit = 1;
    Pl.attackMulti = 1.3;
    Pl.magicMulti = 0.75;
    It.potionC = 1;
    It.etherC = 1;
    It.panaceaC = 0;
}
void mage()
{
    char temp1[100],temp2[100],temp3[100];
    strcpy(temp1,Pl.name);
    strcpy(temp2,En.name);
    strcpy(temp3,Bo.name);
    initialize();
    strcpy(Pl.name,temp1);
    strcpy(En.name,temp2);
    strcpy(Bo.name,temp3);
    Pl.HP = 750;
    Pl.MP = 125;
    Pl.hasFire = 1;
    Pl.hasBlizzard = 1;
    Pl.hasThunder = 1;
    Pl.hasAero = 1;
    Pl.attackMulti = 0.75;
    Pl.magicMulti = 1.3;
    It.potionC = 3;
    It.etherC = 3;
    It.panaceaC = 1;
}
void rogue()
{
    char temp1[100],temp2[100],temp3[100];
    strcpy(temp1,Pl.name);
    strcpy(temp2,En.name);
    strcpy(temp3,Bo.name);
    initialize();
    strcpy(Pl.name,temp1);
    strcpy(En.name,temp2);
    strcpy(Bo.name,temp3);
    Pl.HP = 1000;
    Pl.MP = 100;
    Pl.hasFire = 1;
    Pl.hasBlizzard = 1;
    Pl.hasLucky = 1;
    Pl.hasCritHit = 1;
    It.potionC = 3;
    It.etherC = 2;
    It.panaceaC = 0;
}
void god()
{
    Pl.HP = 99999;
    Pl.MP = 99999;
    Pl.G = 9999999;
    Pl.hasFire = 1;
    Pl.hasBlizzard = 1;
    Pl.hasThunder = 1;
    Pl.hasAero = 1;
    Pl.hasLucky = 1;
    Pl.hasQuick = 1;
    Pl.hasArs = 1;
    Pl.hasCritHit = 1;
    Pl.attackMulti = 10.0;
    Pl.magicMulti = 10.0;
    It.potionC = 9999;
    It.etherC = 9999;
    It.panaceaC = 9999;
    It.potionHeal = 99999;
    It.etherRest = 99999;
    Ma.fireMP = 0;
    Ma.blizzardMP = 0;
    Ma.thunderMP = 0;
    Ma.aeroMP = 0;
    At.luckyMP = 0;
    At.luckyBlock = 100;
    At.quickdrawMP = 0;
    At.arsMP = 0;
    At.arsBlock = 100;
    At.critHitMP = 0;
    At.critHitSuc = 100;
    At.critHitBlock = 100;
    At.lightBlock = 100;
    At.heavyBlock = 100;
    Ma.burnChance = 100;
    Ma.blizzardMiss = 0;
    Ma.freezeChance = 100;
    Ma.shockChance = 100;
    Ma.thunderMiss = 0;
    Ma.aeroMiss = 0;
    Ma.confuseChance = 100;
}
#endif