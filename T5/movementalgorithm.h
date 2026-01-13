#ifndef MOVEMENTALGORITHM_H
#define MOVEMENTALGORITHM_H
#include "game.h"

Move determineBestMove(GameState *GS, GameConfig cfg, int ourPlayerId);

Move findBestScoreFromTile(
    GameState *GS,
    int scores[GS->boardDimensions->height][GS->boardDimensions->width],
    int row, int col);

#endif
