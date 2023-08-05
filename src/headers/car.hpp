#include <SFML/Graphics.hpp>
#include <cmath>

class Car {
 protected:
  sf::RectangleShape hitbox;

  float velocity = 0.f;

  float xVelocity;
  float yVelocity;

  float rotation;

  float acceleration = 0.05f;

  float slowAcceleration = 0.025f;
  float breakAcceleration = 0.035f;

  sf::Clock accelerationClock;

  float maxVelocity = 0.25f;
  // int maxAcceleration;

 public:
  Car();
  ~Car();

  void render(sf::RenderWindow *pWindow);

  sf::Vector2f getPosition();
  sf::Vector2f getCenterPosition();
};
