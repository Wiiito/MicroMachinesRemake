#include "headers/map.hpp"

Map::Map() {}

Map::Map(std::string mapPath, std::string tileSetPath) {
  this->setTileSet(tileSetPath);
  this->setMap(mapPath);
  this->updateMap();
}

Map::~Map() {}

#include <iostream>

void Map::updateMap() {
  std::string string;
  int counter = 0;
  while (getline(this->mapFile, string)) {
    this->map.resize(counter + 1);
    for (char& c : string) {
      map[counter].push_back((int)c - 48);
    }
    counter++;
  }
  this->mapFile.close();
}

// ---- Set functions ----
void Map::setTileSet(std::string path) {
  this->tileTexture.loadFromFile(path);
  acutalSquare.setTexture(&this->tileTexture);
}
void Map::setMap(std::string path) { this->mapFile.open(path); }
void Map::setOffestSize(int size) {
  this->offsetSize = size;
  this->acutalSquare.setSize(sf::Vector2f(size, size));
}

#include <iostream>
// ---- Collision detection ----
bool Map::doesCollide(sf::Vector2f pos) {
  return this->doesCollide((int)pos.x, (int)pos.y);
}

bool Map::doesCollide(int x, int y) {
  // std::cout << this->map[y / this->offsetSize][x / this->offsetSize];
  if (y / this->offsetSize > map.size() || y < 0 ||
      x / this->offsetSize > map[y / this->offsetSize].size() || x < 0) {
    return true;
  }

  if (this->map[y / this->offsetSize][x / this->offsetSize]) {
    return true;
  }
  return false;
}

bool Map::intersects(sf::RectangleShape rect) {
  // Essa brincadeira td aq pq a função da lib é inutil :)
  float angle = rect.getRotation() * M_PI / 180;

  // S - Small
  // B - Big
  float sWidth = rect.getOrigin().x;
  float sHeight = rect.getOrigin().y;

  float bWidth = rect.getLocalBounds().width - sWidth;
  float bHeight = rect.getLocalBounds().height - sHeight;

  sf::Vector2f bottomLeft = sf::Vector2f(
      rect.getPosition().x - (sWidth * cos(angle)) - (sHeight * sin(angle)),
      rect.getPosition().y - (sWidth * sin(angle)) + (sHeight * cos(angle)));

  sf::Vector2f bottomRight = sf::Vector2f(
      rect.getPosition().x + (bWidth * cos(angle)) - (sHeight * sin(angle)),
      rect.getPosition().y + (bWidth * sin(angle)) + (sHeight * cos(angle)));

  sf::Vector2f topLeft = sf::Vector2f(
      rect.getPosition().x - (sWidth * cos(angle)) + (sHeight * sin(angle)),
      rect.getPosition().y - (sWidth * sin(angle)) - (sHeight * cos(angle)));

  sf::Vector2f topRight = sf::Vector2f(
      rect.getPosition().x + (bWidth * cos(angle)) + (sHeight * sin(angle)),
      rect.getPosition().y + (bWidth * sin(angle)) - (sHeight * cos(angle)));

  if (this->doesCollide(topRight) || this->doesCollide(topLeft) ||
      this->doesCollide(bottomLeft) || this->doesCollide(bottomRight)) {
    return true;
  }
  return false;
}

// ---- Render ----
void Map::render(sf::RenderWindow* pWindow) {
  for (unsigned int y = 0; y < this->map.size(); y++) {
    for (unsigned int x = 0; x < this->map[y].size(); x++) {
      this->acutalSquare.setTextureRect(
          sf::IntRect(sf::Vector2i(map[y][x] * this->offsetSize, 0),
                      sf::Vector2i(this->offsetSize, this->offsetSize)));

      this->acutalSquare.setPosition(x * this->offsetSize,
                                     y * this->offsetSize);
      pWindow->draw(this->acutalSquare);
    }
  }
}