#include <raylib.h>

class Bullet {
private:
  Vector2 position; // Ball position
  Vector2 velocity; // Ball velocity
  float radius;     // Ball radius
  Color color;      // Ball color
  bool active = false;
  bool ready = true;

public:
  Bullet(Vector2 startPos, Vector2 startVel, float rad, Color col);
  Bullet();

  void Update();
  void Draw() const;
  void Activate(Vector2 pos, Vector2 vel);
  void Deactivate();
  void Reload();
  bool IsActive() const;
  Vector2 getPosition() const { return position; }
  float getRadius() const { return radius; }
  bool IsReady() const;
};
