//
// Created by Chilled on 18/11/2025.
//

#ifndef SERVER_H
#define SERVER_H
struct Players {
    int current;
    int next;
};

struct BoardDimensions {
    int width;
    int height;
};

void swapPlayers(struct Players *players);

int canPlayerMovePenguin(int player);

int calculateWinner();

int isMoveValid(int move);

void movePenguin(int player, int move);

void collectFish();

int wereAllPenguinsPlaced();

#endif //SERVER_H
