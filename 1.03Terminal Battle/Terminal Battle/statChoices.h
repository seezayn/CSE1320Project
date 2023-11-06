#ifndef shopChoices
#define shopChoices
#include "endless.h"
void mainMenu(int *playing,int *modified, int *titleChoi);
void randomizeItems(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[]);
void Items(int *potionUsed, int *etherUsed, int *blocked);
void Shop(int *playing,int *modified, int *titleChoi)
{
    int shopChoi;
    double newEnHP = En.HP*1.10;
    newEnHP = round(newEnHP);
    En.HP = newEnHP;
    En.burned = 0;
    En.frozen = 0;
    En.shocked = 0;
    En.confused = 0;
    int selection[9] = {0};
    float randoPerc[9] = {0};
    float gPrice[9] = {0};
    float calculateNew[9] = {0};
    int ID[9] = {0};
    Pl.bench = 1;
    randomizeItems(selection,randoPerc,gPrice,calculateNew,ID);         //this is for the Stat Shop
    printf("End of battle %.0f\n", Un.battles);
    do
    {   printf("Select a Choice\n");
        printf("[1] Purchase Items\n");
        printf("[2] Purchase Stat upgrades\n");
        printf("[3] Use current items\n");
        printf("[4] Continue to next round\n");
        printf("[5] Quit\n");
        scanf("%d",&shopChoi);
        if (shopChoi == 1)
        {
            shopChoi = 0;
            printf("\n\n\n");
            int itemChoi = 0;
            do
            {
                printf("Item Shop:\t\t---Current G: %d---\n", Pl.G);
                printf("[1] 5G: Potion (Heals %dHP)\n", It.potionHeal);
                printf("[2] 5G: Ether (Restores %dMP)\n", It.etherRest);
                printf("[3] 7G: Panacea (Removes status effects)\n");
                //printf("[4] 20G: Defense Shield (Blocks %d Damage of attacks)\n", It.defenseValue);
                //printf("[5] 20G: Dire Hit (Increases attack power for 5 turns)\n");
                printf("[4] Back\n");
                scanf("%d", &itemChoi);
                if (itemChoi == 1)
                {
                    itemChoi = 0;
                    if (Pl.G >=  5)
                    {
                        printf("Purchased 1 Potion!\n");
                        Pl.G -= 5;
                        It.potionC += 1;
                        printf("Total Potions: %d\n", It.potionC);
                    }
                    else
                    {
                        printf("You don't have enough G to purchase a potion!\n");
                    }
                }
                else if (itemChoi == 2)
                {
                    itemChoi = 0;
                    if (Pl.G >= 5)
                    {
                        printf("Purchased 1 Ether!\n");
                        Pl.G -= 5;
                        It.etherC += 1;
                        printf("Total Ethers: %d\n", It.etherC);
                    }
                    else
                    {
                        printf("You don't have enough G to purchase an Ether!\n");
                    }
                }
                else if (itemChoi == 3)
                {
                    itemChoi = 0;
                    if (Pl.G >=  7)
                    {
                        printf("Purchased 1 Panacea!\n");
                        Pl.G -= 7;
                        It.panaceaC += 1;
                        printf("Total Panaceas: %d\n", It.panaceaC);
                    }
                    else
                    {
                        printf("You don't have enough G to purchase a Panacea!\n");
                    }
                }
                else if (itemChoi == 4)
                {
                    printf("\n\n\n");
                }
                else
                {
                    printf("Please enter a different number.\n");
                }
            } while (itemChoi < 1 || itemChoi > 4);
        }
        else if (shopChoi == 2)
        {
            shopChoi = 0;
            statShop(&shopChoi, selection, randoPerc, gPrice, calculateNew, ID);
        }
        else if (shopChoi == 3)
        {
            shopChoi = 0;
            printf("Curent HP: %d/%d\t\tCurrent MP: %d/%d\nCurrent Status: ", Pl.HP, Pl.maxHP, Pl.MP, Pl.maxMP);
            if (Pl.burned == 0 && Pl.frozen == 0 && Pl.shocked == 0 && Pl.confused == 0)
            {
                printf("No status effects\n");
            }
        if (Pl.burned == 1)
        {
            printf("\033[0;31m*Burned \033[0m");
        }
        if (Pl.frozen >= 1)
        {
            printf("\033[0;34mFrozen \033[0m");
        }
        if (Pl.shocked == 1)
        {
            printf("\033[0;33m*Shocked \033[0m");
        }
        if (Pl.confused == 1)
        {
            printf("\033[0;35m*Confused \033[0m");
        }
            int temp1 = 0, temp2 = 0, temp3 = 0;
            Items(&temp1,&temp2,&temp3);
            continue;
        }
        else if (shopChoi == 4)
        {
            Pl.bench = 0;
            mainMenu(playing,modified,titleChoi);
        }
        else if (shopChoi == 5)
        {
            exit(1);
        }
    } while (shopChoi < 1 || shopChoi > 5);
}

