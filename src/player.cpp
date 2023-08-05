#include "headers/player.hpp"

#include <algorithm>

void Player::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    this->velocity = std::min(
        this->velocity + this->acceleration * this->accelerationClock.getElapsedTime().asSeconds(),
        this->maxVelocity);
  } else if (this->velocity > 0.f) {
    this->velocity =
        std::max(this->velocity -
                     this->slowAcceleration * this->accelerationClock.getElapsedTime().asSeconds(),
                 0.f);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    this->velocity = this->velocity -
                     this->slowAcceleration * this->accelerationClock.getElapsedTime().asSeconds();
  }

  // Default shmovent
  this->hitbox.move(sf::Vector2f(this->velocity, 0.f));

  this->accelerationClock.restart();
}