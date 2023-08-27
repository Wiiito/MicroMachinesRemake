#include "headers/car.hpp"

Car::Car() {
  // Hitbox do carrinho
  this->hitbox.setFillColor(sf::Color::Red);
  this->hitbox.setSize(sf::Vector2f(85, 60));
  this->hitbox.setPosition(sf::Vector2f(0.f, 0.f));
  this->hitbox.setOrigin(sf::Vector2f(30.f, 30.f));

  // LeftWheel do carrinho
  this->lWheel.setFillColor(sf::Color::Green);
  this->rWheel.setFillColor(sf::Color::Green);
  this->lWheel.setSize(sf::Vector2f(15, 10));
  this->rWheel.setSize(sf::Vector2f(15, 10));
  this->lWheel.setOrigin(sf::Vector2f(10, 5));
  this->rWheel.setOrigin(sf::Vector2f(10, 5));

  // this->lWheel.setPosition(sf::Vector2f(35.f, 30.f));
  // this->rWheel.setPosition(sf::Vector2f(35.f, -30.f));
}

Car::~Car() {}

#include <iostream>

void Car::baseCarUpdate(Engine *pEngine) {
  // Calculate Radius - Distancia da roda traseira e da roda frontal setada aq
  this->radius = 2.f * tan((90 - wheelRotation) * M_PI / 180);

  // Calcular a velocidade algunar
  if (radius != 0) this->angularVelocity = this->velocity / radius;

  this->rotation += this->angularVelocity * pEngine->getDeltaTime().asSeconds();

  // Wheels calculation
  float xDis = cos(rotation * M_PI / 180);
  float yDis = sin(rotation * M_PI / 180);

  float xOffsetDis = cos((this->rotation - 90) * M_PI / 180);
  float YOffsetDis = sin((this->rotation - 90) * M_PI / 180);

  this->rWheel.setPosition(
      this->getPosition().x + xDis * 35.f + xOffsetDis * 30.f,
      this->getPosition().y + yDis * 35.f + YOffsetDis * 30.f);

  this->lWheel.setPosition(
      this->getPosition().x + xDis * 35.f - xOffsetDis * 30.f,
      this->getPosition().y + yDis * 35.f - YOffsetDis * 30.f);

  this->rWheel.setRotation(this->rotation + this->wheelRotation);
  this->lWheel.setRotation(this->rotation + this->wheelRotation);

  // Position
  this->hitbox.move(this->velocity * pEngine->getDeltaTime().asSeconds() *
                        cos(rotation * M_PI / 180),
                    this->velocity * pEngine->getDeltaTime().asSeconds() *
                        sin(rotation * M_PI / 180));
}

void Car::render(sf::RenderWindow *pWindow) {
  // Drawing
  pWindow->draw(this->lWheel);
  pWindow->draw(this->rWheel);
  pWindow->draw(this->hitbox);
}

sf::Vector2f Car::getPosition() { return this->hitbox.getPosition(); }

sf::Vector2f Car::getCenterPosition() {
  return sf::Vector2f(this->hitbox.getPosition().x + 42.5f,
                      this->hitbox.getPosition().y + 30.f);
}