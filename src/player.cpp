#include "headers/player.hpp"

/**
 * Handle's user input
 * @public
 * @param Engine* pointer to engine
 * @return void
 */
void Player::update(Engine *pEngine) {
  this->baseCarUpdate(pEngine);

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
    this->velocity = this->velocity +
                     this->acceleration * pEngine->getDeltaTime().asSeconds();

  } else if (velocity > 0) {
    this->velocity =
        std::max(this->velocity - this->slowAcceleration *
                                      pEngine->getDeltaTime().asSeconds(),
                 0.f);
  }

  // Sim, eu sei que se o usuario começar a
  // correr de costar ele não tem limite de
  // velicidade, mas achei uma interação legal
  // então deixei :)

  // Break
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    this->velocity = this->velocity - this->breakAcceleration *
                                          pEngine->getDeltaTime().asSeconds();
  } else if (velocity < 0) {
    this->velocity =
        std::min(this->velocity +
                     this->acceleration * pEngine->getDeltaTime().asSeconds(),
                 0.f);
  }

  this->returnToNaturalState();
}