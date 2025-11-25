#include "server.h"
#include <stdio.h>
#include <stdlib.h>

int board[64];
// We're going to use a 1d array to store the board with ints 1-3 acting as the
// number of fish 0 acting as an empty tile 8 - player 1 penguin 16 player 2
// penguin 8 and 16 is chosen to be able to use bitwise opperations The array
// will be initialized dynamicallly based on the dimentions provided by the user
//
//

void swapPlayers(struct GameState *GS) {
  int temp = GS->players->next;
  GS->players->next = GS->players->current;
  GS->players->current = temp;
};

int canPlayerMovePenguin(const int player) {
  printf("Checking if player %d can move a penguin\n", player);
  // (makes random actually random)
  int randomPercent = rand() % 100; // generates a number in the range 0-99
  int canMove = randomPercent >= 20;
  if (canMove) {
    printf("player %d can move a penguin\n", player);
  } else {
    printf("player %d can't move a penguin\n", player);
  }
  return canMove;
}

int calculateWinner() {
  printf("Calculating the winner\n");
  return rand() % 2;
}

int isMoveValid(struct GameState *GS, struct Move *move) { return 1; }

void movePenguin(struct GameState *GS, struct Move *move) {}

void collectFish() {}

int wereAllPenguinsPlaced(struct GameState *GS) { return 1; }

int random_seed = 42; // its going to be random later
// int random_seed = time(NULL);
