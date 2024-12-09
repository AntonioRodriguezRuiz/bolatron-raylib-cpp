#include "ball.h"

Ball::Ball(Vector2 startPos, Vector2 accel, Vector2 startVel, Vector2 maxSpeed,
           float rad, Color col)
    : position(startPos), accel(accel), velocity(startVel), radius(rad),
      color(col), maxSpeed(maxSpeed) {
  for (int i = 0; i < MAX_BULLETS; i++) {
    bullets[i] = Bullet({0, 0}, {0, 0}, 10.0f, RED);
  }
}

void Ball::Update() {
  if (IsKeyDown(KEY_D) && velocity.x < maxSpeed.x)
    velocity.x += accel.x;
  else if (IsKeyDown(KEY_A) && velocity.x > -maxSpeed.x)
    velocity.x -= accel.x;
  else if (velocity.x < 0.0f)
    velocity.x += accel.x;
  else if (velocity.x > 0.0f)
    velocity.x -= accel.x;
  if (IsKeyDown(KEY_W) && velocity.y > -maxSpeed.y)
    velocity.y -= accel.y;
  else if (IsKeyDown(KEY_S) && velocity.y < maxSpeed.y)
    velocity.y += accel.y;
  else if (velocity.y < 0.0f)
    velocity.y += accel.y;
  else if (velocity.y > 0.0f)
    velocity.y -= accel.y;

  position = Vector2Add(position, velocity);

  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();

  // Check for collisions with screen edges and wrap around
  if (position.x <= 0) {
    position.x = screenWidth;
  } else if (position.x >= screenWidth) {
    position.x = 0;
  }
  if (position.y <= 0) {
    position.y = screenHeight;
  } else if (position.y >= screenHeight) {
    position.y = 0;
  }

  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    if (cooldown <= 0.0f) {
      Shoot();
      cooldown = COOLDOWN_TIME;
    }
  }

  if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) || Ball::readyBullets() == 0) {
    cooldown = RELOAD_TIME;
    for (int i = 0; i < MAX_BULLETS; i++) {
      bullets[i].Reload();
    }
    PlaySound(LoadSound("resources/sounds/reload.wav"));
  }

  for (int i = 0; i < MAX_BULLETS; i++) {
    bullets[i].Update();
  }
  cooldown -= GetFrameTime();
}

/* Shoots the ball in a given direction
 * @param direction: The direction to shoot the ball
 */
void Ball::Shoot() {
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (!bullets[i].IsActive() && bullets[i].IsReady()) {
      Vector2 mousePos = GetMousePosition();
      Vector2 direction = {mousePos.x - position.x, mousePos.y - position.y};
      direction = Vector2Normalize(direction); // Between 0 and 1
      direction = Vector2Scale(direction, 20); // Scale to 10 units
      bullets[i].Activate(position, direction);

      // Sound
      PlaySound(LoadSound("resources/sounds/shot.wav"));
      break; // Only activate one bullet
    }
  }
}

std::vector<Bullet> Ball::getActiveBullets() const {
  std::vector<Bullet> activeBullets;
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bullets[i].IsActive()) {
      activeBullets.push_back(bullets[i]);
    }
  }
  return activeBullets;
}

int Ball::readyBullets() const {
  int count = 0;
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bullets[i].IsReady()) {
      count++;
    }
  }
  return count;
}

void Ball::Draw() const {
  DrawCircleV(position, radius, color);

  for (int i = 0; i < MAX_BULLETS; i++) {
    bullets[i].Draw();
  }
}
