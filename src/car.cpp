#include "headers/car.hpp"

Car::Car() {
  this->hitbox.setFillColor(sf::Color::Red);
  this->hitbox.setSize(sf::Vector2f(60, 85));
  this->hitbox.setPosition(sf::Vector2f(0.f, 0.f));
}

Car::~Car() {}

void Car::render(sf::RenderWindow *pWindow) { pWindow->draw(this->hitbox); }

sf::Vector2f Car::getPosition() { return this->hitbox.getPosition(); }

sf::Vector2f Car::getCenterPosition() {
  return sf::Vector2f(this->hitbox.getPosition().x + 30.f, this->hitbox.getPosition().y + 42.5f);
}