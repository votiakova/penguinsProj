#include "server.h"
#include <stdio.h>
#include <stdlib.h>

char **createBoard(struct GameState *GS) {
  int height = GS->boardDimensions->height;
  int width = GS->boardDimensions->width;

  char **board = malloc(height * sizeof(char *));
  if (!board)
    return NULL;

  for (int i = 0; i < height; i++) {
    board[i] = malloc(width * sizeof(char));
    if (!board[i]) {
      // cleanup on failure
      for (int j = 0; j < i; j++)
        free(board[j]);
      free(board);
      return NULL;
    }

    for (int j = 0; j < width; j++) {
      board[i][j] = '.';
    }
  }

  return board;
}

void populateBoard(struct GameState *GS) {
  int width = GS->boardDimensions->width;
  int height = GS->boardDimensions->height;
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      int r = rand() % 100; // random number from 0 to 99

      if (r < 60) {
        GS->board[row][col] = '1'; // 60%
      } else if (r < 90) {
        GS->board[row][col] = '2'; // 30%
      } else {
        GS->board[row][col] = '3'; // 10%
      }
    }
  }
}

void swapPlayers(struct GameState *GS) {
  int temp = GS->players->next;
  GS->players->next = GS->players->current;
  GS->players->current = temp;
};

int canPlayerMovePenguin(const int player) { return 1; }

int calculateWinner() {
  printf("Calculating the winner\n");
  return rand() % 2;
}

int isMoveValid(struct GameState *GS, struct Move *move) { return 1; }

void movePenguin(struct GameState *GS, struct Move *move) {
  // am going to add error cheking later
  char *fromTile = &GS->board[move->from.Y - 1][move->from.X - 1];
  char *toTile = &GS->board[move->to.Y - 1][move->to.X - 1];

  int score = *toTile - '0';
  *toTile = *fromTile;
  *fromTile = ' ';
  if (GS->players->current == 0) {
    GS->players->player0Score += score;
  } else if (GS->players->current == 1) {
    GS->players->player1Score += score;
  }
}

void collectFish() {}

int random_seed = 42; // its going to be random later
// int random_seed = time(NULL);
