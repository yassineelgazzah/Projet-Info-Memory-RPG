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

int Move(Game **pa, Game **pb, int c, int a, int b,
         Game **pd) {           // to move anywhere
  int e = 0;                    // equals 1 when you die
  int d = 0;                    // equals 1 when the player has been found
  for (int i = 0; i < 7; i++) { // to go through the game board
    if (d == 1) {               // to stop when the player had already play
      break;
    }
    for (int j = 0; j < 7; j++) { // to go through the game board
      if (d == 1) {               // to stop when the player had already play
        break;
      }
      if ((*(*(pb + i) + j)).type == 1) { // to find a player
        if ((*(*(pb + i) + j)).class ==
            c) { // to find the character of the player that found a portal
          d = 1; // when the player has been found
          ChooseW(pb, c);                     // to choose a weapon
          if ((*(*(pa + a) + b)).type == 5) { // if you move on a empty case
            (*(*(pb + i) + j)).card =
                (*(*(pb + i) + j)).card + 1; // add +1 to the number of case you
                                             // revealed on the game board
            (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                      1; // add +1 to the number of case you
                                         // revealed on the hidden game board
            (*(*(pb + a) + b)) =
                (*(*(pb + i) + j)); // to move on the case on the game board
            (*(*(pa + a) + b)) = (*(
                *(pb + i) + j)); // to move on the case on the hidden game board
            (*(*(pb + i) + j)).type =
                5; // to set the case where we were empty on the game board
            (*(*(pa + i) + j)).type = 5; // to set the case where we were empty
                                         // on the hidden game board
          }
          if ((*(*(pa + a) + b)).type ==
              0) { // if you try to move on a limit case
            printf("Impossible");
          }
          if ((*(*(pa + a) + b)).type ==
              1) { // if you try to move on a player case
            printf("Impossible");
          }
          if ((*(*(pa + a) + b)).type == 3) { // if you move on a labyrinth case
            if ((*(*(pa + a) + b)).lab == 1) { // if you move on a basilisk case
              if ((*(*(pb + i) + j)).weapon ==
                  2) { // if you got the right weapon
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                printf("A Basilisk has been defeated\n");
                (*(*(pb + i) + j)).kill = (*(*(pb + i) + j)).kill +
                                          1; // add +1 to the number of monsters
                                             // you defeated on the game board
                (*(*(pa + i) + j)).kill =
                    (*(*(pa + i) + j)).kill +
                    1; // add +1 to the number of monsters you defeated on the
                       // hidden game board
                (*(*(pb + a) + b)) =
                    (*(*(pb + i) + j)); // to move on the case on the game board
                (*(*(pa + a) + b)) =
                    (*(*(pb + i) +
                       j)); // to move on the case on the hidden game board
                (*(*(pb + i) + j)).type =
                    5; // to set the case where we were empty on the game board
                (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                             // empty on the hidden game board

              } else { // if you don't got the right weapon
                printf("A Basilisk defeated you\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                e = 1; // when you die
              }
            }
            if ((*(*(pa + a) + b)).lab == 2) { // if you move on a troll case
              if ((*(*(pb + i) + j)).weapon ==
                  3) { // if you got the right weapon
                printf("A Troll has been defeated\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                (*(*(pb + i) + j)).kill = (*(*(pb + i) + j)).kill +
                                          1; // add +1 to the number of monsters
                                             // you defeated on the game board
                (*(*(pa + i) + j)).kill =
                    (*(*(pa + i) + j)).kill +
                    1; // add +1 to the number of monsters you defeated on the
                       // hidden game board
                (*(*(pb + a) + b)) =
                    (*(*(pb + i) + j)); // to move on the case on the game board
                (*(*(pa + a) + b)) =
                    (*(*(pb + i) +
                       j)); // to move on the case on the hidden game board
                (*(*(pb + i) + j)).type =
                    5; // to set the case where we were empty on the game board
                (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                             // empty on the hidden game board

              } else { // if you don't got the right weapon
                printf("A Troll defeated you\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                e = 1; // when you die
              }
            }
            if ((*(*(pa + a) + b)).lab == 4) { // if you move on a zombie case
              if ((*(*(pb + i) + j)).weapon ==
                  1) { // if you got the right weapon
                printf("A Zombie has been defeated\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                (*(*(pb + i) + j)).kill = (*(*(pb + i) + j)).kill +
                                          1; // add +1 to the number of monsters
                                             // you defeated on the game board
                (*(*(pa + i) + j)).kill =
                    (*(*(pa + i) + j)).kill +
                    1; // add +1 to the number of monsters you defeated on the
                       // hidden game board
                (*(*(pb + a) + b)) =
                    (*(*(pb + i) + j)); // to move on the case on the game board
                (*(*(pa + a) + b)) =
                    (*(*(pb + i) +
                       j)); // to move on the case on the hidden game board
                (*(*(pb + i) + j)).type =
                    5; // to set the case where we were empty on the game board
                (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                             // empty on the hidden game board

              } else { // if you don't got the right weapon
                printf("A Zombie defeated you\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                e = 1; // when you die
              }
            }
            if ((*(*(pa + a) + b)).lab == 5) { // if you move on a harpy case
              if ((*(*(pb + i) + j)).weapon ==
                  4) { // if you got the right weapon
                printf("A Harpy has been defeated\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                (*(*(pb + i) + j)).kill = (*(*(pb + i) + j)).kill +
                                          1; // add +1 to the number of monsters
                                             // you defeated on the game board
                (*(*(pa + i) + j)).kill =
                    (*(*(pa + i) + j)).kill +
                    1; // add +1 to the number of monsters you defeated on the
                       // hidden game board
                (*(*(pb + a) + b)) =
                    (*(*(pb + i) + j)); // to move on the case on the game board
                (*(*(pa + a) + b)) =
                    (*(*(pb + i) +
                       j)); // to move on the case on the hidden game board
                (*(*(pb + i) + j)).type =
                    5; // to set the case where we were empty on the game board
                (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                             // empty on the hidden game board
              } else { // if you don't got the right weapon
                printf("A Harpy defeated you\n");
                (*(*(pb + i) + j)).card = (*(*(pb + i) + j)).card +
                                          1; // add +1 to the number of case you
                                             // revealed on the game board
                (*(*(pa + i) + j)).card =
                    (*(*(pa + i) + j)).card +
                    1; // add +1 to the number of case you revealed on the
                       // hidden game board
                e = 1; // when you die
              }
            }
            if ((*(*(pa + a) + b)).lab == 3) { // if you move on a portal case
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              e = Teleport(pa, pb, c, pd); // to teleport
              (*(*(pb + a) + b)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + a) + b)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
            if ((*(*(pa + a) + b)).lab == 6) { // if you move on a totem case
              e = Totem(pa, pb, c, pd, a, b);  // to use a totem
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
            }
          }
          if ((*(*(pa + a) + b)).type ==
              4) { // if you move on an ancient weapon case
            if ((*(*(pa + a) + b)).loot == 1) { // if you move on the stick case
              printf("You found the Pet Control Stick\n");
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              if ((*(*(pb + i) + j)).class ==
                  1) { // if you are the player that seek this weapon
                (*(*(pb + i) + j)).item1 = 1;
              }
              (*(*(pb + a) + b)) =
                  (*(*(pb + i) + j)); // to move on the case on the game board
              (*(*(pa + a) + b)) =
                  (*(*(pb + i) +
                     j)); // to move on the case on the hidden game board
              (*(*(pb + i) + j)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
            if ((*(*(pa + a) + b)).loot ==
                2) { // if you move on the dagger case
              printf("You found the Sleep Dagger\n");
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              if ((*(*(pb + i) + j)).class ==
                  3) { // if you are the player that seek this weapon
                (*(*(pb + i) + j)).item1 = 1;
              }
              (*(*(pb + a) + b)) =
                  (*(*(pb + i) + j)); // to move on the case on the game board
              (*(*(pa + a) + b)) =
                  (*(*(pb + i) +
                     j)); // to move on the case on the hidden game board
              (*(*(pb + i) + j)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
            if ((*(*(pa + a) + b)).loot == 3) { // if you move on the sword case
              printf("You found the Fire Sword\n");
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              if ((*(*(pb + i) + j)).class ==
                  2) { // if you are the player that seek this weapon
                (*(*(pb + i) + j)).item1 = 1;
              }
              (*(*(pb + a) + b)) =
                  (*(*(pb + i) + j)); // to move on the case on the game board
              (*(*(pa + a) + b)) =
                  (*(*(pb + i) +
                     j)); // to move on the case on the hidden game board
              (*(*(pb + i) + j)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
            if ((*(*(pa + a) + b)).loot ==
                4) { // if you move on the grimoire case
              printf("You found the Forbidden Grimoire\n");
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              if ((*(*(pb + i) + j)).class ==
                  4) { // if you are the player that seek this weapon
                (*(*(pb + i) + j)).item1 = 1;
              }
              (*(*(pb + a) + b)) =
                  (*(*(pb + i) + j)); // to move on the case on the game board
              (*(*(pa + a) + b)) =
                  (*(*(pb + i) +
                     j)); // to move on the case on the hidden game board
              (*(*(pb + i) + j)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
            if ((*(*(pa + a) + b)).loot ==
                5) { // if you move on a treasure case
              printf("You found a Treasure\n");
              (*(*(pb + i) + j)).treasure =
                  (*(*(pb + i) + j)).treasure +
                  1; // add +1 to the treasure you found on the game board
              (*(*(pa + i) + j)).treasure = (*(*(pa + i) + j)).treasure +
                                            1; // add +1 to the treasure you
                                               // found on the hidden game board
              (*(*(pb + i) + j)).card =
                  (*(*(pb + i) + j)).card + 1; // add +1 to the number of case
                                               // you revealed on the game board
              (*(*(pa + i) + j)).card = (*(*(pa + i) + j)).card +
                                        1; // add +1 to the number of case you
                                           // revealed on the hidden game board
              (*(*(pb + i) + j)).item2 = 1;
              (*(*(pb + a) + b)) =
                  (*(*(pb + i) + j)); // to move on the case on the game board
              (*(*(pa + a) + b)) =
                  (*(*(pb + i) +
                     j)); // to move on the case on the hidden game board
              (*(*(pb + i) + j)).type =
                  5; // to set the case where we were empty on the game board
              (*(*(pa + i) + j)).type = 5; // to set the case where we were
                                           // empty on the hidden game board
            }
          }
        }
      }
    }
  }
  return e; // return if the player died or not, equals 1 if he died, 0 if not
}

int MoveD(Game **pa, Game **pb, Game **pd,
          int c) { // to choose the direction you want to move
  int d, e, f;
  e = 0; // equals 1 if you are dead
  f = 0; // equals 1 when the player has been found
  printf("Now choose your direction:\n           Up\n           [1]\nLeft [4]  "
         "        Right [2]\n           [3]\n           Down\n");
  scanf("%d", &d);         // to select your direction
  empty_buffer();          // if you select characters
  while (d > 4 || d < 1) { // if you don t select a number between 1 and 4
    printf("Impossible\n");
    printf("Now choose your direction:\n           Up\n           [1]\nLeft "
           "[4]          Right [2]\n           [3]\n           Down\n");
    scanf("%d", &d); // to select your direction
    empty_buffer();  // if you select characters
  }
  for (int i = 0; i < 7; i++) { // to go through the game board
    if (f == 1) {               // to stop when the player had already play
      break;
    }
    for (int j = 0; j < 7; j++) { // to go through the game board
      if (f == 1) {               // to stop when the player had already play
        break;
      }
      if ((*(*(pb + i) + j)).type == 1) { // to find a player
        if ((*(*(pb + i) + j)).class ==
            c) {        // to find the character of the player that move
          f = 1;        // when the player has been found
          if (d == 1) { // if you want to go up
            e = Move(pa, pb, c, i - 1, j, pd);
          }
          if (d == 2) { // if you want to go right
            e = Move(pa, pb, c, i, j + 1, pd);
          }
          if (d == 3) { // if you want to go down
            e = Move(pa, pb, c, i + 1, j, pd);
          }
          if (d == 4) { // if you want to go left
            e = Move(pa, pb, c, i, j - 1, pd);
          }
        }
      }
    }
  }
  return e; // return if the player died or not, equals 1 if he died, 0 if not
}

int FirstMove(
    Game **pa, Game **pb, Game **pd,
    int c) { // to move on the board, first move is different for every player
  int a, e, d;
  e = 0; // equals 1 if you are dead
  d = 0; // equals 1 when the player has been found
  printf("Now choose your direction:\n           Up\n           [1]\nLeft [4]  "
         "        Right [2]\n           [3]\n           Down\n");
  scanf("%d", &a);              // to select your direction
  empty_buffer();               // if you select characters
  for (int i = 0; i < 7; i++) { // to go through the game board
    if (d == 1) {               // to stop when the player had already play
      break;
    }
    for (int j = 0; j < 7; j++) { // to go through the game board
      if (d == 1) {               // to stop when the player had already play
        break;
      }
      if ((*(*(pb + i) + j)).type == 1) { // to find a player
        if ((*(*(pb + i) + j)).class ==
            c) {        // to find the character of the player that move
          d = 1;        // when the player has been found
          if (c == 1) { // if the character of the player that move is the
                        // ranger
            empty_buffer();  // if you select characters
            while (a != 3) { // can only go down for first move
              printf("Impossible\n");
              printf("Now choose your direction:\n           Up\n           "
                     "[1]\nLeft [4]          Right [2]\n           [3]\n       "
                     "    Down\n");
              scanf("%d", &a); // to select your direction
              empty_buffer();  // if you select characters
            }
            e = Move(pa, pb, c, i + 1, j,
                     pd); // to move with the right direction
            (*(*(pb + i) + j)).type =
                0; // to set the case where we were a limit on the game board
            (*(*(pa + i) + j)).type = 0; // to set the case where we were a
                                         // limit on the hidden game board
          }
          if (c ==
              2) { // if the character of the player that move is the warrior
            empty_buffer();  // if you select characters
            while (a != 2) { // can only go right for first move
              printf("Impossible\n");
              printf("Now choose your direction:\n           Up\n           "
                     "[1]\nLeft [4]          Right [2]\n           [3]\n       "
                     "    Down\n");
              scanf("%d", &a); // to select your direction
              empty_buffer();  // if you select characters
            }
            e = Move(pa, pb, c, i, j + 1,
                     pd); // to move with the right direction
            (*(*(pb + i) + j)).type =
                0; // to set the case where we were a limit on the game board
            (*(*(pa + i) + j)).type = 0; // to set the case where we were a
                                         // limit on the hidden game board
          }
          if (c == 3) { // if the character of the player that move is the thief
            empty_buffer();  // if you select characters
            while (a != 1) { // can only go up for first move
              printf("Impossible\n");
              printf("Now choose your direction:\n           Up\n           "
                     "[1]\nLeft [4]          Right [2]\n           [3]\n       "
                     "    Down\n");
              scanf("%d", &a); // to select your direction
              empty_buffer();  // if you select characters
            }
            e = Move(pa, pb, c, i - 1, j,
                     pd); // to move with the right direction
            (*(*(pb + i) + j)).type =
                0; // to set the case where we were a limit on the game board
            (*(*(pa + i) + j)).type = 0; // to set the case where we were a
                                         // limit on the hidden game board
          }
          if (c == 4) { // if the character of the player that move is the
                        // wizard
            empty_buffer();  // if you select characters
            while (a != 4) { // can only go left for first move
              printf("Impossible\n");
              printf("Now choose your direction:\n           Up\n           "
                     "[1]\nLeft [4]          Right [2]\n           [3]\n       "
                     "    Down\n");
              scanf("%d", &a); // to select your direction
              empty_buffer();  // if you select characters
            }
            e = Move(pa, pb, c, i, j - 1,
                     pd); // to move with the right direction
            (*(*(pb + i) + j)).type =
                0; // to set the case where we were a limit on the game board
            (*(*(pa + i) + j)).type = 0; // to set the case where we were a
                                         // limit on the hidden game board
          }
        }
      }
    }
  }
  return e; // return if the player died or not, equals 1 if he died, 0 if not
}