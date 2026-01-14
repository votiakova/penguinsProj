#ifndef PLACEMENTALGORITHM_H
#define PLACEMENTALGORITHM_H

#include "game.h"
int potentialTileValue(GameState *GS, int row, int col);
Coordinate determineBestPlacement(GameState *GS);

#endif // PLACEMENTALGORITHM_H
