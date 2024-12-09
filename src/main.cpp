#include "scene/scene.h"

int main() {
  const Color darkGreen = {20, 160, 133, 255};

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 600;

  InitWindow(screenWidth, screenHeight,
             "Stupid simple shooter game (Bolatron 64)");
  InitAudioDevice();
  SetTargetFPS(60);

  Scene scene = Scene();

  Music background = LoadMusicStream("resources/sounds/background.mp3");
  PlayMusicStream(background);
  float timePlayed = 0.0f;

  // Main game loop
  while (!WindowShouldClose()) {
    while (scene.getGameStatus() == PLAYING) {
    game:
      UpdateMusicStream(background);

      timePlayed =
          GetMusicTimePlayed(background) / GetMusicTimeLength(background);
      if (timePlayed >= 0.95f) {
        StopMusicStream(background);
        PlayMusicStream(background);
      }

      scene.Update();

      BeginDrawing();
      ClearBackground(darkGreen);
      scene.Draw();
      EndDrawing();
    }

    StopMusicStream(background);
    BeginDrawing();
    ClearBackground(darkGreen);
    DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 40) / 2,
             screenHeight / 2 - 20, 40, RAYWHITE);
    DrawText("Press [SPACE] to play again", screenWidth / 2 - 150,
             screenHeight / 2 + 20, 20, RAYWHITE);
    DrawText(TextFormat("Score: %i", scene.getScore()), 10, 10, 20, RAYWHITE);
    DrawText(TextFormat("Max Score: %i", scene.getMaxScore()), 10, 40, 20,
             RAYWHITE);
    EndDrawing();
    if (IsKeyPressed(KEY_SPACE)) {
      scene.Reset();
      PlayMusicStream(background);
      goto game;
    }
  }

  UnloadMusicStream(background);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
