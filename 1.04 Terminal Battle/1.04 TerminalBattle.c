#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "options.h"
#include "endless.h"
#include "statChoices.h"
//(rand()%100) + 1; is used throughout the program, this is range 1 - 100 (Inclusive)
void bossTurn(int *blocked)
{
    if (Pl.burned == 1)
    {
        Pl.HP -= Pl.burnDamage;
        printf("You took %d additional \033[0;31mburn\033[0m damage!\n", Pl.burnDamage);
    }
    int bossBurn = 0;
    int maxBossHP = Bo.HP;
    int bossConfuseChance = 0;
    int confusedDamage = 0;
    int totalBlockDamage = 0;
    int totalConfuseDamage = 0;     //all these are used later in the function
    if (Bo.frozen == 1)
    {
        printf("%s has fully \033[0;34mthawed out!\033[0m\n", Bo.name);
        Bo.frozen = -1;
    }
    if (Bo.burned == 1)
    {
        bossBurn = (rand() % 50) + 25;
    }
    if (Bo.HP <= 0)
    {
        return;
    }
    else
    {
        if (Bo.frozen == 0)
        {
            int bossAttack = (rand() % 100) + 1;
            if (Bo.confused == 1)
            {
                bossConfuseChance = (rand() % 100) + 1;
            }
            if (Bo.shocked == 1)
            {
                int furtherMiss = (rand() % 100) + 1;
                if (furtherMiss > 70)   //This is a 30% chance that they will miss due to shock
                {
                    printf("%s couldn't attack due to being \033[0;33mshocked!\033[0m\n", Bo.name);
                    bossAttack = 0;
                }
            }
            if (bossAttack > 0 && bossAttack <= 20)
            {
                float bossDamage = round(((rand() % 50) + 100) * Bo.bossDamageMulti);
                printf("%s used Vampire Stab and dealt %.0f Damage!\n", Bo.name, bossDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = bossDamage - bossDamage*blockedDamage;
                    bossDamage = bossDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (bossConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = bossDamage * confusedDamage;
                    round(confusedDamage);
                    Bo.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", Bo.name, confusedDamage);
                }
                Pl.HP -= bossDamage;
                float vampireRecovery = (rand() % 75) + 51;
                vampireRecovery *= 0.01;
                Bo.HP += (bossDamage * vampireRecovery);
                printf("%s recovered %.0f HP using Vampire Stab!\n", Bo.name, bossDamage * vampireRecovery);
                if (Bo.HP > maxBossHP)
                {
                    Bo.HP = maxBossHP;
                }
            }
            else if (bossAttack > 20 && bossAttack <= 40)
            {
                float bossDamage = round(((rand() % 200) + 200) * Bo.bossDamageMulti);
                printf("%s used Gigantic Beat and dealt %.0f Damage!\n", Bo.name, bossDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = bossDamage - bossDamage*blockedDamage;
                    bossDamage = bossDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (bossConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = bossDamage * confusedDamage;
                    round(confusedDamage);
                    Bo.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", Bo.name, confusedDamage);
                }
                Pl.HP -= bossDamage;                
            }
            else if (bossAttack > 40 && bossAttack <= 60)
            {
                float bossDamage = round(((rand() % 150) + 125) * Bo.bossDamageMulti);
                int hellBurn = (rand() % 100) + 1;
                printf("%s used Hellfire and dealt %.0f Damage!\n", Bo.name, bossDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = bossDamage - bossDamage*blockedDamage;
                    bossDamage = bossDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (bossConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = bossDamage * confusedDamage;
                    round(confusedDamage);
                    Bo.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", Bo.name, confusedDamage);
                }
                if (hellBurn <= 25)
                {
                    Pl.burned = 1;
                    printf("You have been \033[0;31mburned\033[0m by %s's Hellfire!\n", Bo.name);
                }
                Pl.HP -= bossDamage;
            }
            else if (bossAttack > 60 && bossAttack <= 75)
            {
                float bossDamage = round(((rand() % 200) + 150) * Bo.bossDamageMulti);
                int suikeiFreeze = (rand() % 100) + 1;
                int suikenAmount = (rand() % 1) + 1;
                printf("%s used Suikei and dealt %.0f Damage!\n", Bo.name, bossDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = bossDamage - bossDamage*blockedDamage;
                    bossDamage = bossDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (bossConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = bossDamage * confusedDamage;
                    round(confusedDamage);
                    Bo.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", Bo.name, confusedDamage);
                }
                Pl.HP -= bossDamage;
                if (suikeiFreeze >= 66)
                {
                    Pl.frozen = suikenAmount;
                    printf("You have been \033[0;34mfrozen solid\033[0m by %s's Suikei!\n", Bo.name);
                }
            }
            else if (bossAttack > 75 && bossAttack <= 79)
            {
                printf("%s used Mechanical Rhythm and swapped your HP with their HP!\n", Bo.name);
                int tempPLHP = Pl.HP;
                int tempBOHP = Bo.HP;
                Pl.HP = tempBOHP;
                Bo.HP = tempPLHP;
            }
            else if (bossAttack == 80)
            {
                if (Un.battles <= 5)
                {
                    printf("%s used Guillotine ", Bo.name);
                    if (Pl.HP <= 400)
                    {
                        printf("and it failed!\n");
                    }
                    else
                    {
                        printf("and left you at low health!\n");
                        Pl.HP = 400;
                    }
                }
                if (Un.battles > 5 && Un.battles <= 9)
                {
                    printf("%s used Guillotine and left you at very low health and \033[0;33mshocked!\033[0m!\n", Bo.name);
                    Pl.HP = 200;
                    Pl.shocked = 1;
                }
                if (Un.battles > 9)
                {
                    printf("%s used Guillotine and left you at critical health, \033[0;33mshocked!\033[0m, and \033[0;35mconfused!\033[0m!\n", Bo.name);
                    Pl.HP = 1;
                    Pl.shocked = 1;
                    Pl.confused = 1;
                }
            }
            else if (bossAttack > 80 && bossAttack <= 98)
            {
                float bossDamage = round((Bo.HP * 0.2)*Bo.bossDamageMulti);                  //the more health the boss has, the greater attack power this has
                int gravityChance = (rand() % 100) + 1;
                printf("%s used Gravity and dealt %.0f Damage!\n", Bo.name, bossDamage);
                if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40);
                    blockedDamage *= 0.01;
                    totalBlockDamage = bossDamage - bossDamage*blockedDamage;
                    bossDamage = bossDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                if (bossConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = bossDamage * confusedDamage;
                    round(confusedDamage);
                    Bo.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", Bo.name, confusedDamage);
                }
                Pl.HP -= bossDamage;
                if (gravityChance <= 20)
                {
                    Pl.confused = 1;
                    printf("You have been \033[0;35mconfused\033[0m by %s's Gravity!\n", Bo.name);
                }
            }
            else
            {
                printf("%s missed their attack!\n", Bo.name);
            }
        }
        else
        {
            if (Bo.frozen >= 1)
            {
                printf("%s is \033[0;34mfrozen solid\033[0m for %d more turn", Bo.name, Bo.frozen-1);
                if (Bo.frozen - 1 == 1)
                {
                    printf("!\n");
                    Bo.frozen -= 1;
                }
                if (Bo.frozen - 1 > 1)
                {
                    printf("s!\n");             //this and the previous printf statements are for plural turns
                    Bo.frozen -= 1;
                }
            }
        }
    }
    if (Bo.burned == 1)
    {
        printf("%s took %d additional \033[0;31mburn\033[0m damage\n", Bo.name, bossBurn);
        Bo.HP -= bossBurn;
    }
    if (Bo.frozen == -1)
    {
        Bo.frozen = 0;
    }
}
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
    int totalConfuseDamage = 0;     //all these are used later in the function
    int enemyAttack = 0;
    if (En.frozen == 1)
    {
        printf("%s has fully \033[0;34mthawed out!\033[0m\n", En.name);
        En.frozen = -1;
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
        if (En.frozen == 0)
        {
            if (Un.battles <= 3)
            {
                enemyAttack = (rand() % 100) + 1;
            }
            else if (Un.battles >= 3)                    //On 4 battles, the enemy will gain access to Harmonic Rhythm
            {
                enemyAttack = (rand() % 110) + 1;
            }
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
            {
                float enemyDamage = round(((rand() % 75) + 50) * En.enemyDamageMulti);
                printf("%s used Rolling Kick and dealt %.0f Damage!\n", En.name, enemyDamage);
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
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = enemyDamage * confusedDamage;
                    round(confusedDamage);
                    En.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, confusedDamage);
                }
                if (Un.battles >= 7)        //On 8 battles, Rolling Kick can Shock
                {
                    int shockChance = (rand() % 100) + 1;
                    if (shockChance <= 15)
                    {
                        Pl.shocked = 1;
                        printf("You have been \033[0;33mshocked\033[0m by %s's Rolling Kick!\n", En.name);
                    }
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 40 && enemyAttack <= 70)
            {
                float enemyDamage = round(((rand() % 125) + 100) * En.enemyDamageMulti);
                int burnChance = (rand() % 100) + 1;
                printf("%s used Heat Haze and dealt %.0f Damage!\n", En.name,enemyDamage);
                if (Un.battles >= 5)            //On 6 battles, Heat Haze can burn
                {
                    int burnChance = (rand() % 100) + 1;
                    if (burnChance <= 15)
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
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = enemyDamage * confusedDamage;
                    round(confusedDamage);
                    En.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, confusedDamage);
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 70 && enemyAttack <=85)
            {
                float enemyDamage = round(((rand() % 175) + 175) * En.enemyDamageMulti);
                printf("%s used Angel Blow and dealt %.0f Damage!\n", En.name, enemyDamage);
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
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = enemyDamage * confusedDamage;
                    round(confusedDamage);
                    En.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, confusedDamage);
                }
                Pl.HP -= enemyDamage;
            }
            else if (enemyAttack > 85 && enemyAttack <= 100)
            {
            printf("%s went for an attack but missed!\n", En.name);
            }
            else if (enemyAttack > 100 && enemyAttack <= 110)           //Activated after 2 rounds
            {
                float enemyDamage = round(((rand() % 200) + 1) * En.enemyDamageMulti);               //the wide range of damage is intentional
                int harmonicStatus = (rand() % 100) + 1;
                printf("%s used Harmonic Rhythm and dealt %.0f damage\n", En.name, enemyDamage);
                if (enemyConfuseChance > 50)
                {
                    double confusedDamage = ((rand() % 25) + 25) * 0.01;
                    confusedDamage = enemyDamage * confusedDamage;
                    round(confusedDamage);
                    En.HP -= confusedDamage;
                    printf("%s dealt %.0f damage to themselves in \033[0;35mconfusion!\033[0m\n", En.name, confusedDamage);
                }
                if (harmonicStatus >= 0 && harmonicStatus < 20)
                {
                    Pl.burned = 1;
                    printf("You have been \033[0;31mburned\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                else if (harmonicStatus >= 20 && harmonicStatus < 40)
                {
                    Pl.frozen =  (rand() % 3) + 1;
                    printf("You have been \033[0;34mfrozen\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                else if (harmonicStatus >= 40 && harmonicStatus < 60)
                {
                    Pl.shocked = 1;
                    printf("You have been \033[0;33mshocked\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                    else if (harmonicStatus >= 60 && harmonicStatus < 80)
                {
                    Pl.confused = 1;
                    printf("You have been \033[0;35mconfused\033[0m by %s's Harmonic Rhythm!\n", En.name);
                }
                 if (*blocked == 1)
                {
                    double blockedDamage = (rand() % 40) * 0.01;
                    totalBlockDamage = enemyDamage - enemyDamage*blockedDamage;
                    enemyDamage = enemyDamage * blockedDamage;
                    printf("Blocked %d Damage!\n", totalBlockDamage);
                }
                Pl.HP -= enemyDamage;
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
    if (En.frozen == -1)
    {
        En.frozen = 0;
    }
}
void playerConfusionDamage(float *damage)
{
    int playerConfuseChance = (rand() % 100) + 1;
    if (Pl.confused == 1 && playerConfuseChance > 50)
    {
        double confusedDamage = ((rand() % 25) + 25) * 0.01;
        confusedDamage = confusedDamage * *damage;
        round(confusedDamage);
        Pl.HP -= confusedDamage;
        printf("You dealt %.0f damage to yourself in \033[0;35mconfusion!\033[0m\n", confusedDamage);
    }
}
void specialAttacks(int *attackChoice, int *blocked)
{
    int specialChoice = 0;
    int already[4] = {0,0,0,0};
    int back = 1;
    printf("\n\n\n");
    do
    {
        printf("Special Attacks:\n\t\t---Current MP: %d---\n", Pl.MP);
        for (int i = 1; i <= 4; i++)
        {
            if (Pl.hasLucky == 1 && already[0] == 0)
            {
                already[0] = i;
                back++;
                printf("[%d] Lucky Strike (Low Damage, HP and MP restoration chance, %d%% Block Rate, %d MP)\n", i, At.luckyBlock, At.luckyMP);
            }
            else if (Pl.hasQuick == 1 && already[1] == 0)
            {
                already[1] = i;
                back++;
                printf("[%d] Quickdraw (Moderate Damage, skips enemy turn, %d MP)\n", i, At.quickdrawMP);
            }
            else if (Pl.hasArs == 1 && already[2] == 0)
            {
                already[2] = i;
                back++;
                printf("[%d] Ars Arcanum (Massive Damage, %d%% Block Rate, %d MP)\n", i, At.arsBlock, At.arsMP);
            }
            else if (Pl.hasCritHit == 1 && already[3] == 0)
            {
                already[3] = i;
                back++;
                printf("[%d] Critical Hit (Super small damage, %d%% Chance for instant death, %d%% Block Rate, %d MP)\n", i, At.critHitSuc, At.critHitBlock, At.critHitMP);
            }
        }
    if (back == 1)
    {
        printf("You have no special attacks!\n");
    }
    printf("[%d] Back\n",back);
    scanf("%d", &specialChoice);
    if (Pl.frozen > 1 && specialChoice < back)
    {
        *attackChoice = 4;
        printf("You are still \033[0;34mfrozen solid\033[0m for %d turns!\n", Pl.frozen);
        Pl.frozen -= 1;
        if (Un.bossOrEnemy == 0)
        {
            enemyTurn(blocked);
        }
        else if (Un.bossOrEnemy == 1)
        {
            bossTurn(blocked);
        }
    }
    else if (Pl.frozen == 1 && specialChoice < back)
    {
        *attackChoice = 4;
        printf("You have \033[0;34munthawed from being frozen\033[0m!\n");
        Pl.frozen -= 1;
        if (Un.bossOrEnemy == 0)
        {
            enemyTurn(blocked);
        }
        else if (Un.bossOrEnemy == 1)
        {
            bossTurn(blocked);
        }
    }
    else if (Pl.shockSucc == 100)
    {
        if (specialChoice > 0 && specialChoice < back)
        {
            *attackChoice = 4;
            printf("You missed your special attack due to being \033[0;33mshocked\033[0m\n");
            if (Un.bossOrEnemy == 0)
            {
                enemyTurn(blocked);
            }
            else if (Un.bossOrEnemy == 1)
            {
                bossTurn(blocked);
            }
        }
    }
    else if (specialChoice == already[0] && already[0] > 0)
    {
        if (Pl.MP >= At.luckyMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.luckyMP;
            float luckyAttackDamage = round(((rand() % 50) + 60) * Pl.attackMulti);
            int luckyBlock = (rand()%100) + 1;
            playerConfusionDamage(&luckyAttackDamage);
            if (luckyBlock > 100 - At.luckyBlock)
            {
                *blocked = 1;
            }
            if (Un.bossOrEnemy == 0)
            {
                En.HP -= luckyAttackDamage;
            }
            else if  (Un.bossOrEnemy == 1)
            {
                Bo.HP -= luckyAttackDamage;
            }
            printf("Dealt %.0f damage using Lucky Strike!\n", luckyAttackDamage);
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
                if (Pl.MP > Pl.maxMP)
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
            if (Un.bossOrEnemy == 0)
            {
                enemyTurn(blocked);
            }
            else if (Un.bossOrEnemy == 1)
            {
                bossTurn(blocked);
            }
        }
        else
        {
            printf("You don't have enough MP to use Lucky Strike!\n");
        }
    }
    else if (specialChoice == already[1] && already[1] > 0)
    {
        if (Pl.MP >= At.quickdrawMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.quickdrawMP;
            float quickdrawDamage = round(((rand() % 200) + 100) * Pl.attackMulti);
            En.HP -= quickdrawDamage;
            printf("Dealt %.0f damage using Quickdraw!\n", quickdrawDamage);
            playerConfusionDamage(&quickdrawDamage);
            if (Un.bossOrEnemy == 0)
            {
                printf("%s's turn was skipped!\n", En.name);
            }
            else if (Un.bossOrEnemy == 1)
            {
                printf("%s's turn was skipped!\n", Bo.name);
            }
        }
        else
        {
            printf("You don't have enough MP to use Quickdraw!\n");
        }
    }
    else if (specialChoice == already[2] && already[2] > 0)
    {
        if (Pl.MP >= At.arsMP)
        {
            *attackChoice = 4;
            Pl.MP -= At.arsMP;
            float arsArcanum = round(((rand() % 400) + 300) * Pl.attackMulti);
            int arsBlock = (rand() % 100) + 1;
            if (Un.bossOrEnemy == 0)
            {
                En.HP -= arsArcanum;
            }
            else if (Un.bossOrEnemy == 1)
            {
                Bo.HP -= arsArcanum;
            }
            printf("Dealt %.0f damage using Ars Arcanum!\n", arsArcanum);
            playerConfusionDamage(&arsArcanum);
            if (arsBlock > 100 - At.arsBlock)
            {
                *blocked = 1;
            }
            if (Un.bossOrEnemy == 0)
            {
                enemyTurn(blocked);
            }
            else if (Un.bossOrEnemy == 1)
            {
                bossTurn(blocked);
            }
        }
        else
        {
            printf("You don't have enough MP to use Ars Arcanum!\n");
        }
    }
    else if (specialChoice == already[3] && already[3] > 0)
    {
        if (Pl.MP >= At.critHitMP)
            {
            *attackChoice = 4;
            Pl.MP -= At.critHitMP;
            int critHitChance = (rand() % 100) + 1;
            float critHitDamage = round(((rand() % 2) + 1) * Pl.attackMulti);
            int critHitBlock = (rand()% 100)+ 1;
            if (critHitBlock > 100 - At.critHitBlock)
            {
                *blocked = 1;
            }
            if (critHitChance > 100 - At.critHitSuc)
            {
                if (Un.bossOrEnemy == 0)
                {
                    printf("Critical Hit succeded, dealt %d damage!!\n", En.HP);
                    Pl.expMulti -= 0.25;
                    En.HP = 0;
                    enemyTurn(blocked);
                }
                else if (Un.bossOrEnemy == 1)
                {
                    printf("Critical Hit succeded, dealt %d damage!!\n", Bo.HP);
                    Pl.expMulti -= 0.2;
                    Bo.HP = 0;
                    bossTurn(blocked);
                }
            }
            else
            {
                if (Un.bossOrEnemy == 0)
                {
                    En.HP -= critHitDamage;
                    printf("Dealt %.0f damage using Critical Hit...\n", critHitDamage);
                    playerConfusionDamage(&critHitDamage);
                    enemyTurn(blocked);
                }
                else if (Un.bossOrEnemy == 1)
                {
                    Bo.HP -= critHitDamage;
                    printf("Dealt %.0f damage using Critical Hit...\n", critHitDamage);
                    playerConfusionDamage(&critHitDamage);
                    bossTurn(blocked);
                }
            }
        }
        else
        {
            printf("You don't have enough MP to use Critical Hit!\n");
        }
    }
    else if (specialChoice == back)
    {
        continue;
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
    } while (specialChoice < 1 || specialChoice > back);
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
                if (Un.bossOrEnemy == 0)
                {
                    enemyTurn(blocked);
                }
                else if (Un.bossOrEnemy == 1)
                {
                    bossTurn(blocked);
                }
            }
        }
        else if (Pl.shockSucc == 100)
        {
            if (attackChoice > 0 && attackChoice <= 2)
            {
                printf("You missed your attack due to being \033[0;33mshocked\033[0m\n");
                if (Un.bossOrEnemy == 0)
                {
                    enemyTurn(blocked);
                }
                else if (Un.bossOrEnemy == 1)
                {
                    bossTurn(blocked);
                }
            }
        }
        else if (attackChoice == 1)
        {
            float lightAttackDamage = round(((rand() % 50) + 80) * Pl.attackMulti);
            int lightBlock = (rand()%100)+1;
            if (lightBlock > 100 - At.lightBlock)
            {
                *blocked = 1;
            }
            if (Un.bossOrEnemy == 0)
            {
                En.HP -= lightAttackDamage;
            }
            else if (Un.bossOrEnemy == 1)
            {
                Bo.HP -= lightAttackDamage;
            }
            printf("Dealt %.0f damage using a light attack!\n", lightAttackDamage);
            playerConfusionDamage(&lightAttackDamage);
            if (Un.bossOrEnemy == 0)
            {
                enemyTurn(blocked);
            }
            else if (Un.bossOrEnemy == 1)
            {
                bossTurn(blocked);
            }
        }
        else if (attackChoice == 2)
        {
            float heavyAttackDamage = round(((rand() % 60) + 150) * Pl.attackMulti);
            int heavyBlock = (rand()%100)+1;
            if (heavyBlock > 100 - At.heavyBlock)
            {
                *blocked = 1;
            }
            if (Un.bossOrEnemy == 0)
            {
                En.HP -= heavyAttackDamage;
            }
            else if (Un.bossOrEnemy == 1)
            {
                Bo.HP -= heavyAttackDamage;
            }
            printf("Dealt %.0f damage using a heavy attack!\n", heavyAttackDamage);
            playerConfusionDamage(&heavyAttackDamage);
            if (Un.bossOrEnemy == 0)
            {
                enemyTurn(blocked);
            }
            else if (Un.bossOrEnemy == 1)
            {
                bossTurn(blocked);
            }
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
    int already[4] = {0,0,0,0};
    int back = 1;
    printf("\n\n\n");
    do
    {
        printf("Magic Spells:\n\t\t---Current MP: %d---\n", Pl.MP);
        for (int i = 1; i <= 4; i++)
        {
            if (Pl.hasFire == 1 && already[0] == 0)
            {
                already[0] = i;
                back++;
                printf("[%d] Fire\t(Low Damage, %d%% Chance to Burn, %d%% Chance to miss, %dMP)\n", i, Ma.burnChance, Ma.fireMiss, Ma.fireMP);
            }
            else if (Pl.hasBlizzard == 1 && already[1] == 0)
            {
                already[1] = i;
                back++;
                printf("[%d] Blizzard\t(Medium Damage, %d%% Chance to Freeze, %d%% Chance to miss, %dMP)\n", i, Ma.freezeChance, Ma.blizzardMiss, Ma.blizzardMP);
            }
            else if (Pl.hasThunder == 1 && already[2] == 0)
            {
                already[2] = i;
                back++;
                printf("[%d] Thunder\t(Large Damage, %d%% Chance to Shock, %d%% Chance to miss, %dMP)\n", i, Ma.shockChance, Ma.thunderMiss, Ma.thunderMP);
            }
            else if (Pl.hasAero == 1 && already[3] == 0)
            {
                already[3] = i;
                back++;
                printf("[%d] Aero\t(Medium Damage, %d%% Chance to Confuse, %d%% Chance to miss, %dMP)\n", i, Ma.confuseChance, Ma.aeroMiss, Ma.aeroMP);
            }
        }
        if (back == 1)
        {
            printf("You have learned no magic spells!\n");
        }
            printf("[%d] Back\n",back);
            scanf("%d", &magicMenuChoice);
            if (Pl.frozen > 1)
            {
                if (magicMenuChoice > 0 && magicMenuChoice < back)
                {
                    printf("You are still \033[0;34mfrozen solid\033[0m for %d turns!\n", Pl.frozen);
                    Pl.frozen -= 1;
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
                }
            }
            else if (Pl.frozen == 1)
            {
                if (magicMenuChoice > 0 && magicMenuChoice < back)
                {
                    printf("You have \033[0;34munthawed from being frozen\033[0m!\n");
                    Pl.frozen -= 1;
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
                }
            }
            else if (Pl.shockSucc == 100)
            {
                if (magicMenuChoice > 0 && magicMenuChoice < back)
                {
                    printf("You missed your magic cast due to being \033[0;33mshocked\033[0m\n");
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
                }
            }
            else if (magicMenuChoice == already[0] && already[0] > 0)
            {
                if (Pl.MP >= Ma.fireMP)
                {
                    Pl.MP -= Ma.fireMP;
                    int fireChance = (rand() % 100) + 1;
                    if (fireChance <= 100- Ma.fireMiss)
                    {
                        float fireDamage = round(((rand() % 121) + 60) * Pl.magicMulti);
                        int burnChance = (rand() % 100) + 1;
                        printf("\nDealt %.0f Damage using Fire!\n", fireDamage);
                        playerConfusionDamage(&fireDamage);
                        if (Un.bossOrEnemy == 0)
                        {
                            En.HP -= fireDamage;
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            Bo.HP -= fireDamage;
                        }
                        if (En.frozen > 0)
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                printf("Fire \033[0;31mthawed\033[0m %s out...\n", En.name);
                                En.frozen = 0;
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                printf("Fire \033[0;31mthawed\033[0m %s out...\n", Bo.name);
                                Bo.frozen = 0;                                
                            }
                        }
                        else if (burnChance > 100 - Ma.burnChance)
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                En.burned = 1;
                                printf("%s has been \033[0;31mburned\033[0m and will take damage every turn!\n", En.name);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                Bo.burned = 1;
                                printf("%s has been \033[0;31mburned\033[0m and will take damage every turn!\n", Bo.name);                                
                            }
                        }
                        if (Un.bossOrEnemy == 0)
                        {
                            enemyTurn(blocked);
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            bossTurn(blocked);
                        }
                    }
                    else
                    {
                        printf("Fire missed!\n");
                        if (Un.bossOrEnemy == 0)
                        {
                            enemyTurn(blocked);
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            bossTurn(blocked);
                        }
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Fire!\n");
                }
            }
            else if (magicMenuChoice == already[1] && already[1] > 0)
            {
                if (Pl.MP >= Ma.blizzardMP)
                {
                    Pl.MP -= Ma.blizzardMP;
                    int blizzardChance = (rand() % 100) + 1;
                    if (blizzardChance <= 100 - Ma.blizzardMiss)
                    {
                        float blizzardDamage = round(((rand() % 126) + 125) * Pl.magicMulti);
                        int freezeChance = (rand() % 100) + 1;
                        if (freezeChance > 100 - Ma.freezeChance)
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                printf("\nDealt %.0f Damage using Blizzard!\n", blizzardDamage);
                                printf("%s has been \033[0;34mfrozen\033[0m and can't move!\n", En.name);
                                playerConfusionDamage(&blizzardDamage);
                                En.frozen = (rand() % 4) + 2;
                                En.HP -= blizzardDamage;
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                printf("\nDealt %.0f Damage using Blizzard!\n", blizzardDamage);
                                printf("%s has been \033[0;34mfrozen\033[0m and can't move!\n", Bo.name);
                                playerConfusionDamage(&blizzardDamage);
                                Bo.frozen = (rand() % 4) + 2;
                                Bo.HP -= blizzardDamage;
                                bossTurn(blocked);                                
                            }
                        }
                        else
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                printf("\nDealt %.0f Damage using Blizzard!\n", blizzardDamage);
                                playerConfusionDamage(&blizzardDamage);
                                En.HP -= blizzardDamage;
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                printf("\nDealt %.0f Damage using Blizzard!\n", blizzardDamage);
                                playerConfusionDamage(&blizzardDamage);
                                Bo.HP -= blizzardDamage;
                                bossTurn(blocked);
                            }
                        }
                    }
                    else
                    {
                        printf("Blizzard Missed!\n");
                        if (Un.bossOrEnemy == 0)
                        {
                            enemyTurn(blocked);
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            bossTurn(blocked);
                        }
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Blizzard!\n");
                }
            }
            else if (magicMenuChoice == already[2] && already[2] > 0)
            {
                if (Pl.MP >= Ma.thunderMP)
                {
                    Pl.MP -= Ma.thunderMP;
                    int thunderChance = (rand() % 100) + 1;
                    if (thunderChance <= 100 - Ma.thunderMiss)
                    {
                        float thunderDamage = round(((rand() % 251) + 320) * Pl.magicMulti);
                        int shockChance = (rand() % 100 + 1);
                        if (shockChance > 100 - Ma.shockChance)
                        {
                            printf("\nDealt %.0f Damage using Thunder!\n", thunderDamage);
                            playerConfusionDamage(&thunderDamage);
                            if (Un.bossOrEnemy == 0)
                            {
                                printf("%s has been \033[0;33mshocked!\033[0m %s will now miss attacks more frequently!\n", En.name, En.name);
                                En.shocked = 1;
                                En.HP -= thunderDamage;
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                printf("%s has been \033[0;33mshocked!\033[0m %s will now miss attacks more frequently!\n", Bo.name, Bo.name);
                                Bo.shocked = 1;
                                Bo.HP -= thunderDamage;
                                bossTurn(blocked);
                            }
                        }
                        else
                        {
                            printf("\nDealt %.0f Damage using Thunder!\n", thunderDamage);
                            playerConfusionDamage(&thunderDamage);
                            if (Un.bossOrEnemy == 0)
                            {
                                En.HP -= thunderDamage;
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                Bo.HP -= thunderDamage;
                                bossTurn(blocked);
                            }
                        }
                    }
                    else
                    {
                        printf("Thunder missed!\n");
                        if (Un.bossOrEnemy == 0)
                        {
                            enemyTurn(blocked);
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            bossTurn(blocked);
                        }
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Thunder!\n");
                }
            }
            else if (magicMenuChoice == already[3] && already[3] > 0)
            {
                if (Pl.MP >= Ma.aeroMP)
                {
                    Pl.MP -= Ma.aeroMP;
                    int aeroChance = (rand() % 100) + 1;
                    if (aeroChance <= 100 - Ma.aeroMiss)
                    {
                        int confuseChance = (rand() % 100) + 1;
                        float aeroDamage = round(((rand() % 200) + 175) * Pl.magicMulti);
                        printf("Dealt %.0f damage using Aero!\n", aeroDamage);
                        playerConfusionDamage(&aeroDamage);
                        if (Un.bossOrEnemy == 0)
                        {
                            En.HP -= aeroDamage;
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            Bo.HP -= aeroDamage;
                        }
                        if (confuseChance > 100 - Ma.confuseChance)
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                printf("%s is now \033[0;35mconfused\033[0m and may hit themselves!\n",En.name);
                                En.confused = 1;
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                printf("%s is now \033[0;35mconfused\033[0m and may hit themselves!\n",Bo.name);
                                Bo.confused = 1;
                                bossTurn(blocked);
                            }
                        }
                        else
                        {
                            if (Un.bossOrEnemy == 0)
                            {
                                enemyTurn(blocked);
                            }
                            else if (Un.bossOrEnemy == 1)
                            {
                                bossTurn(blocked);
                            }
                        }
                    }
                    else
                    {
                        printf("Aero Missed!\n");
                        if (Un.bossOrEnemy == 0)
                        {
                            enemyTurn(blocked);
                        }
                        else if (Un.bossOrEnemy == 1)
                        {
                            bossTurn(blocked);
                        }
                    }
                }
                else
                {
                    printf("You don't have enough MP to use Aero!\n");
                }
            }
            else if (magicMenuChoice == back)
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
        } while (magicMenuChoice < 1 || magicMenuChoice > back);
}
void Items(int *blocked)
{
    int itemMenuChoice = 0;
    int already[3] = {0,0,0};
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
                It.potionUsed += 1;
                if (Pl.bench == 0)
                {
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
                }
            }
            else if (Pl.HP >= Pl.maxHP)
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
                It.etherUsed += 1;
                if (Pl.bench == 0)
                {
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
                }
            }
            else if (Pl.MP >= Pl.maxMP)
            {
                printf("Using an ether now would have no effect!\n");
            }
        }
        else if (itemMenuChoice == already[2] && already[2] > 0)
        {
            if (Pl.burned == 0 && Pl.frozen == 0 && Pl.shocked == 0 && Pl.confused == 0)
            {
                printf("Using a panacea now would have no effect!\n");
            }
            else
            {
                It.panaceaUsed += 1;
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
                    if (Un.bossOrEnemy == 0)
                    {
                        enemyTurn(blocked);
                    }
                    else if (Un.bossOrEnemy == 1)
                    {
                        bossTurn(blocked);
                    }
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
    int battleDone = 0;
    En.maxHP = En.HP;
    Bo.maxHP = Bo.HP;
    It.maxPotionCount = It.potionC;
    It.maxEtherCount = It.etherC;   //used for end-game statistics, might add more if we decide to track more
    It.maxPanaceaCount = It.panaceaC;
    int blocked = 0;
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
        if (Un.bossOrEnemy == 0)
        {
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
        }
        if (Un.bossOrEnemy == 1)
        {
            if (Bo.burned == 1)
            {
                printf("\033[0;31m*\033[0m");
            }
            if (Bo.frozen >= 1)
            {
                printf("\033[0;34m*\033[0m");
            }
            if (Bo.shocked == 1)
            {
                printf("\033[0;33m*\033[0m");
            }
            if (Bo.confused == 1)
            {
                printf("\033[0;35m*\033[0m");
            }
            printf("%s's HP: %d\n", Bo.name, Bo.HP);
        }
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
            Items(&blocked);
        }
        else
        {
            printf("Please enter a different number.\n");
        }
        if (Pl.HP <= 0 || En.HP <= 0)
        {
            battleDone = 1;
        }
        if (Pl.HP <= 0 || Bo.HP <= 0)
        {
            battleDone = 1;
        }
    } while (battleDone == 0);
    if (Pl.HP <= 0 && (En.HP <= 0 || Bo.HP <= 0))
    {
        Pl.HP = 0;
        En.HP = 0;
        Bo.HP = 0;
        printf("The battle has ended in a draw!\n");
        if (Un.inEndless == 1)
        {
            if (Un.bossOrEnemy == 0)
            {
                printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, En.maxHP);
            }
            else if (Un.bossOrEnemy == 1)
            {
                printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, Bo.name, Bo.HP, Bo.maxHP);
            }
            printf("Potions Used: %d\nEthers Used: %d\n", It.potionUsed, It.etherUsed);
            printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        }
    }
    else if (Pl.HP <= 0)           
    {
        if (Un.bossOrEnemy == 0)
        {
            printf("You lost to %s...\n", En.name);
        }
        else if (Un.bossOrEnemy == 1)
        {
            printf("You lost to %s...\n", Bo.name);
        }
        Pl.HP = 0;
        if (Un.inEndless == 1)
        {
            if (Un.bossOrEnemy == 0)
            {
                printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, En.maxHP);
            }
            else if (Un.bossOrEnemy == 1)
            {
                printf("Ending Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, Bo.name, Bo.HP, Bo.maxHP);
            }
            printf("Potions Used: %d\nEthers Used: %d\n", It.potionUsed, It.etherUsed);
            printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        }
    }
    else if (En.HP <= 0 || Bo.HP <= 0)
    {
        En.HP = 0;
        Bo.HP = 0;
        if (Un.bossOrEnemy == 0)
        {
            printf("You have defeated %s!\n\n", En.name);
        }
        else if (Un.bossOrEnemy == 1)
        {
            printf("You have defeated %s!\n\n", Bo.name);
        }
        int moreExp = (rand() % 500) + 500;
        moreExp = (moreExp*Pl.expMulti) * (Un.battles * 0.25);
        moreExp = round(moreExp);
        Pl.experience += moreExp; 
        float moreG = (rand() % 3) + 20;
        moreG = moreG*(Pl.GMulti*(Un.battles * 0.5));
        moreG = round(moreG);
        if ((int)Un.battles % 4 == 0)
        {
            moreG += 30;
        }
        if (Un.inEndless == 0)
        {
            printf("You gained %d experience\n", moreExp);
            Pl.G = 0;
        }
        else if (Un.inEndless == 1 && Pl.HP > 0)
        {
            if (Un.battles == 1)
            {
                moreG += 10;             //if someone could help me find a balanced formula for the amount of G you get after each battle, that'd be great ~Roxie
                printf("You gained %d experience and %.0fG\n", moreExp, moreG);
                Pl.G += moreG;
            }
            else
            {
                printf("You gained %d experience and %.0fG\n", moreExp, moreG);
                Pl.G += moreG;
            }
            En.HP = En.maxHP;
            Bo.HP = Bo.maxHP;
            Shop(playing,modified,titleChoi);
        }
    }
    else
    {
        printf("This message should never appear. If this appears, you found a bug!\n");        //gotta do something for this right? funsies
    }
    if (Un.inEndless == 0)
    {
        if (Un.bossOrEnemy == 0)
        {
            printf("Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, En.name, En.HP, En.maxHP);
        }
        else if (Un.bossOrEnemy == 1)
        {
            printf("Stats:\n%s's HP: %d/%d\t||\t%s's HP: %d/%d\n", Pl.name, Pl.HP, Pl.maxHP, Bo.name, Bo.HP,Bo.maxHP);
        }
        printf("Potions Used: %d/%d\nEthers Used: %d/%d\n", It.potionUsed, It.maxPotionCount, It.etherUsed, It.maxEtherCount);
        printf("Remaining MP: %d/%d\n", Pl.MP, Pl.maxMP);
        printf("Total Experience: %d\n", Pl.experience);
    }
        int playChoice = 0;
        if (Pl.bench == 0)
        {
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
void startingGame(int *playing, int *modified, int *titleChoi)
{
    int nameChoi = 0;
    do
    {
        printf("Would you like to name you or your opponent?\n");
        printf("[1] Rename Player\n");
        printf("[2] Rename Enemy\n[3] Rename Boss\n[4] Rename All at Random\n");
        printf("[5] Start Game\n[6] Back to Title Screen\n");
        scanf("%d", &nameChoi);
        if (nameChoi == 1)
        {
            nameChoi = 0;
            getchar();
            printf("Enter your name: ");
            fgets(Pl.name,sizeof(Pl.name), stdin);
            Pl.name[strlen(Pl.name) - 1] = '\0';
            printf("Successfully renamed yourself to \"%s\"\n",Pl.name);
        }
        else if (nameChoi == 2)
        {
            nameChoi = 0;
            getchar();
            printf("Enter the name of an enemy: ");
            fgets(En.name,sizeof(En.name), stdin);
            En.name[strlen(En.name) - 1] = '\0';
            printf("Successfully renamed the enemy to \"%s\"\n",En.name);
        }
        else if (nameChoi == 3)
        {
            nameChoi = 0;
            getchar();
            printf("Enter the name of the boss: ");
            fgets(Bo.name,sizeof(Bo.name), stdin);
            Bo.name[strlen(Bo.name) - 1] = '\0';
            printf("Successfully renamed the boss to \"%s\"\n",Bo.name);
        }    
        else if (nameChoi == 4)
        {
            nameChoi = 0;
            char nameLine[50];
            FILE *names = fopen("names.txt", "r+");
            if (names == NULL)
            {
                printf("\033[0;31mFailed to retrieve names. Please make sure 'names.txt' file is present in the directory!\033[0m\n");
                break;
            }
            int lineCount = 0;
            while (fgets(nameLine, sizeof(nameLine), names))
            {
                lineCount++;
            }
            fseek(names,0,SEEK_SET);
            int currentLine = 0;
            int nameResu = (rand() % lineCount);
            int nameResu2 = (rand() % lineCount);
            int nameResu3 = (rand() % lineCount);
            while (fgets(nameLine,sizeof(nameLine),names))
            {
                if (currentLine == nameResu)
                {
                    nameLine[strcspn(nameLine, "\n")] = '\0';
                    strcpy(Pl.name, nameLine);
                    break;
                }
                currentLine++;
            }
            currentLine = 0;
            rewind(names);              //rewinds the pointer back to the beginning of names.txt
            while (fgets(nameLine,sizeof(nameLine),names))
            {
                if (currentLine == nameResu2)
                {
                    nameLine[strcspn(nameLine, "\n")] = '\0';
                    strcpy(En.name, nameLine);
                    break;
                }
                currentLine++;
            }
            currentLine = 0;
            rewind(names);              //rewinds the pointer back to the beginning of names.txt
            while (fgets(nameLine,sizeof(nameLine),names))
            {
                if (currentLine == nameResu3)
                {
                    nameLine[strcspn(nameLine, "\n")] = '\0';
                    strcpy(Bo.name, nameLine);
                    break;
                }
                currentLine++;
            }
            fclose(names);
            printf("Successfully renamed yourself to \"%s\"\n",Pl.name);
            printf("Successfully renamed the enemy to \"%s\"\n",En.name);
            printf("Successfully renamed the boss to \"%s\"\n",Bo.name);
        }
        else if (nameChoi == 5)
        {
            nameChoi == 6;
            printf("Starting the game!\n\n");
            Pl.maxHP = Pl.HP;
            Pl.maxMP = Pl.MP;
            mainMenu(playing, modified, titleChoi);            
        }
        else if (nameChoi == 6)
        {
            titleChoi = 0;
            printf("\n\n\n");
            continue; 
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (nameChoi < 1 || nameChoi > 6);
}
int main(void)
{
    int playing = 0;
    do
    {
        Un.inEndless = 0;
        int modified = 0;       //used for if the player modified settings
        int titleChoi = 0;
        initialize();           //this is located in endless.h at the bottom
    //from testing, the values had to be set to 0 to prevent memory overflow (Specifically in blizzardChance and potionCount, idk why those two specifically ~Roxie)
        srand(time(NULL)); //sets the seed for the random values based on time
        do
        {
            FILE *fptr;   
            fptr = fopen("title.txt", "r"); 
            char c = fgetc(fptr); 
            while (c != EOF) 
            { 
                printf ("%c", c); 
                c = fgetc(fptr); 
            }
            fclose(fptr);
            printf("\nSelect a choice! (Type the number corresponding to the option, then press enter)\n");
            printf("[1] Single Battle\n[2] Endless Battle\n[3] Options\n[4] Exit\n"); //didnt separate this printf statement bc it was so small ~Roxie
            scanf("%d", &titleChoi);
            if (titleChoi == 1)             //we can do switch case if we want, but it doesn't matter
            {
                int classChoi = 0;
                do
                {
                    printf("Select your class!\n");
                    printf("[1] Knight (1250HP, 75MP, Attack Mulitplier: 1.3x, Magic Multiplier: 0.75x)\n");
                    printf("[2] Mage (750HP, 125MP, Attack Multiplier: 0.75x, Magic Multiplier: 1.3x)\n");
                    printf("[3] Rogue (1000HP, 100MP, Attack Multiplier: 1x, Magic Multiplier: 1x)\n");
                    printf("[4] Custom (Determined in Options)\n");
                    printf("[5] Back\n");
                    scanf("%d", &classChoi);
                    if (classChoi == 1)
                    {
                        classChoi = 5;
                        knight();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 2)
                    {
                        classChoi = 5;
                        mage();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 3)
                    {
                        classChoi = 5;
                        rogue();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 4)
                    {
                        classChoi = 5;
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 5)
                    {
                        Un.inEndless = 0;
                        continue;
                    }
                    else
                    {
                        printf("Please enter a different number.\n");
                    }
                } while (classChoi < 1 || classChoi > 5);
            }
            else if (titleChoi == 2)
            {
                Un.inEndless = 1;
                int classChoi = 0;
                do
                {
                    printf("Select your class!\n");
                    printf("[1] Knight (1250HP, 50MP, Attack Mulitplier: 1.1x)\n");
                    printf("[2] Mage (750HP, 150MP, Magic Multiplier: 1.3x)\n");
                    printf("[3] Rogue (1000HP, 100MP, No Multipliers)\n");
                    printf("[4] Custom (Determined in Options)\n");
                    printf("[5] Back\n");
                    scanf("%d", &classChoi);
                    if (classChoi == 1)
                    {
                        classChoi = 5;
                        knight();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 2)
                    {
                        classChoi = 5;
                        mage();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 3)
                    {
                        classChoi = 5;
                        rogue();
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 4)
                    {
                        classChoi = 5;
                        startingGame(&playing,&modified,&titleChoi);
                    }
                    else if (classChoi == 5)
                    {
                        Un.inEndless = 0;
                        continue;
                    }
                    else
                    {
                        printf("Please enter a different number.\n");
                    }
                } while (classChoi < 1 || classChoi > 5);
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