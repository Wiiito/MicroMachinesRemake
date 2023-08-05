#include <SFML/Graphics.hpp>

class Car {
 protected:
  sf::RectangleShape hitbox;

  float velocity = 0.f;
  float acceleration = 0.05f;
  float slowAcceleration = 0.025f;
  float breakAcceleration = 0.025f;

  sf::Clock accelerationClock;

  float maxVelocity = 0.5f;
  // int maxAcceleration;

 public:
  Car();
  ~Car();

  void render(sf::RenderWindow *pWindow);

  sf::Vector2f getPosition();
  sf::Vector2f getCenterPosition();
};
