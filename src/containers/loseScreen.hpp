
#include <SFML/Graphics.hpp>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"

class LoseScreen {
 private:
  sf::Texture backgroundTexture;
  sf::RectangleShape background;

  sf::Font font;

  sf::Text playAgainText;
  sf::Text menuText;

  Button playAgainButton;
  Button menuButton;

 public:
  LoseScreen(Engine *pEngine);
  ~LoseScreen();

  void update(Engine *pEngine);
  void render(sf::RenderWindow *pWindow);
};
