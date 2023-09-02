#pragma once

#include <algorithm>

#include "car.hpp"
#include "engine.hpp"

class Player : public Car {
 private:
 public:
  Player() : Car() { this->hitbox.setPosition(200, 200); }
  void update(Engine *pEngine);
};
