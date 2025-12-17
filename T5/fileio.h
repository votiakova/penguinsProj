#ifndef FILEIO_H
#define FILEIO_H

#define FILE_BUFF_SIZE 512
#include "game.h"

/**
 * Reads the file contents into the buffer
 * @returns the amount of lines read from the file or -1 if it fails
 * @param file_name the string containing the path to the file
 * @param file_buffer buffer to which we are going to write the file contents
 */
int read_file(const char *file_name, char *file_buffer[FILE_BUFF_SIZE]);

/**
 * Parses the buffer created by read_file and puts it in the GameState struct
 * @returns 0 or -1 if it fails
 * @param file_buffer the buffer containing the file contents
 * @param lines_read the amount of lines we read from the file (the amount of filled slots in the buffer)
 * @param GS a pointer to the GameState struct that is going to be filled
 */
int parse_file(char *file_buffer[FILE_BUFF_SIZE], int lines_read, GameState *GS);

/**
 * Creates the output filed based on the current game state
 * @returns 0 or -1 if it fails
 * @param file_name a string containing the path to the file
 * @param GS a pointer to the GameState struct
 */
int create_file(const char *file_name, GameState *GS);

#endif
