#include <SFML/Graphics.hpp>

#include "../headers/engine.hpp"
#include "../headers/map.hpp"
#include "../headers/player.hpp"

class Game {
 private:
  Player player;
  Map map;

  void initMap();

 public:
  Game();
  ~Game();
  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
