#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void enemyTurn(int *enemyHP, int *playerHP, int *enemyFreeze, int *enemyBurned, char enemyName[100])
{
    int enemyBurn = 0;
    if (*enemyBurned == 1)
    {
        enemyBurn = (rand() % 50) + 25;
    }
    if (*enemyHP <= 0)
    {
        return;
    }
    else
    {
        if (*enemyFreeze <= 0)
        {
            int enemyAttack = (rand() % 100);
            if (enemyAttack <= 40)
            {
                int enemyDamage = (rand() % 75) + 50;
                printf("%s used Dark Firaga and dealt %d Damage!\n", enemyName, enemyDamage);
                *playerHP -= enemyDamage;
                *enemyHP -= enemyBurn;
            }
            else if (enemyAttack > 40 && enemyAttack <= 70)
            {
                int enemyDamage = (rand() % 125) + 100;
                printf("%s used Dark Break and dealt %d Damage!\n", enemyName,enemyDamage);
                *playerHP -= enemyDamage;
                *enemyHP -= enemyBurn;
            }
            else if (enemyAttack > 70 && enemyAttack <=85)
            {
                int enemyDamage = (rand() % 175) + 175;
                printf("%s used Dark Aura and dealt %d Damage!\n", enemyName, enemyDamage);
                *playerHP -= enemyDamage;
                *enemyHP -= enemyBurn;
            }
            else
            {
            printf("%s went for an attack but missed!\n", enemyName);
            *enemyHP -= enemyBurn;
            }
        }
        else
        {
            printf("%s is frozen solid for %d more turns!\n", enemyName, *enemyFreeze);
            *enemyFreeze -= 1;
        }
    }
    if (*enemyBurned == 1)
    {
        printf("%s took %d additional burn damage\n", enemyName, enemyBurn);
    }
}
void Magic(int *playerHP,int *enemyHP, int *enemyFreeze, int *enemyBurn, char enemyName[100])
{
    int magicMenuChoice;
    do
        {
            printf("[1] Firaga (Low Damage, 15%% Chance to Burn, Guaranteed Hit)\n");
            printf("[2] Blizzaga (Medium Damage, 15%% Chance to Freeze, 15%% Chance to miss)\n");
            printf("[3] Thundaga (Large Damage, 50%% Chance to Miss)\n[4] Back\n");
            scanf("%d", &magicMenuChoice);
            if (magicMenuChoice == 1)
            {
                int firagaDamage = (rand() % 121) + 60;
                int burnChance = (rand() % 100);
                printf("\nDealt %d Damage using Firaga!\n", firagaDamage);
                *enemyHP -= firagaDamage;
                if (*enemyFreeze > 0)
                {
                    printf("Firaga thawed %s out...\n", enemyName);
                    *enemyFreeze = 0;
                }
                else if (burnChance < 15)
                {
                    *enemyBurn = 1;
                    printf("%s has been burned!\n", enemyName);
                }
                enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
            }
            else if (magicMenuChoice == 2)
            {
                int blizzagaChance = (rand() % 100);
                if (blizzagaChance >= 15)
                {
                    int blizzagaDamage = (rand() % 126) + 125;
                    int freezeChance = (rand() % 100);
                    if (freezeChance <= 14)
                    {
                        printf("\nDealt %d Damage using Blizzaga!\n", blizzagaDamage);
                        printf("%s has been frozen!\n", enemyName);
                        *enemyFreeze = (rand() % 4) + 1;
                        *enemyHP -= blizzagaDamage;
                        enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
                    }
                    else
                    {
                        printf("\nDealt %d Damage using Blizzaga!\n", blizzagaDamage);
                        *enemyHP -= blizzagaDamage;
                        enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
                    }
                }
                else
                {
                    printf("Blizzaga Missed!\n");
                    enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
                }
            }
            else if (magicMenuChoice == 3)
            {
                int thundagaChance = (rand() % 100);
                if (thundagaChance >= 50)
                {
                    int thundagaDamage = (rand() % 251) + 320;
                    printf("\nDealt %d Damage using Thundaga!\n", thundagaDamage);
                    *enemyHP -= thundagaDamage;
                    enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
                }
                else
                {
                    printf("Thundaga missed!\n");
                    enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
                }
            }
            else
            {
                printf("Please choose a different number\n");
            }
        } while (magicMenuChoice < 1 || magicMenuChoice > 4);
}
void Items(int *playerHP, int *enemyHP, int *enemyFreeze, int *enemyBurn, int *potionCount, int *potionUsed, int *maxPlayerHP, int *healAmount, char enemyName[100])
{
    int itemMenuChoice;
    do
    {
        printf("[1] Potion (Heals %dHP) x %d\n",*healAmount,*potionCount);
        printf("[2] Back\n");
        scanf("%d", &itemMenuChoice);
        if (itemMenuChoice == 1)
        {
            if (*potionCount > 0 && *playerHP < *maxPlayerHP)
            {
                *playerHP += *healAmount;
                if (*playerHP > *maxPlayerHP)
                {
                    *playerHP = *maxPlayerHP;
                }
                printf("Healed %dHP!\n", *healAmount);
                *potionCount -= 1;
                *potionUsed += 1;
                enemyTurn(enemyHP, playerHP, enemyFreeze, enemyBurn, enemyName);
            }
            else if (*playerHP == *maxPlayerHP)
            {
                printf("Using a potion now would have no effect!\n");
            }
            else
            {
                printf("You're all out of potions!\n");
            }
        }
        else if (itemMenuChoice == 2)
        {
            
        }
        else
        {
            printf("Please choose a different number\n");
        }
    } while (itemMenuChoice < 1 || itemMenuChoice > 2);
}
void mainMenu(int *playerHP,int *enemyHP, int *potionCount,int *healAmount, char enemyName[100])
{
    int maxPlayerHP = *playerHP;
    int maxEnemyHP = *enemyHP;
    int maxPotionCount = *potionCount;
    int enemyFreeze = 0 , potionUsed = 0, enemyBurn = 0;
    do
    {
        int menuChoice;
        printf("Player HP: %d\t%s's HP: %d\n", *playerHP, enemyName, *enemyHP);
        printf("[1] Attack\n");
        printf("[2] Magic Spells\n");
        printf("[3] Items\n");
        scanf("%d", &menuChoice);
        if (menuChoice == 1)
        {
            printf("Mehmeh! Sorry not funished!\n");
        }
        else if (menuChoice == 2)
        {
            Magic(playerHP, enemyHP, &enemyFreeze, &enemyBurn, enemyName);
        }
        else if (menuChoice == 3)
        {
            Items(playerHP, enemyHP, &enemyFreeze, &enemyBurn, potionCount, &potionUsed, &maxPlayerHP, healAmount, enemyName);
        }
        else
        {
            printf("Please choose a different number.\n");
        }
    } while (*playerHP >= 0 && *enemyHP >= 0);
    if (*playerHP < 0)
    {
        printf("You lost to %s...\n", enemyName);
        *playerHP = 0;
    }
    if (*enemyHP < 0)
    {
        printf("You have defeated %s!\n\n", enemyName);
        int experience = (rand() % 2000) + 1000;
        printf("You gained %d experience\n", experience);
        *enemyHP = 0;
    }
    printf("Stats: Player HP: %d/%d\t%s's HP: %d/%d\n", *playerHP, maxPlayerHP, enemyName, *enemyHP, maxEnemyHP);
    printf("Potions Used: %d/%d", potionUsed, maxPotionCount);
}
void gameOptions(int *playerHP, int *enemyHP, int *potionCount, int *healAmount)
{
    int optionChoice = 0;
    do
    {
        printf("Options:\n");
        printf("[1] Max Player HP (Currently: %d) \n", *playerHP);
        printf("[2] Max Enemy HP (Currently: %d)\n", *enemyHP);
        printf("[3] Potion Count (Currently: %d)\n", *potionCount);
        printf("[4] Potion Heal Amount (Currently Heals: %dHP)\n", *healAmount);
        printf("[5] Back\n");
        scanf("%d", &optionChoice);
        if (optionChoice == 1)
        {
            printf("Enter new amount for Max player HP: ");
            scanf("%d", &*playerHP);
            printf("Player HP successfully changed!\n");
        }
        else if (optionChoice == 2)
        {
            printf("Enter new amount for Max Enemy HP: ");
            scanf("%d", &*enemyHP);
            printf("Enemy HP successfully changed!\n");
        }
        else if (optionChoice == 3)
        {
            printf("Enter new amount for Potion Count: ");
            scanf("%d", &*potionCount);
            printf("Potion Count successfully changed!\n");
        }
        else if (optionChoice == 4)
        {
            printf("Enter new amount for the Potion Heal Amount: ");
            scanf("%d", &*healAmount);
            printf("Potion Heal Amount successfully changed!\n");
        }
        else if (optionChoice == 5)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please choose a different number\n");
        }
    } while (optionChoice != 5);
}
int main(void)
{
    char enemyName[100];
    int titleChoi = 0, potionCount = 3, healAmount = 200, playerHP = 750, enemyHP = 1000;;
    srand(time(NULL));
    printf("----------------------------\n");
    printf("\tTERMINAL BATTLE\n");
    printf("----------------------------\n");
    do
    {
        printf("Select a choice! (Type the number corresponding to the option, then press enter)\n");
        printf("[1] Start Battle\n[2] Options\n[3] Exit\n");
        scanf("%d", &titleChoi);
        if (titleChoi == 1)
        {
            printf("What is the name of the enemy?\n");
            scanf("%s", enemyName);
            printf("Starting the battle!\n\n");
            mainMenu(&playerHP,&enemyHP,&potionCount,&healAmount,enemyName);
        }
        else if (titleChoi == 2)
        {
            gameOptions(&playerHP,&enemyHP,&potionCount,&healAmount);
        }
        else if (titleChoi == 3)
        {
            exit(1);
        }
        else
        {
            printf("Please choose a different number\n");
        }
    } while (titleChoi != 1);
    return 0;
}