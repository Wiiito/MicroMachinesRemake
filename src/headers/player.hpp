#pragma once

#include <algorithm>

#include "car.hpp"
#include "engine.hpp"

class Player : public Car {
 private:

 public:
  Player() : Car("assets/cars/YellowBlock.png") {
    this->hitbox.setPosition(sf::Vector2f(300, 800));
    this->rotation = -90;
  }
  void update(Engine *pEngine);
};
