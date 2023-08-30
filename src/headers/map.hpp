#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

class Map {
 private:
  sf::Texture tileTexture;
  std::ifstream mapFile;

  sf::RectangleShape acutalSquare;

  int offsetSize;

  std::vector<std::vector<int>> map;

 public:
  Map();
  Map(std::string mapPath, std::string tileSetPath);

  ~Map();

  void setTileSet(std::string path);
  void setMap(std::string path);
  void setOffestSize(int size);

  bool doesCollide(sf::Vector2f pos);
  bool doesCollide(int x, int y);

  bool intersects(sf::RectangleShape rect);

  void updateMap();
  void render(sf::RenderWindow *pWindow);
};
