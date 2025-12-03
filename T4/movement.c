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
  int canPlayerMove[2] = {1, 1};
  while (1) {
    // We are going to add checks for if the player can make a move later, once
    // we add move validation

    if (canPlayerMove[GS->players->current]) {
      showBoard(GS);
      playerMove = askPlayerForMove(GS->players->current);
      while (!isMoveValid(GS, &playerMove)) {
        playerMove = askPlayerForMove(GS->players->current);
      }

      if (playerMove.from.X == 0 && playerMove.from.Y == 0) {
        canPlayerMove[GS->players->current] = 0;
        swapPlayers(GS);
        continue;
      }
      movePenguin(GS, &playerMove);
      swapPlayers(GS);
    } else if (canPlayerMove[GS->players->next]) {
      swapPlayers(GS);
      continue;
    } else {
      break;
    }
  }
  printf("Neither player can move, the final score is:\nPlayer1: %d\nPlayer2: "
         "%d\n",
         GS->players->player0Score, GS->players->player1Score);
}
