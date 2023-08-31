#include "game.hpp"

#include <iostream>

Game::Game() { this->initMap(); }

Game::~Game() {}

void Game::initCheckpoints(std::string path) {
  std::ifstream checks(path);
  std::string line;

  getline(checks, line);
  while (getline(checks, line)) {
    sf::RectangleShape shape;
    std::stringstream ss(line);
    std::string value;

    getline(ss, value, ',');
    int xPos = atoi(value.c_str());
    getline(ss, value, ',');
    int yPos = atoi(value.c_str());
    shape.setPosition(sf::Vector2f(xPos, yPos));

    getline(ss, value, ',');
    int width = atoi(value.c_str());
    getline(ss, value, ',');
    int height = atoi(value.c_str());
    shape.setSize(sf::Vector2f(width, height));

    Checkpoint check;
    check.hitbox = shape;

    getline(ss, value, ',');
    int counter = atoi(value.c_str());
    check.checkpointNumber = counter;

    this->maxCheckpoint = counter;

    this->checkpoints.push_back(check);
  }

  checks.close();
}

void Game::initMap() {
  this->map.setTileSet("assets/imgs/map.png");
  this->map.setMap("assets/map.txt");
  this->map.setOffestSize(32);
  this->map.updateMap();

  this->initCheckpoints("assets/level1Checkpoints.csv");
}

void Game::update(Engine *gameEngine) {
  player.baseCarUpdate(gameEngine);
  player.update(gameEngine);
  player.returnToNaturalState();

  if (map.intersects(player.getRect())) {
    player.stop(gameEngine);
  }

  // Checkpoints checks / Laps Check
  for (auto i : this->checkpoints) {
    if (player.getRect().getGlobalBounds().intersects(
            i.hitbox.getGlobalBounds())) {
      if (i.checkpointNumber > player.currentCheckpoint) {  // Checkpoint check
        player.currentCheckpoint = i.checkpointNumber;
        break;
      }

      if (i.checkpointNumber == 0 &&
          player.currentCheckpoint == this->maxCheckpoint) {  // Lap check
        player.currentLap = player.currentLap + 1;
        player.currentCheckpoint = i.checkpointNumber;
      }
    }
  }
}

void Game::render(sf::RenderWindow *pWindow) {
  pWindow->setView(
      sf::View(player.getCenterPosition(), sf::Vector2f(pWindow->getSize())));

  map.render(pWindow);
  player.render(pWindow);
}