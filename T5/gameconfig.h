#ifndef GAMECONFIG_H
#define GAMECONFIG_H

typedef enum { PHASE_NONE, PHASE_PLACEMENT, PHASE_MOVEMENT } Phase;

/**
 * Struct that holds the command line parameters provided on runtime
 */
typedef struct {
  /**
   * Enum containing the game phase (PHASE_NONE, PHASE_PLACEMENT,
   * PHASE_MOVEMENT)
   */
  Phase phase;
  /**
   * Amount of penguins each player gets to place (only applicable during
   * movement phase)
   */
  int penguins;

  const char *input_file;
  const char *output_file;
  int show_name;
  int visual_mode;
} GameConfig;

/**
 * Parses the command line arguments provided and puts them into the GameConfig
 * struct
 * @param argc argc from the main function
 * @param argv argv from the main function
 * @param cfg a pointer to the GameConfig struct that is going to be filled
 */
int parse_args(int argc, char *argv[], GameConfig *cfg);

#endif
