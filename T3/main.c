#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "server.h"


void movementPhase(struct Players players, struct BoardDimensions boardDimensions) {
  int playerMove;
  while (1) {

    if (canPlayerMovePenguin(players.current)) {
      showBoard();
      playerMove = askPlayerForMove(players.current);
      while (!isMoveValid(playerMove)) {
        playerMove = askPlayerForMove(players.current);
      }
      movePenguin(players.current, playerMove);
      collectFish();
      swapPlayers(&players);
    } else {
      if (canPlayerMovePenguin(players.next)) {
        swapPlayers(&players);
      } else {
        calculateWinner();
        break;
      }
    }
  }
  printf("Game is over\n");
}


void placementPhase() {
  while (!wereAllPenguinsPlaced()) {
  }
}

int main() {
  int random_seed = 42;

  struct Players players;
  players.current = 0;
  players.next = 1;

  askForBoardDimensions();
  struct BoardDimensions boardDimensions;
  boardDimensions.width = 8;
  boardDimensions.height = 8;
  // currently not implemented
  srand(random_seed);
  placementPhase();
  movementPhase(players, boardDimensions);

  return 0;
  // currently not implemented
}
