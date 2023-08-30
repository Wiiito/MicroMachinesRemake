#include "headers/player.hpp"

void Player::update(Engine *pEngine) {
  // Wheel turn
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    this->wheelRotation =
        std::min(this->wheelRotation +
                     turnVelocity * pEngine->getDeltaTime().asSeconds(),
                 35.f);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    this->wheelRotation =
        std::max(this->wheelRotation -
                     turnVelocity * pEngine->getDeltaTime().asSeconds(),
                 -35.f);
  }

  // Acceleration
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    this->velocity =
        std::min(this->velocity +
                     this->acceleration * pEngine->getDeltaTime().asSeconds(),
                 this->maxVelocity);
  } else if (velocity > 0) {  // 🤢
    this->velocity =
        std::max(this->velocity - this->slowAcceleration *
                                      pEngine->getDeltaTime().asSeconds(),
                 0.f);
  }

  // Break
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    this->velocity = this->velocity - this->breakAcceleration *
                                          pEngine->getDeltaTime().asSeconds();
  } else if (velocity < 0) {  // 🤢
    this->velocity =
        std::min(this->velocity +
                     this->acceleration * pEngine->getDeltaTime().asSeconds(),
                 0.f);
  }
}