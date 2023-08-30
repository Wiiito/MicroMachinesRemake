#include "headers/map.hpp"

Map::Map() {}

Map::Map(std::string mapPath, std::string tileSetPath) {
  this->setTileSet(tileSetPath);
  this->setMap(mapPath);
  this->updateMap();
}

Map::~Map() {}

void Map::updateMap() {
  std::string string;
  while (getline(this->mapFile, string)) {
    std::vector<int> line;
    for (unsigned int i = 0; i < string.size(); i++) {
      line.push_back(int(string.at(i)) - 48);
    }
    this->map.push_back(line);
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

// ---- Collision detection ----
bool Map::doesCollide(sf::Vector2f pos) {
  return this->doesCollide((int)pos.x, (int)pos.y);
}

bool Map::doesCollide(int x, int y) {
  if (this->map[x / this->offsetSize][y / this->offsetSize]) {
    return true;
  }
  return false;
}

bool Map::intersectsCollision(sf::RectangleShape rect,
                              sf::RenderWindow *pWindow) {
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

  sf::CircleShape shape;
  shape.setFillColor(sf::Color::Yellow);
  shape.setRadius(2.5f);
  shape.setOrigin(shape.getLocalBounds().width / 2,
                  shape.getLocalBounds().height / 2);

  shape.setPosition(bottomLeft);
  pWindow->draw(shape);
  shape.setPosition(bottomRight);
  pWindow->draw(shape);
  shape.setPosition(topLeft);
  pWindow->draw(shape);
  shape.setPosition(topRight);
  pWindow->draw(shape);
}

// ---- Render ----
void Map::render(sf::RenderWindow *pWindow) {
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