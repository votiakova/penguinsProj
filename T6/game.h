#ifndef GAME_H
#define GAME_H

#include "gameconfig.h"

#define TEAM_NAME "SAU"

/**
 * Struct to hold all player data
 */
struct Players {
  int amountOfPlayers;
  /**
   * Holds the list index of the current player 0 <= currentPlayer <
   * amountOfPlayers
   */
  int currentPlayer;
  int *playerScores;
  char **playerNames;
  int *playerIds;
};

/**
 * Struct to hold the board dimensions
 */
struct BoardDimensions {
  int width;
  int height;
};

/**
 * Main gamestate struct that holds all the data about the current gamestate
 */
typedef struct {
  struct Players *players;
  struct BoardDimensions *boardDimensions;
  char **fishBoard;
  char **penguinBoard;
  int teamNameAdded;
} GameState;

/**
 * Struct to hold a pair of values representing coordinates
 * Currently unused
 */
typedef struct {
  int X;
  int Y;
} Coordinate;

/**
 * Struct to hold a pair of coordinates representing a move
 */
typedef struct {
  Coordinate to;
  Coordinate from;
} Move;

void print2DIntArray(int rows, int cols, int array[rows][cols]);

int placementPhase(GameConfig *cfg, GameState *GS);
int movementPhase(GameConfig *cfg, GameState *GS);

#endif // !GAME_H
