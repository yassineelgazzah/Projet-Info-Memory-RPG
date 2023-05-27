#ifndef H_B
#define H_B
struct Game;
int Move(struct Game **pa, struct Game **pb, int c, int a, int b,
         struct Game **pd);
int MoveD(struct Game **pa, struct Game **pb, struct Game **pd, int c);
int FirstMove(struct Game **pa, struct Game **pb, struct Game **pd, int c);
#endif
