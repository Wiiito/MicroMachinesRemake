#include "game.hpp"

#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::update(Engine *gameEngine) { player.update(); }

void Game::render(sf::RenderWindow *pWindow) {
  pWindow->setView(sf::View(player.getCenterPosition(), sf::Vector2f(pWindow->getSize())));
  player.render(pWindow);
}