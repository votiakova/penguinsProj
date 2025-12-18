#include "fileio.h"
#include "game.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(const char *file_name, char *file_buffer[FILE_BUFF_SIZE]) {

  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("The file %s doesn't exist\n", file_name);
    return -1;
  }

  for (int i = 0; i < FILE_BUFF_SIZE; i++) {
    file_buffer[i] = malloc(512 * sizeof(char));
    if (file_buffer[i] == NULL) {
      printf("Memory allocation failed for file_buffer[%d]\n", i);
      fclose(fp);
      return -1;
    }
  }
  int i = 0;
  while (i < FILE_BUFF_SIZE && fgets(file_buffer[i], 512, fp) != NULL) {
    file_buffer[i][strcspn(file_buffer[i], "\n")] = '\0'; // Remove newline
    i++;
  }

  fclose(fp);
  return i;
};

int parse_file(char *file_buffer[FILE_BUFF_SIZE], int lines_read,
               GameState *GS) {
  if (lines_read < 1 || !file_buffer || !GS) {
    printf("Error: invalid input to parse_file\n");
    return -1;
  }

  // Parse board dimensions
  long m, n; // height x width
  char *line = file_buffer[0];
  char *endptr;

  errno = 0;
  m = strtol(line, &endptr, 10);
  if (errno != 0 || endptr == line || m <= 0 || m > FILE_BUFF_SIZE) {
    printf("Error: invalid board height\n");
    return -1;
  }

  errno = 0;
  while (*endptr == ' ')
    endptr++;
  n = strtol(endptr, &endptr, 10);
  if (errno != 0 || endptr == line || n <= 0 || n > 1000) {
    printf("Error: invalid board width\n");
    return -1;
  }

  GS->boardDimensions = malloc(sizeof(struct BoardDimensions));
  if (!GS->boardDimensions) {
    printf("Error: malloc failed for boardDimensions\n");
    return -1;
  }
  GS->boardDimensions->height = (int)m;
  GS->boardDimensions->width = (int)n;

  // Allocate boards
  GS->fishBoard = malloc(m * sizeof(char *));
  GS->penguinBoard = malloc(m * sizeof(char *));
  if (!GS->fishBoard || !GS->penguinBoard) {
    printf("Error: malloc failed for boards\n");
    return -1;
  }
  for (int i = 0; i < m; i++) {
    GS->fishBoard[i] = malloc(n * sizeof(char));
    GS->penguinBoard[i] = malloc(n * sizeof(char));
    if (!GS->fishBoard[i] || !GS->penguinBoard[i]) {
      printf("Error: malloc failed for board row %d\n", i);
      return -1;
    }
  }

  // Parse board lines
  if (lines_read < m + 1) {
    printf("Error: not enough lines for board\n");
    return -1;
  }

  for (int row = 0; row < m; row++) {
    line = file_buffer[row + 1];
    char *p = line;

    for (int col = 0; col < n; col++) {
      while (*p == ' ')
        p++; // skip spaces

      if (!*p) {
        printf("Error: missing board token at row %d, col %d\n", row + 1,
               col + 1);
        return -1;
      }

      if (p[0] < '0' || p[0] > '3' || p[1] < '0' || p[1] > '9') {
        printf("Error: invalid board token '%c%c' at row %d, col %d\n", p[0],
               p[1], row + 1, col + 1);
        return -1;
      }

      GS->fishBoard[row][col] = p[0] - '0';
      GS->penguinBoard[row][col] = p[1] - '0';

      p += 2; // move past this token
    }

    if (*p != '\0') {
      printf("Error: extra data at end of line %d\n", row + 1);
      return -1;
    }
  }

  // Parse players
  int first_player_line = (int)m + 1;
  int player_lines = lines_read - first_player_line;

  if (player_lines <= 0) {
    // You are the 1st player. In this case we are going to add our name to the
    // list For now we will throw an error
    printf("Error: no player data found\n");
    return -1;
  }

  GS->players = malloc(sizeof(struct Players));
  if (!GS->players) {
    printf("Error: malloc failed for players\n");
    return -1;
  }

  GS->players->amountOfPlayers = player_lines;
  GS->players->currentPlayer = 0;
  GS->players->playerScores = malloc(player_lines * sizeof(int));
  GS->players->playerNames = malloc(player_lines * sizeof(char *));
  if (!GS->players->playerScores || !GS->players->playerNames) {
    printf("Error: malloc failed for player arrays\n");
    return -1;
  }

  for (int i = 0; i < player_lines; i++) {
    line = file_buffer[first_player_line + i];
    char *p = line;
    char name[256];

    // Parse team name
    while (*p == ' ')
      p++;
    int name_len = 0;
    while (*p != ' ' && *p != '\0' && name_len < 255) {
      name[name_len++] = *p++;
    }
    name[name_len] = '\0';
    if (name_len == 0) {
      printf("Error: missing player name on line %d\n",
             first_player_line + i + 1);
      return -1;
    }

    // Parse team ID (ignored)
    while (*p == ' ')
      p++;
    errno = 0;
    long id = strtol(p, &endptr, 10);
    if (errno != 0 || endptr == p || id < 0 || id > INT_MAX) {
      printf("Error: invalid player ID on line %d\n",
             first_player_line + i + 1);
      return -1;
    }
    p = endptr;

    // Parse player score
    while (*p == ' ')
      p++;
    errno = 0;
    long score = strtol(p, &endptr, 10);
    if (errno != 0 || endptr == p || score < 0 || score > INT_MAX) {
      printf("Error: invalid player score on line %d\n",
             first_player_line + i + 1);
      return -1;
    }
    p = endptr;

    // Ensure no extra data
    while (*p == ' ')
      p++;
    if (*p != '\0') {
      printf("Error: trailing data on line %d\n", first_player_line + i + 1);
      return -1;
    }

    // Store player
    GS->players->playerScores[i] = (int)score;
    GS->players->playerNames[i] = malloc(strlen(name) + 1);
    if (!GS->players->playerNames[i]) {
      printf("Error: malloc failed for player name\n");
      return -1;
    }
    strcpy(GS->players->playerNames[i], name);
  }

  return 0;
}

