#ifndef shopChoices
#define shopChoices
#include "endless.h"
void Shop(int *playing,int *modified, int *titleChoi)
{
    int instrucOption[3] = {0,0,0};
    int instrucG[3] = {0,0,0};
    int shopChoi = 0;
    En.burned = 0;
    En.frozen = 0;
    En.shocked = 0;
    En.confused = 0;            //cant let these carry over to the next battle
    Bo.burned = 0;
    Bo.frozen = 0;
    Bo.shocked = 0;
    Bo.confused = 0;
    int selection[24] = {0};
    float randoPerc[24] = {0};
    float gPrice[24] = {0};
    float calculateNew[24] = {0};
    int ID[24] = {0};
    Pl.bench = 1;       //indicator that the player is NOT in a battle (For using items)
    randomizeItems(selection,randoPerc,gPrice,calculateNew,ID);         //this is for the Stat Shop
    printf("End of battle %.0f\n", Un.battles);
        if ((int)Un.battles % 4 == 0)
        {
            Un.bossOrEnemy = 1;
            if ((int)Un.battles > 4)
            {
                double newBoHP = Bo.HP*1.25;        //boss gets 25% more HP each appearance
                newBoHP = round(newBoHP);
                Bo.HP = newBoHP;
                Bo.bossDamageMulti += 0.10;         //boss gets 10% stronger each appearance
            }
        }
        else
        {
            double newEnHP = En.HP*1.10;        //enemy gets 10% more HP each appearance
            newEnHP = round(newEnHP);
            En.HP = newEnHP;
            Un.bossOrEnemy = 0;
            En.enemyDamageMulti += 0.03;        //enemy gets 3% stronger each appearance
        }
    do
    {  
        if (Un.bossOrEnemy == 1)
        {
             printf("\033[0;31mA strong presence is nearby...\033[0m\n");           //spooky message for when the next round is a boss battle
        }
        printf("Select a Choice\n");
        printf("[1] Purchase Items\n");
        printf("[2] Purchase Stat upgrades\n");
        printf("[3] Purchase New Moves and Spells\n");
        printf("[4] Use current items\n");
        printf("[5] Continue to next round\n");
        printf("[6] Quit\n");
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
                //printf("[5] 20G: Dire Hit (Increases attack power for 5 turns)\n");                   //cut content!
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
            newMoves(instrucOption,instrucG);
        }
        else if (shopChoi == 4)
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
            printf("\033[0;34m*Frozen \033[0m");
        }
        if (Pl.shocked == 1)
        {
            printf("\033[0;33m*Shocked \033[0m");
        }
        if (Pl.confused == 1)
        {
            printf("\033[0;35m*Confused \033[0m");
        }
            int *temp = 0;      //a temporary substitute for the *blocked integer as enemyTurn nor bossTurn should be callled if items is called from here
            Items(temp);        //if Pl.bench == 1, then it skips the enemyTurn and bossTurn and comes back here
        }
        else if (shopChoi == 5)
        {
            Pl.bench = 0;
            mainMenu(playing,modified,titleChoi);
        }
        else if (shopChoi == 6)
        {
            printf("Ended game on round %.0f\n",Un.battles+1);
            printf("Remaining HP: %d/%d\n",Pl.HP,Pl.maxHP);
            printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
            printf("Potions Used: %d\nEthers Used: %d\n", It.potionUsed, It.etherUsed);
            printf("Panaceas Used: %d\n", It.panaceaUsed);
            printf("Total Experience: %d\n", Pl.experience);
            int playChoice = 0;
            do
            {
                if (Pl.bench == 1)
                {
                    printf("\n\nPlay Again?\n[1] Yes\n[2] No\n");
                    scanf("%d", &playChoice);
                    if (playChoice == 1)
                    {
                        if (*modified == 1)
                        {
                            int saveChoice;
                            do
                            {
                                printf("\n\n\nIt appears you were using modified settings! Would you like to save them for the next battle?\n");
                                printf("[1] Yes\n[2] No\n");
                                scanf("%d", &saveChoice);
                                if (saveChoice == 1)
                                {
                                    Pl.HP = Pl.maxHP;
                                    Pl.MP = Pl.maxMP;    //all of these need to be returned to max or else one of these will be 0 (or both HPs or all 3)
                                    En.HP = En.maxHP;      //others dont need this treatment as they dont change throughout the battle
                                    Bo.HP = Bo.maxHP;
                                    It.potionC = It.maxPotionCount;
                                    It.etherC = It.maxEtherCount; 
                                    It.panaceaC = It.maxPanaceaCount;
                                    *titleChoi = 0;
                                    En.burned = 0, En.frozen = 0, En.shocked = 0, En.confused = 0;
                                    Bo.burned = 0, Bo.frozen = 0, Bo.shocked = 0, Bo.confused = 0;
                                }
                                else if (saveChoice == 2)
                                {
                                    *modified = 0;
                                    En.burned = 0, En.frozen = 0, En.shocked = 0, En.confused = 0;
                                    Bo.burned = 0, Bo.frozen = 0, Bo.shocked = 0, Bo.confused = 0;
                                }
                                else
                                {
                                    printf("Please enter a different number.\n");
                                }
                            } while (saveChoice < 1 || saveChoice > 2);
                        }
                        else if (*modified == 0)
                        { 
                            initialize();
                            Pl.bench = 1;
                        }
                        Un.battles = 0;
                        printf("Starting Terminal Battle Again!\n");
                        *playing = 0;
                        continue;
                    }
                    else if (playChoice == 2)
                    {
                    exit(1);
                    }
                    else
                    {
                    printf("Please enter a different number.\n");
                    }
                }
            } while (playChoice < 1 || playChoice > 2);
        }
    } while (shopChoi < 1 || shopChoi > 6);
}
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
        printf("New Fire Burn Chance: %d%%\n", Ma.burnChance);
    }
    else if (ID[*i] == 6)
    {
        Ma.freezeChance = calculateNew[*i];
        printf("New Blizzard Freeze Chance: %d%%\n", Ma.freezeChance);
    }
    else if (ID[*i] == 7)
    {
        Ma.shockChance = calculateNew[*i];
        printf("New Thunder Shock Chance: %d%%\n", Ma.shockChance);
    }
    else if (ID[*i] == 8)
    {
        Ma.confuseChance = calculateNew[*i];
        printf("New Aero Confuse Chance: %d%%\n", Ma.confuseChance);
    }
    else if (ID[*i] == 9)
    {
        At.critHitSuc = calculateNew[*i];
        printf("New Critical Hit success Chance: %d%%\n", At.critHitSuc);
    }
    else if (ID[*i] == 10)
    {
        At.luckyMP = calculateNew[*i];
        printf("New Lucky Strike MP Cost: %dMP\n", At.luckyMP);
    }
    else if (ID[*i] == 11)
    {
        At.quickdrawMP = calculateNew[*i];
        printf("New Quickdraw MP Cost: %dMP\n", At.quickdrawMP);
    }
    else if (ID[*i] == 12)
    {
        At.arsMP = calculateNew[*i];
        printf("New Ars Arcanum MP Cost: %dMP\n", At.arsMP);
    }
    else if (ID[*i] == 13)
    {
        Ma.fireMP = calculateNew[*i];
        printf("New Fire MP Cost: %dMP\n", Ma.fireMP);
    }
    else if (ID[*i] == 14)
    {
        Ma.blizzardMP = calculateNew[*i];
        printf("New Blizzard MP Cost: %dMP\n", Ma.blizzardMP);
    }
    else if (ID[*i] == 15)
    {
        Ma.thunderMP = calculateNew[*i];
        printf("New Thunder MP Cost: %dMP\n", Ma.thunderMP);
    }
    else if (ID[*i] == 16)
    {
        Ma.aeroMP = calculateNew[*i];
        printf("New Aero MP Cost: %dMP\n", Ma.aeroMP);
    }
    else if (ID[*i] == 17)
    {
        At.lightBlock = calculateNew[*i];
        printf("New Light Attack Block Rate: %d%%\n", At.lightBlock);
    }
    else if (ID[*i] == 18)
    {
        At.heavyBlock = calculateNew[*i];
        printf("New Heavy Attack Block Rate: %d%%\n", At.heavyBlock);
    }
    else if (ID[*i] == 19)
    {
        At.luckyBlock = calculateNew[*i];
        printf("New Lucky Block Rate: %d%%\n", At.luckyBlock);
    }
    else if (ID[*i] == 20)
    {
        At.arsBlock = calculateNew[*i];
        printf("New Ars Arcanum Block Rate: %d%%\n", At.arsBlock);
    }
    else if (ID[*i] == 21)
    {
        At.critHitBlock = calculateNew[*i];
        printf("New Critical Hit Block Rate: %d%%\n", At.critHitBlock);
    }
    else if (ID[*i] == 22)
    {
        Ma.blizzardMiss = calculateNew[*i];
        printf("New Blizzard Miss Rate: %d%%\n", Ma.blizzardMiss);
    }
    else if (ID[*i] == 23)
    {
        Ma.thunderMiss = calculateNew[*i];
        printf("New Thunder Miss Rate: %d%%\n", Ma.thunderMiss);
    }
    else if (ID[*i] == 24)
    {
        Ma.aeroMiss = calculateNew[*i];
        printf("New Aero Miss Rate: %d%%\n", Ma.aeroMiss);
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
            selection[i] = (rand() % 24) + 1;            //(rand() % X) + 1); with the X equaling the max ID value;
            randoPerc[i] = 0; 
        }
    }
    reCalculate(selection,randoPerc,gPrice,calculateNew,ID);
}
void reCalculate(int selection[],float randoPerc[],float gPrice[],float calculateNew[],int ID[])
{
    for (int i = 1; i <= 4; i++)
    {
        if (selection[i] == 1)          //Increase Max HP
        {
            ID[i] = 1;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.2;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Pl.maxHP * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 2)     //Increase Max MP
        {
            ID[i] = 2;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Pl.maxMP * (1 + (randoPerc[i]*0.01));
            calculateNew[i] = round(calculateNew[i]);
        }
        else if (selection[i] == 3)     //Increase Potion Heal Amount
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
        else if (selection[i] == 4)     //Increase Ether Restoration Amount
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
        else if (selection[i] == 5)         //Increase Fire's Burn Chance
        {
            ID[i] = 5;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.burnChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 6)     //Increase Blizzard's Freeze Chance
        {
            ID[i] = 6;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.freezeChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 7)     //Increase Thunder's Shock Chance
        {
            ID[i] = 7;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.shockChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 8)     //Increase Aero's Confuse Chance
        {
            ID[i] = 8;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = Ma.confuseChance + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 9)     //Increase Critical Hit's Success Rate
        {
            ID[i] = 9;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 3) + 1;
                gPrice[i] = randoPerc[i] * 4;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = randoPerc[i] + At.critHitSuc;
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 10)     //Decrease Lucky Strike's MP Cost
        {
            ID[i] = 10;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 50) + 25;
                gPrice[i] = randoPerc[i] * 0.4;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(At.luckyMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 11)     //Decrease Quickdraw's MP Cost
        {
            ID[i] = 11;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 50) + 25;
                gPrice[i] = randoPerc[i] * 0.5;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(At.quickdrawMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 15)       //this is higher to prevent Quickdraw Spam
            {
                calculateNew[i] = 15;
            }
        }
        else if (selection[i] == 12)     //Decrease Ars Arcanum's MP Cost
        {
            ID[i] = 12;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 20;
                gPrice[i] = randoPerc[i] * 0.6;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(At.arsMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 13)     //Decrease Fire's MP Cost
        {
            ID[i] = 13;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 50) + 25;
                gPrice[i] = randoPerc[i] * 0.4;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.fireMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 14)     //Decrease Blizzard's MP Cost
        {
            ID[i] = 14;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 50) + 25;
                gPrice[i] = randoPerc[i] * 0.4;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.blizzardMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 15)     //Decrease Thunder's MP Cost
        {
            ID[i] = 15;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 15) + 25;
                gPrice[i] = randoPerc[i] * 0.5;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.thunderMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 16)     //Decrease Aero's MP Cost
        {
            ID[i] = 16;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 20) + 25;
                gPrice[i] = randoPerc[i] * 0.5;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.aeroMP/(1 + (randoPerc[i]*0.01)));
            if (calculateNew[i] <= 1)
            {
                calculateNew[i] = 1;
            }
        }
        else if (selection[i] == 17)     //Increase Light Attack's Block Rate
        {
            ID[i] = 17;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 0.9;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = At.lightBlock + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 18)     //Increase Heavy Attack's Block Rate
        {
            ID[i] = 18;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 15) + 10;
                gPrice[i] = randoPerc[i] * 1;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = At.heavyBlock + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 19)     //Increase Lucky Strike's Block Rate
        {
            ID[i] = 19;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 20) + 10;
                gPrice[i] = randoPerc[i] * 1.2;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = At.luckyBlock + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 20)     //Increase Ars Arcanum's Block Rate
        {
            ID[i] = 20;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 15) + 5;
                gPrice[i] = randoPerc[i] * 0.6;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = At.arsBlock + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 21)     //Increase Critical Hit's Block Rate
        {
            ID[i] = 21;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 20) + 20;
                gPrice[i] = randoPerc[i] * 0.2;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = At.critHitBlock + randoPerc[i];
            calculateNew[i] = round(calculateNew[i]);
            if (calculateNew[i] > 100)
            {
                calculateNew[i] = 100;
            }
        }
        else if (selection[i] == 22)     //Decrease Blizzard's Miss Rate
        {
            ID[i] = 22;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 5;
                gPrice[i] = randoPerc[i] * 1.25;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.aeroMiss - randoPerc[i]);
            if (calculateNew[i] <= 0)
            {
                calculateNew[i] = 0;
            }
        }
        else if (selection[i] == 23)     //Decrease Thunder's Miss Rate
        {
            ID[i] = 23;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 15) + 10;
                gPrice[i] = randoPerc[i] * 1.3;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.thunderMiss - randoPerc[i]);
            if (calculateNew[i] <= 0)
            {
                calculateNew[i] = 0;
            }
        }
        else if (selection[i] == 24)     //Decrease Aero's Miss Rate
        {
            ID[i] = 24;
            if (randoPerc[i] == 0)
            {
                randoPerc[i] = (rand() % 10) + 10;
                gPrice[i] = randoPerc[i] * 1.5;
                gPrice[i] = round(gPrice[i]);
            }
            calculateNew[i] = round(Ma.aeroMiss - randoPerc[i]);
            if (calculateNew[i] <= 0)
            {
                calculateNew[i] = 0;
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
        printf("Stat Shop\t\t---Current G: %d---\n", Pl.G);
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
                printf("[%d] %.0fG: Increase Fire's Burn Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.burnChance, calculateNew[i]);
            }
            else if (selection[i] == 6)
            {
                printf("[%d] %.0fG: Increase Blizzard's Freeze Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.freezeChance, calculateNew[i]);
            }
            else if (selection[i] == 7)
            {
                printf("[%d] %.0fG: Increase Thunder's Shock Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.shockChance, calculateNew[i]);
            }
            else if (selection[i] == 8)
            {
                printf("[%d] %.0fG: Increase Aero's Confuse Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.confuseChance, calculateNew[i]);
            }
            else if (selection[i] == 9)
            {
                printf("[%d] %.0fG: Increase Critical Hit's success Chance by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.critHitSuc, calculateNew[i]);
            }
            else if (selection[i] == 10)
            {
                printf("[%d] %.0fG: Decrease Lucky Strike's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], At.luckyMP, calculateNew[i]);
            }
            else if (selection[i] == 11)
            {
                printf("[%d] %.0fG: Decrease Quickdraw's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], At.quickdrawMP, calculateNew[i]);
            }
            else if (selection[i] == 12)
            {
                printf("[%d] %.0fG: Decrease Ars Arcanum's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], At.arsMP, calculateNew[i]);
            }
            else if (selection[i] == 13)
            {
                printf("[%d] %.0fG: Decrease Fire's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], Ma.fireMP, calculateNew[i]);
            }
            else if (selection[i] == 14)
            {
                printf("[%d] %.0fG: Decrease Blizzard's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], Ma.blizzardMP, calculateNew[i]);
            }
            else if (selection[i] == 15)
            {
                printf("[%d] %.0fG: Decrease Thunder's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], Ma.thunderMP, calculateNew[i]);
            }
            else if (selection[i] == 16)
            {
                printf("[%d] %.0fG: Decrease Aero's MP Cost by %.0f%% (%dMP -> %.0fMP)\n", i, gPrice[i], randoPerc[i], Ma.aeroMP, calculateNew[i]);
            }
            else if (selection[i] == 17)
            {
                printf("[%d] %.0fG: Increase Light Attack's Block Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.lightBlock, calculateNew[i]);
            }
            else if (selection[i] == 18)
            {
                printf("[%d] %.0fG: Increase Heavy Attack's Block Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.heavyBlock, calculateNew[i]);
            }
            else if (selection[i] == 19)
            {
                printf("[%d] %.0fG: Increase Lucky Strike's Block Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.luckyBlock, calculateNew[i]);
            }
            else if (selection[i] == 20)
            {
                printf("[%d] %.0fG: Increase Ars Arcanum's Block Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.arsBlock, calculateNew[i]);
            }
            else if (selection[i] == 21)
            {
                printf("[%d] %.0fG: Increase Critical Hit's Block Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], At.critHitBlock, calculateNew[i]);
            }
            else if (selection[i] == 22)
            {
                printf("[%d] %.0fG: Decrease Blizzard's Miss Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.blizzardMiss, calculateNew[i]);
            }
            else if (selection[i] == 23)
            {
                printf("[%d] %.0fG: Decrease Thunder's Miss Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.thunderMiss, calculateNew[i]);
            }
            else if (selection[i] == 24)
            {
                printf("[%d] %.0fG: Decrease Aero's Miss Rate by %.0f Percentage Points (%d%% -> %.0f%%)\n", i, gPrice[i], randoPerc[i], Ma.aeroMiss, calculateNew[i]);
            }
    }
        printf("[5] 1G: Reroll Shop\n");
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
            if (Pl.G < 1)
            {
                printf("You don't have enough G to reroll the shop!\n");
            }
            else
            {
                Pl.G -= 1;
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
void checkForMoves(int amount, int instrucOption[], int instrucG[])
{
    int failed = 0;
    do
    {
        failed = 0;
        instrucOption[1] = (rand() % 8) + 1;
        instrucOption[2] = (rand() % 8) + 1;
        instrucOption[3] = (rand() % 8) + 1;
        for (int i = 1; i <= amount; i++)
        {
            if (instrucOption[i] == 1 && Pl.hasLucky == 1)
            {
                instrucG[i] = 30;
                failed = 1;
            }
            if (instrucOption[i] == 2 && Pl.hasQuick == 1)
            {
                instrucG[i] = 30;
                failed = 1;
            }
            if (instrucOption[i] == 3 && Pl.hasArs == 1)
            {
                instrucG[i] = 30;
                failed = 1;
            }
            if (instrucOption[i] == 4 && Pl.hasCritHit == 1)
            {
                instrucG[i] = 10;
                failed = 1;
            }
            if (instrucOption[i] == 5 && Pl.hasFire == 1)
            {
                instrucG[i] = 10;
                failed = 1;
            }
            if (instrucOption[i] == 6 && Pl.hasBlizzard == 1)
            {
                instrucG[i] = 10;
                failed = 1;
            }
            if (instrucOption[i] == 7 && Pl.hasThunder == 1)
            {
                instrucG[i] = 30;
                failed = 1;
            }
            if (instrucOption[i] == 8 && Pl.hasAero == 1)
            {
                instrucG[i] = 30;
                failed = 1;
            }
            if (instrucOption[1] == instrucOption[2] || instrucOption[1] == instrucOption[3] || instrucOption[2] == instrucOption[3])
            {
                failed = 1;         //checks to make sure every value is different, every book is different and no dupes)
            }
        }
    } while (failed == 1);
}
int unlearnCount()
{
    int unlearned = 0;
    if (Pl.hasLucky == 0)
    {
        unlearned++;
    }
    if (Pl.hasQuick == 0)
    {
        unlearned++;
    }
    if (Pl.hasArs == 0)
    {
        unlearned++;
    }
    if (Pl.hasCritHit == 0)
    {
        unlearned++;
    }
    if (Pl.hasFire == 0)
    {
        unlearned++;
    }
    if (Pl.hasBlizzard == 0)
    {
        unlearned++;
    }
    if (Pl.hasThunder == 0)
    {
        unlearned++;
    }
    if (Pl.hasAero == 0)
    {
        unlearned++;
    }
    return unlearned;
}
void newMoves(int instrucOption[], int instrucG[])
{
    int back = 0;
    int unlearned = 0;
    int amount = 0;
    unlearnCount();
    if (unlearnCount() >= 3)
    {
        amount = 3;
        back = 4;
        checkForMoves(amount,instrucOption,instrucG);
    }
    else if (unlearnCount() == 2)
    {
        back = 3;
        amount = 2;
        checkForMoves(amount,instrucOption,instrucG);
    }
    else if (unlearnCount() == 1)
    {
        back = 2;
        amount = 1;
        checkForMoves(amount,instrucOption,instrucG);
    }
    else
    {
        back = 1;
    }
    int instrucChoi = 0;
    do
    {
            printf("Intruction Shop\n");
            if (unlearnCount() == 0)
            {
                printf("You have learned all there is to know!\n");
            }
            else
            {
                for (int i = 1; i <= amount; i++)
                {
                    if (instrucOption[i] == 1)
                    {
                        instrucG[i] = 30;
                        printf("[%d] 30G: Lucky Strike\t\t\t(Low Damage, HP and MP restoration chance, %d%% Block Rate, %d MP)\n", i, At.luckyBlock, At.luckyMP);
                    }
                    else if (instrucOption[i] == 2)
                    {
                        instrucG[i] = 30;
                        printf("[%d] 30G: Quickdraw\t\t\t(Moderate Damage, skips enemy turn, %d MP)\n", i, At.quickdrawMP);
                    }
                    else if (instrucOption[i] == 3)
                    {
                        instrucG[i] = 30;
                        printf("[%d] 30G: Ars Arcanum\t\t\t(Massive Damage, %d%% Block Rate, %d MP)\n", i, At.arsBlock, At.arsMP);
                    }
                    else if (instrucOption[i] == 4)
                    {
                        instrucG[i] = 10;
                        printf("[%d] 10G: Critical Hit\t\t\t(Super small damage, %d%% Chance for instant death, %d%% Block Rate, %d MP)\n", i, At.critHitSuc, At.critHitBlock, At.critHitMP);
                    }
                    else if (instrucOption[i] == 5)
                    {
                        instrucG[i] = 10;
                        printf("[%d] 10G: Fire\t\t\t\t(Low Damage, %d%% Chance to Burn, %d%% Chance to miss, %dMP)\n", i, Ma.burnChance, Ma.fireMiss, Ma.fireMP);
                    }
                    else if (instrucOption[i] == 6)
                    {
                        instrucG[i] = 10;
                        printf("[%d] 10G: Blizzard\t\t\t(Medium Damage, %d%% Chance to Freeze, %d%% Chance to miss, %dMP)\n", i, Ma.freezeChance, Ma.blizzardMiss, Ma.blizzardMP);
                    }
                    else if (instrucOption[i] == 7)
                    {
                        instrucG[i] = 30;
                        printf("[%d] 30G: Thunder\t\t\t(Large Damage, %d%% Chance to Shock, %d%% Chance to miss, %dMP)\n", i, Ma.shockChance, Ma.thunderMiss, Ma.thunderMP);
                    }
                    else if (instrucOption[i] == 8)
                    {
                        instrucG[i] = 30;
                        printf("[%d] 30G: Aero\t\t\t\t(Medium Damage, %d%% Chance to Confuse, %d%% Chance to miss, %dMP)\n", i, Ma.confuseChance, Ma.aeroMiss, Ma.aeroMP);
                    }
                }
            }
        printf("[%d] Back\n",back);
        scanf("%d", &instrucChoi);
        if (instrucChoi == 1)
        {
            if (Pl.G <= instrucG[instrucChoi])
            {
                printf("You don't have enough G!\n");
            }
            else
            {
                Pl.G -= instrucG[instrucChoi];
                learnMoves(instrucChoi,instrucOption);
            }
        }
        else if (instrucChoi == 2)
        {
            if (Pl.G <= instrucG[instrucChoi])
            {
                printf("You don't have enough G!\n");
            }
            else
            {
                Pl.G -= instrucG[instrucChoi];
                learnMoves(instrucChoi,instrucOption);
            }
        }
        else if (instrucChoi == 3)
        {
            if (Pl.G <= instrucG[instrucChoi])
            {
                printf("You don't have enough G!\n");
            }
            else
            {
                Pl.G -= instrucG[instrucChoi];
                learnMoves(instrucChoi,instrucOption);
            }
        }
        else if (instrucChoi == back)
        {
            printf("\n\n\n");
            return;
            instrucChoi = 0;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (instrucChoi < 1 || instrucChoi > back);
}
void learnMoves(int instrucChoi, int instrucOption[])
{
    if (instrucOption[instrucChoi] == 1)
    {
        Pl.hasLucky = 1;
        printf("Successfully learned Lucky Strike!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 2)
    {
        Pl.hasQuick = 1;
        printf("Successfully learned Quickdraw!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 3)
    {
        Pl.hasArs = 1;
        printf("Successfully learned Ars Arcanum!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 4)
    {
        Pl.hasCritHit = 1;
        printf("Successfully learned Critical Hit!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 5)
    {
        Pl.hasFire = 1;
        printf("Successfully learned Fire!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 6)
    {
        Pl.hasBlizzard = 1;
        printf("Successfully learned Blizzard!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 7)
    {
        Pl.hasThunder = 1;
        printf("Successfully learned Thunder!\n");
        unlearnCount();
    }
    else if (instrucOption[instrucChoi] == 8)
    {
        Pl.hasAero = 1;
        printf("Successfully learned Aero!\n");
        unlearnCount();
    }
}
#endif
