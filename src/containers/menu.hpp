#include <SFML/Graphics.hpp>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"

class Menu {
 private:
  sf::Texture backgroundImage;
  sf::RectangleShape backgroundRect;

  sf::Font terminalFont;

  sf::Text startText;
  sf::Text settingsText;
  sf::Text quitText;
  Button startButton;
  Button settingsButton;
  Button quitButton;

 public:
  Menu(Engine *gameEngine);
  ~Menu();

  void update(Engine *pEngine);
  void render(sf::RenderWindow *pWindow);
};
