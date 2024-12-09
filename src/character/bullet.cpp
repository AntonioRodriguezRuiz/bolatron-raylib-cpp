#include "bullet.h"

Bullet::Bullet(Vector2 startPos, Vector2 startVel, float rad, Color col)
    : position(startPos), velocity(startVel), radius(rad), color(col) {}

Bullet::Bullet()
    : position({0, 0}), velocity({0, 0}), radius(5.0f), color(BLACK),
      active(false), ready(true) {}

void Bullet::Update() {
  if (active) {
    position.x += velocity.x;
    position.y += velocity.y;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    if (position.x - radius <= 0 || position.x + radius >= screenWidth ||
        position.y - radius <= 0 || position.y + radius >= screenHeight) {
      active = false;
    }
  }
}

void Bullet::Draw() const {
  if (active)
    DrawCircleV(position, radius, color);
}

void Bullet::Activate(Vector2 pos, Vector2 vel) {
  position = pos;
  velocity = vel;
  active = true;
  ready = false;
}

void Bullet::Deactivate() { active = false; }

void Bullet::Reload() { ready = true; }

bool Bullet::IsActive() const { return active; }
bool Bullet::IsReady() const { return ready; }
