#include "headers/player.hpp"

#include <algorithm>
#include <iostream>

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
                     this->breakAcceleration * this->accelerationClock.getElapsedTime().asSeconds();
  } else if (this->velocity < 0.f) {
    this->velocity =
        std::min(this->velocity +
                     this->breakAcceleration * this->accelerationClock.getElapsedTime().asSeconds(),
                 0.f);
  }

  if (velocity != 0.f) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      this->rotation +=
          4 * (0.75f - this->velocity) * this->accelerationClock.getElapsedTime().asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
      this->rotation -=
          4 * (0.75f - this->velocity) * this->accelerationClock.getElapsedTime().asSeconds();
    }

    if (rotation >= 2 * M_PI) {
      rotation -= 2 * M_PI;
    }
    if (rotation < 0) {
      rotation += 2 * M_PI;
    }

    std::cout << this->xVelocity << "," << this->yVelocity << "\n";
  }

  // Default shmovent
  this->xVelocity = this->velocity * cos(rotation);
  this->yVelocity = this->velocity * sin(rotation);

  this->hitbox.setRotation(rotation * 180 / M_PI);

  this->hitbox.move(sf::Vector2f(this->xVelocity, this->yVelocity));

  this->accelerationClock.restart();
}