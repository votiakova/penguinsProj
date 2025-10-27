#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int currentPlayer = 0;
int nextPlayer = 1;

void readBoardDimentions() { printf("Reading board dimentions\n"); }

void swapPlayers() {
  printf("Swapping players\n");
  int temp = currentPlayer;
  currentPlayer = nextPlayer;
  nextPlayer = temp;
  // swaps current player and temp player
}

int canPlayerMovePenguin(int player) {
  printf("Checking if player %d can move a penguin\n", player);
  srand(time(NULL)); // set the random seet to the current time, or whatever
                     // (makes random actually random)
  int randomPercent = rand() % 100; // generates a number in the range 0-99
  int canMove = randomPercent >= 5;
  if (canMove) {
    printf("player %d can move a penguin\n", player);
  } else {
    printf("player %d can't move a penguin\n", player);
  }
  return canMove;
}

int calculateWinner() {
  printf("Calculating the winner\n");
  srand(time(NULL));
  return rand() % 2;
}

int askPlayerForMove(int player) {
  printf("Asking player %d for move\n", player);
  int userMove;
  scanf("%d", &userMove);
  return userMove;
}

int isMoveValid(int move) { return 1; }

void movePenguin(int player, int move) {}

void collectFish() {}

void showBoard() { printf("Printing the board state\n"); }

int wereAllPenguinsPlaced() { return 1; }

void placementPhase() {
  while (!wereAllPenguinsPlaced()) {
  }
}
void movementPhase() {
  int playerMove;
  readBoardDimentions();
  while (1) {
    if (canPlayerMovePenguin(currentPlayer)) {
      showBoard();
      playerMove = askPlayerForMove(currentPlayer);
      while (!isMoveValid(playerMove)) {
        playerMove = askPlayerForMove(currentPlayer);
      }
      movePenguin(currentPlayer, playerMove);
      collectFish();
      swapPlayers();
    } else {
      if (canPlayerMovePenguin(nextPlayer)) {
        swapPlayers();
      } else {
        calculateWinner();
        break;
      }
    }
  }
  printf("Game is over\n");
}

int main() {
  placementPhase();
  movementPhase();

  return 0;
}
