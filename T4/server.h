
#ifndef SERVER_H
#define SERVER_H

struct Players {
  int current;
  int next;
  int player0Score;
  int player1Score;
  char player0Icon;
  char player1Icon;
};

struct BoardDimensions {
  int width;
  int height;
};

struct GameState {
  struct Players *players;
  struct BoardDimensions *boardDimensions;
  char **board;
};

struct Coordinate {
  int X;
  int Y;
};

struct Move {
  struct Coordinate to;
  struct Coordinate from;
};

/**
 * Creaates the NxM board based on the date in the GameState struct
 * @param GS A pointer to the GameState struct
 */
char **createBoard(struct GameState *GS);

void populateBoard(struct GameState *GS);

/**
 * Swaps the variables for the current player and the next player
 * @param GS A pointer to the GameState struct
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
 * @param GS a pointer to the GameState struct
 * @param move A pointer to ther move struct
 */
int isMoveValid(struct GameState *GS, struct Move *move);

/**
 * Makes the move on the board
 * @param GS the pointer the the GameState struct
 * @param move A pointer to the move struct
 */
void movePenguin(struct GameState *GS, struct Move *move);

#endif // SERVER_H
