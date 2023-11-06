#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "options.h"
#include "endless.h"
#include "statChoices.h"
//(rand()%100) + 1; is used throughout the program, this is range 1 - 100 (Inclusive)
void enemyTurn(int *blocked)
{
    if (Pl.burned == 1)
    {
        Pl.HP -= Pl.burnDamage;
        printf("You took %d additional \033[0;31mburn\033[0m damage!\n", Pl.burnDamage);
    }
    int enemyBurn = 0;
    int enemyConfuseChance = 0;
    int confusedDamage = 0;
    int totalBlockDamage = 0;
    int totalConfuseDamage = 0; //all these are used later in the function
    if (En.frozen == 1)
    {
        printf("%s has fully \033[0;34mthawed out!\033[0m\n", En.name);
        En.frozen -= 1;
    }
    if (En.burned == 1)
    {
        enemyBurn = (rand() % 50) + 25;
    }
    if (En.HP <= 0)
    {
        return;
    }
    else
    {
        if (En.frozen <= 0)
        {
            int enemyAttack = (rand() % 100) + 1;
            if (En.confused == 1)
            {
                enemyConfuseChance = (rand() % 100) + 1;
            }
            if (En.shocked == 1)
            {
                int furtherMiss = (rand() % 100) + 1;
                if (furtherMiss > 70)   //This is a 30% chance that they will miss due to shock
                {
                    printf("%s couldn't attack due to being \033[0;33mshocked!\033[0m\n", En.name);
                    enemyAttack = 0;
                }
            }
            if (enemyAttack > 0 && enemyAttack <= 40)
            {   //just when we figured out a solution for enemy name, now we need to find enemy attack names ;^;
                int enemyDamage = (rand() % 75) + 50;
                printf("%s used Rolling Kick and dealt %d Damage!\n", En.name, enemyDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = enemyDamage - enemyDamage*blockedDamage;
                    enemyDamage = enemyDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (enemyConfuseChance > 50)
                {
                    double confusedDamage = (rand() % 25) + 25;
                    confusedDamage *= 0.01;
                    En.HP -= enemyDamage * confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, enemyDamage * confusedDamage);
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 40 && enemyAttack <= 70)
            {
                int enemyDamage = (rand() % 125) + 100;
                int burnChance = (rand() % 100) + 1;
                printf("%s used Heat Haze and dealt %d Damage!\n", En.name,enemyDamage);
                if (Un.battles >= 3)
                {
                    int burnChance = (rand() % 100) + 1;
                    if (burnChance > 15);
                    {
                        printf("You have been \033[0;31mburned\033[0m by %s's Heat Haze!\n", En.name);
                        Pl.burned = 1;
                    }
                }
                 if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = enemyDamage - enemyDamage*blockedDamage;
                    enemyDamage = enemyDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (enemyConfuseChance > 50)
                {
                    double confusedDamage = (rand() % 25) + 25;
                    confusedDamage *= 0.01;
                    En.HP -= enemyDamage * confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, enemyDamage * confusedDamage);
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 70 && enemyAttack <=85)
            {
                int enemyDamage = (rand() % 175) + 175;
                printf("%s used Angel Blow and dealt %d Damage!\n", En.name, enemyDamage);
                 if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = enemyDamage - enemyDamage*blockedDamage;
                    enemyDamage = enemyDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (enemyConfuseChance > 50)
                {
                    double confusedDamage = (rand() % 25) + 25;
                    confusedDamage *= 0.01;
                    En.HP -= enemyDamage * confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, enemyDamage * confusedDamage);
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 85 && enemyAttack <= 100)
            {
            printf("%s went for an attack but missed!\n", En.name);
            }
            else if (enemyAttack > 100 && enemyAttack <= 110)
            {
                int enemyDamage = (rand() % 300) + 1;
                int harmonicStatus = (rand() % 100) + 1;
                printf("%s used Harmonic Rhythm and dealt %d damage", En.name, enemyDamage);
                if (enemyConfuseChance > 50)
                {
                    double confusedDamage = (rand() % 25) + 25;
                    confusedDamage *= 0.01;
                    En.HP -= enemyDamage * confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, enemyDamage * confusedDamage);
                }
                if (harmonicStatus >= 0 && harmonicStatus < 20)
                {
                    Pl.burned == 1;
                    printf("You have been \033[0;31mburned\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                else if (harmonicStatus >= 20 && harmonicStatus < 40)
                {
                    Pl.frozen ==  (rand() % 3) + 1;
                    printf("You have been \033[0;34mfrozen\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                else if (harmonicStatus >= 40 && harmonicStatus < 60)
                {
                    Pl.shocked == 1;
                    printf("You have been \033[0;33mshocked\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                    else if (harmonicStatus >= 60 && harmonicStatus < 80)
                {
                    Pl.confused == 1;
                    printf("You have been \033[0;35mconfused\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                 if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = enemyDamage - enemyDamage*blockedDamage;
                    enemyDamage = enemyDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
            }
        }
        else
        {
            if (En.frozen >= 1)
            {
                printf("%s is \033[0;34mfrozen solid\033[0m for %d more turn", En.name, En.frozen-1);
                if (En.frozen - 1 == 1)
                {
                    printf("!\n");
                    En.frozen -= 1;
                }
                if (En.frozen - 1 > 1)
                {
                    printf("s!\n");             //this and the previous printf statements are for plural turns
                    En.frozen -= 1;
                }
            }
        }
    }
    if (En.burned == 1)
    {
        printf("%s took %d additional \033[0;31mburn\033[0m damage\n", En.name, enemyBurn);
        En.HP -= enemyBurn;
    }
}
void specialAttacks(int *attackChoice, int *blocked)
{
    int specialChoice = 0;
    printf("\n\n\n");
    do
    {
    printf("Special Attacks:\n\t\t---Current MP: %d---\n", Pl.MP);
    printf("[1] Lucky Strike (Low Damage, HP and MP restoration chance, %d%% Block Rate, %d MP)\n", At.luckyBlock, At.luckyMP);
    printf("[2] Sonic Blade (Moderate Damage, skips enemy turn, %d MP)\n", At.sonicMP);
    printf("[3] Ars Arcanum (Massive Damage, %d%% Block Rate, %d MP)\n", At.arsBlock, At.arsMP);
    printf("[4] Zantesuken (Super small damage, %d%% Chance for instant death, %d%% Block Rate, %d MP)\n", At.zanteSuc, At.zanteBlock, At.zanteMP);
    printf("[5] Back\n");
    scanf("%d", &specialChoice);
    if (Pl.frozen > 1 && specialChoice != 5)
    {
        *attackChoice = 4;
        printf("You are still \033[0;34mfrozen solid\033[0m for %d turns!\n", Pl.frozen);
        Pl.frozen -= 1;
        enemyTurn(blocked);
    }
    else if (Pl.frozen == 1 && specialChoice != 5)
    {
        *attackChoice = 4;
        printf("You have \033[0;34munthawed from being frozen\033[0m!\n");
        Pl.frozen -= 1;
        enemyTurn(blocked);
    }
    else if (Pl.shockSucc == 100)
    {
        if (specialChoice > 0 && specialChoice <= 4)
        {
            printf("You missed your special attack due to being \033[0;33mshocked\033[0m\n");
            enemyTurn(blocked);
        }
    }
    else if (specialChoice == 1)
    {
        if (Pl.MP >= At.luckyMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.luckyMP;
            int luckyAttackDamage = (rand() % 50) + 60;
            int luckyBlock = (rand()%100) + 1;
            if (luckyBlock > 100 - At.luckyBlock)
            {
                *blocked = 1;
            }
            En.HP -= luckyAttackDamage;
            printf("Dealt %d damage using Lucky Strike!\n", luckyAttackDamage);
            int restoreHPMP = (rand() % 100) + 1;
            if (restoreHPMP <= 25)
            {
                int restoreamoHP = (rand() % 150) + 50;
                Pl.HP += restoreamoHP;
                if (Pl.HP > Pl.maxHP)
                {
                     Pl.HP = Pl.maxHP;
                }
                printf("Restored %d HP!\n",restoreamoHP);
            }
            else if (restoreHPMP > 25 && restoreHPMP <= 50)
            {
                int restoreamoMP = (rand() % 10) + 20;
                Pl.MP += restoreamoMP;
                if (Pl.MP > Pl.maxHP)
                {
                    Pl.MP = Pl.maxMP;
                }
                printf("Restored %d MP!\n", restoreamoMP);
            }
            else if (restoreHPMP > 50 && restoreHPMP <= 75)
            {
                int restoreamoHP = (rand() % 150) + 50;
                int restoreamoMP = (rand() % 10) + 20;
                Pl.HP += restoreamoHP;
                Pl.MP += restoreamoMP;
                if (Pl.HP > Pl.maxHP)
                {
                    Pl.HP = Pl.maxHP;
                }
                if (Pl.MP > Pl.maxMP)
                {
                    Pl.MP = Pl.maxMP;
                }
                printf("Restored %d HP and %d MP!\n", restoreamoHP, restoreamoMP);
            }
            else
            {
                printf("Restored neither HP nor MP...\n");
            }
            enemyTurn(blocked);
        }
        else
        {
            printf("You don't have enough MP to use Lucky Strike!\n");
        }
    }
    else if (specialChoice == 2)
    {
        if (Pl.MP >= At.sonicMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.sonicMP;
            int sonicBlade = (rand() % 200) + 100;
            En.HP -= sonicBlade;
            printf("Dealt %d damage using Sonic Blade!\n", sonicBlade);
            printf("%s's turn was skipped!\n", En.name);
        }
        else
        {
            printf("You don't have enough MP to use Sonic Blade!\n");
        }
    }
    else if (specialChoice == 3)
    {
        if (Pl.MP >= At.arsMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.arsMP;
            int arsArcanum = (rand() % 400) + 300;
            int arsBlock = (rand() % 100) + 1;
            En.HP -= arsArcanum;
            printf("Dealt %d damage using Ars Arcanum!\n", arsArcanum);
            if (arsBlock > 100 - At.arsBlock)
            {
                *blocked = 1;
            }
            enemyTurn(blocked);
        }
        else
        {
            printf("You don't have enough MP to use Ars Arcanum!\n");
        }
    }
    else if (specialChoice == 4)
    {
        if (Pl.MP >= At.zanteMP)
            {
            *attackChoice = 4;
            Pl.MP -= At.zanteMP;
            int zantChance = (rand() % 100) + 1;
            int zantDamage = (rand() % 2) + 1;
            int zantBlock = (rand()% 100)+ 1;
            if (zantBlock > 100 - At.zanteBlock)
            {
                *blocked = 1;
            }
            if (zantChance > 100 - At.zanteSuc)
            {
                printf("Zantesuken succeded, dealt %d damage!!\n", En.HP);
                Pl.expMulti -= 0.25;
                En.HP = 0;
                enemyTurn(blocked);
            }
            else
            {
                En.HP -= zantDamage;
                printf("Dealt %d damage using Zantesuken...\n", zantDamage);
                enemyTurn(blocked);
            }
        }
        else
        {
            printf("You don't have enough MP to use Zantesuken!\n");
        }
    }
    else if (specialChoice == 5)
    {
        printf("\n\n\n");
        continue;
    }
    else
    {
        printf("\n\n\n");
        printf("Please enter a different number.\n");
    }
    } while (specialChoice < 1 || specialChoice > 5);
}
void Attack(int *blocked)
{
    int attackChoice = 0;
    do
    {
        printf("\n\n\n");
        printf("Attacks Choices:\n");
        printf("[1] Light Attack (Low Damage, %d%% Block Rate)\n", At.lightBlock);
        printf("[2] Heavy Attack (High Damage, %d%% Block Rate)\n", At.heavyBlock);
        printf("[3] Special Attacks\n");
        printf("[4] Back\n");
        scanf("%d", &attackChoice);
        if (Pl.frozen > 1)
        {
            if (attackChoice > 0 && attackChoice <= 2)
            {
                printf("You are still \033[0;34mfrozen solid\033[0m for %d turns!\n", Pl.frozen);
                Pl.frozen -= 1;
                enemyTurn(blocked);
            }
        }
        else if (Pl.frozen == 1)
        {
            if (attackChoice > 0 && attackChoice <= 2)
            {
                printf("You have \033[0;34munthawed from being frozen\033[0m!\n");
                Pl.frozen -= 1;
                enemyTurn(blocked);
            }
        }
        else if (Pl.shockSucc == 100)
        {
            if (attackChoice > 0 && attackChoice <= 2)
            {
                printf("You missed your attack due to being \033[0;33mshocked\033[0m\n");
                enemyTurn(blocked);
            }
        }
        else if (attackChoice == 1)
        {
            int lightAttackDamage = (rand() % 50) + 80;
            int lightBlock = (rand()%100)+1;
            if (lightBlock > 100 - At.lightBlock)
            {
                *blocked = 1;
            }
            En.HP -= lightAttackDamage;
            printf("Dealt %d damage using a light attack!\n", lightAttackDamage);
            enemyTurn(blocked);
        }
        else if (attackChoice == 2)
        {
            int heavyAttackDamage = (rand() % 60) + 150;
            int heavyBlock = (rand()%100)+1;
            if (heavyBlock > 100 - At.heavyBlock)
            {
                *blocked = 1;
            }
            En.HP -= heavyAttackDamage;
            printf("Dealt %d damage using a heavy attack!\n", heavyAttackDamage);
            enemyTurn(blocked);
        }
        if (attackChoice == 3)
        {
            attackChoice = 0;
            specialAttacks(&attackChoice,blocked);
        }
        else if (attackChoice == 4)
        {
            printf("\n\n\n");
            continue;
        }
        else if (attackChoice != 1 && attackChoice != 2)
        {
            printf("%d", attackChoice);
            printf("Please enter a different number.\n");
        }
        if (attackChoice == 4)
        {
            printf("\n\n\n");
            continue;
        }
    } while (attackChoice < 1 || attackChoice > 4);
}
void Magic(int *blocked)
{
    int magicMenuChoice = 0;
    printf("\n\n\n");
    do
        {
            printf("Magic Spells:\n\t\t---Current MP: %d---\n", Pl.MP);
            printf("[1] Firaga\t(Low Damage, %d%% Chance to Burn, %d%% Chance to miss, %dMP)\n", Ma.burnChance, Ma.firagaMiss, Ma.firagaMP);
            printf("[2] Blizzaga\t(Medium Damage, %d%% Chance to Freeze, %d%% Chance to miss, %dMP)\n", Ma.freezeChance, Ma.blizzagaMiss, Ma.blizzagaMP);
            printf("[3] Thundaga\t(Large Damage, %d%% Chance to Shock, %d%% Chance to miss, %dMP)\n", Ma.shockChance, Ma.thundagaMiss, Ma.thundagaMP);
            printf("[4] Aeroga\t(Medium Damage, %d%% Chance to Confuse, %d%% Chance to miss, %dMP)\n[5] Back\n", Ma.confuseChance, Ma.aerogaMiss, Ma.aerogaMP);
            scanf("%d", &magicMenuChoice);
            if (Pl.frozen > 1)
            {
                if (magicMenuChoice > 0 && magicMenuChoice <= 4)
                {
                    printf("You are still \033[0;34mfrozen solid\033[0m for %d turns!\n", Pl.frozen);
                    Pl.frozen -= 1;
                    enemyTurn(blocked);
                }
            }
            else if (Pl.frozen == 1)
            {
                if (magicMenuChoice > 0 && magicMenuChoice <= 4)
                {
                    printf("You have \033[0;34munthawed from being frozen\033[0m!\n");
                    Pl.frozen -= 1;
                    enemyTurn(blocked);
                }
            }
            else if (Pl.shockSucc == 100)
            {
                if (magicMenuChoice > 0 && magicMenuChoice <= 4)
                printf("You missed your magic cast due to being \033[0;33mshocked\033[0m\n");
                enemyTurn(blocked);
            }
            else if (magicMenuChoice == 1)
            {
                if (Pl.MP >= Ma.firagaMP)
                {
                    Pl.MP -= Ma.firagaMP;
                    int firagaChance = (rand() % 100) + 1;
                    if (firagaChance <= 100- Ma.firagaMiss)
                    {
                        int firagaDamage = (rand() % 121) + 60;
                        int burnChance = (rand() % 100) + 1;
                        printf("\nDealt %d Damage using Firaga!\n", firagaDamage);
                        En.HP -= firagaDamage;
                        if (En.frozen > 0)
                        {
                            printf("Firaga \033[0;31mthawed\033[0m %s out...\n", En.name);
                            En.frozen = 0;
                        }
                        else if (burnChance > 100 - Ma.burnChance)
                        {
                            En.burned = 1;
                            printf("%s has been \033[0;31mburned\033[0m and will take damage every turn!\n", En.name);
                        }
                        enemyTurn(blocked);
                    }
                    else
                    {
                        printf("Firaga missed!\n");
                        enemyTurn(blocked);
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Firaga!\n");
                }
            }
            else if (magicMenuChoice == 2)
            {
                if (Pl.MP >= Ma.blizzagaMP)
                {
                    Pl.MP -= Ma.blizzagaMP;
                    int blizzagaChance = (rand() % 100) + 1;
                    if (blizzagaChance <= 100 - Ma.blizzagaMiss)
                    {
                        int blizzagaDamage = (rand() % 126) + 125;
                        int freezeChance = (rand() % 100) + 1;
                        if (freezeChance > 100 - Ma.freezeChance)
                        {
                            printf("\nDealt %d Damage using Blizzaga!\n", blizzagaDamage);
                            printf("%s has been \033[0;34mfrozen\033[0m and can't move!\n", En.name);
                            En.frozen = (rand() % 4) + 2;
                            En.HP -= blizzagaDamage;
                            enemyTurn(blocked);
                        }
                        else
                        {
                            printf("\nDealt %d Damage using Blizzaga!\n", blizzagaDamage);
                            En.HP -= blizzagaDamage;
                            enemyTurn(blocked);
                        }
                    }
                    else
                    {
                        printf("Blizzaga Missed!\n");
                        enemyTurn(blocked);
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Blizzaga!\n");
                }
            }
            else if (magicMenuChoice == 3)
            {
                if (Pl.MP >= Ma.thundagaMP)
                {
                    Pl.MP -= Ma.thundagaMP;
                    int thundagaChance = (rand() % 100) + 1;
                    if (thundagaChance <= 100 - Ma.thundagaMiss)
                    {
                        int thundagaDamage = (rand() % 251) + 320;
                        int shockChance = (rand() % 100 + 1);
                        if (shockChance > 100 - Ma.shockChance)
                        {
                            printf("\nDealt %d Damage using Thundaga!\n", thundagaDamage);
                            printf("%s has been \033[0;33mshocked!\033[0m %s will now miss attacks more frequently!\n", En.name, En.name);
                            En.shocked = 1;
                            En.HP -= thundagaDamage;
                            enemyTurn(blocked);
                        }
                        else
                        {
                            printf("\nDealt %d Damage using Thundaga!\n", thundagaDamage);
                            En.HP -= thundagaDamage;
                            enemyTurn(blocked);
                        }
                    }
                    else
                    {
                        printf("Thundaga missed!\n");
                        enemyTurn(blocked);
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Thundaga!\n");
                }
            }
            else if (magicMenuChoice == 4)
            {
                if (Pl.MP >= Ma.aerogaMP)
                {
                    Pl.MP -= Ma.aerogaMP;
                    int aerogaChance = (rand() % 100) + 1;
                    if (aerogaChance <= 100 - Ma.aerogaMiss)
                    {
                        int confuseChance = (rand() % 100) + 1;
                        int aerogaDamage = (rand() % 200) + 175;
                        printf("Dealt %d damage using Aeroga!\n", aerogaDamage);
                        En.HP -= aerogaDamage;
                        if (confuseChance > 100 - Ma.confuseChance)
                        {
                            printf("%s is now \033[0;35mconfused\033[0m and may hit themselves!\n",En.name);
                            En.confused = 1;
                            enemyTurn(blocked);
                        }
                        else
                        {
                        enemyTurn(blocked);
                        }
                    }
                    else
                    {
                        printf("Aeroga Missed!\n");
                        enemyTurn(blocked);
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Aeroga!\n");
                }
            }
            else if (magicMenuChoice == 5)
            {
                printf("\n\n\n");
            }
            else
            {
                printf("Please enter a different number.\n");
            }
        } while (magicMenuChoice < 1 || magicMenuChoice > 5);
}
void Items(int *potionUsed, int *etherUsed, int *blocked)
{
    int itemMenuChoice = 0;
    int already[3] = {0,0};
    int back = 1;
    printf("\n\n\n");
    do
    {
        printf("Items:\n");
        //FYI Personally, I think the player should be allowed to use items while frozen (Other than Panacea), What do yall think? ~Roxie
        for (int i = 1; i <= 3; i++)
        {
            if (It.potionC >= 1 && already[0] == 0)
            {
                already[0] = i;
                back++;
                printf("[%d] Potion (Heals %dHP) x %d\n",i, It.potionHeal, It.potionC);
            }
            else if (It.etherC >= 1 && already[1] == 0)
            {
                already[1] = i;
                back++;
                printf("[%d] Ether (Restores %dMP) x %d\n",i, It.etherRest, It.etherC);
            }
            else if (It.panaceaC >= 1 && already[2] == 0)
            {
                already[2] = i;
                back++;
                printf("[%d] Panacea (Cures status conditions) x %d\n",i, It.panaceaC);
            }
        }
        printf("[%d] Back\n", back);
        scanf("%d", &itemMenuChoice);
        if (itemMenuChoice == already[0] && already[0] > 0)
        {
            if (It.potionC > 0 && Pl.HP < Pl.maxHP)
            {
                Pl.frozen -= 1;
                Pl.HP += It.potionHeal;
                if (Pl.HP > Pl.maxHP)
                {
                    Pl.HP = Pl.maxHP;
                }
                printf("Healed %dHP!\n", It.potionHeal);
                It.potionC -= 1;
                *potionUsed += 1;
                if (Pl.bench == 0)
                {
                enemyTurn(blocked);
                }
            }
            else if (Pl.HP == Pl.maxHP)
            {
                printf("Using a potion now would have no effect!\n");
            }
        }
        else if (itemMenuChoice == already[1] && already[1] > 0)
        {
            if (It.etherC > 0 && Pl.MP < Pl.maxMP)
            {
                Pl.frozen -= 1;
                Pl.MP += It.etherRest;
                if (Pl.MP> Pl.maxMP)
                {
                    Pl.MP = Pl.maxMP;
                }
                printf("Restored %dMP!\n", It.etherRest);
                It.etherC -= 1;
                *etherUsed += 1;
                if (Pl.bench == 0)
                {
                enemyTurn(blocked);
                }
            }
            else if (Pl.MP == Pl.maxMP)
            {
                printf("Using an ether now would have no effect!\n");
            }
        }
        else if (itemMenuChoice == already[2] && already[2] > 0)
        {
            if (Pl.burned == 0 && Pl.frozen == 0 && Pl.shocked == 0 && Pl.confused == 0)
            {
                printf("Using a panacea now would have no effect!\n");
                It.panaceaC++;
            }
            else
            {
                if (Pl.burned == 1)
                {
                    Pl.burned = 0;
                    printf("Healed %s's \033[0;31mburn\033[0m using a panacea!\n", Pl.name);
                }
                if (Pl.frozen >= 1)
                {
                    Pl.frozen = 0;
                    printf("\033[0;34mMelted\033[0m %s using a panacea!\n", Pl.name);
                }
                if (Pl.shocked == 1)
                {
                    Pl.shocked = 0;
                    printf("Healed %s's \033[0;33mshocked\033[0m condition using a panacea!\n", Pl.name);
                }
                if (Pl.confused == 1)
                {
                    Pl.confused = 0;
                    printf("Healed %s's \033[0;35mconfusion\033[0m using a panacea!\n",Pl.name);
                }
                It.panaceaC--;
                if (Pl.bench == 0)
                {
                    enemyTurn(blocked);
                }
            }
        }
        else if (itemMenuChoice == back)
        {
            printf("\n\n\n");
        }
        else
        {
            back = 1;
            int amount = 0;
            amount = sizeof(already)/sizeof(already[0]);
            for (int i = 0; i < amount; i++)
            {
                already[i] = 0;
            }
            printf("Please enter a different number.\n");
        }
    } while (itemMenuChoice < 1 || itemMenuChoice > back); 
}
void mainMenu(int *playing,int *modified, int *titleChoi)
{   
    int maxEnemyHP = En.HP;
    int maxPotionCount = It.potionC;
    int maxEtherCount = It.etherC; //used for end-game statistics, might add more if we decide to track more
    int potionUsed = 0, etherUsed = 0, blocked = 0;
    Un.battles++;
    do
    {
        Pl.burnDamage = (rand() % 50) + 25;
        blocked = 0;
        int menuChoice = 0;
        if (Pl.burned == 1)
        {
            printf("\033[0;31m*\033[0m");
        }
        if (Pl.frozen >= 1)
        {
            printf("\033[0;34m*\033[0m");
        }
        if (Pl.shocked == 1)
        {
            printf("\033[0;33m*\033[0m");
            Pl.shockSucc = (rand() % 100) + 1;
            if (Pl.shockSucc > 80)
            {
                Pl.shockSucc = 100;            //makes it 100 so it guarantees that the attack misses, moreso for easier rate modification as needed
            }
        }
        else
        {
            Pl.shockSucc = 0;
        }
        if (Pl.confused == 1)
        {
            printf("\033[0;35m*\033[0m");
        }
        printf("%s's HP: %d\t||\t", Pl.name, Pl.HP);
        if (En.burned == 1)
        {
            printf("\033[0;31m*\033[0m");
        }
        if (En.frozen >= 1)
        {
            printf("\033[0;34m*\033[0m");
        }
        if (En.shocked == 1)
        {
            printf("\033[0;33m*\033[0m");
        }
        if (En.confused == 1)
        {
            printf("\033[0;35m*\033[0m");
        }
        printf("%s's HP: %d\n", En.name, En.HP);
        if (Pl.frozen > 1)
        {
            printf("\033[0;34mTime until unfrozen: %d turns!\033[0m\n", Pl.frozen);
        }
        if (Pl.frozen == 1)
        {
            printf("\033[0;34mTime until unfrozen: %d turn!\033[0m\n", Pl.frozen);
        }
        printf("[1] Attack\n");
        printf("[2] Magic Spells\n");
        printf("[3] Items\n");
        scanf("%d", &menuChoice);
        if (menuChoice == 1)
        {
            Attack(&blocked);
        }
        else if (menuChoice == 2)
        {
            Magic(&blocked);
        }
        else if (menuChoice == 3)
        {
            Items(&potionUsed, &etherUsed, &blocked);
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (Pl.HP > 0 && En.HP > 0);
    if (Pl.HP <= 0 && En.HP <= 0)
    {
        Pl.HP = 0;
        En.HP = 0;
        printf("The battle has ended in a draw!\n");
        if (Un.inEndless == 1)
        {
        printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, maxEnemyHP);
        printf("Potions Used: %d\nEthers Used: %d\n", potionUsed, etherUsed);
        printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        }
    }
    else if (Pl.HP <= 0)           
    {
        printf("You lost to %s...\n", En.name);
        Pl.HP = 0;
        if (Un.inEndless == 1)
        {
        printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, maxEnemyHP);
        printf("Potions Used: %d\nEthers Used: %d\n", potionUsed, etherUsed);
        printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        }
    }
    else if (En.HP <= 0)
    {
        printf("You have defeated %s!\n\n", En.name);
        int moreExp = (rand() % 500) + 500;
        moreExp = moreExp*Pl.expMulti;
        moreExp = round(moreExp);
        Pl.experience += moreExp; 
        float moreG = (rand() % 3) + 20;
        moreG = moreG*(Pl.GMulti*(Un.battles * 0.25));
        moreG = round(moreG);
        if (Un.inEndless == 0)
        {
            printf("You gained %d experience\n", moreExp);
            Pl.G = 0;
        }
        else if (Un.inEndless == 1 && Pl.HP > 0)
        {
            if (Un.battles == 1)
            {
                Pl.G += 10;             //if someone could help me find a balanced formula for the amount of G you get after each battle, that'd be great ~Roxie
                printf("You gained %d experience and %.0fG\n", moreExp, Pl.G + moreG);
                Pl.G += moreG;
            }
            else
            {
            printf("You gained %d experience and %.0fG\n", moreExp, moreG);
            Pl.G += moreG;
            }
            En.HP = maxEnemyHP;
            Shop(playing,modified,titleChoi);
        }
        En.HP = maxEnemyHP;
    }
    else
    {
        printf("This message should never appear. If this appears, you found a bug!\n");        //gotta do something for this right? funsies
    }
    if (Un.inEndless == 0)
    {
        printf("Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, maxEnemyHP);
        printf("Potions Used: %d/%d\nEthers Used: %d/%d\n", potionUsed, maxPotionCount, etherUsed, maxEtherCount);
        printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        int playChoice = 0;
        do
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
                            En.HP = maxEnemyHP;      //others dont need this treatment as they dont change throughout the battle
                            It.potionC = maxPotionCount;
                            It.etherC = maxEtherCount; 
                            *titleChoi = 0;
                            En.burned = 0, En.frozen = 0, En.shocked = 0, En.confused = 0;   
                        }
                        else if (saveChoice == 2)
                        {
                            *modified = 0;
                            En.burned = 0, En.frozen = 0, En.shocked = 0, En.confused = 0;   
                        }
                        else
                        {
                            printf("Please enter a different number.\n");
                        }
                        } while (saveChoice < 1 || saveChoice > 2);
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
        } while (playChoice < 1 || playChoice > 2);
    }
}
int main(void)
{
    int playing = 0;
    do
    {
        int modified = 0;       //used for if the player modified settings
        int titleChoi = 0;
        initialize();           //this is located in endless.h at the bottom
    //from testing, the values had to be set to 0 to prevent memory overflow (Specifically in blizzagaChance and potionCount, idk why those two specifically ~Roxie)
        srand(time(NULL)); //sets the seed for the random values based on time
        printf("---------------------------------\n");
        printf("|\tTERMINAL BATTLE\t\t|\n");
        printf("---------------------------------\n");
        do
        {
            printf("Select a choice! (Type the number corresponding to the option, then press enter)\n");
            printf("[1] Single Battle\n[2] Endless Battle\n[3] Options\n[4] Exit\n"); //didnt separate this printf statement bc it was so small ~Roxie
            scanf("%d", &titleChoi);
            if (titleChoi == 1)             //we can do switch case if we want, but it doesn't matter
            {
                int nameChoi = 0;
                do
                {
                    printf("Would you like to name your opponent?\n");
                    printf("[1] Yes\n[2] Pick for me\n[3] Back to Title Screen\n");
                    scanf("%d", &nameChoi);
                    if (nameChoi == 1)
                    {
                        getchar();  //apparently this removes the newline character from the previous input (nameChoi??), don't understand it entirely yet
                        printf("Enter the name of your opponent: ");
                        fgets(En.name,sizeof(En.name), stdin);
                        En.name[strlen(En.name) - 1] = '\0';        //gotta remove the newline charater from THIS input now
                        mainMenu(&playing, &modified, &titleChoi);
                    }
                    else if (nameChoi == 2)
                    {
                        char nameLine[50];
                        FILE *names = fopen("names", "r+");
                        if (names == NULL)
                        {
                            printf("Failed to retrieve names. Aborting!");
                            exit (1);
                        }
                        int lineCount = 0;
                        while (fgets(nameLine, sizeof(nameLine), names))
                        {
                            lineCount++;
                        }
                        fseek(names,0,SEEK_SET);
                        int currentLine = 0;
                        int nameResu = (rand() % lineCount);
                        while (fgets(nameLine,sizeof(nameLine),names))
                        {
                            if (currentLine == nameResu)
                            {
                                nameLine[strcspn(nameLine, "\n")] = '\0';
                                strcpy(En.name, nameLine);
                                break;
                            }
                            currentLine++;
                        }
                        fclose(names);
                        printf("Starting the battle!\n\n");     //this thing was a mess, i hated it. any way to make this simpler?
                        mainMenu(&playing, &modified, &titleChoi);
                    }
                    else if (nameChoi == 3)
                    {
                        titleChoi = 0;
                        printf("\n\n\n");
                       continue; 
                    }
                    else
                    {
                        printf("Please enter a different number.\n");
                    }
                } while (nameChoi < 1 || nameChoi > 3);
            }
            else if (titleChoi == 2)
            {
                int nameChoi = 0;
                do
                {
                    printf("Would you like to name your opponent?\n");
                    printf("[1] Yes\n[2] Pick for me\n[3] Back to Title Screen\n");
                    scanf("%d", &nameChoi);
                    if (nameChoi == 1)
                    {
                        getchar();
                        printf("Enter the name of your opponent: ");
                        fgets(En.name,sizeof(En.name), stdin);
                        En.name[strlen(En.name) - 1] = '\0';
                        Un.inEndless = 1;
                        Pl.maxHP = Pl.HP;
                        Pl.maxMP = Pl.MP;
                        mainMenu(&playing, &modified, &titleChoi);
                    }
                    else if (nameChoi == 2)
                    {
                        char nameLine[50];
                        FILE *names = fopen("names", "r+");
                        if (names == NULL)
                        {
                            printf("Failed to retrieve names. Aborting!");
                            exit (1);
                        }
                        int lineCount = 0;
                        while (fgets(nameLine, sizeof(nameLine), names))
                        {
                            lineCount++;
                        }
                        fseek(names,0,SEEK_SET);
                        int currentLine = 0;
                        int nameResu = (rand() % lineCount);
                        while (fgets(nameLine,sizeof(nameLine),names))
                        {
                            if (currentLine == nameResu)
                            {
                                nameLine[strcspn(nameLine, "\n")] = '\0';
                                strcpy(En.name, nameLine);
                                break;
                            }
                            currentLine++;
                        }
                        fclose(names);
                        printf("Starting the battle!\n\n");
                        Un.inEndless = 1;
                        Pl.maxHP = Pl.HP;
                        Pl.maxMP = Pl.MP;
                        mainMenu(&playing, &modified, &titleChoi);
                    }
                    else if (nameChoi == 3)
                    {
                        titleChoi = 0;
                        printf("\n\n\n");
                       continue; 
                    }
                    else
                    {
                        printf("Please enter a different number.\n");
                    }
                } while (nameChoi < 1 || nameChoi > 3);
            }
            else if (titleChoi == 3)
            {
                titleChoi = 0;
                gameOptions(&modified);
            }
            else if (titleChoi == 4)
            {
                exit(1);
            }
            else
            {
                titleChoi = 0;
                printf("Please enter a different number.\n");
            }
        } while (titleChoi < 1 || titleChoi > 4);
    } while (playing != 1);
    return 0;
}