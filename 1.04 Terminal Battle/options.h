#ifndef Options
#define Options
#include <stdlib.h>
#include "endless.h"
void enemyOptions(int *modified)
{
    int enemyChoi = 0;
    do
    {
        printf("Enemy Options:\n");
        printf("[1] Regular Enemy Name\t\t\t(Currently: '%s')\n", En.name);
        printf("[2] Regular Enemy HP\t\t\t(Currently: %d)\n",En.HP);
        printf("[3] Regular Enemy Damage Multiplier\t(Currently: %.2fx)\n", En.enemyDamageMulti);
        printf("[4] Boss Name\t\t\t\t(Currently: '%s')\n",Bo.name);
        printf("[5] Boss HP\t\t\t\t(Currently: %d)\n",Bo.HP);
        printf("[6] Boss Damage Multiplier\t\t(Currently: %.2fx)\n", Bo.bossDamageMulti);
        printf("[7] Back\n");
        scanf("%d",&enemyChoi);
        if (enemyChoi == 1)
        {
            enemyChoi = 0;
            *modified = 1;
            getchar();
            printf("Enter the enemy's new name: ");
            fgets(En.name,sizeof(En.name), stdin);
            En.name[strlen(En.name) - 1] = '\0';
            printf("Regular Enemy name has succesfully been changed to %s\n", En.name);
        }
        else if (enemyChoi == 2)
        {
            enemyChoi = 0;
            *modified = 1;
            printf("Enter new amount for Max Enemy HP: ");
            scanf("%d", &En.HP);
            printf("Max Enemy HP successfully changed!\n");
        }
        else if (enemyChoi == 3)
        {
            enemyChoi = 0;
            *modified = 1;
            printf("Enter new Enemy Attack Multiplier (Can Include Decimals): ");
            scanf("%f", &En.enemyDamageMulti);
            printf("Enemy Attack Multiplier successfully changed!\n");
        }
        else if (enemyChoi == 4)
        {
            enemyChoi = 0;
            *modified = 1;
            getchar();
            printf("Enter the boss's new name: ");
            fgets(Bo.name,sizeof(Bo.name), stdin);
            Bo.name[strlen(Bo.name) - 1] = '\0';
            printf("Boss' name has succesfully been changed to %s\n", Bo.name);
        }
        else if (enemyChoi == 5)
        {
            enemyChoi = 0;
            *modified = 1;
            printf("Enter new Boss HP\n");
            scanf("%d", &Bo.HP);
            printf("Boss HP successfully changed!\n");
        }
        else if (enemyChoi == 6)
        {
            enemyChoi = 0;
            *modified = 1;
            printf("Enter new Boss Attack Multiplier (Can Include Decimals): ");
            scanf("%f", &Bo.bossDamageMulti);
            printf("Boss Attack Multiplier successfully changed!\n");
        }
        else if (enemyChoi == 7)
        {
            break;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (enemyChoi < 1 || enemyChoi > 7);
}
void unlockableOptions(int *modified)
{
    int unlockChoi = 0;
    do
    {
        int correctChar = 0;
        printf("Unlockable Options:\n");
        printf("[1] Lucky Strike Unlocked\t\t\t(Currently: ");
        if (Pl.hasLucky == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[2] Quickdraw Unlocked\t\t\t\t(Currently: ");
        if (Pl.hasQuick == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[3] Ars Arcanum Unlocked\t\t\t(Currently: ");
        if (Pl.hasArs == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[4] Critical Hit Unlocked\t\t\t(Currently: ");
        if (Pl.hasCritHit == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[5] Fire Unlocked\t\t\t\t(Currently: ");
        if (Pl.hasFire == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[6] Blizzard Unlocked\t\t\t\t(Currently: ");
        if (Pl.hasBlizzard == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[7] Thunder Unlocked\t\t\t\t(Currently: ");
        if (Pl.hasThunder == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[8] Aero Unlocked\t\t\t\t(Currently: ");
        if (Pl.hasAero == 1)
        {
            printf("Yes)\n");
        }
        else
        {
            printf("No)\n");
        }
        printf("[9] Back\n");
        scanf("%d",&unlockChoi);
        if (unlockChoi == 1)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Lucky Strike, or N to lock Lucky Strike\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasLucky = 1;
                    printf("Unlocked Lucky Strike!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasLucky = 0;
                    printf("Locked Lucky Strike!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Lucky Strike!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 2)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Quickdraw, or N to lock Quickdraw\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasQuick = 1;
                    printf("Unlocked Quickdraw!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasQuick = 0;
                    printf("Locked Quickdraw!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Quickdraw!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 3)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Ars Arcanum, or N to lock Ars Arcanum\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasArs = 1;
                    printf("Unlocked Ars Arcanum!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasArs = 0;
                    printf("Locked Ars Arcanum!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Ars Arcanum!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 4)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Critical Hit, or N to lock Critical Hit\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasCritHit = 1;
                    printf("Unlocked Critical Hit!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasCritHit = 0;
                    printf("Locked Critical Hit!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Critical Hit!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 5)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Fire, or N to lock Fire\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasFire = 1;
                    printf("Unlocked Fire!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasFire = 0;
                    printf("Locked Fire!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Fire!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 6)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Blizzard, or N to lock Blizzard\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasBlizzard = 1;
                    printf("Unlocked Blizzard!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasBlizzard = 0;
                    printf("Locked Blizzard!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Blizzard!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 7)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Thunder, or N to lock Thunder\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasThunder = 1;
                    printf("Unlocked Thunder!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasThunder = 0;
                    printf("Locked Thunder!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Thunder!\n");
                }
            } while (correctChar != 1);
        }
        else if (unlockChoi == 8)
        {
            getchar();
            do
            {
                char decision[999];
                unlockChoi = 0;
                *modified = 1;
                printf("Type Y to unlock Aero, or N to lock Aero\n");
                fgets(decision,sizeof(decision),stdin);
                decision[strlen(decision) - 1] = '\0';
                if (strcmp(decision,"Y") == 0 || strcmp(decision,"y") == 0)
                {
                    Pl.hasAero = 1;
                    printf("Unlocked Aero!\n");
                    correctChar = 1;
                }
                else if (strcmp(decision,"N") == 0 || strcmp(decision,"n") == 0)
                {
                    Pl.hasAero = 0;
                    printf("Locked Aero!\n");
                    correctChar = 1;
                }
                else
                {
                    printf("Please enter 'Y' or 'y' to Unlock or 'N' or 'n' to Lock Aero!\n");
                }
            } while (correctChar != 1);
        }
    } while (unlockChoi < 1 || unlockChoi > 9);
}
void playerOptions(int *modified)
{
    int playerChoi = 0;
    int wrongNumber = 0;
    int hidden = 0;
    do
    {
        printf("General Options:\n");
        printf("[1] Player Name\t\t\t (Currently: '%s')\n", Pl.name);
        printf("[2] Player Max HP\t\t (Currently: %dHP)\n",Pl.HP);
        printf("[3] Player Max MP\t\t (Currently: %dMP)\n",Pl.MP);
        printf("[4] Player G\t\t\t (Currently: %dG)\n", Pl.G);
        printf("[5] Player Unlockable Options\n");
        printf("[6] Unlock All Moves\n");
        printf("[7] Lock All Moves\n");
        printf("[8] Back\n");
        if (hidden >= 5)
        {
            printf("[333] \033[1;35mEnable OP mode\033[0m\n");
        }
        scanf("%d", &playerChoi);
        if (playerChoi == 1)
        {
            playerChoi = 0;
            *modified = 1;
            getchar();
            printf("Enter your new name: ");
            fgets(Pl.name,sizeof(Pl.name), stdin);
            Pl.name[strlen(Pl.name) - 1] = '\0';
            printf("Your name has succesfully been changed to %s\n", Pl.name);
        }
        else if (playerChoi == 2)
        {
            playerChoi = 0;
            *modified = 1;
            printf("Enter new amount for Max Player HP: ");
            scanf("%d", &Pl.HP);
            printf("Max Player HP successfully changed!\n");
            Pl.maxHP = Pl.HP;
        }
        else if (playerChoi == 3)
        {
            playerChoi = 0;
            *modified = 1;
            printf("Enter new amount for Max Player MP: ");
            scanf("%d", &Pl.MP);
            printf("Max Player MP successfully changed!\n");
            Pl.maxMP = Pl.MP;
        }
        else if (playerChoi == 4)
        {
            playerChoi = 0;
            *modified = 1;
            printf("Enter new amount for Player G: ");
            scanf("%d", &Pl.G);
            printf("Player G successfully changed!\n");
        }
        else if (playerChoi == 5)
        {
            playerChoi = 0;
            unlockableOptions(modified);
            
        }
        else if (playerChoi == 6)
        {
            playerChoi = 0;
            *modified = 1;
            Pl.hasFire = 1;
            Pl.hasBlizzard = 1;
            Pl.hasThunder = 1;
            Pl.hasAero = 1;
            Pl.hasLucky = 1;
            Pl.hasQuick = 1;
            Pl.hasArs = 1;
            Pl.hasCritHit = 1;
            printf("Successfully unlocked all available moves!\n");
        }
        else if (playerChoi == 7)
        {
            playerChoi = 0;
            *modified = 1;
            Pl.hasFire = 0;
            Pl.hasBlizzard = 0;
            Pl.hasThunder = 0;
            Pl.hasAero = 0;
            Pl.hasLucky = 0;
            Pl.hasQuick = 0;
            Pl.hasArs = 0;
            Pl.hasCritHit = 0;
            printf("Successfully locked all available moves!\n");
        }
        else if (playerChoi == 333)
        {
            playerChoi = 0;
            if (hidden >= 5)
            {
                *modified = 1;
                god();
                printf("\033[0;31mIt has been done...\033[0m\n");
            }
            else if (hidden <= 5)
            {
                hidden += 1;
                if (hidden == 1)
                {
                    wrongNumber = 1;
                    printf("Now why would you do that? A hidden '333rd' option? Get real! Here of all places?\nThere's no menu in this game with that many options on one screen!\nHeck this message is already getting too long, Imagine there being 333 options at ONCE, \nit'd feel like you're watching some kind of hacker movie just seeing all that\n");
                }
                else if (hidden == 2 && wrongNumber == 1)
                {
                    printf("I already told you! There is NO secret!\n");
                }
                else if (hidden == 3 && wrongNumber == 1)
                {
                    printf("Persistent, are you just doing this over and over because you're getting a response?\n");
                }
                else if (hidden == 4 && wrongNumber == 1)
                {
                    printf("LEAVE ME ALONE\n");
                }
                else if (hidden == 5 && wrongNumber == 1)
                {
                    printf("Alright you know what. Become God or something, is that all you wanted? Now get out\n");
                }
            }
        if (hidden > 1 && hidden < 5)
            {
                printf("\033[0;32mSomething strange is going on...Maybe don't do that again?\033[0m\n");
            }
            if (hidden == 5)
            {
                hidden = 10;
                printf("\033[0;31mUnlocked OP mode!\033[0m\n");
            }
        }
        else if (playerChoi == 8)
        {
            printf("\n\n\n");
            break;
        }
        else
        {
            hidden++;
            printf("Please enter a different number.\n");
            if (hidden > 1 && hidden <= 5)
            {
                if (hidden == 2 && wrongNumber == 1)
                {
                    printf("I already told you! There is NO secret!\n");
                }
                else if (hidden == 3 && wrongNumber == 1)
                {
                    printf("Persistent, are you just doing this over and over because you're getting a response?\n");
                }
                else if (hidden == 4 && wrongNumber == 1)
                {
                    printf("LEAVE ME ALONE\n");
                }
                else if (hidden == 5 && wrongNumber == 1)
                {
                    printf("Alright you know what. Become God or something, is that all you wanted? Now get out\n");
                }
                if (hidden > 1 && hidden < 5)
                {
                    printf("\033[0;32mSomething strange is going on...Maybe don't do that again?\033[0m\n");
                }
            }
            if (hidden == 5)
            {
                hidden = 10;
                printf("\033[0;31mUnlocked OP mode!\033[0m\n");
            }
        }
    } while (playerChoi < 1 || playerChoi > 8 || playerChoi != 333);
}
void specialOptions(int *modified)
{
    int specialAttackChoice = 0;
    do
    {
        printf("Special Attack Options:\n");
        printf("[1] Lucky Strike MP Cost\t\t(Currenty: %dMP)\n", At.luckyMP);
        printf("[2] Lucky Strike Block Rate\t\t(Currently: %d%%) \n", At.luckyBlock);
        printf("[3] Quickdraw MP Cost\t\t\t(Currently: %dMP)\n", At.quickdrawMP);
        printf("[4] Ars Arcanum MP Cost\t\t\t(Currently: %dMP)\n", At.arsMP);
        printf("[5] Ars Arcanum Block Rate\t\t(Currently: %d%%)\n", At.arsBlock);
        printf("[6] Critical Hit MP Cost\t\t(Currently: %dMP)\n", At.critHitMP);
        printf("[7] Critical Hit Success Rate\t\t(Currently: %d%%)\n", At.critHitSuc);
        printf("[8] Critical Hit Block Rate\t\t(Currently: %d%%)\n", At.critHitBlock);
        printf("[9] Back\n");
        scanf("%d", &specialAttackChoice);
        if (specialAttackChoice == 1)
        {
            *modified = 1;
            specialAttackChoice = 0;
            printf("Enter new Lucky Strike MP Cost: ");
            scanf("%d", &At.luckyMP);
            printf("Lucky Strike MP Cost successfully changed!\n");
        }
        else if (specialAttackChoice == 2)
        {
            do
            {
                *modified = 1;
                specialAttackChoice = 0;
                printf("Enter new Lucky Strike Block Rate: ");
                scanf("%d", &At.luckyBlock);
                if (At.luckyBlock < 0 || At.luckyBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Lucky Strike Block Rate successfully changed!\n");    
                }
            }  while (At.luckyBlock < 0 || At.luckyBlock > 100);
        }
        else if (specialAttackChoice == 3)
        {
            specialAttackChoice = 0;
            *modified = 1;
            printf("Enter new Quickdraw MP Cost: ");
            scanf("%d", &At.quickdrawMP);
            printf("Quickdraw MP Cost successfully changed!\n");
        }
        else if (specialAttackChoice == 4)
        {
            specialAttackChoice = 0;
            *modified = 1;
            printf("Enter new Ars Arcanum MP Cost: ");
            scanf("%d", &At.arsMP);
            printf("Ars Arcanum MP Cost successfully changed!\n");
        }
        else if (specialAttackChoice == 5)
        {
            do
            {
                specialAttackChoice = 0;
                *modified = 1;
                printf("Enter new Ars Arcanum Block Rate: ");
                scanf("%d", &At.arsBlock);
                if (At.arsBlock < 0 || At.arsBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Ars Arcanum Block Rate successfully changed!\n");    
                }
            }  while (At.arsBlock < 0 || At.arsBlock > 100);
        }
        else if (specialAttackChoice == 6)
        {
            specialAttackChoice = 0;
            *modified = 1;
            printf("Enter new Critical Hit MP Cost: ");
            scanf("%d", &At.critHitMP);
            printf("Critical Hit MP Cost successfully changed!\n");
        }
        else if (specialAttackChoice == 7)
        {
            do
            {
                specialAttackChoice = 0;
                *modified = 1;
                printf("Enter new Critical Hit Success Rate: ");
                scanf("%d", &At.critHitSuc);
                if (At.critHitSuc < 0 || At.critHitSuc > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Critical Hit Sucess Rate successfully changed!\n");    
                }
            }  while (At.critHitSuc < 0 || At.critHitSuc > 100);
        }
        else if (specialAttackChoice == 8)
        {
            do
            {
                specialAttackChoice = 0;
                *modified = 1;
                printf("Enter new Critical Hit Block Rate: ");
                scanf("%d", &At.critHitBlock);
                if (At.critHitBlock < 0 || At.critHitBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Critical Hit Block Rate successfully changed!\n");    
                }
            }  while (At.critHitBlock < 0 || At.critHitBlock > 100);
        }
        else if (specialAttackChoice == 9)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (specialAttackChoice < 1 || specialAttackChoice > 9);
}
void attackOptions(int *modified)
{
    int attackOptionChoice = 0;
    do
    {
        printf("Attack Options:\n");
        printf("[1] Attack Damage Multiplier\t\t(Currently: %.2fx)\n",Pl.attackMulti);
        printf("[2] Light Attack Block Rate\t\t(Curently: %d%%)\n", At.lightBlock);
        printf("[3] Heavy Attack Block Rate\t\t(Currently: %d%%)\n", At.heavyBlock);
        printf("[4] Special Attack Options\n");
        printf("[5] Back\n");
        scanf("%d", &attackOptionChoice);
        if (attackOptionChoice == 1)
        {
            attackOptionChoice = 0;
            *modified = 1;
            printf("Enter new Attack Multiplier (Can Include Decimals): ");
            scanf("%f", &Pl.attackMulti);
            printf("Attack Multiplier successfully changed!\n");
        }
        else if (attackOptionChoice == 2)
        {
            do
            {
                attackOptionChoice = 0;
                *modified = 1;
                printf("Enter new Light Attack Block Rate: ");
                scanf("%d", &At.lightBlock);
                if (At.lightBlock < 0 || At.lightBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Light Attack Block Rate successfully changed!\n");    
                }
            }  while (At.lightBlock < 0 || At.lightBlock > 100);
        }
        else if (attackOptionChoice == 3)
        {
            do
            {
                attackOptionChoice = 0;
                *modified = 1;
                printf("Enter new Heavy Attack Block Rate: ");
                scanf("%d", &At.heavyBlock);
                if (At.heavyBlock < 0 || At.heavyBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Heavy Attack Block Rate successfully changed!\n");    
                }
            }  while (At.heavyBlock < 0 || At.heavyBlock > 100);
        }
        else if (attackOptionChoice == 4)
        {
            attackOptionChoice = 0;
            printf("\n\n\n");
            specialOptions(modified);
        }
        else if (attackOptionChoice == 5)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (attackOptionChoice < 1 || attackOptionChoice > 5);   
}
void magicOptionsTwo(int *modified)
{
    int magicOptionChoiceTwo = 0;
    do
    {
        printf("[1] Blizzard Miss Chance\t\t(Currently: %d%%)\n", Ma.blizzardMiss);
        printf("[2] Thunder MP Cost\t\t\t(Currently: %dMP)\n", Ma.thunderMP);
        printf("[3] Thunder Shock Chance\t\t(Currently: %d%%)\n", Ma.shockChance);
        printf("[4] Thunder Miss Chance\t\t\t(Currently: %d%%)\n", Ma.thunderMiss);
        printf("[5] Aero MP Cost\t\t\t(Currently: %dMP)\n", Ma.aeroMP);
        printf("[6] Aero Confuse Chance\t\t\t(Currently: %d%%)\n", Ma.confuseChance);
        printf("[7] Aero Miss Chance\t\t\t(Currently: %d%%)\n", Ma.aeroMiss);
        printf("[8] Back\n");
        scanf("%d", &magicOptionChoiceTwo);
        if (magicOptionChoiceTwo == 1)
        {
            do
            {
                magicOptionChoiceTwo = 0;
                *modified = 1;
                printf("Enter new Blizzard Miss Chance: ");
                scanf("%d", &Ma.blizzardMiss);
                if (Ma.blizzardMiss < 0 || Ma.blizzardMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Blizzard Miss Chance successfully changed!\n");    
                }
            }  while (Ma.blizzardMiss < 0 || Ma.blizzardMiss > 100);
        }
        else if (magicOptionChoiceTwo == 2)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Thunder MP cost: ");
            scanf("%d", &Ma.thunderMP);
            printf("Thunder MP cost successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 3)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Thunder Shock Chance: ");
            scanf("%d", &Ma.shockChance);
            printf("Thunder Shock Chance successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 4)
        {
            do
            {
                magicOptionChoiceTwo = 0;
                *modified = 1;
                printf("Enter new Thunder Miss Chance: ");
                scanf("%d", &Ma.thunderMiss);
                if (Ma.thunderMiss < 0 || Ma.thunderMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Thunder Miss Chance successfully changed!\n");    
                }
            }  while (Ma.thunderMiss < 0 || Ma.thunderMiss > 100);
        }
        else if (magicOptionChoiceTwo == 5)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Aero MP cost: ");
            scanf("%d", &Ma.aeroMP);
            printf("Aero MP cost successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 6)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Aero Confuse Chance: ");
            scanf("%d", &Ma.confuseChance);
            printf("Aero Confuse Chance successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 7)
        {
            do
            {
                magicOptionChoiceTwo = 0;
                *modified = 1;
                printf("Enter new Aero Miss Chance: ");
                scanf("%d", &Ma.aeroMiss);
                if (Ma.aeroMiss < 0 || Ma.aeroMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Aero Miss Chance successfully changed!\n");    
                }
            }  while (Ma.aeroMiss < 0 || Ma.aeroMiss > 100);
        }
        else if (magicOptionChoiceTwo == 8)
        {
            printf("\n\n\n");
            continue;
        }
    } while (magicOptionChoiceTwo < 1 || magicOptionChoiceTwo > 8);
}
void magicOptions(int *modified)
{
    int magicOptionChoice = 0;
    do
    {
        printf("Magic Options:\n");
        printf("[1] Magic Damage Multiplier\t\t(Currently: %.2fx)\n",Pl.magicMulti);
        printf("[2] Fire MP Cost\t\t\t(Currently: %dMP)\n", Ma.fireMP);
        printf("[3] Fire Burn Chance\t\t\t(Currently: %d%%)\n", Ma.burnChance);
        printf("[4] Fire Miss Chance\t\t\t(Currently: %d%%)\n", Ma.fireMiss);
        printf("[5] Blizzard MP Cost\t\t\t(Currently: %dMP)\n", Ma.blizzardMP);
        printf("[6] Blizzard Freeze Chance\t\t(Currently: %d%%)\n",Ma.freezeChance);
        printf("[7] Next Page\n");
        printf("[8] Back\n");
        scanf("%d", &magicOptionChoice);
        if (magicOptionChoice == 1)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Magic Multiplier (Can Include Decimals): ");
            scanf("%f", &Pl.magicMulti);
            printf("Magic Multiplier successfully changed!\n");            
        }
        else if (magicOptionChoice == 2)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Fire MP cost: ");
            scanf("%d", &Ma.fireMP);
            printf("Fire MP cost successfully changed!\n");
        }
        else if (magicOptionChoice == 3)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Fire Burn Chance: ");
            scanf("%d", &Ma.burnChance);
            printf("Fire Burn Chance successfully changed!\n");
        }
        else if (magicOptionChoice == 4)
        {
            do
            {
                magicOptionChoice = 0;
                *modified = 1;
                printf("Enter new Fire Miss Chance: ");
                scanf("%d", &Ma.fireMiss);
                if (Ma.fireMiss < 0 || Ma.fireMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Fire Miss Chance successfully changed!\n");    
                }
            }  while (Ma.fireMiss < 0 || Ma.fireMiss > 100);
        }
        else if (magicOptionChoice == 5)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Blizzard MP cost: ");
            scanf("%d", &Ma.blizzardMP);
            printf("Blizzard MP cost successfully changed!\n");
        }
        else if (magicOptionChoice == 6)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Blizzard Freeze Chance: ");
            scanf("%d", &Ma.freezeChance);
            printf("Blizzard Freeze Chance successfully changed!\n");
        }
        else if (magicOptionChoice == 7)
        {
            magicOptionChoice = 0;
            magicOptionsTwo(modified);
        }
        else if (magicOptionChoice == 8)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (magicOptionChoice < 1 || magicOptionChoice > 10);
}
void itemOptions(int *modified)
{
    int itemOptionChoice = 0;
    do
    {
        printf("Item Options:\n");
        printf("[1] Potion Count\t\t (Currently: %d)\n", It.potionC);
        printf("[2] Potion Heal Amount\t\t (Currently: %dHP)\n", It.potionHeal);
        printf("[3] Ether Count\t\t\t (Currently %d)\n", It.etherC);
        printf("[4] Ether MP restoration Amount\t (Currently: %dMP)\n", It.etherRest);
        printf("[5] Panacea Count\t\t (Currently: %d)\n", It.panaceaC);
        printf("[6] Back\n");
        scanf("%d", &itemOptionChoice);
        if (itemOptionChoice == 1)
        {
            itemOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for Potion Count: ");
            scanf("%d", &It.potionC);
            printf("Potion Count successfully changed!\n");
        }
        else if (itemOptionChoice == 2)
        {
            itemOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for the Potion Heal Amount: ");
            scanf("%d", &It.potionHeal);
            printf("Potion Heal Amount successfully changed!\n");
        }
        else if (itemOptionChoice== 3)
        {
            itemOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for the Ether Count: ");
            scanf("%d", &It.etherC);
            printf("Ether Count successfully changed!\n");
        }
        else if (itemOptionChoice == 4)
        {
            itemOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for the Ether's MP Restoration Count: ");
            scanf("%d", &It.etherRest);
            printf("Ether's MP Restoration Amount successfully changed!\n");
        }
        else if (itemOptionChoice == 5)
        {
            itemOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for Panacea Count: ");
            scanf("%d", &It.panaceaC);
            printf("Panacea Count successfully changed!\n");
        }
        else if (itemOptionChoice == 6)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (itemOptionChoice < 1 || itemOptionChoice > 6);
}
void gameOptions(int *modified)
{
    int optionChoice = 0;
    printf("\n\n\n");
    do
    {
        printf("[1] Player Options\n");
        printf("[2] Opponent Options\n");
        printf("[3] Attack Options\n");
        printf("[4] Magic Options\n");
        printf("[5] Item Options\n");
        printf("[6] Reset all Options\n");
        printf("[7] Back\n");
        scanf("%d", &optionChoice);
        if (optionChoice == 1)
        {
            optionChoice = 0;
            printf("\n\n\n");
            playerOptions(modified);
        }
        else if (optionChoice == 2)
        {
            optionChoice = 0;
            printf("\n\n\n");
            enemyOptions(modified);
        }
        else if (optionChoice == 3)
        {
            optionChoice = 0;
            printf("\n\n\n");
            attackOptions(modified);   
        }
        else if (optionChoice == 4)
        {
            optionChoice = 0;
            printf("\n\n\n");
            magicOptions(modified);
        }
        else if (optionChoice == 5)
        {
            optionChoice = 0;
            printf("\n\n\n");
            itemOptions(modified);
        }
        else if (optionChoice == 6)
        {
            optionChoice = 0;
            int resetChoi = 0;
            do
            {
                printf("Are you sure you want to reset all options? This cannot be undone\n[1] Yes\n[2] No\n");
                scanf("%d",&resetChoi);
                if (resetChoi == 1)
                {
                    *modified = 0;
                    initialize();
                    printf("All options have been reset to default!\n");
                }
                else if (resetChoi == 2)
                {
                    continue;
                }
                else
                {
                    printf("Please enter a different number.\n");
                }
            } while (resetChoi < 1 || resetChoi > 2);
        }
        else if (optionChoice == 7)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (optionChoice < 1 || optionChoice > 7);
}
#endif