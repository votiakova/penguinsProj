#include "game.h"
#include "gameconfig.h"
#include "movementalgorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Move findBestScoreFromTile(GameState *GS, int scores[GS->boardDimensions->height][GS->boardDimensions->width], int row, int col) {
    // this will output the best score accessible from the tile at (row, col)
    int bestScore = 0;
    Move bestMove;
    bestMove.from.X = col;
    bestMove.from.Y = row;
    bestMove.to.X = -1;
    bestMove.to.Y = -1;
    // look up
    for (int r = row - 1; r >= 0; r--) {
        if (GS->penguinBoard[r][col] == 0 && GS->fishBoard[r][col] > 0) {
            if (scores[r][col] > bestScore) {
                bestScore = scores[r][col];
                bestMove.to.X = col;
                bestMove.to.Y = r;
            }
        } else {
            break;
        }
    }
    // look down
    for (int r = row + 1; r < GS->boardDimensions->height; r++) {
        if (GS->penguinBoard[r][col] == 0 && GS->fishBoard[r][col] > 0) {
            if (scores[r][col] > bestScore) {
                bestScore = scores[r][col];
                bestMove.to.X = col;
                bestMove.to.Y = r;
            }
        } else {
            break;
        }
    }
    // look left
    for (int c = col - 1; c >= 0; c--) {
        if (GS->penguinBoard[row][c] == 0 && GS->fishBoard[row][c] > 0) {
            if (scores[row][c] > bestScore) {
                bestScore = scores[row][c];
                bestMove.to.X = c;
                bestMove.to.Y = row;
            }
        } else {
            break;
        }
    }
    // look right
    for (int c = col + 1; c < GS->boardDimensions->width; c++) {
        if (GS->penguinBoard[row][c] == 0 && GS->fishBoard[row][c] > 0) {
            if (scores[row][c] > bestScore) {
                bestScore = scores[row][c];
                bestMove.to.X = c;
                bestMove.to.Y = row;
            }
        } else {
            break;
        }
    }
    return bestMove;
}

Move determineBestMove(GameState *GS, GameConfig cfg, int ourPlayerId) {
    // to determine the best move we will do something similar to the placement algorithm
    // we will create a score for each tile on the map
    Move bestMove;
    bestMove.from.X = -1;
    bestMove.from.Y = -1;
    bestMove.to.X = -1;
    bestMove.to.Y = -1;

    int scores[GS->boardDimensions->height][GS->boardDimensions->width];
    printf("got here 1\n");

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
                printf("got here 2 (%d,%d)\n", row, col);
                int tileScore = potentialTileValue(GS, row, col);
                printf("got here 3 (%d,%d) tileScore=%d\n", row, col, tileScore);
                scores[row][col] += tileScore;
            }
        }
    }

    print2DIntArray(GS->boardDimensions->height, GS->boardDimensions->width, scores);
    // now we look for our penguins and see which one can make the best move
    int bestOverallScore = -1;
    for (int row = 0; row < GS->boardDimensions->height; row++) {
        for (int col = 0; col < GS->boardDimensions->width; col++) {
            if (GS->penguinBoard[row][col] == ourPlayerId) {
                // this is one of our penguins, see what is the best score it can reach
                Move moveFromThisTile = findBestScoreFromTile(GS, scores, row, col);
                if (moveFromThisTile.to.X != -1 && moveFromThisTile.to.Y != -1) {
                    int moveScore = scores[moveFromThisTile.to.Y][moveFromThisTile.to.X];
                    if (moveScore > bestOverallScore) {
                        bestOverallScore = moveScore;
                        bestMove = moveFromThisTile;
                    }
                }
            }
        }
    }
    return bestMove;

}