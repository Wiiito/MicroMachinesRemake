#include <SFML/Graphics.hpp>
#include <sstream>

#include "../headers/engine.hpp"
#include "../headers/map.hpp"
#include "../headers/player.hpp"

struct Checkpoint {
  sf::RectangleShape hitbox;
  int checkpointNumber;
};

class Game {
 private:
  Player player;
  Map map;

  // Checkpoints related
  std::vector<Checkpoint> checkpoints;
  void initMap();

  void initCheckpoints(std::string path);

 public:
  Game();
  ~Game();
  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
