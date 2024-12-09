#include "enemy.h"

Enemy::Enemy(Vector2 startPos, Vector2 startVel, float rad, Color col)
    : position(startPos), velocity(startVel), radius(rad), color(col),
      active(false) {}

Enemy::Enemy()
    : position({0, 0}), velocity({0.0f, 0.0f}), radius(10.0f), color(BLACK),
      active(false) {}

void Enemy::Update(Vector2 playerPos) {
  if (active) {
    Vector2 direction = Vector2Subtract(playerPos, position);
    direction = Vector2Normalize(direction); // Between 0 and 1
    velocity = Vector2Scale(direction, 5);   // Scale to 10 units

    position = Vector2Add(position, velocity);
  }
}

void Enemy::Draw() const {
  if (active)
    DrawCircleV(position, radius, color);
}

void Enemy::Activate() {
  // random appearance from the top, right, bottom, or left
  int random = GetRandomValue(0, 3);
  switch (random) {
  case 0:
    position = {0, float(GetRandomValue(0, GetScreenHeight()))};
    break;
  case 1:
    position = {float(GetRandomValue(0, GetScreenWidth())), 0};
    break;
  case 2:
    position = {float(GetScreenWidth()),
                float(GetRandomValue(0, GetScreenHeight()))};
    break;
  case 3:
    position = {float(GetRandomValue(0, GetScreenWidth())),
                float(GetScreenHeight())};
    break;
  }
  active = true;
}

void Enemy::Deactivate() { active = false; }

bool Enemy::IsActive() const { return active; }
