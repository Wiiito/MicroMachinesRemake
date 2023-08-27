#include "game.hpp"

#include <iostream>

Game::Game() { this->initMap(); }

Game::~Game() {}

void Game::initMap() {
  this->mapTexture.loadFromFile("src/assets/imgs/map.jpg");
  this->mapSprite.setTexture(this->mapTexture);
}

void Game::update(Engine *gameEngine) {
  player.baseCarUpdate(gameEngine);
  player.update(gameEngine);
}

void Game::render(sf::RenderWindow *pWindow) {
  pWindow->setView(sf::View(player.getCenterPosition(), sf::Vector2f(pWindow->getSize())));
  pWindow->draw(this->mapSprite);
  player.render(pWindow);
}