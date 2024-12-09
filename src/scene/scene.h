#include "../character/ball.h"
#include "../enemies/enemy.h"
#include <bits/stdc++.h>
#include <raylib.h>

enum status { INIT, PLAYING, GAME_OVER };

class Scene {
private:
  int width = GetScreenWidth();
  int height = GetScreenHeight();
  Ball ball;
  int score = 0;
  int maxScore = 0;
  int enemySpawnTimer = 0;
  status gameStatus = PLAYING;

  float timePlayed = 0.0f;

  std::vector<Enemy> enemies;

public:
  Scene();

  int GetMaxEnemies() const;

  void Update();
  void Draw() const;
  void Reset();
  status getGameStatus() const { return gameStatus; }
  int getScore() const { return score; }
  int getMaxScore() const { return maxScore; }
};
