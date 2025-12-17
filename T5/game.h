#ifndef GAME_H
#define GAME_H

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

typedef struct {
  struct Players *players;
  struct BoardDimensions *boardDimensions;
  char **board;
} GameState;

struct Coordinate {
  int X;
  int Y;
};

struct Move {
  struct Coordinate to;
  struct Coordinate from;
};

#endif // !GAME_H
