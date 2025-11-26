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

void showBoard(struct GameState *GS) { printf("Printing the board state\n"); }

struct Move askPlayerForMove(int player) {
  int userInput;
  struct Move userMove;
  userMove.toX = 0;
  userMove.fromX = 1;
  while (1) {
    printf("Asking player %d for move: ", player);
    if (scanf("%d", &userInput) == 1) {
      break; // valid integer entered
    } else {
      printf("Invalid input, try again.\n");
      while (getchar() != '\n')
        ; // clear invalid input
    }
  }
  return userMove;
}
