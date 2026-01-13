#include "game.h"
#include "gameconfig.h"
#include "movementalgorithm.h"
#include "placementalgorithm.h"

#include <stdio.h>
#include <string.h>

// the point is to make a min max algorithm that will play the game for us,
// thats for the movement phase for the placement phase we will use a simple
// greedy algorithm that places penguins in the best possible spots

void print2DIntArray(int rows, int cols, int array[rows][cols]) {
  printf("printing 2D int array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

int placementPhase(GameConfig *cfg, GameState *GS) {
  if (cfg->phase != PHASE_PLACEMENT) {
    printf("Error: Not in placement phase\n");
    return -1;
  }

  // we check for our teamname in the players list to get our player id
  // if it is not found we add it
  int ourPlayerId = -1;
  for (int i = 0; i < GS->players->amountOfPlayers; i++) {
    if (strcmp(GS->players->playerNames[i], TEAM_NAME) == 0) {
      ourPlayerId = GS->players->playerIds[i];
      break;
    }
  }
  if (ourPlayerId == -1) {
    ourPlayerId = GS->players->amountOfPlayers + 1;
    GS->players->playerNames[ourPlayerId - 1] = TEAM_NAME;
    GS->players->playerIds[ourPlayerId - 1] = ourPlayerId;
    GS->players->playerScores[ourPlayerId - 1] = 0;
    GS->players->amountOfPlayers++;
  }

  int penguinsToPlace = cfg->penguins;
  // check how many penguins with our id are already on the board
  for (int row = 0; row < GS->boardDimensions->height; row++) {
    for (int col = 0; col < GS->boardDimensions->width; col++) {
      if (GS->penguinBoard[row][col] == ourPlayerId) {
        penguinsToPlace--;
      }
    }
  }
  if (penguinsToPlace <= 0) {
    // we have already placed all our penguins
    return 0;
  }
  // now we place one of our penguins in the best possible spot
  Coordinate bestPlacement = determineBestPlacement(GS);
  if (bestPlacement.X == -1 || bestPlacement.Y == -1) {
    printf("Error: No valid placement found\n");
    return -1;
  }
  GS->penguinBoard[bestPlacement.Y][bestPlacement.X] = ourPlayerId;
  GS->players->playerScores[ourPlayerId - 1] +=
      GS->fishBoard[bestPlacement.Y][bestPlacement.X];
  GS->fishBoard[bestPlacement.Y][bestPlacement.X] = 0;

  return 0;
}

int movementPhase(GameConfig *cfg, GameState *GS) {
  if (cfg->phase != PHASE_MOVEMENT) {
    printf("Error: Not in movement phase\n");
    return -1;
  }
  Move bestMove;
  // we check for our teamname in the players list to get our player id
  int ourPlayerId = -1;
  for (int i = 0; i < GS->players->amountOfPlayers; i++) {
    if (strcmp(GS->players->playerNames[i], TEAM_NAME) == 0) {
      ourPlayerId = GS->players->playerIds[i];
      break;
    }
  }
  if (ourPlayerId == -1) {
    printf("Error: Our PlayerID not found\n");
    return -1;
  }
  bestMove = determineBestMove(GS, *cfg, ourPlayerId);
  if (bestMove.to.X == -1 || bestMove.to.Y == -1) {
    // no valid move found
    return 0;
  }
  int fromRow = bestMove.from.Y;
  int fromCol = bestMove.from.X;
  int toRow = bestMove.to.Y;
  int toCol = bestMove.to.X;
  GS->penguinBoard[toRow][toCol] = GS->penguinBoard[fromRow][fromCol];
  GS->penguinBoard[fromRow][fromCol] = 0;
  GS->players->playerScores[ourPlayerId - 1] += GS->fishBoard[toRow][toCol];
  GS->fishBoard[toRow][toCol] = 0;

  return 0;
}
