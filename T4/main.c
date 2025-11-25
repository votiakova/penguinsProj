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
  GS.players = &players;

  askForBoardDimensions();
  struct BoardDimensions boardDimensions;
  boardDimensions.width = 8;
  boardDimensions.height = 8;
  GS.boardDimensions = &boardDimensions;
  // currently not implemented
  srand(random_seed);
  placementPhase(&GS);
  movementPhase(&players, &boardDimensions);

  return 0;
  // currently not implemented
}
