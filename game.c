#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = WATER;
}

void printBoard(char board[SIZE][SIZE], int hideShips) {
    printf("  ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (hideShips && board[i][j] == SHIP)
                printf("%c ", WATER);
            else
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int placeShip(char board[SIZE][SIZE], int row, int col, int size, char direction) {
    if (direction == 'H') {
        if (col + size > SIZE) return 0;
        for (int i = 0; i < size; i++)
            if (board[row][col+i] != WATER) return 0;
        for (int i = 0; i < size; i++)
            board[row][col+i] = SHIP;
    } else {
        if (row + size > SIZE) return 0;
        for (int i = 0; i < size; i++)
            if (board[row+i][col] != WATER) return 0;
        for (int i = 0; i < size; i++)
            board[row+i][col] = SHIP;
    }
    return 1;
}

void placeAllShips(char board[SIZE][SIZE]) {
    int ships[] = {5,4,3,3,2};
    for (int s = 0; s < 5; s++) {
        int placed = 0;
        while (!placed) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            char dir = (rand() % 2) ? 'H' : 'V';
            placed = placeShip(board, row, col, ships[s], dir);
        }
    }
}

int shoot(char board[SIZE][SIZE], int row, int col) {
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        return 1;
    }
    if (board[row][col] == WATER)
        board[row][col] = MISS;
    return 0;
}

int allShipsSunk(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == SHIP)
                return 0;
    return 1;
}
