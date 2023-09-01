#include "headers/bot.hpp"

Bot::Bot() {}

Bot::~Bot() {}

#include <iostream>

void Bot::pushCheckpoint(std::vector<Checkpoint> &checkpoints) {
  for (Checkpoint &check : checkpoints) {
    this->checkpoints.push_back(check);
  }
}

void Bot::pushCheckpoint(Checkpoint &checkpoint) {
  this->checkpoints.push_back(checkpoint);
}

void Bot::update(Engine *pEngine) {
  this->baseCarUpdate(pEngine);

  sf::Vector2f nextCheckpoint;

  if (this->currentCheckpoint < this->checkpoints.size() - 1) {
    nextCheckpoint = sf::Vector2f(
        this->checkpoints[this->currentCheckpoint + 1].hitbox.getPosition());
  } else {
    nextCheckpoint = sf::Vector2f(this->checkpoints[0].hitbox.getPosition());
  }

  sf::Vector2f triangleSize(nextCheckpoint - this->getPosition());

  float angle = atan(triangleSize.y / triangleSize.x) * 180 / M_PI;

  if (triangleSize.x < 0) angle += 180;

  this->rotation = angle;
  this->velocity =
      this->acceleration * pEngine->getDeltaTime().asSeconds() + this->velocity;

  this->returnToNaturalState();
}