void reCalculate(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[]);
void changeStats(int selection[],float randoPerc[], float gPrice[], float calculateNew[], int ID[], int *i)
{
    if (ID[*i] == 1)
    {
        Pl.HP = (calculateNew[*i] - Pl.maxHP) + Pl.HP;
        Pl.maxHP = calculateNew[*i];
        printf("New Max HP: %d\nNew Current HP: %d\n", Pl.maxHP, Pl.HP);
    }
    else if (ID[*i] == 2)
    {
        Pl.MP = (calculateNew[*i] - Pl.maxMP) + Pl.MP;
        Pl.maxMP = calculateNew[*i];
        printf("New Max MP: %d\nNew Current MP: %d\n", Pl.maxMP, Pl.MP);
    }
    else if (ID[*i] == 3)
    {
        It.potionHeal = calculateNew[*i];
        printf("New Potion Heal Amount: %d\n", It.potionHeal);
    }
    else if (ID[*i] == 4)
    {
        It.etherRest = calculateNew[*i];
        printf("New Ether Restoration Amount: %d\n", It.etherRest);
    }
    else if (ID[*i] == 5)
    {
        Ma.burnChance = calculateNew[*i];
        printf("New Firaga Burn Chance: %d%%\n", Ma.burnChance);
    }
    else if (ID[*i] == 6)
    {
        Ma.freezeChance = calculateNew[*i];
        printf("New Blizzaga Freeze Chance: %d%%\n", Ma.freezeChance);
    }
    else if (ID[*i] == 7)
    {
        Ma.shockChance = calculateNew[*i];
        printf("New Thundaga Shock Chance: %d%%\n", Ma.shockChance);
    }
    else if (ID[*i] == 8)
    {
        Ma.confuseChance = calculateNew[*i];
        printf("New Aeroga Confuse Chance: %d%%\n", Ma.confuseChance);
    }
    else if (ID[*i] == 9)
    {
        At.zanteSuc = calculateNew[*i];
        printf("New Zantesuken success Chance: %d%%\n", At.zanteSuc);
    }
    reCalculate(selection,randoPerc,gPrice,calculateNew,ID);
    
}
void randomizeItems(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[])
{
    for (int i = 1; i <= 4; i++)
    {
        if (i == 1)
        {
        selection[i] = (rand() % 4) + 1;            //This guarantees that the first option relates to HP or MP, this makes the game easier and not screw you over
        randoPerc[i] = 0;
        }
        else
        {
            selection[i] = (rand() % 9) + 1;            //(rand() % X) + 1); with the X equaling the max ID value;
            randoPerc[i] = 0; 
        }
    }
    reCalculate(selection,randoPerc,gPrice,calculateNew,ID);
}
void reCalculate(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[])
{
    for (int i = 1; i <= 4; i++)
    {
        if (selection[i] == 1)
        {
            ID[i] = 1;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Pl.maxHP * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 2)
        {
            ID[i] = 2;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Pl.maxMP * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 3)
        {
            ID[i] = 3;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 20) + 15;
                gPrice[i] = randoPerc[i] * 0.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = It.potionHeal * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 4)
        {
            ID[i] = 4;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 20) + 15;
                gPrice[i] = randoPerc[i] * 0.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = It.etherRest * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 5)
        {
            ID[i] = 5;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.burnChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 6)
        {
            ID[i] = 6;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.freezeChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 7)
        {
            ID[i] = 7;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.8;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.shockChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 8)
        {
            ID[i] = 8;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.confuseChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 9)
        {
            ID[i] = 9;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 3) + 1;
                gPrice[i] = randoPerc[i] * 4;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = randoPerc[i] + At.zanteSuc;
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
    }
}
void statShop(int *shopChoi, int selection[], float randoPerc[], float gPrice[], float calculateNew[], int ID[])
{
    *shopChoi = 0;
    int statChoice = 0;
    do
    {
        printf("Stat Shop\t\t--Current G: %d --\n", Pl.G);
        for (int i = 1; i <= 4; i++)
        {
            if (selection[i] == -1)
            {
                printf("[%d] ---------------------\n",i);
            }
            else if (selection[i] == 1)
            {
                printf("[%d] %.0fG: Increase Max HP by %.0f%% (%dHP -> %.0fHP)\n", i, gPrice[i], randoPerc[i], Pl.maxHP, calculateNew[i]);
            }
            else if (selection[i] == 2)
            {
                printf("[%d] %.0fG: Increase Max MP by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], Pl.maxMP, calculateNew[i]);
            }
            else if (selection[i] == 3)
            {
                printf("[%d] %.0fG: Increase Potion Heal Amount by %.0f%% (%dHP -> %.0fHP)\n", i, gPrice[i], randoPerc[i], It.potionHeal, calculateNew[i]);
            }
            else if (selection[i] == 4)
            {
                printf("[%d] %.0fG: Increase Ether Restoration Amount by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], It.etherRest, calculateNew[i]);
            }
            else if (selection[i] == 5)
            {
                printf("[%d] %.0fG: Increase Firaga's Burn Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.burnChance, calculateNew[i]);
            }
            else if (selection[i] == 6)
            {
                printf("[%d] %.0fG: Increase Blizzaga's Freeze Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.freezeChance, calculateNew[i]);
            }
            else if (selection[i] == 7)
            {
                printf("[%d] %.0fG: Increase Thundaga's Shock Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.shockChance, calculateNew[i]);
            }
            else if (selection[i] == 8)
            {
                printf("[%d] %.0fG: Increase Aeroga's Confuse Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.confuseChance, calculateNew[i]);
            }
            else if (selection[i] == 9)
            {
                printf("[%d] %.0fG: Increase Zantesuken's success Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.zanteSuc, calculateNew[i]);
            }
    }
        printf("[5] 2G: Reroll Shop\n");
        printf("[6] Back\n");
        scanf("%d",&statChoice);
        if (statChoice == 1)
        {
            if (selection[statChoice] == -1)
            {
                printf("You already purchased this stat upgrade!\n");
            }
            else if (Pl.G < gPrice[statChoice])
            {
                printf("You don't have enough G to purchase this upgrade!\n");
            }
            else
            {
                Pl.G -= gPrice[statChoice];
                selection[statChoice] = -1;
                int i = 1;
                changeStats(selection, randoPerc, gPrice, calculateNew,ID, &i);
            }
        }
        else if (statChoice == 2)
        {
            if (selection[statChoice] == -1)
            {
                printf("You already purchased this stat upgrade!\n");
            }
            else if (Pl.G < gPrice[statChoice])
            {
                printf("You don't have enough G to purchase this upgrade!\n");
            }
            else
            {
                Pl.G -= gPrice[statChoice];
                selection[statChoice] = -1;
                int i = 2;
                changeStats(selection, randoPerc, gPrice, calculateNew, ID, &i);
            }
        }
        else if (statChoice == 3)
        {
            if (selection[statChoice] == -1)
            {
                printf("You already purchased this stat upgrade!\n");
            }
            else if (Pl.G < gPrice[statChoice])
            {
                printf("You don't have enough G to purchase this upgrade!\n");
            }
            else
            {
                Pl.G -= gPrice[statChoice];
                selection[statChoice] = -1;
                int i = 3;
                changeStats(selection, randoPerc, gPrice, calculateNew, ID, &i);
            }
        }
        else if (statChoice == 4)
        {
            if (selection[statChoice] == -1)
            {
                printf("You already purchased this stat upgrade!\n");
            }
            else if (Pl.G < gPrice[statChoice])
            {
                printf("You don't have enough G to purchase this upgrade!\n");
            }
            else
            {
                Pl.G -= gPrice[statChoice];
                selection[statChoice] = -1;
                int i = 4;
                changeStats(selection, randoPerc, gPrice, calculateNew, ID, &i);
            }
        }
        else if (statChoice == 5)
        {
            if (Pl.G < 2)
            {
                printf("You don't have enough G to reroll the shop!\n");
            }
            else
            {
                Pl.G -= 2;
                randomizeItems(selection,randoPerc,gPrice,calculateNew,ID);
                printf("Refreshed Stat Upgrade Shop!\n");
            }
        }
        else if (statChoice == 6)
        {
            printf("\n\n\n");
            return;
            statChoice = 0;
        }
        else
        {
        printf("Please enter a different number.\n");
        }
    } while (statChoice != 6);
}
#endif