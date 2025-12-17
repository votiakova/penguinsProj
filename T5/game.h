#ifndef GAME_H
#define GAME_H

/**
 * Struct to hold all player data
 */
struct Players {
  int amountOfPlayers;
  /**
   * Holds the list index of the current player 0 <= currentPlayer < amountOfPlayers
   */
  int currentPlayer;
  int *playerScores;
  char **playerNames;
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
} GameState;

/**
 * Struct to hold a pair of values representing coordinates
 * Currently unused
 */
struct Coordinate {
  int X;
  int Y;
};

/**
 * Struct to hold a pair of coordinates representing a move
 */
struct Move {
  struct Coordinate to;
  struct Coordinate from;
};

#endif // !GAME_H
