#ifndef H_A
#define H_A
struct Game;
void ChooseW(struct Game **p, int b);
void empty_buffer();
int Totem(struct Game **pa, struct Game **pb, int c, struct Game **pd, int g,
          int h);
int Teleport(struct Game **pa, struct Game **pb, int c, struct Game **pd);
#endif
