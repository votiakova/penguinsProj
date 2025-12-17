#include "client.h"
#include "movement.h"
#include "placement.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  struct GameState GS;

  int random_seed = 42;

  struct Players players;
  players.current = 0;
  players.next = 1;
  players.player0Icon = '#';
  players.player1Icon = '@';
  players.player0Score = 0;
  players.player1Score = 0;
  GS.players = &players;

  struct BoardDimensions boardDimensions = askForBoardDimensions();
  GS.boardDimensions = &boardDimensions;
  GS.board = createBoard(&GS);

  srand(random_seed);
  populateBoard(&GS);
  placementPhase(&GS);
  movementPhase(&GS);

  return 0;
  // currently not implemented
}
