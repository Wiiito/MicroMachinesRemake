#include "game.hpp"

#include <iostream>

Game::Game() { this->initMap(); }

Game::~Game() {}

void Game::initCheckpoints(std::string path) {
  std::ifstream checks(path);
  std::string line;

  int counter = 0;

  getline(checks, line);
  while (getline(checks, line)) {
    sf::RectangleShape *shape = new sf::RectangleShape;
    std::stringstream ss(line);
    std::string value;

    getline(ss, value, ',');
    int xPos = atoi(value.c_str());
    getline(ss, value, ',');
    int yPos = atoi(value.c_str());
    shape->setPosition(sf::Vector2f(xPos, yPos));

    getline(ss, value, ',');
    int width = atoi(value.c_str());
    getline(ss, value, ',');
    int height = atoi(value.c_str());
    shape->setSize(sf::Vector2f(width, height));

    this->maxCheckpoint = counter;
    counter++;

    this->checkpoints.push_back(shape);
    bot.pushWaypoint(shape->getPosition());
  }

  checks.close();
}

void Game::initMap() {
  this->map.setTileSet("assets/imgs/texture.png");
  this->map.setMap("assets/level1/map.txt");
  this->map.setOffestSize(32);

  this->initCheckpoints("assets/level1/checkpoints.csv");
}

void Game::update(Engine *gameEngine) {
  player.update(gameEngine);
  bot.update(gameEngine);

  if (map.intersects(player.getRect())) {
    player.stop(gameEngine);
  }

  // Checkpoints checks / Laps Check
  for (int i = 0; i < this->checkpoints.size(); i++) {
    if (player.getRect().getGlobalBounds().intersects(
            this->checkpoints[i]->getGlobalBounds())) {
      if (i > player.currentCheckpoint) {  // Checkpoint check
        player.currentCheckpoint = i;
        break;
      }

      if (i == 0 &&
          player.currentCheckpoint == this->maxCheckpoint) {  // Lap check
        player.currentLap = player.currentLap + 1;
        player.currentCheckpoint = i;
      }
    }
  }
  for (int i = 0; i < this->checkpoints.size(); i++) {
    if (bot.getRect().getGlobalBounds().intersects(
            this->checkpoints[i]->getGlobalBounds())) {
      if (i > bot.currentCheckpoint) {  // Checkpoint check
        bot.currentCheckpoint = i;
        break;
      }

      if (i == 0 &&
          bot.currentCheckpoint == this->maxCheckpoint) {  // Lap check
        bot.currentLap = bot.currentLap + 1;
        bot.currentCheckpoint = i;
      }
    }
  }
}

void Game::render(sf::RenderWindow *pWindow) {
  pWindow->setView(
      sf::View(player.getCenterPosition(), sf::Vector2f(pWindow->getSize())));

  map.render(pWindow);
  player.render(pWindow);
  bot.render(pWindow);
}