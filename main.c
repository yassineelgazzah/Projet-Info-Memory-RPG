#include "Create.h"
#include "Interface.h"
#include "Move.h"
#include "Prop.h"
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

void FillScore(Game **p, FILE *a,
               int b) { // fonction to fill the fill Score.txt
  fputs("Players :\n", a);
  for (int i = 0; i < 7; i++) {   // to go through the game board
    for (int j = 0; j < 7; j++) { // to go through the game board
      if ((*(*(p + i) + j)).type ==
          1) { // to find the players and put their names...
        fprintf(a, "    -%s :\n", (*(*(p + i) + j)).name);
        fputs("           Number of victories :", a);
        if ((*(*(p + i) + j)).item1 == 1 && (*(*(p + i) + j)).item2 == 1) {
          fprintf(a, "%d\n", 1);
        } else {
          fprintf(a, "%d\n", 0);
        }
        fputs("           Number of Monsters defeated : ", a);
        fprintf(a, "%d\n", (*(*(p + i) + j)).kill);
        fputs("           Number of cards revealed : ", a);
        fprintf(a, "%d\n", (*(*(p + i) + j)).card);
        fputs("           Number of treasure found : ", a);
        fprintf(a, "%d\n", (*(*(p + i) + j)).treasure);
      }
    }
  }
  fprintf(a, "Number of Games : %d\n", b);
}

int Play(Game **p, Game **pa, Game **pb, Game **pd, int b, FILE *Score,
         int k) { // fonction to play a game
  int e, d, f, a, g;
  e = 0; // equals 1 if a player is dead, to mark the end of the round
  d = 0; // equals 1 if a player won (found his weapon and a treasure), to mark
         // the end of the game
  f = 0; // used to change player at every round
  g = 2; // equals 0 if you want to restart a game, 1 if not
  a = 1 + (f % b); // to change player at every round with b the number of
                   // players that play
  while (d != 1) { // while no one won the game continue
    print(pb);     // print the game board
    int start_time, end_time, elapsed_time;
    start_time = (int)time(NULL); // start recording the time
    for (int i = 0; i < 1000000000; i++) {
    } // the code to clock
    if (a == 1) {
      printf("Ranger it's your turn to play:\n");
    }
    if (a == 2) {
      printf("Warrior it's your turn to play:\n");
    }
    if (a == 3) {
      printf("Thief it's your turn to play:\n");
    }
    if (a == 4) {
      printf("Wizard it's your turn to play:\n");
    }
    e = FirstMove(
        pa, pb, pd,
        a); // to move on the board, first move is different for every player
    while (e != 1) { // while the player that play is not dead
      if (d == 1) {  // if the player win
        break;
      }
      for (int i = 0; i < 7; i++) {           // to go through the game board
        for (int j = 0; j < 7; j++) {         // to go through the game board
          if ((*(*(pb + i) + j)).type == 1) { // to find the players
            if ((*(*(pb + i) + j)).item1 == 1 &&
                (*(*(pb + i) + j)).item2 ==
                    1) { // if the player win (got his weapon and a treasure)
              printf("End of the Game\n");
              FillScore(pa, Score, k); // to fill the fill Score.txt
              d = 1;                   // equals 1 if a player won
              if ((*(*(pb + i) + j)).class == 1) {
                printf("The Ranger wins\n");
                printf("%s", (*(*(pb + i) + j)).name);
                printf(" wins\n");
                print(pd);
              }
              if ((*(*(pb + i) + j)).class == 2) {
                printf("The Warrior wins\n");
                printf("%s", (*(*(pb + i) + j)).name);
                printf(" wins\n");
                print(pd);
              }
              if ((*(*(pb + i) + j)).class == 3) {
                printf("The Thief wins\n");
                printf("%s", (*(*(pb + i) + j)).name);
                printf(" wins\n");
                print(pd);
              }
              if ((*(*(pb + i) + j)).class == 4) {
                printf("The Wizard wins\n");
                printf("%s", (*(*(pb + i) + j)).name);
                printf(" wins\n");
                print(pd);
              }
            }
          }
        }
      }
      if (d != 1) {               // if the player hasn't win
        print(pb);                // print the game board
        e = MoveD(pa, pb, pd, a); // to move on the board
      }
    }
    if (d != 1) {                 // if the player hasn't win and has died
      e = 0;                      // reset the state of dead or not
      f = f + 1;                  // used to change  to the next player
      a = 1 + (f % b);            // change to the next player
      printf("Game over\n");      // to the player that is dead
      end_time = (int)time(NULL); // end of the timer
      elapsed_time =
          end_time - start_time;    // calculates the eclapsed time in seconds
      printf("\nRound finished\n"); // to mark the end of the round to the
                                    // player that is dead
      printf("Time elapsed: %d seconds\n",
             elapsed_time); // print the time elapsed
      for (int i = 0; i < 7;
           i++) { // to go through the game board to reset the position of the
                  // player with his statistics
        for (int j = 0; j < 7;
             j++) { // to go through the game board to reset the position of the
                    // player with his statistics
          if ((*(*(pb + i) + j)).type == 1) {
            if ((*(*(pb + i) + j)).class == 1) {
              (*(*p + 4)) = (*(*(pb + i) + j));
              (*(*pd + 4)) = (*(*(pb + i) + j));
            }
            if ((*(*(pb + i) + j)).class == 2) {
              (*(*(p + 2))) = (*(*(pb + i) + j));
              (*(*(pd + 2))) = (*(*(pb + i) + j));
            }
            if ((*(*(pb + i) + j)).class == 3) {
              (*(*(p + 6) + 2)) = (*(*(pb + i) + j));
              (*(*(pd + 6) + 2)) = (*(*(pb + i) + j));
            }
            if ((*(*(pb + i) + j)).class == 4) {
              (*(*(p + 4) + 6)) = (*(*(pb + i) + j));
              (*(*(pd + 4) + 6)) = (*(*(pb + i) + j));
            }
          }
        }
      }
      pa = fill(pd, pa); // reset the game board
      pb = fill(p, pb);  // reset the hidden game board
    }
    if (d == 1) { // if a player has won, end of the game
      printf("Do you want to restart:\n");
      printf("[0] Yes        No [1]\n");
      scanf("%d", &g);
      empty_buffer();          // if you answer with characters
      while (g < 0 || 1 < g) { // if you don't select 1 or 0
        printf("Impossible\n");
        printf("Do you want to restart:\n");
        printf("[0] Yes        No [1]\n");
        scanf("%d", &g);
        empty_buffer(); // if you answer with characters
      }
    }
  }
  return g; // return if you want to restart a game
}

