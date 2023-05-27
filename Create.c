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

Game **fill(Game **p,
            Game **pa) { // to fill an array with an other(copy game board)
  pa = malloc(7 * sizeof(Game));
  *pa = malloc(sizeof(Game));
  for (int i = 0; i < 7; i++) { // to fill every line
    *(pa + i) = malloc(7 * sizeof(Game));
    for (int j = 0; j < 7; j++) { // to fill every case of the line
      (*(*(pa + i) + j)) = (*(*(p + i) + j));
    }
  }
  return pa; // return the filled array (other game board)
}

void createM(Game **p,
             Game **pa) { // to create the hidden game board with all cases
                          // visible by using the first gameboard
  srand(time(NULL));      // to reset the rand
  printf("\n");
  int k = 0;
  int a;                          // to choose a line of the gameboard
  int b;                          // to choose a column of the gameboard
  for (int i = 0; i < 7; i++) {   // to go through the game board
    for (int j = 0; j < 7; j++) { // to go through the game board
      if ((*(*(p + i) + j)).type ==
          2) { // to find case that are not limit or player on the game board
        (*(*(pa + i) + j)).type = 2;
      } else {
        (*(*(pa + i) + j)).type =
            (*(*(p + i) + j)).type; // if the case is a player or a limit
      }
    }
  }
  while (k != 19) {                     // to affect 19 pieces of the labyinth
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 2) { // if the case isn t already affected
      (*(*(pa + a) + b)).type = 3;      // affect the pieces to type labyrinth
      (*(*(pa + a) + b)).lab = 0;       // to set
      k = k + 1;                        // to affect 19 pieces of the labyinth
    }
  }
  k = 0;                                // to reset
  while (k != 4) {                      // to affect 4 basilisk
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 1;      // to set a basilisk
        k = k + 1;                       // to affect 4 basilisk
      }
    }
  }
  k = 0;                                // to reset
  while (k != 4) {                      // to affect 4 troll
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 2;      // to set a troll
        k = k + 1;                       // to affect 4 troll
      }
    }
  }
  k = 0;                                // to reset
  while (k != 4) {                      // to affect 4 zombie
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 4;      // to set a zombie
        k = k + 1;                       // to affect 4 zombie
      }
    }
  }
  k = 0;                                // to reset
  while (k != 4) {                      // to affect 4 harpy
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 5;      // to set a harpy
        k = k + 1;                       // to affect 4 harpy
      }
    }
  }
  k = 0;                                // to reset
  while (k != 2) {                      // to affect 2 totem
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 6;      // to set a totem
        k = k + 1;                       // to affect 2 totem
      }
    }
  }
  k = 0;                                // to reset
  while (k != 1) {                      // to affect 1 portal
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 3) { // if the case is a labyrinth case
      if ((*(*(pa + a) + b)).lab == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).lab = 3;      // to set a portal
        k = k + 1;                       // to affect 1 portal
      }
    }
  }
  k = 0;                                // to reset
  while (k != 6) {                      // to affect 6 pieces of loot
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 2) { // if the case isn t already affected
      (*(*(pa + a) + b)).type = 4;      // affect the pieces to type loot
      (*(*(pa + a) + b)).loot = 0;      // to set
      k = k + 1;                        // to affect 6 pieces of loot
    }
  }
  k = 0;                                // to reset
  while (k != 2) {                      // to affect 2 treasure
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 4) { // if the case is a loot case
      if ((*(*(pa + a) + b)).loot == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).loot = 5;      // to set a treasure
        k = k + 1;                        // to affect 2 treasure
      }
    }
  }
  k = 0;                                // to reset
  while (k != 4) {                      // to affect 4 ancient weapons
    a = 1 + rand() % 5;                 // to choose a line of a case randomly
    b = 1 + rand() % 5;                 // to choose a column of a case randomly
    if ((*(*(pa + a) + b)).type == 4) { // if the case is a loot case
      if ((*(*(pa + a) + b)).loot == 0) { // if the case isn t already affected
        (*(*(pa + a) + b)).loot = k + 1;  // to set every ancient weapons
        k = k + 1;                        // to affect 4 ancient weapons
      }
    }
  }

  for (int i = 0; i < 7; i++) {           // to go through the game board
    for (int j = 0; j < 7; j++) {         // to go through the game board
      if ((*(*(pa + i) + j)).type == 2) { // if there is unaffected cases
        (*(*(pa + i) + j)).type = 5;      // to empty cases
      }
    }
  }
}

