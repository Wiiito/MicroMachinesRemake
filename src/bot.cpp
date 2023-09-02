#include "headers/bot.hpp"

Bot::Bot() {
  this->currentCheckpoint = -1;
  this->rotation = -90;
  this->hitbox.setPosition(sf::Vector2f(350, 800));
}

Bot::~Bot() {}

/**
 * Recives wayPoins to where should pass
 * @param waypoints std::vector<sf::Vector2f>, with waypoints to be pushed
 * @public
 * @return void
 */
void Bot::pushWaypoint(std::vector<sf::Vector2f> waypoint) {
  for (sf::Vector2f &check : waypoint) {
    this->waypoints.push_back(check);
  }
}

/**
 * Recives wayPoins to where should pass
 * @param waypoint sf::Vector2f, with waypoints to be pushed
 * @public
 * @return void
 */
void Bot::pushWaypoint(sf::Vector2f waypoint) {
  this->waypoints.push_back(waypoint);
}

/**
 * Peforms calculations to get wheel rotation the car should have
 * @param pEngine game engine
 * @public
 * @return void
 */
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

  this->wheelRotation = angle - this->rotation;
  this->velocity =
      this->acceleration * pEngine->getDeltaTime().asSeconds() + this->velocity;

  this->returnToNaturalState();
}