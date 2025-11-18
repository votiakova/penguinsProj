#include "client.h"
#include <stdio.h>
#include <stdlib.h>

struct Players {
  int current;
  int next;
};

struct BoardDimentions {
  int width;
  int height;
};

int board[64];
// We're going to use a 1d array to store the board with ints 1-3 acting as the
// number of fish 0 acting as an empty tile 8 - player 1 penguin 16 player 2
// penguin 8 and 16 is chosen to be able to use bitwise opperations The array
// will be initialized dynamicallly based on the dimentions provided by the user
//
//

void swapPlayers(struct Players players) {
  int temp = players.next;
  players.next = players.current;
  players.current = temp;
};

int canPlayerMovePenguin(int player) {
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

int isMoveValid(int move) { return 1; }

void movePenguin(int player, int move) {}

void collectFish() {}

int wereAllPenguinsPlaced() { return 1; }

void placementPhase() {
  while (!wereAllPenguinsPlaced()) {
  }
}

void movementPhase(struct Players players) {
  int playerMove;
  readBoardDimentions();
  while (1) {
    if (canPlayerMovePenguin(players.current)) {
      showBoard();
      playerMove = askPlayerForMove(players.current);
      while (!isMoveValid(playerMove)) {
        playerMove = askPlayerForMove(players.current);
      }
      movePenguin(players.current, playerMove);
      collectFish();
      swapPlayers();
    } else {
      if (canPlayerMovePenguin(players.next)) {
        swapPlayers(players);
      } else {
        calculateWinner();
        break;
      }
    }
  }
  printf("Game is over\n");
}

int random_seed = 42; // its going to be random later
// int random_seed = time(NULL);
int main() {
  struct Players players;
  players.current = 0;
  players.next = 1;

  askForBoardDimentions();
  struct BoardDimentions boardDimentions;
  boardDimentions.width = 8;
  boardDimentions.height = 8;
  // currently not implemented
  srand(random_seed);
  placementPhase();
  movementPhase();

  return 0;
  // currently not implemented
}
