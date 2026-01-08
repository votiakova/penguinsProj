#include "game.h"
#include "gameconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potentialTileValue(GameState *GS, int row, int col) {
    // this will return a value from 0 to 10 depending on the amount of fish accessible from this tile
    // the best possible scenario is that all tiles in the same row and column are unoccupied and have 3 fish
    int score = 0;
    // look up
    for (int r = row - 1; r >= 0; r--) {
        if (GS->penguinBoard[r][col] == 0 && GS->fishBoard[r][col] > 0) {
            score += GS->fishBoard[r][col];
        } else {
            break;
        }
    }
    // look down
    for (int r = row + 1; r < GS->boardDimensions->height; r++) {
        if (GS->penguinBoard[r][col] == 0 && GS->fishBoard[r][col] > 0) {
            score += GS->fishBoard[r][col];
        } else {
            break;
        }
    }
    // look left
    for (int c = col - 1; c >= 0; c--) {
        if (GS->penguinBoard[row][c] == 0 && GS->fishBoard[row][c] > 0) {
            score += GS->fishBoard[row][c];
        } else {
            break;
        }
    }
    // look right
    for (int c = col + 1; c < GS->boardDimensions->width; c++) {
        if (GS->penguinBoard[row][c] == 0 && GS->fishBoard[row][c] > 0) {
            score += GS->fishBoard[row][c];
        } else {
            break;
        }
    }
    int maxPossibleScore = 3 * (GS->boardDimensions->width + GS->boardDimensions->height - 2);
    // normalize score to be between 0 and 10
    score = (int)round(((double)score / (double)maxPossibleScore) * 10.0);
    return score;
}

Coordinate determineBestPlacement(GameState *GS) {
    // we are going to look for the tile with the most fish that is unoccupied, while taking into account the tiles that are accessible from there
    // being accessible means that there is a path of adjacent tiles (not diagonally) that are unoccupied, no matter how long the path is
    // to do that we will create a board with tile scores, then we will pick the tile with the highest score
    Coordinate bestCoord = { -1, -1 };
    int scores[GS->boardDimensions->height][GS->boardDimensions->width];

    // initialize scores to 0
    for (int row = 0; row < GS->boardDimensions->height; row++) {
        for (int col = 0; col < GS->boardDimensions->width; col++) {
            scores[row][col] = 0;
        }
    }
    // 1st pass will add the fish value of the tile to the score
    for (int row = 0; row < GS->boardDimensions->height; row++) {
        for (int col = 0; col < GS->boardDimensions->width; col++) {
            if (GS->penguinBoard[row][col] == 0 && GS->fishBoard[row][col] > 0) { // unoccupied and has fish
                scores[row][col] += GS->fishBoard[row][col] * 10;
            }
        }
    }
    // 2nd pass will add the potential score of the tile to the score
    for (int row = 0; row < GS->boardDimensions->height; row++) {
        for (int col = 0; col < GS->boardDimensions->width; col++) {
            if (GS->penguinBoard[row][col] == 0 && GS->fishBoard[row][col] > 0) { // unoccupied and has fish
                int tileScore = potentialTileValue(GS, row, col);
                scores[row][col] += tileScore;
            }
        }
    }
    // find the tile with the highest score
    int bestScore = -1;
    for (int row = 0; row < GS->boardDimensions->height; row++) {
        for (int col = 0; col < GS->boardDimensions->width; col++) {
            if (scores[row][col] > bestScore) {
                bestScore = scores[row][col];
                bestCoord.X = col;
                bestCoord.Y = row;
            }
        }
    }
    return bestCoord;
}