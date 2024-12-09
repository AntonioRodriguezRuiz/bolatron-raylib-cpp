#include <raylib.h>
#include <raymath.h>

class Enemy {
private:
  Vector2 position;
  Vector2 velocity;
  float radius;
  Color color;
  bool active = false;

public:
  Enemy(Vector2 startPos, Vector2 startVel, float rad, Color col);
  Enemy();

  void Update(Vector2 playerPos);
  void Draw() const;
  void Activate();
  void Deactivate();
  Vector2 getPosition() const { return position; }
  float getRadius() const { return radius; }
  bool IsActive() const;
};
