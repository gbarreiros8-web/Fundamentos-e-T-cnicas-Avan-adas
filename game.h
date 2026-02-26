#ifndef GAME_H
#define GAME_H

#define SIZE 10

#define WATER '~'
#define SHIP 'S'
#define HIT 'X'
#define MISS 'O'

typedef struct {
    int size;
    int hits;
} Ship;

void initBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], int hideShips);
int placeShip(char board[SIZE][SIZE], int row, int col, int size, char direction);
void placeAllShips(char board[SIZE][SIZE]);
int shoot(char board[SIZE][SIZE], int row, int col);
int allShipsSunk(char board[SIZE][SIZE]);

#endif
