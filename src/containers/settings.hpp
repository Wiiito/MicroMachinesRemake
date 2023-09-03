#include <SFML/Graphics.hpp>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"
#include "../headers/rangeButton.hpp"

class Settings {
 private:
  sf::Texture backgroundTexture;
  sf::RectangleShape backgroundRect;

  sf::Font terminalFont;

  sf::Text MasterText;
  sf::Text MusicText;
  sf::Text EffectsText;

  sf::Text backText;

  RangeButton master;
  RangeButton music;
  RangeButton effects;

  Button backButton;

 public:
  Settings(Engine *pEngine);
  ~Settings();

  void update(Engine *gameEngine);
  void render(sf::RenderWindow *pWindow);
};
