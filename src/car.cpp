#include "headers/car.hpp"

Car::Car(std::string texturePath) {
  // Hitbox do carrinho
  this->hitbox.setSize(sf::Vector2f(85, 60));
  this->hitbox.setPosition(sf::Vector2f(0.f, 0.f));
  this->hitbox.setOrigin(sf::Vector2f(30.f, 30.f));

  this->carTexture.loadFromFile(texturePath);
  this->hitbox.setTexture(&carTexture);

  // LeftWheel do carrinho
  this->lWheel.setFillColor(sf::Color::Black);
  this->rWheel.setFillColor(sf::Color::Black);
  this->lWheel.setSize(sf::Vector2f(15, 10));
  this->rWheel.setSize(sf::Vector2f(15, 10));
  this->lWheel.setOrigin(sf::Vector2f(7.5f, 5));
  this->rWheel.setOrigin(sf::Vector2f(7.5f, 5));

  this->currentCheckpoint = 0;
  this->currentLap = 0;
}

Car::~Car() {}

/**
 * Updates Car physics
 * @param pEngine pointer to gameEngine
 * @return void
 * @private
 */
void Car::logicUpdate(Engine *pEngine) {
  // Set max velocity
  this->velocity = std::min(this->velocity, this->maxVelocity);

  // Calculate Radius - Distancia da roda traseira e da roda frontal setada aq
  this->radius = 2.f * tan((90 - wheelRotation) * M_PI / 180);

  // Position
  this->hitbox.move(this->velocity * pEngine->getDeltaTime().asSeconds() *
                        cos(rotation * M_PI / 180),
                    this->velocity * pEngine->getDeltaTime().asSeconds() *
                        sin(rotation * M_PI / 180));

  // Calcular a velocidade algunar
  if (radius != 0) this->angularVelocity = this->velocity / radius;

  this->rotation += this->angularVelocity * pEngine->getDeltaTime().asSeconds();
}

/**
 * Updates Wheels relative to car body
 * @return void
 * @private
 */
void Car::wheelsUpdate() {
  // Wheels calculation
  float xDis = cos(rotation * M_PI / 180);
  float yDis = sin(rotation * M_PI / 180);

  float xOffsetDis = cos((this->rotation - 90) * M_PI / 180);
  float YOffsetDis = sin((this->rotation - 90) * M_PI / 180);

  this->rWheel.setPosition(
      this->getPosition().x + xDis * 35.f + xOffsetDis * 22.f,
      this->getPosition().y + yDis * 35.f + YOffsetDis * 22.f);

  this->lWheel.setPosition(
      this->getPosition().x + xDis * 35.f - xOffsetDis * 22.f,
      this->getPosition().y + yDis * 35.f - YOffsetDis * 22.f);

  this->rWheel.setRotation(this->rotation + this->wheelRotation);
  this->lWheel.setRotation(this->rotation + this->wheelRotation);

  this->hitbox.setRotation(rotation);
}

/**
 * Updated base car state
 * @param pEngine engine pointer, used to get deltaTime
 * @return void
 * @protected
 */
void Car::baseCarUpdate(Engine *pEngine) {
  this->logicUpdate(pEngine);
  this->wheelsUpdate();
}

/**
 * Called when car collides with something
 * @return void
 * @public
 */
void Car::stop() { this->maxVelocity = 50.f; }

/**
 * Return car to it's original state
 * @return void
 * @protected
 */
void Car::returnToNaturalState() { this->maxVelocity = originalMaxVelocity; }

/**
 * Renders car and it's wheels on a window
 * @param pWindow pointer to window that will recive the car
 * @return void
 * @public
 */
void Car::render(sf::RenderWindow *pWindow) {
  // Drawing
  pWindow->draw(this->lWheel);
  pWindow->draw(this->rWheel);
  pWindow->draw(this->hitbox);
}

/**
 * Get car RectangleShape
 * @return RectangleShape, car hitbox
 * @public
 */
sf::RectangleShape Car::getRect() { return this->hitbox; }

/**
 * Get car current position
 * @return Vector2f, with current position
 * @public
 */
sf::Vector2f Car::getPosition() { return this->hitbox.getPosition(); }

/**
 * Get car center
 * @return Vector2f, with car current center
 * @public
 */
sf::Vector2f Car::getCenterPosition() {
  return sf::Vector2f(this->hitbox.getPosition().x + 42.5f,
                      this->hitbox.getPosition().y + 30.f);
}