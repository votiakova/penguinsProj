#include "gameconfig.h"
#include <stdio.h>

void print_config(const GameConfig *cfg) {
  if (!cfg) {
    printf("Config: (null)\n");
    return;
  }

  printf("Game configuration:\n");

  printf("  Phase: ");
  switch (cfg->phase) {
  case PHASE_PLACEMENT:
    printf("placement\n");
    break;
  case PHASE_MOVEMENT:
    printf("movement\n");
    break;
  default:
    printf("not set\n");
    break;
  }

  if (cfg->phase == PHASE_PLACEMENT)
    printf("  Penguins: %d\n", cfg->penguins);

  printf("  Input board file:  %s\n",
         cfg->input_file ? cfg->input_file : "(none)");

  printf("  Output board file: %s\n",
         cfg->output_file ? cfg->output_file : "(none)");

  printf("  Show name only: %s\n", cfg->show_name ? "yes" : "no");
}

int main(int argc, char *argv[]) {
  GameConfig gameConfig;
  parse_args(argc, argv, &gameConfig);
  print_config(&gameConfig);
}
