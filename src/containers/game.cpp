#include "game.hpp"

#include <iostream>

Game::Game() { this->initMap(); }

Game::~Game() {}

void Game::initMap() {
  this->map.setTileSet("assets/imgs/map.png");
  this->map.setMap("assets/map.txt");
  this->map.setOffestSize(32);
  this->map.updateMap();
}

void Game::update(Engine *gameEngine) {
  player.baseCarUpdate(gameEngine);
  player.update(gameEngine);
  player.returnToNaturalState();

  if (map.intersects(player.getRect())) {
    // std::cout << "Barbeiro\n";
    player.stop(gameEngine);
  }
}

void Game::render(sf::RenderWindow *pWindow) {
  pWindow->setView(
      sf::View(player.getCenterPosition(), sf::Vector2f(pWindow->getSize())));
  map.render(pWindow);
  player.render(pWindow);
}