#pragma once

#include <algorithm>

#include "car.hpp"
#include "engine.hpp"

class Player : public Car {
 private:
 public:
  void update(Engine *pEngine);
};
