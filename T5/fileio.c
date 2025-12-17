#include "fileio.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int read_file(char *file_name, char *file_buffer[FILE_BUFF_SIZE]) {
  FILE *fp = fopen(file_name, "r"); // Open the file for readin
  if (fp == NULL) { // If fopen failed, the file probably doesn't exist or can't be opened
    printf("The file %s doesen't exist\n", file_name);
    return -1; // Read one line from the file into the buffer
  }

  fgets(*file_buffer, sizeof(*file_buffer), fp);
  return 0; // If everything went fine, return 0
};

int parse_file(char *file_biffer[FILE_BUFF_SIZE], GameState *GS); // Takes file contents and fills the game state based on it
