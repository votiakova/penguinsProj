//main point of this file is to define blueprint of our data structuers and to tell the program what functions exist

#ifndef GAMECONFIG_H
#define GAMECONFIG_H

typedef enum { PHASE_NONE, PHASE_PLACEMENT, PHASE_MOVEMENT } Phase;


//structure "GameConfig" which groups all these settings together
typedef struct {
  Phase phase; //stores current phase of the game
  int penguins; //stores the number of penguins
  const char *input_file; //a pointer to a string for the input file name
  const char *output_file; //a pointer to a string for the output file name
  int show_name; //determines whether the name is shown
} GameConfig;

int parse_args(int argc, char *argv[], GameConfig *cfg);

#endif
