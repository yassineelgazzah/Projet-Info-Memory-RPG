#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int type;   // 5 types for the cases: 0 for the limits, 1 players, 2 cards
              // hidden sides, 3 pieces of the labyrinth, 4 loot(treasures and
              // ancients weapons) and 5 empty cases
  int weapon; // 4 weapon for the players : 1 torch, 2  shield, 3  axe and 4 bow
  int class;  // 4 class for the players : 1 ranger, 2 warrior, 3 thief and 4
              // Wizard
  int lab;    // 6 pieces of the labyrinth : 1 basilisk, 2 troll, 3 portal, 4
              // zombie, 5 harpy, 6 totem
  int loot;   // 5 pieces of loot : 1 stick, 2 dagger, 3 sword, 4 grimoire, 5
              // treasure
  int item1;  // equals 1 if the player is carrying a treasure
  int item2;  // equals 1 if the player is carrying his ancient weapon
  char name[20]; // name of the player
  int kill;      // number of monster the player has defeated
  int card;      // number of card the player has revealed
  int treasure;  // number of treasure the player has found
} Game;

void print(Game **p) { // to print the game board
  printf(
      "\n----------------------------------------------------------------\n");
  printf("        ");
  for (int i = 0; i < 7; i++) {          // to go through the game board
    for (int j = 0; j < 7; j++) {        // to go through the game board
      if ((*(*(p + i) + j)).type == 1) { // to find a player
        printf(" %s ",
               (*(*(p + i) + j)).name); // to print the name of the player
      }
    }
  }
  printf("\n----------------------------------------------------------------");
  printf("\n\n");
  for (int i = 0; i < 7; i++) { // to go through the game board to print the
                                // right character to the case
    printf("          ");
    for (int j = 0; j < 7; j++) { // to go through the game board to print the
                                  // right character to the case
      if ((*(*(p + i) + j)).type == 2) { // for a unrevealed case
        printf(" o ");
      } else {
        if ((*(*(p + i) + j)).type == 1) {    // for a player case
          if ((*(*(p + i) + j)).class == 1) { // for the ranger case
            printf(" R ");
          }
          if ((*(*(p + i) + j)).class == 2) { // for the warrior case
            printf(" G ");
          }
          if ((*(*(p + i) + j)).class == 3) { // for the thief case
            printf(" V ");
          }
          if ((*(*(p + i) + j)).class == 4) { // for the wizard case
            printf(" M ");
          }
        } else {
          if ((*(*(p + i) + j)).type == 0) { // for a limit case
            printf("   ");
          } else {
            if ((*(*(p + i) + j)).type == 3) {  // for a labyrinth case
              if ((*(*(p + i) + j)).lab == 1) { // for the basilisk case
                printf(" B ");
              } else {
                if ((*(*(p + i) + j)).lab == 2) { // for the troll case
                  printf(" T ");
                } else {
                  if ((*(*(p + i) + j)).lab == 3) { // for the portal case
                    printf(" P ");
                  } else {
                    if ((*(*(p + i) + j)).lab == 4) { // for the zombie case
                      printf(" Z ");
                    } else {
                      if ((*(*(p + i) + j)).lab == 5) { // for the harpy case
                        printf(" H ");
                      } else {
                        if ((*(*(p + i) + j)).lab == 6) { // for the totem case
                          printf(" O ");
                        }
                      }
                    }
                  }
                }
              }
            } else {
              if ((*(*(p + i) + j)).type == 4) {   // for a loot case
                if ((*(*(p + i) + j)).loot == 1) { // for the stick case
                  printf(" 1 ");
                } else {
                  if ((*(*(p + i) + j)).loot == 2) { // for the dagger case
                    printf(" 2 ");
                  } else {
                    if ((*(*(p + i) + j)).loot == 3) { // for the sword case
                      printf(" 3 ");
                    } else {
                      if ((*(*(p + i) + j)).loot ==
                          4) { // for the grimoire case
                        printf(" 4 ");
                      } else {
                        if ((*(*(p + i) + j)).loot ==
                            5) { // for the treasure case
                          printf(" 5 ");
                        }
                      }
                    }
                  }
                }
              } else {
                if ((*(*(p + i) + j)).type == 5) { // for an empty case
                  printf("   ");
                }
              }
            }
          }
        }
      }
    }
    printf("\n");
  }
}

