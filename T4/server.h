
#ifndef SERVER_H
#define SERVER_H

struct Players {
  int current;
  int next;
  int player0Score;
  int player1Score;
};

struct BoardDimensions {
  int width;
  int height;
};

struct GameState {
  struct Players *players;
  struct BoardDimensions *boardDimensions;
  int *board[64];
};

struct Move {
  int toX;
  int toY;
  int fromX;
  int fromY;
};

/**
 * Swaps the variables for the current player and the next player
 * @param players A pointer to the players struct
 */
void swapPlayers(struct GameState *GS);

/**
 * Checks if the given player can move a penguin
 * @param player the nuber of the player to check (either 0 or 1)
 */
int canPlayerMovePenguin(int player);

/**
 * Adds up the points and returns the the number of the winning player (either 0
 * or 1)
 */
int calculateWinner();

/**
 * Checks if a move is valid
 * @param move A move struct (to be implemented)
 */
int isMoveValid(struct GameState *GS, struct Move *move);

/**
 *  3 |
 *  2 |
 *  1 |1
 *     -----
 *     1 2 3
 *
 */

/**
 * Makes the move on the board
 * @param player the id of the current player
 * @param move the move struct (int for now)
 */
void movePenguin(struct GameState *GS, struct Move *move);

/**
 * Checks if every penguin was placed
 *
 */
int wereAllPenguinsPlaced(struct GameState *GS);

#endif // SERVER_H
