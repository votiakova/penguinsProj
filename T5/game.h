#ifndef GAME_H
#define GAME_H

struct Players {
  int current; //ID of the current players turn
  int next; //ID of the player who has the next turn
  int player0Score; //score of player 0
  int player1Score; //score of player 1
  char player0Icon; //the character which represents player 0 on the board
  char player1Icon; //the character which represents player 1 on the board
};
//is the structure of the board
struct BoardDimensions {
  int width; //number of columns
  int height; //number of rows
};
//is the structure for representing the state of the game
typedef struct {
  struct Players *players;
  struct BoardDimensions *boardDimensions;
  char **board;
} GameState;

//structure to show a single point on the board by using X Y coordinates
struct Coordinate {
  int X;
  int Y;
};

//structure to show the penguins movement from one coordinate to another
struct Move {
  struct Coordinate to;
  struct Coordinate from;
};

#endif // !GAME_H
