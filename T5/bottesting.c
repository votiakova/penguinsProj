#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *fp = fopen("tests.txt", "r");
  if (NULL == fp) {
    puts("Invalid file \n");
  }

  char *code1 = "./penguing.out";
  char *code2 = "./penguing.out";
  char *placement_variables = "phase=placement penguins=3 tests.txt tests.txt";
  char *movement_variables = "phase=movement tests.txt tests.txt";

  int out1, out2;
  char *placement1, *placement2;
  placement1 = malloc(128 * sizeof(char));
  placement2 = malloc(128 * sizeof(char));
  memcpy(placement1, code1, strlen(code1));
  memcpy(placement1 + strlen(code1), " ", 1);
  memcpy(placement1 + strlen(code1) + 1, placement_variables,
         strlen(placement_variables));
  memcpy(placement2, code2, strlen(code2));
  memcpy(placement2 + strlen(code2), " ", 1);
  memcpy(placement2 + strlen(code2) + 1, placement_variables,
         strlen(placement_variables));
  char *movement1, *movement2;
  movement1 = malloc(128 * sizeof(char));
  movement2 = malloc(128 * sizeof(char));
  memcpy(movement1, code1, strlen(code1));
  memcpy(movement1 + strlen(code1), " ", 1);
  memcpy(movement1 + strlen(code1) + 1, movement_variables,
         strlen(movement_variables));
  memcpy(movement2, code2, strlen(code2));
  memcpy(movement2 + strlen(code2), " ", 1);
  memcpy(movement2 + strlen(code2) + 1, movement_variables,
         strlen(movement_variables));
  while (1) {
    out1 = system(placement1);
    out2 = system(placement2);
    if (out1 == 1 || out2 == 1)
      break;
  }
  while (1) {
    out1 = system(movement1);
    out2 = system(movement2);
    if (out1 == 1 || out2 == 1)
      break;
  }
}
