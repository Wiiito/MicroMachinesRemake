#include "menu.hpp"

Menu::Menu() {
  // Loading background
  this->backgroundImage.loadFromFile("assets/imgs/menu.png");
  this->backgroundRect.setPosition(sf::Vector2f(0.f, 0.f));
  this->backgroundRect.setSize(sf::Vector2f(1280.f, 720.f));
  this->backgroundRect.setTexture(&this->backgroundImage);
}

Menu::~Menu() {}

void Menu::update(Engine *pEngine) {}

void Menu::render(sf::RenderWindow *pWindow) {
  pWindow->draw(this->backgroundRect);
}