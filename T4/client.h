
#ifndef CLIENT_H
#define CLIENT_H

/*
 * Asks the user for the board dimensions, and returns them as an array of ints
 */

int *askForBoardDimensions();

/*
 * Displays the board to the user
 */
void showBoard();

/*
 * Asks the user to input a move, and returns a move Struct (To be implemented)
 * @param player, the number of the player (either 0 or 1)
 */
struct Move askPlayerForMove(int player);
#endif // CLIENT_H
