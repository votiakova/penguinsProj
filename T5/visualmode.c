#include "game.h"
#include "gameconfig.h"
#include "raylib.h"
#include "visualmode.h"
#include <stdio.h>

int visual_mode(GameState *GS, GameConfig *GC) {
  const int width = 1200;
  const int height = 800;
  InitWindow(width, height, "Penguing Game Visual Mode");
  SetTargetFPS(60);
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    {
      ClearBackground(BG_COLOR);
    }
    EndDrawing();
  }
  CloseWindow();
  printf("Visual Mode\n");
  return 0;
}
