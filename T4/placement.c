#include "client.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void placementPhase(struct GameState *GS) {
  int penguinUserInput;
  printf("How many penguins per player?:\n");
  scanf("%d", &penguinUserInput);
  int amountOfPenguinsToPlace =
      penguinUserInput * 2; // *2 because we have two players
  while (amountOfPenguinsToPlace > 0) {
    showBoard(GS);
    struct Coordinate coordinate;
    printf("Player %d, where do you want to place your penguin (X Y)\n",
           GS->players->current + 1);
    coordinate = askPlayerForCoordinate(GS->players->current);

    char *selectedTile = &GS->board[coordinate.Y - 1][coordinate.X - 1];
    int score = *selectedTile - '0';
    if (GS->players->current == 0) {
      GS->players->player0Score += score;
      *selectedTile = GS->players->player0Icon;
    } else if (GS->players->current == 1) {
      GS->players->player1Score += score;
      *selectedTile = GS->players->player1Icon;
    }

    swapPlayers(GS);

    amountOfPenguinsToPlace--;
  }
}
