#include "headers/map.hpp"

Map::Map() {}

Map::Map(std::string mapPath, std::string tileSetPath) {
  this->setTileSet(tileSetPath);
  this->setMap(mapPath);
  this->updateMap();
}

Map::~Map() {}

// Essa função é privada pra evitar tentar ler arquivo q ñ ta aberto :v
/**
 * Read mapFile to push each number to a matrix of numbers that represent the
 * map
 * @return void
 * @private
 */
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
}

// ---- Set functions ----

/**
 * Set map texture
 * @param std::string string to texture from .exe location
 * @return void
 * @public
 */
void Map::setTileSet(std::string path) {
  this->tileTexture.loadFromFile(path);
  acutalSquare.setTexture(&this->tileTexture);
}

/**
 * Set the actual map path
 * @param std::string string to map from .exe location
 * @return void
 * @public
 */
void Map::setMap(std::string path) {
  this->mapFile.open(path);
  this->updateMap();
  this->mapFile.close();
}

/**
 * Set tileSet Size
 * @param int number that each square should be
 * @return void
 * @public
 */
void Map::setOffestSize(int size) {
  this->offsetSize = size;
  this->acutalSquare.setSize(sf::Vector2f(size, size));
}

// ---- Collision detection ----

/**
 * Checks if a point is colliding on a wall of the map
 * @public
 * @param sf::Vector2f absolute position on game
 * @return bool, true if collides or out of borders
 */
bool Map::doesCollide(sf::Vector2f pos) {
  return this->doesCollide((int)pos.x, (int)pos.y);
}

/**
 * Checks if a point is colliding on a wall of the map
 * @public
 * @param int X absolute position on map
 * @param int Y absolute position on map
 * @return bool, true if collides or out of borders
 */
bool Map::doesCollide(int x, int y) {
  // std::cout << this->map[y / this->offsetSize][x / this->offsetSize];
  if (y / this->offsetSize > map.size() - 1 || y < 0 ||
      x / this->offsetSize > map[y / this->offsetSize].size() || x < 0) {
    return true;
  }

  if (this->map[y / this->offsetSize][x / this->offsetSize]) {
    return true;
  }
  return false;
}

/**
 * Checks if a sf::RectangleShape collides with any wall on the map
 * @public
 * @param sf::RectangleShale rect to be checked
 * @return bool, true if collides
 */
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

/**
 * Renders the map on screen
 * @public
 * @param sf::RenderWindow* pointer to window that will recive the map
 * @return void
 */
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