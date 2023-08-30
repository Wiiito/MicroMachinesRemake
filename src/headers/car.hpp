#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "engine.hpp"
#include "map.hpp"

class Car {
 protected:
  sf::RectangleShape hitbox;
  sf::RectangleShape lWheel;
  sf::RectangleShape rWheel;

  float velocity = 0.f;
  float angularVelocity = 0.f;

  float xVelocity;
  float yVelocity;

  float rotation;
  float wheelRotation;

  const float turnVelocity = 45.f;
  const float acceleration = 100.f;

  float radius;

  const float slowAcceleration = 50.f;
  const float breakAcceleration = 35.f;

  const float originalMaxVelocity = 500.f;
  float maxVelocity = originalMaxVelocity;

 public:
  Car();
  ~Car();

  void baseCarUpdate(Engine *pEngine);
  void render(sf::RenderWindow *pWindow);

  void stop(Engine *pEngine);
  void returnToNaturalState();

  sf::RectangleShape getRect();

  sf::Vector2f getPosition();
  sf::Vector2f getCenterPosition();
};
