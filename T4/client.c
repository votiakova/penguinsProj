#include "client.h"
#include "server.h"
#include <stdio.h>

// Allows the user to input the board dimentions for the game
// The limit for the size will be
struct BoardDimensions askForBoardDimensions() {
  struct Coordinate coordinate;
  struct BoardDimensions boardDimensions;
  printf("Enter board dimensions (width height)\n");
  coordinate = askPlayerForCoordinate(0);
  boardDimensions.width = coordinate.X;
  boardDimensions.height = coordinate.Y;
  return boardDimensions;
}

<<<<<<< HEAD
void showBoard(struct GameState *GS) {
  int width = GS->boardDimensions->width;
  int height = GS->boardDimensions->height;
  for (int i = 0; i < 10; i++) {
    printf("\n");
  }

  printf("Player 1 score: %d\nPlayer 2 score: %d\n", GS->players->player0Score,
         GS->players->player1Score);
  // top separator
  printf("   +");
  for (int col = 1; col <= width; col++) {
    printf("---");
  }
  printf("+\n");

  for (int row = height - 1; row >= 0; row--) {
    printf("%2d ", row + 1); // row index on the left
    printf("| ");

    for (int col = 0; col < width; col++) {
      if (col != width - 1) {
        printf("%c  ", GS->board[row][col]);
      } else {
        printf("%c ",
               GS->board[row][col]); // the last column will have one less
                                     // whitespace to make it look nicer
      }
    }
    printf("|\n");
  }

  // bottom separator
  printf("   +");
  for (int col = 1; col <= width; col++) {
    printf("---");
  }
  printf("+\n");
  // collumn index on the bottom
  printf("     ");
  for (int col = 1; col <= width; col++) {
    printf("%-2d ", col);
  }
  printf("\n");
}

struct Move askPlayerForMove(int player) {
  struct Move userMove;
  struct Coordinate from;
  struct Coordinate to;
  userMove.from = from;
  userMove.to = to;
  struct Coordinate userCoordinate;

  printf("\nPlayer %d, enter your move. Enter 0 0 if you can't move\n",
         player + 1);
  printf("FROM: \n");
  userCoordinate = askPlayerForCoordinate(player);
  userMove.from.X = userCoordinate.X;
  userMove.from.Y = userCoordinate.Y;

  if (userMove.from.X == 0 && userMove.from.Y == 0) {
    userMove.to.X = 0;
    userMove.to.Y = 0;
    return userMove;
  }

  printf("TO: \n");
  userCoordinate = askPlayerForCoordinate(player);
  userMove.to.X = userCoordinate.X;
  userMove.to.Y = userCoordinate.Y;

  return userMove;
}

struct Coordinate askPlayerForCoordinate(int player) {
  struct Coordinate userCoordinate;
  int valid = 0;
  while (!valid) {
    if (scanf("%d %d", &userCoordinate.X, &userCoordinate.Y) != 2) {
      printf("Invalid input. Please enter two integers.\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    valid = 1;
  }
  return userCoordinate;
}
=======
#include <stdio.h>
#include "server.h"

void showBoard(struct GameState *GS) {

    int rows = GS->boardDimensions->height;
    int cols = GS->boardDimensions->width;

    printf("\n");

    for (int i = 0; i < rows; i++) {
        
        printf("%2d ", i + 1);

        for (int j = 0; j < cols; j++) {

            int val = (int)(long)GS->board[i][j];

            int fish = val / 10;
            int player = val % 10;

            if (val == 0) {
                printf(" ~~"); 
            } 
            else if (player > 0) {
                printf(" P%d", player);
            } 
            else {
                printf(" %d ", fish);
            }
        }
        printf("\n");
    }

    printf("   "); 
    for (int j = 0; j < cols; j++) {
        printf("%3d", j + 1);
    }
}

struct Move askPlayerForMove(int player) {
    struct Move userMove;
    int valid = 0;

    while (!valid) {
        printf("\nPlayer %d, enter your move.\n", player);

        printf(" Enter FROM coordinates (row col): ");
        if (scanf("%d %d", &userMove.fromX, &userMove.fromY) != 2) {
            printf(" Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        printf(" Enter TO coordinates (row col): ");
        if (scanf("%d %d", &userMove.toX, &userMove.toY) != 2) {
            printf(" Invalid input. Please enter two integers.\n");
            while (getchar() != '\n');
            continue;
        }

        valid = 1; // all good!
    }

    printf("You chose: FROM (%d,%d) → TO (%d,%d)\n",
           userMove.fromX, userMove.fromY, userMove.toX, userMove.toY);

    return move;
}
>>>>>>> 3ab2634223c0fe7ca97f30e0e0d9f3197cca9b10
