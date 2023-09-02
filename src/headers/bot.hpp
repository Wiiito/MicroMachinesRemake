#include <vector>

#include "car.hpp"
#include "engine.hpp"

class Bot : public Car {
 private:
  std::vector<sf::Vector2f> waypoints;

 public:
  Bot();
  ~Bot();

  void pushWaypoint(std::vector<sf::Vector2f> waypoint);
  void pushWaypoint(sf::Vector2f waypoint);

  void update(Engine *pEngine);
};