void Rule() { // to print the rules of the game
  printf("\n");
  printf("----------------------------------------------------------------\n");
  printf("----------------------------------------------------------------\n");
  printf("The goal of the game is to find its ancient weapon and a braid by "
         "facing the dangers of the Labyrinth\n");
  printf("----------------------------------------------------------------\n");
  printf("-Loot\n");
  printf("|[1] Stick        [2] Dagger     |\n");
  printf("|[3] Sword        [4] Grimoire   |\n");
  printf("|[5] Treasure                    |\n");
  printf("----------------------------------------------------------------\n");
  printf("-The Ranger seeks the Pet Control Stick\n");
  printf("-The Warrior seeks the Fire Sword\n");
  printf("-The Wizard seeks the Forbidden Grimoire\n");
  printf("-The Thief seeks the Sleep Dagger\n");
  printf("----------------------------------------------------------------\n");
  printf("-Player\n");
  printf("|[R] Ranger      [G] Warrior|\n");
  printf("|[M] Wizard      [V] Thief  |\n");
  printf("----------------------------------------------------------------\n");
  printf("-Monster\n");
  printf("|[Z] Zombie      [H] Harpy   |\n");
  printf("|[T] Troll       [B] Basilisk|\n");
  printf("----------------------------------------------------------------\n");
  printf("-To defeat the Zombie use the Torch\n");
  printf("-To defeat the Troll use the Axe\n");
  printf("-To defeat the Harpy use the Bow\n");
  printf("-To defeat the Basilisk use the Schield\n");
  printf("----------------------------------------------------------------\n");
  printf("-Labyrinth\n");
  printf("|[P] Portal      [O] Totem|\n");
  printf("----------------------------------------------------------------\n");
  printf("-The Portal allows you to teleport sur la carte\n");
  printf("-The Totem allows you to swap two cases\n");
  printf("----------------------------------------------------------------\n");
  printf("----------------------------------------------------------------\n");
  printf("\n");
}

int Menu(Game **p) { // to print and access to the menu of the game
  int a;             // to select number of player
  a = 0;             // to select number of player
  printf("Welcome to Cy-Memo-RPG:\n");
  printf("Select the number of players between 2 and 4:\n");
  scanf("%d", &a); // to select number of player
  empty_buffer();  // if you answer with characters
  while (a > 4 ||
         a < 2) { // if you don t select number of player beetween 4 and 2
    printf("Impossible\n");
    printf("Select the number of players between 2 and 4:\n");
    scanf("%d", &a); // to select number of player
    empty_buffer();  // if you answer with characters
  }
  if (a == 2) { // if you select 2 players
    printf("Player 1 you are the Ranger:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*p + 4)).name); // to assign the name of the player
    printf("Player 2 you are the Warrior:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 2))).name); // to assign the name of the player
  }
  if (a == 3) { // if you select 3 players
    printf("Player 1 you are the Ranger:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*p + 4)).name); // to assign the name of the player
    printf("Player 2 you are the Warrior:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 2))).name); // to assign the name of the player
    printf("Player 3 you are the Thief:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 6) + 2)).name); // to assign the name of the player
  }
  if (a == 4) { // if you select 4 players
    printf("Player 1 you are the Ranger:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*p + 4)).name); // to assign the name of the player
    printf("Player 2 you are the Warrior:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 2))).name); // to assign the name of the player
    printf("Player 3 you are the Thief:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 6) + 2)).name); // to assign the name of the player
    printf("Player 4 you are the Wizard:\n");
    printf("Give your name:\n");
    scanf("%s", (*(*(p + 4) + 6)).name); // to assign the name of the player
  }
  return a; // return the number of players
}
void FillName(Game **p, Game **pa, int a,
              int b) { // to copy the name of a player
  for (int i = 0; i < 20; i++) {
    (*(*(p + a) + b)).name[i] =
        (*(*(pa + a) + b))
            .name[i]; //  to assign the name of the player to the new game board
  }
}

void SamePlayer(Game **p, int a,
                Game **pa) { // if you select new game with same players
  if (a == 2) {              // if there is 2 players
    FillName(p, pa, 0,
             4); //  to assign the name of the player to the new game board
    FillName(p, pa, 2,
             0); //  to assign the name of the player to the new game board
  }
  if (a == 3) { // if there is 3 players
    FillName(p, pa, 0,
             4); //  to assign the name of the player to the new game board
    FillName(p, pa, 2,
             0); //  to assign the name of the player to the new game board
    FillName(p, pa, 6,
             2); //  to assign the name of the player to the new game board
  }
  if (a == 4) { // if there is 4 players
    FillName(p, pa, 0,
             4); //  to assign the name of the player to the new game board
    FillName(p, pa, 2,
             0); //  to assign the name of the player to the new game board
    FillName(p, pa, 6,
             2); //  to assign the name of the player to the new game board
    FillName(p, pa, 4,
             6); //  to assign the name of the player to the new game board
  }
}