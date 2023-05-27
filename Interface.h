#ifndef H_D
#define H_D
struct Game;
void print(struct Game **p);
void Rule();
int Menu(struct Game **p);
void FillName(struct Game **p, struct Game **pa, int a, int b);
void SamePlayer(struct Game **p, int a, struct Game **pa);
#endif
