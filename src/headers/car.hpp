#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "engine.hpp"
#include "map.hpp"

struct Checkpoint {
  sf::RectangleShape hitbox;
  int checkpointNumber;

  sf::Vector2f operator+(Checkpoint anotherCheckpoint) {
    return this->hitbox.getPosition() - anotherCheckpoint.hitbox.getPosition();
  };
  sf::Vector2f operator-(Checkpoint anotherCheckpoint) {
    return this->hitbox.getPosition() - anotherCheckpoint.hitbox.getPosition();
  };

  sf::Vector2f operator+(sf::Vector2f pos) {
    return this->hitbox.getPosition() - pos;
  };
  sf::Vector2f operator-(sf::Vector2f pos) {
    return this->hitbox.getPosition() - pos;
  };
};

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
  // Race things - They are public cuz every car has one n' it's kinda pointless
  // making them private

  int currentLap = 0;
  int currentCheckpoint = 0;

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
