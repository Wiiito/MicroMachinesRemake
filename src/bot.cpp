#include "headers/bot.hpp"

Bot::Bot() { this->currentCheckpoint = -1; }

Bot::~Bot() {}

void Bot::pushWaypoint(std::vector<sf::Vector2f> waypoint) {
  for (sf::Vector2f &check : waypoint) {
    this->waypoints.push_back(check);
  }
}

void Bot::pushWaypoint(sf::Vector2f waypoint) {
  this->waypoints.push_back(waypoint);
}

void Bot::update(Engine *pEngine) {
  this->baseCarUpdate(pEngine);

  sf::Vector2f nextCheckpoint;

  if (this->currentCheckpoint < this->waypoints.size() - 1) {
    nextCheckpoint = sf::Vector2f(this->waypoints[this->currentCheckpoint + 1]);
  } else {
    nextCheckpoint = sf::Vector2f(this->waypoints[0]);
  }

  sf::Vector2f triangleSize(nextCheckpoint - this->getPosition());

  float angle = atan(triangleSize.y / triangleSize.x) * 180 / M_PI;

  if (triangleSize.x < 0) angle += 180;

  this->rotation = angle;
  this->velocity =
      this->acceleration * pEngine->getDeltaTime().asSeconds() + this->velocity;

  this->returnToNaturalState();
}