void createJ(Game **p) {          // to set all of the players statistics
  (*(*p + 4)).class = 1;          // to set the class to ranger
  (*(*(p + 2))).class = 2;        // to set the class to warrior
  (*(*(p + 6) + 2)).class = 3;    // to set the class to thief
  (*(*(p + 4) + 6)).class = 4;    // to set the class to wizard
  (*(*p + 4)).kill = 0;           // to set the kill count to 0
  (*(*(p + 2))).kill = 0;         // to set the kill count to 0
  (*(*(p + 6) + 2)).kill = 0;     // to set the kill count to 0
  (*(*(p + 4) + 6)).kill = 0;     // to set the kill count to 0
  (*(*p + 4)).treasure = 0;       // to set the treasure count to 0
  (*(*(p + 2))).treasure = 0;     // to set the treasure count to 0
  (*(*(p + 6) + 2)).treasure = 0; // to set the treasure count to 0
  (*(*(p + 4) + 6)).treasure = 0; // to set the treasure count to 0
  (*(*p + 4)).card = 0;           // to set the cards revealed count to 0
  (*(*(p + 2))).card = 0;         // to set the cards revealed count to 0
  (*(*(p + 6) + 2)).card = 0;     // to set the cards revealed count to 0
  (*(*(p + 4) + 6)).card = 0;     // to set the cards revealed count to 0
  (*(*p + 4)).item1 = 0;       // to set the carry of your ancient weapon to 0
  (*(*(p + 2))).item1 = 0;     // to set the carry of your ancient weapon to 0
  (*(*(p + 6) + 2)).item1 = 0; // to set the carry of your ancient weapon to 0
  (*(*(p + 4) + 6)).item1 = 0; // to set the carry of your ancient weapon to 0
  (*(*p + 4)).item2 = 0;       // to set the carry of treasure to 0
  (*(*(p + 2))).item2 = 0;     // to set the carry of treasure to 0
  (*(*(p + 6) + 2)).item2 = 0; // to set the carry of treasure to 0
  (*(*(p + 4) + 6)).item2 = 0; // to set the carry of treasure to 0
}

Game **create(Game **p) { // to create the game board
  p = malloc(7 * sizeof(Game));
  *p = malloc(sizeof(Game));
  for (int i = 0; i < 7; i++) {
    *(p + i) = malloc(7 * sizeof(Game));
    for (int j = 0; j < 7; j++) {
      (*(*(p + i) + j)).type = 2;
    }
  }
  (*(*p + 4)).type = 1;          // to set the player
  (*(*(p + 2))).type = 1;        // to set the player
  (*(*(p + 6) + 2)).type = 1;    // to set the player
  (*(*(p + 4) + 6)).type = 1;    // to set the player
  for (int i = 0; i < 7; i++) {  // to go through the line of the game board
    if ((*(*p + i)).type == 2) { // if the case is not a player
      (*(*p + i)).type = 0;      // to set the limits
    }
  }
  for (int i = 0; i < 7; i++) {    // to go through the line of the game board
    if ((*(*(p + i))).type == 2) { // if the case is not a player
      (*(*(p + i))).type = 0;      // to set the limits
    }
  }
  for (int i = 0; i < 7; i++) { // to go through the line of the game board
    if ((*(*(p + 6) + i)).type == 2) { // if the case is not a player
      (*(*(p + 6) + i)).type = 0;      // to set the limits
    }
  }
  for (int i = 0; i < 7; i++) { // to go through the line of the game board
    if ((*(*(p + i) + 6)).type == 2) { // if the case is not a player
      (*(*(p + i) + 6)).type = 0;      // to set the limits
    }
  }
  return p; // return the new game board
}