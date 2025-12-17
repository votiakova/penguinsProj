#include "gameconfig.h"
#include <stdio.h>


// function to print the current game config settings
void print_config(const GameConfig *cfg) {
  //checks if the pointer NULL to prevent a fault
  if (!cfg) {
    printf("Config: (null)\n");
    return; // if theres no config, then it exits the function early
  }

  printf("Game configuration:\n");

  printf("  Phase: ");
  //checks the phase in the config
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

  if (cfg->phase == PHASE_PLACEMENT) //works once we are in placement phase
    printf("  Penguins: %d\n", cfg->penguins);

  printf("  Input board file:  %s\n",
         cfg->input_file ? cfg->input_file : "(none)"); //shows "none" if pointer is null

  printf("  Output board file: %s\n",
         cfg->output_file ? cfg->output_file : "(none)");//shows "none" if pointer is null

  printf("  Show name only: %s\n", cfg->show_name ? "yes" : "no"); //shows if show_name is true or false (0 or 1)
}

int main(int argc, char *argv[]) { //this is the entry point of the program
  GameConfig gameConfig;
  parse_args(argc, argv, &gameConfig);
  print_config(&gameConfig);
}
