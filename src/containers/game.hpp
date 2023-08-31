#include <SFML/Graphics.hpp>
#include <sstream>

#include "../headers/bot.hpp"
#include "../headers/engine.hpp"
#include "../headers/map.hpp"
#include "../headers/player.hpp"

class Game {
 private:
  Player player;
  Bot bot;
  Map map;

  // Checkpoints related
  std::vector<Checkpoint> checkpoints;
  void initMap();

  int maxCheckpoint;

  void initCheckpoints(std::string path);

 public:
  Game();
  ~Game();
  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
