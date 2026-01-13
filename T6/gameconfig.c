#include "gameconfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int starts_with(const char *s, const char *prefix) {
  return strncmp(s, prefix, strlen(prefix)) == 0;
}
// sets all the config fields in the structure
void init_config(GameConfig *cfg) {
  cfg->phase = PHASE_NONE; // no phase yet
  cfg->penguins = -1;      // indicates value hasnt been set yet
  cfg->input_file = NULL;  // not assigned
  cfg->output_file = NULL; // not assigned
  cfg->show_name = 0;      // defaulted to no for name showing
  cfg->visual_mode = 0;
}

int parse_args(int argc, char *argv[], GameConfig *cfg) {
  init_config(cfg);

  // Loop through all arguments starting at index 1
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "name") == 0) {
      cfg->show_name = 1;
      return 0;
    }
    if (strcmp(argv[i], "vis") == 0) {
      cfg->visual_mode = 1;
    }
    if (starts_with(argv[i], "phase=")) {
      const char *value =
          argv[i] +
          6; // moves pointer forward by 6 spots to get the value after =
      if (strcmp(value, "placement") == 0)
        cfg->phase = PHASE_PLACEMENT;
      else if (strcmp(value, "movement") == 0)
        cfg->phase = PHASE_MOVEMENT;
      else
        return -1; // means the program would return an error
    } else if (starts_with(argv[i], "penguins=")) {
      cfg->penguins = atoi(argv[i] + 9); // moves pointer forward by 9 spots
    } else {
      // positional arguments (files)
      if (!cfg->input_file)
        cfg->input_file = argv[i];
      else if (!cfg->output_file)
        cfg->output_file = argv[i];
      else
        return -1; // means the program would return an error
    }
  }
  return 0; // ran successfully
};
