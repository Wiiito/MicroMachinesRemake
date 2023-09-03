#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "engine.hpp"
#include "map.hpp"

class Car {
 private:
  sf::Texture carTexture;

  // Wheels
  sf::RectangleShape lWheel;
  sf::RectangleShape rWheel;

  // Physics
  float xVelocity;
  float yVelocity;

  // Rotating
  float radius;

  // Max velocity
  const float originalMaxVelocity = 500.f;
  float maxVelocity = originalMaxVelocity;

  void logicUpdate(Engine *pEngine);
  void wheelsUpdate();

 protected:
  sf::RectangleShape hitbox;

  float velocity = 0.f;
  float angularVelocity = 0.f;

  float rotation;
  float wheelRotation;

  const float turnVelocity = 45.f;
  const float acceleration = 100.f;

  const float slowAcceleration = 50.f;
  const float breakAcceleration = 100.f;

  void baseCarUpdate(Engine *pEngine);
  void returnToNaturalState();

 public:
  int currentLap = 0;
  int currentCheckpoint = 0;
  // Race things - They are public cuz every car has one n' it's kinda pointless
  // making them private

  Car(std::string texturePath);
  ~Car();

  void render(sf::RenderWindow *pWindow);

  void stop();

  sf::RectangleShape getRect();

  sf::Vector2f getPosition();
  sf::Vector2f getCenterPosition();
};
