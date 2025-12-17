#ifndef GAMECONFIG_H
#define GAMECONFIG_H

typedef enum { PHASE_NONE, PHASE_PLACEMENT, PHASE_MOVEMENT } Phase;

typedef struct {
  Phase phase;
  int penguins;
  const char *input_file;
  const char *output_file;
  int show_name;
} GameConfig;

int parse_args(int argc, char *argv[], GameConfig *cfg);

#endif
