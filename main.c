#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "ai.h"

int main() {
    char player[SIZE][SIZE];
    char computer[SIZE][SIZE];
    int row, col;

    srand(time(NULL));

    initBoard(player);
    initBoard(computer);

    placeAllShips(player);
    placeAllShips(computer);

    while (1) {
        printf("\n=== SEU TABULEIRO ===\n");
        printBoard(player, 0);

        printf("\n=== TABULEIRO INIMIGO ===\n");
        printBoard(computer, 1);

        printf("Digite linha e coluna: ");
        scanf("%d %d", &row, &col);

        if (shoot(computer, row, col))
            printf("Você ACERTOU!\n");
        else
            printf("Você errou.\n");

        if (allShipsSunk(computer)) {
            printf("VOCÊ VENCEU!\n");
            break;
        }

        printf("\n--- Turno da IA ---\n");
        aiMove(player);

        if (allShipsSunk(player)) {
            printf("A IA venceu!\n");
            break;
        }
    }

    return 0;
}
