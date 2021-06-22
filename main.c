#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "game.h"
#include "condition.h"

void hello();
int choice();

void endResult(int winner, char field[], int len);

int main() {
	char field[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int len = 10;
    int winner;
    hello();
    srand(time(NULL));
    switch (choice()) {
        case 1:
        winner = pvp(field, len);
        break;
        case 2: 
        winner = pve(field, len);
        break;
        case 3:
        winner = eve(field, len);
        break;
        default:
        printf("Something went wrong\n");
        return 0;
        break;
    }

    endResult(winner, field, len);

    return 0;
}
int choice() {
    printf("\n\n");
    printf("[1] Player vs Player\n");
    printf("[2] Player vs AI\n");
    printf("[3] AI vs AI\n");
    int temp;
    scanf("%d", &temp);
    
    if (temp > 0 && temp < 4) {
        return temp;
    } else {
        printf("Wrong input, try again\n");
        return choice();
    }
}
void hello() {
    system("clear");
	printf("\n\t WELCOME TO\n\n");
	sleep(1);
	printf("\t t | i | c \n");
	printf("\t---|---|---\n");
	sleep(1);
	printf("\t t | a | c \n");
	printf("\t---|---|---\n");
	sleep(1);
	printf("\t t | o | e \n");
}



void endResult(int winner, char field[], int len) {
    draw(field, len);
    printf("\n\n");
    switch (winner) {
        case 0:
            printf("[X] HAS WON THE GAME\n");
            break;
        case 1:
            printf("[O] HAS WON THE GAME\n");
            break;
        case 3:
            printf("WE'VE GOT A DRAW!\n");
            break;
    }
}

