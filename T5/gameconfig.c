#include "gameconfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int starts_with(const char *s, const char *prefix) {
  return strncmp(s, prefix, strlen(prefix)) == 0;
}

void init_config(GameConfig *cfg) {
  cfg->phase = PHASE_NONE;
  cfg->penguins = -1;
  cfg->input_file = NULL;
  cfg->output_file = NULL;
  cfg->show_name = 0;
}

int parse_args(int argc, char *argv[], GameConfig *cfg) {
  init_config(cfg);

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "name") == 0) {
      cfg->show_name = 1;
      return 0;
    }
    if (starts_with(argv[i], "phase=")) {
      const char *value = argv[i] + 6;
      if (strcmp(value, "placement") == 0)
        cfg->phase = PHASE_PLACEMENT;
      else if (strcmp(value, "movement") == 0)
        cfg->phase = PHASE_MOVEMENT;
      else
        return -1;
    } else if (starts_with(argv[i], "penguins=")) {
      cfg->penguins = atoi(argv[i] + 9);
    } else {
      // positional arguments (files)
      if (!cfg->input_file)
        cfg->input_file = argv[i];
      else if (!cfg->output_file)
        cfg->output_file = argv[i];
      else
        return -1;
    }
  }
  return 0;
};
