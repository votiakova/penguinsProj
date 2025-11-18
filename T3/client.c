#include "client.h"
#include <stdio.h>

// Allows the user to input the board dimentions for the game
// The limit for the size will be
int *askForBoardDimentions() {
  printf("Reading board dimentions\n");
  // We're going to scan for two numbers form the user, then output the pointer
  // to the array with both coordinates
  return 0;
}

void showBoard() { printf("Printing the board state\n"); }

int askPlayerForMove(int player) {
  printf("Asking player %d for move\n", player);
  int userMove;
  scanf("%d", &userMove);
  return userMove;
}