int main() {
  Game **p, **pa, **pb, **pc, **pd;
  int e, a, b, g;
  e = 0;    // equals 0 if you want to restart a game, 1 if not
  b = 2;    // equals 0 if you want to restart with same players, 1 if not
  g = 0;    // number of game played
  p = NULL; // to initialize an array
  FILE *Score = fopen("Score.txt", "r+"); // to open the file Score.txt
  if (Score == NULL) {                    // if there is no file Score.txt
    printf("Impossible to open file Score\n\n");
  }
  pa = create(p); // to create a first game board
  createJ(pa);    // to create all of the players
  Rule();         // to print the rules
  a = Menu(pa); // to print the menu (to choose the number of players and names)
  pb = fill(pa, pb); // to create a second game board, to be hidden, with all
                     // the cases revealed
  pc = fill(pa, pc); // to create a third game board, back up for the first
  createM(pa, pb);   // to create the second gameboard
  pd = fill(pb, pd); // to create a fourth game board, back up for the second
  e = Play(pa, pb, pc, pd, a, Score,
           g);     // to play until the end of the game, equals 0 if you want to
                   // restart a game
  g = g + 1;       // at the end of the game, +1 to number of game played
  while (e != 1) { // while you want to play
    printf("Do you want to restart with the same players:\n");
    printf("[0] Yes        No [1]\n");
    scanf("%d", &b);
    empty_buffer();          // if you answer with characters
    while (b < 0 || 1 < b) { // if you don't select 1 or 0
      printf("Impossible\n");
      printf("Do you want to restart with the same players:\n");
      printf("[0] Yes        No [1]\n");
      scanf("%d", &b);
      empty_buffer(); // if you answer with characters
    }
    if (b == 1) { // without the same players reset everything
      pa = create(p);
      createJ(pa);
      a = Menu(pa);
      pb = fill(pa, pb);
      pc = fill(pa, pc);
      createM(pa, pb);
      pd = fill(pb, pd);
      e = Play(pa, pb, pc, pd, a, Score, g);
      g = g + 1;
    }
    if (b ==
        0) { // with the same players recovers the names and reset everything
      pa = create(p);
      createJ(pa);
      SamePlayer(pa, a, pd); // to recovers the names
      pb = fill(pa, pb);
      pc = fill(pa, pc);
      createM(pa, pb);
      pd = fill(pb, pd);
      e = Play(pa, pb, pc, pd, a, Score, g);
      g = g + 1;
    }
  }
  fclose(Score); // to close the file Score.txt
  return 0;
}
