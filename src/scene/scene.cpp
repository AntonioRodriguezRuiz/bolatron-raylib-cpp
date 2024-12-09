#include "scene.h"

Scene::Scene()
    : ball({width / 2.0f, height / 2.0f}, {1.0f, 1.0f}, {0.0f, 0.0f},
           {15.0f, 15.0f}, 20.0f, RED) {}

void Scene::Reset() {
  score = 0;
  enemySpawnTimer = 0;
  gameStatus = PLAYING;
  ball = Ball({width / 2.0f, height / 2.0f}, {1.0f, 1.0f}, {0.0f, 0.0f},
              {15.0f, 15.0f}, 20.0f, RED);
  enemies.clear();
  timePlayed = 0.0f;
}

/* Rertuns the maximum number of enemies that can be on screen at once
 * This value depends on the time played and grows logarithmically
 * */
int Scene::GetMaxEnemies() const {
  return std::min(int(1 + log10(timePlayed + 1) * 2), 10);
}

float TimeToSpawn(int timePlayed) {
  return std::min(float(60.0f / timePlayed * 5), 120.0f);
}

void Scene::Update() {
  int MAX_ENEMIES = GetMaxEnemies();

  ball.Update();

  enemySpawnTimer++;
  if (enemySpawnTimer >= TimeToSpawn(timePlayed)) {
    if (enemies.size() < MAX_ENEMIES) {
      enemySpawnTimer = 0;
      Enemy newEnemy = Enemy();
      newEnemy.Activate();
      enemies.push_back(newEnemy);
    }
  }

  for (int i = 0; i < enemies.size(); i++) {
    enemies[i].Update(ball.getPosition());
  }

  // Now we check for collisions. First bullets with enemies, then enemies with
  // ball
  for (int i = 0; i < enemies.size(); i++) {
    if (enemies[i].IsActive()) {
      for (int j = 0; j < ball.getActiveBullets().size(); j++) {
        if (CheckCollisionCircles(
                enemies[i].getPosition(), enemies[i].getRadius(), // Enemy
                ball.getActiveBullets()[j].getPosition(),
                ball.getActiveBullets()[j].getRadius())) // Bullet
        {
          enemies[i].Deactivate();
          enemies.erase(enemies.begin() + i);
          score++;
          break;
        }
      }
      if (CheckCollisionCircles(enemies[i].getPosition(),
                                enemies[i].getRadius(), ball.getPosition(),
                                ball.getRadius())) {
        gameStatus = GAME_OVER;
        maxScore = std::max(score, maxScore);
        break;
      }
    }
  }

  timePlayed += GetFrameTime();
}

void Scene::Draw() const {
  ball.Draw();

  int readyBullets = ball.readyBullets();
  DrawText(TextFormat("Score: %d", score), 10, 10, 20, RAYWHITE);
  DrawText(TextFormat("Max Score: %i", maxScore), 10, 40, 20, RAYWHITE);
  DrawText(TextFormat("Bullets: %d", readyBullets), GetScreenWidth() - 120, 10,
           20, RAYWHITE);

  // Draw a timer
  DrawText(TextFormat("%.2f", timePlayed), GetScreenWidth() / 2 - 30, 30, 40,
           RAYWHITE);

  for (int i = 0; i < enemies.size(); i++) {
    enemies[i].Draw();
  }
}
