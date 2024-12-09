#include "bullet.h"
#include <bits/stdc++.h>
#include <raylib.h>
#include <raymath.h>

class Ball {
private:
  Vector2 position; // Ball position
  Vector2 accel;
  Vector2 velocity; // Ball velocity
  Vector2 maxSpeed;
  float cooldown = 0.0f;
  float radius; // Ball radius
  Color color;  // Ball color

  static const int MAX_BULLETS = 20;           // Maximum bullets on screen
  static constexpr float COOLDOWN_TIME = 0.2f; // Tick cooldown
  static constexpr float RELOAD_TIME = 1.0f;   // Tick cooldown
  Bullet bullets[MAX_BULLETS];                 // Array of bullets
public:
  Ball(Vector2 startPos, Vector2 accel, Vector2 startVel, Vector2 maxSpeed,
       float rad, Color col);

  Vector2 getPosition() const { return position; }
  float getRadius() const { return radius; }

  void Update();
  void Draw() const;
  void Shoot();
  void Reload();
  int readyBullets() const;
  std::vector<Bullet> getActiveBullets() const;
};
