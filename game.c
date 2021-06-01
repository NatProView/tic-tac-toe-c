#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "condition.h"

void draw(char field[], int len) {
    printf("\tTic Tac Toe\n\n");
	printf("\t %c | %c | %c \n", field[1], field[2], field[3]);
	printf("\t---|---|---\n");
	printf("\t %c | %c | %c \n", field[4], field[5], field[6]);
	printf("\t---|---|---\n");
	printf("\t %c | %c | %c \n", field[7], field[8], field[9]);
}

void input(char field[], char mark, int len) {
    int input;
    bool isOk = false;
    printf("\n\tTurn of [%c]\n", mark);

    while (!isOk) {
        scanf("%d", &input);
        for (int i = 1; i < len; i++) {
            if (input == i && field[i] != 'X' && field[i] != 'O') {
                field[i] = mark;
                isOk = true;
            }
        }
        if (!isOk) {
            printf("[INPUT] Wrong input, try again\n");
        } 
    }

}
void inputBot(char field[], char mark, int len) {
    int input;
    bool isOk = false;
    printf("\n\tTurn of [%c]\n", mark);

    sleep((rand() % 3) + 1);
    while (!isOk) {
        input = (rand() % 10);
        for (int i = 1; i < len; i++) {
            if (input == i && field[i] != 'X' && field[i] != 'O') {
                field[i] = mark;
                isOk = true;
            }
        }
        if (!isOk) {
            printf("[INPUT] Wrong input, try again\n");
        } 
    }
    
}

int pvp(char field[], int len) {
    system("clear");
    for (int i = 0; i < 9; i++) {
        draw(field, 10);
        int turn = i % 2;

        if (turn == 0) {
            input(field,'X', len);
        } else {
            input(field,'O', len);
        }

        switch (check(field, len)) {
            case 1:
                system("clear");
                return turn; // 0: [X]  1: [O]
                break;
            case 2:
                system("clear");
                return 3; //remis
            default:
                system("clear");
                break;
        }
    }
}

int pve(char field[], int len) {
    system("clear");
    bool playerStarts;
    char temp;

    if (rand() % 3 == 1) {
        printf("Player gets [X] and starts the game\n");
        playerStarts = true;
    } else {
        printf("AI gets [X] and starts the game\n");
        playerStarts = false;
    }

    while (temp != 'y') {
        printf("Ready? [y]\n");
        scanf("%c", &temp);
    }
    system("clear");
    bool turn;
    for  (int i = 0; i < 9; i++) {

        if (i % 2 == 0) {
            turn = true;    // turn of [X]
        } else {
            turn = false;   // turn of [X]
        }
        draw(field, len);

        if (turn && playerStarts) {
            input(field, 'X', len);
        } else if (turn && !playerStarts) {
            inputBot(field, 'X', len);
        } else if (!turn && playerStarts) {
            inputBot(field, 'O', len);
        } else {
            input(field, 'O', len);
        }

        switch (check(field, len)) {
            case 1:
                system("clear");
                return i % 2;   // 0: [X]	1: [O]    
                break;
            case 2:
                system("clear");
                return 3;       //remis
        }
        system("clear");

        
    }
    return -1;
    
}

int eve(char field[], int len) {
    system("clear");
    for (int i = 0; i < 9; i++) {

        draw(field, len);
        int turn = i % 2;

        if (turn == 0) {
            inputBot(field, 'X', len);
        } else {
            inputBot(field, 'O', len);
        }

        switch (check(field, len)) {
            case 1:
                system("clear");
                return turn;   // 0: [X]	1: [O]    
                break;
            case 2:
                system("clear");
                return 3;       //remis
                break;
            default:
                system("clear");
                break;

        }     
    }
}
