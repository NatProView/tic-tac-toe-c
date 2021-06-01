#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void draw(char field[], int len);

void inputBot(char field[], char mark, int len);

void input(char field[], char mark, int len);

int pvp(char field[], int len);

int pve(char field[], int len);

int eve(char field[], int len);



#endif