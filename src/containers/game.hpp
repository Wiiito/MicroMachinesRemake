#include <SFML/Graphics.hpp>

#include "../headers/engine.hpp"
#include "../headers/player.hpp"

class Game {
 private:
  Player player;

 public:
  Game();
  ~Game();
  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
