#ifndef Options
#define Options
#include <stdlib.h>
#include "endless.h"
void generalOptions(int *modified, int *optionChoice)
{
    int generalOptionChoice = 0;
    *optionChoice = 0;
    do
    {
        printf("General Options:\n");
        printf("[1] Player Name\t\t\t (Currently: '%s')\n", Pl.name);
        printf("[2] Player Max HP\t\t (Currently: %dHP)\n",Pl.HP);
        printf("[3] Player Max MP\t\t (Currently: %dMP)\n",Pl.MP);
        printf("[4] Max Enemy HP\t\t (Currently: %dHP)\n", En.HP);
        printf("[5] Back\n");
        scanf("%d", &generalOptionChoice);
        if (generalOptionChoice == 1)
        {
            generalOptionChoice = 0;
            *modified = 1;
            getchar();
            printf("Enter your new name: ");
            fgets(Pl.name,sizeof(Pl.name), stdin);
            Pl.name[strlen(Pl.name) - 1] = '\0';
            printf("Your name has succesfully been changed to %s\n", Pl.name);
        }
        else if (generalOptionChoice == 2)
        {
            generalOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for Max Player HP: ");
            scanf("%d", &Pl.HP);
            printf("Max Player HP successfully changed!\n");
            Pl.maxHP = Pl.HP;
        }
        else if (generalOptionChoice == 3)
        {
            generalOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for Max Player MP: ");
            scanf("%d", &Pl.MP);
            printf("Max Player MP successfully changed!\n");
            Pl.maxMP = Pl.MP;
        }
        else if (generalOptionChoice == 4)
        {
            generalOptionChoice = 0;
            *modified = 1;
            printf("Enter new amount for Max Enemy HP: ");
            scanf("%d", &En.HP);
            printf("Max Enemy HP successfully changed!\n");
        }
        else if (generalOptionChoice == 5)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (generalOptionChoice < 1 || generalOptionChoice > 5);
}
void specialOptions(int *modified, int *attackOptionChoice)
{
    int specialAttackChoice = 0;
    *attackOptionChoice = 0;
    do
    {
        printf("Special Attack Options:\n");
        printf("[1] Lucky Strike MP Cost\t\t(Currenty: %dMP)\n", At.luckyMP);
        printf("[2] Lucky Strike Block Rate\t\t(Currently: %d%%) \n", At.luckyBlock);
        printf("[3] Sonic Blade MP Cost\t\t\t(Currently: %dMP)\n", At.sonicMP);
        printf("[4] Ars Arcanum MP Cost\t\t\t(Currently: %dMP)\n", At.arsMP);
        printf("[5] Ars Arcanum Block Rate\t\t(Currently: %d%%)\n", At.arsBlock);
        printf("[6] Zantesuken MP Cost\t\t\t(Currently: %dMP)\n", At.zanteMP);
        printf("[7] Zantesuken Success Rate\t\t(Currently: %d%%)\n", At.zanteSuc);
        printf("[8] Zantesuken Block Rate\t\t(Currently: %d%%)\n", At.zanteBlock);
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
            printf("Enter new Sonic Blade MP Cost: ");
            scanf("%d", &At.sonicMP);
            printf("Sonic Blade MP Cost successfully changed!\n");
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
            printf("Enter new Zantesuken MP Cost: ");
            scanf("%d", &At.zanteMP);
            printf("Zantesuken MP Cost successfully changed!\n");
        }
        else if (specialAttackChoice == 7)
        {
            do
            {
                specialAttackChoice = 0;
                *modified = 1;
                printf("Enter new Zantesuken Success Rate: ");
                scanf("%d", &At.zanteSuc);
                if (At.zanteSuc < 0 || At.zanteSuc > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Zantesuken Sucess Rate successfully changed!\n");    
                }
            }  while (At.zanteSuc < 0 || At.zanteSuc > 100);
        }
        else if (specialAttackChoice == 8)
        {
            do
            {
                specialAttackChoice = 0;
                *modified = 1;
                printf("Enter new Zantesuken Block Rate: ");
                scanf("%d", &At.zanteBlock);
                if (At.zanteBlock < 0 || At.zanteBlock > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Zantesuken Block Rate successfully changed!\n");    
                }
            }  while (At.zanteBlock < 0 || At.zanteBlock > 100);
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
void attackOptions(int *modified, int *optionChoice)
{
    int attackOptionChoice = 0;
    *optionChoice = 0;
    do
    {
        printf("Attack Options:\n");
        printf("[1] Light Attack Block Rate (Curently: %d%%)\n", At.lightBlock);
        printf("[2] Heavy Attack Block Rate (Currently: %d%%)\n", At.heavyBlock);
        printf("[3] Special Attack Options\n");
        printf("[4] Back\n");
        scanf("%d", &attackOptionChoice);
        if (attackOptionChoice == 1)
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
        else if (attackOptionChoice == 2)
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
        else if (attackOptionChoice == 3)
        {
            printf("\n\n\n");
            specialOptions(modified, &attackOptionChoice);
        }
        else if (attackOptionChoice == 4)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (attackOptionChoice < 1 || attackOptionChoice > 4);   
}
void magicOptionsTwo(int *modified)
{
    int magicOptionChoiceTwo = 0;
    do
    {
        printf("[1] Thundaga MP Cost\t\t\t(Currently: %dMP)\n", Ma.thundagaMP);
        printf("[2] Thundaga Shock Chance\t\t(Currently: %d%%)\n", Ma.shockChance);
        printf("[3] Thundaga Miss Chance\t\t(Currently: %d%%)\n", Ma.thundagaMiss);
        printf("[4] Aeroga MP Cost\t\t\t(Currently: %dMP)\n", Ma.aerogaMP);
        printf("[5] Aeroga Confuse Chance\t\t(Currently: %d%%)\n", Ma.confuseChance);
        printf("[6] Aeroga Miss Chance\t\t\t(Currently: %d%%)\n", Ma.aerogaMiss);
        printf("[7] Back\n");
        scanf("%d", &magicOptionChoiceTwo);
        if (magicOptionChoiceTwo == 1)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Thundaga MP cost: ");
            scanf("%d", &Ma.thundagaMP);
            printf("Thundaga MP cost successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 2)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Thundaga Shock Chance: ");
            scanf("%d", &Ma.shockChance);
            printf("Thundaga Shock Chance successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 3)
        {
            do
            {
                magicOptionChoiceTwo = 0;
                *modified = 1;
                printf("Enter new Thundaga Miss Chance: ");
                scanf("%d", &Ma.thundagaMiss);
                if (Ma.thundagaMiss < 0 || Ma.thundagaMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Firaga Miss Chance successfully changed!\n");    
                }
            }  while (Ma.thundagaMiss < 0 || Ma.thundagaMiss > 100);
        }
        else if (magicOptionChoiceTwo == 4)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Aeroga MP cost: ");
            scanf("%d", &Ma.aerogaMP);
            printf("Aeroga MP cost successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 5)
        {
            magicOptionChoiceTwo = 0;
            *modified = 1;
            printf("Enter new Aeroga Confuse Chance: ");
            scanf("%d", &Ma.confuseChance);
            printf("Aeroga Confuse Chance successfully changed!\n");
        }
        else if (magicOptionChoiceTwo == 6)
        {
            do
            {
                magicOptionChoiceTwo = 0;
                *modified = 1;
                printf("Enter new Aeroga Miss Chance: ");
                scanf("%d", &Ma.aerogaMiss);
                if (Ma.aerogaMiss < 0 || Ma.aerogaMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Aeroga Miss Chance successfully changed!\n");    
                }
            }  while (Ma.aerogaMiss < 0 || Ma.aerogaMiss > 100);
        }
        else if (magicOptionChoiceTwo == 7)
        {
            printf("\n\n\n");
            continue;
        }
    } while (magicOptionChoiceTwo < 1 || magicOptionChoiceTwo > 7);
}
void magicOptions(int *modified, int *optionChoice)
{
    int magicOptionChoice = 0;
    *optionChoice = 0;
    do
    {
        printf("Magic Options:\n");
        printf("[1] Firaga MP Cost\t\t\t(Currently: %dMP)\n", Ma.firagaMP);
        printf("[2] Firaga Burn Chance\t\t\t(Currently: %d%%)\n", Ma.burnChance);
        printf("[3] Firaga Miss Chance\t\t\t(Currently: %d%%)\n", Ma.firagaMiss);
        printf("[4] Blizzaga MP Cost\t\t\t(Currently: %dMP)\n", Ma.blizzagaMP);
        printf("[5] Blizzaga Freeze Chance\t\t(Currently: %d%%)\n",Ma.freezeChance);
        printf("[6] Blizzaga Miss Chance\t\t(Currently: %d%%)\n", Ma.blizzagaMiss);
        printf("[7] Next Page\n");
        printf("[8] Back\n");
        scanf("%d", &magicOptionChoice);
        if (magicOptionChoice == 1)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Firaga MP cost: ");
            scanf("%d", &Ma.firagaMP);
            printf("Firaga MP cost successfully changed!\n");
        }
        else if (magicOptionChoice == 2)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Firaga Burn Chance: ");
            scanf("%d", &Ma.burnChance);
            printf("Firaga Burn Chance successfully changed!\n");
        }
        else if (magicOptionChoice == 3)
        {
            do
            {
                magicOptionChoice = 0;
                *modified = 1;
                printf("Enter new Firaga Miss Chance: ");
                scanf("%d", &Ma.firagaMiss);
                if (Ma.firagaMiss < 0 || Ma.firagaMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Firaga Miss Chance successfully changed!\n");    
                }
            }  while (Ma.firagaMiss < 0 || Ma.firagaMiss > 100);
        }
        else if (magicOptionChoice == 4)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Blizzaga MP cost: ");
            scanf("%d", &Ma.blizzagaMP);
            printf("Blizzaga MP cost successfully changed!\n");
        }
        else if (magicOptionChoice == 5)
        {
            magicOptionChoice = 0;
            *modified = 1;
            printf("Enter new Blizzaga Freeze Chance: ");
            scanf("%d", &Ma.freezeChance);
            printf("Blizzaga Freeze Chance successfully changed!\n");
        }
        else if (magicOptionChoice == 6)
        {
            {
                magicOptionChoice = 0;
                *modified = 1;
                printf("Enter new Blizzaga Miss Chance: ");
                scanf("%d", &Ma.blizzagaMiss);
                if (Ma.blizzagaMiss < 0 || Ma.blizzagaMiss > 100)
                {
                    printf("Please choose a value between 0 and 100\n");
                }
                else
                {
                    printf("Blizzaga Miss Chance successfully changed!\n");    
                }
            }  while (Ma.blizzagaMiss < 0 || Ma.blizzagaMiss > 100);
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
void itemOptions(int *modified, int *optionChoice)
{
    int itemOptionChoice = 0;
    *optionChoice = 0;
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
        printf("[1] General Options\n");
        printf("[2] Attack Options\n");
        printf("[3] Magic Options\n");
        printf("[4] Item Options\n");
        printf("[5] Back\n");
        scanf("%d", &optionChoice);
        if (optionChoice == 1)
        {
            printf("\n\n\n");
            generalOptions(modified, &optionChoice);
        }
        else if (optionChoice == 2)
        {
            printf("\n\n\n");
            attackOptions(modified, &optionChoice);   
        }
        else if (optionChoice == 3)
        {
            printf("\n\n\n");
            magicOptions(modified, &optionChoice);
        }
        else if (optionChoice == 4)
        {
            printf("\n\n\n");
            itemOptions(modified, &optionChoice);
        }
        else if (optionChoice == 5)
        {
            printf("\n\n\n");
            continue;
        }
        else
        {
            printf("Please enter a different number.\n");
        }
    } while (optionChoice < 1 || optionChoice > 5);
}
#endif