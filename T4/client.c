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

void showBoard(struct GameState *GS) {
    int rows = GS->height;
    int cols = GS->width;

    printf("\n"); 
    
    for (int i = 0; i < rows; i++) {
        
        printf("%2d ", i + 1);

        for (int j = 0; j < cols; j++) { 
            printf("   "); 
        }
        printf("\n");
    }
    printf("   "); 
    for (int j = 0; j < cols; j++) {
        printf("%3d", j + 1);
    }
    printf("\n");
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