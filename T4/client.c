#include "client.h"
#include "server.h"
#include <stdio.h>

// Allows the user to input the board dimentions for the game
// The limit for the size will be
int *askForBoardDimensions() {
  printf("Reading board dimensions\n");
  // We're going to scan for two numbers form the user, then output the pointer
  // to the array with both coordinates
  return 0;
}

#include <stdio.h>
#include "server.h"

void showBoard(struct GameState *GS) {

    int rows = GS->boardDimensions->height;
    int cols = GS->boardDimensions->width;

    printf("\n");

    for (int i = 0; i < rows; i++) {
        
        printf("%2d ", i + 1);

        for (int j = 0; j < cols; j++) {

            int val = (int)(long)GS->board[i][j];

            int fish = val / 10;
            int player = val % 10;

            if (val == 0) {
                printf(" ~~"); 
            } 
            else if (player > 0) {
                printf(" P%d", player);
            } 
            else {
                printf(" %d ", fish);
            }
        }
        printf("\n");
    }

    printf("   "); 
    for (int j = 0; j < cols; j++) {
        printf("%3d", j + 1);
    }
}

struct Move askPlayerForMove(int player) {
    struct Move userMove;
    int valid = 0;

    while (!valid) {
        printf("\nPlayer %d, enter your move.\n", player);

        printf(" Enter FROM coordinates (row col): ");
        if (scanf("%d %d", &userMove.fromX, &userMove.fromY) != 2) {
            printf(" Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        printf(" Enter TO coordinates (row col): ");
        if (scanf("%d %d", &userMove.toX, &userMove.toY) != 2) {
            printf(" Invalid input. Please enter two integers.\n");
            while (getchar() != '\n');
            continue;
        }

        valid = 1; // all good!
    }

    printf("You chose: FROM (%d,%d) → TO (%d,%d)\n",
           userMove.fromX, userMove.fromY, userMove.toX, userMove.toY);

    return move;
}