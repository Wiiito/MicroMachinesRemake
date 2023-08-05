#include "headers/car.hpp"

Car::Car() {
  this->hitbox.setFillColor(sf::Color::Red);
  this->hitbox.setSize(sf::Vector2f(85, 60));
  this->hitbox.setPosition(sf::Vector2f(0.f, 0.f));

  this->hitbox.setOrigin(sf::Vector2f(30.f, 30.f));
}

Car::~Car() {}

void Car::render(sf::RenderWindow *pWindow) { pWindow->draw(this->hitbox); }

sf::Vector2f Car::getPosition() { return this->hitbox.getPosition(); }

sf::Vector2f Car::getCenterPosition() {
  return sf::Vector2f(this->hitbox.getPosition().x + 42.5f, this->hitbox.getPosition().y + 30.f);
}