#include <SFML/Graphics.hpp>
#include <string>

class Map {
 private:
  sf::Texture tileTexture;
  sf::Image map;

 public:
  Map();
  ~Map();

  void setTileSet(std::string path);
  void setMap(std::string path);
};
