#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] == HIT || board[row][col] == MISS);

    printf("IA atirou em: %d %d\n", row, col);

    if (board[row][col] == SHIP) {
        printf("IA ACERTOU!\n");
        board[row][col] = HIT;
    } else {
        printf("IA errou.\n");
        board[row][col] = MISS;
    }
}
