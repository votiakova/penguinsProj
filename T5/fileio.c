#include "fileio.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int read_file(char *file_name, char *file_buffer[FILE_BUFF_SIZE]) {
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("The file %s doesen't exist\n", file_name);
    return -1;
  }

  fgets(*file_buffer, sizeof(*file_buffer), fp);
  return 0;
};

int parse_file(char *file_biffer[FILE_BUFF_SIZE], GameState *GS);
