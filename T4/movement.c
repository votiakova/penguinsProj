#include "client.h"
#include "server.h"
#include <stdio.h>

/**
 * The main loop for the movement plase
 * @param players the player struct
 * @param boardDimensions the board dimentions struct
 */
void movementPhase(struct GameState *GS) {
  struct Move playerMove;
  while (1) {

    if (canPlayerMovePenguin(GS->players->current)) {
      showBoard();
      playerMove = askPlayerForMove(GS->players->current);
      while (!isMoveValid(GS, &playerMove)) {
        playerMove = askPlayerForMove(GS->players->current);
      }
      movePenguin(GS, &playerMove);
      swapPlayers(GS);
    } else {
      if (canPlayerMovePenguin(GS->players->next)) {
        swapPlayers(GS);
      } else {
        calculateWinner();
        break;
      }
    }
  }
  printf("Game is over\n");
}
