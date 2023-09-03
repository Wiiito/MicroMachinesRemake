#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

#include "../headers/bot.hpp"
#include "../headers/engine.hpp"
#include "../headers/map.hpp"
#include "../headers/player.hpp"
#include "../headers/sound.hpp"

class Game {
 private:
  Player player;
  Bot bot;
  Map map;

  // Checkpoints related
  std::vector<sf::RectangleShape *> checkpoints;
  void initMap();

  int maxCheckpoint;

  void initCheckpoints(std::string path);

  sf::Music menuMusic;

 public:
  Game();
  ~Game();
  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