int create_file(const char *file_name, GameState *GS) {
  // Validate input pointers
  if (!file_name || !GS || !GS->boardDimensions || !GS->fishBoard ||
      !GS->penguinBoard || !GS->players) {
    printf("Error: invalid GameState or file name\n");
    return -1;
  }

  // Open the file for writing
  FILE *fp = fopen(file_name, "w");
  if (!fp) {
    perror("Error opening file for writing");
    return -1;
  }

  int m = GS->boardDimensions->height;
  int n = GS->boardDimensions->width;

  // Write board dimensions
  if (fprintf(fp, "%d %d\n", m, n) < 0) {
    perror("Error writing board dimensions");
    fclose(fp);
    return -1;
  }

  // Write board data
  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      // Each token is two digits: fish then penguin id
      if (fprintf(fp, "%d%d", GS->fishBoard[row][col],
                  GS->penguinBoard[row][col]) < 0) {
        perror("Error writing board token");
        fclose(fp);
        return -1;
      }
      if (col < n - 1)
        fputc(' ', fp);
    }
    fputc('\n', fp);
  }

  // Write player data
  for (int i = 0; i < GS->players->amountOfPlayers; i++) {
    const char *name = GS->players->playerNames[i];
    int team_id = i + 1; // Use list index as team ID
    int score = GS->players->playerScores[i];

    if (fprintf(fp, "%s %d %d\n", name, team_id, score) < 0) {
      perror("Error writing player data");
      fclose(fp);
      return -1;
    }
  }

  fclose(fp);
  return 0;
}
