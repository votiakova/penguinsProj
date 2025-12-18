#include "fileio.h"
#include "game.h"
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
  GameState gameState;
  GameConfig gameConfig;
  parse_args(argc, argv, &gameConfig);

  // COMMENT OUT TO AVOID CONSOLE OUTPUT
  print_config(&gameConfig);

  if (gameConfig.show_name) {
    printf("very_original_team_name");
    return 0;
  }

  char *fb[512];
  int lines_read;
  lines_read = read_file(gameConfig.input_file, fb);
  if (lines_read > 0) {
    if (parse_file(fb, lines_read, &gameState) != 0) {
      printf("Failed to parse input file\n");
      return 2;
    }
  } else {
    printf("Failed to read input file\n");
    return 3;
  }

  if (create_file(gameConfig.output_file, &gameState) != 0) {
    printf("Failed to write output file\n");
    return 3;
  }
  return 0;
}
