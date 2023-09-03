#include <SFML/Graphics.hpp>

#include "../headers/engine.hpp"

class Menu {
 private:
  sf::Texture backgroundImage;
  sf::RectangleShape backgroundRect;

 public:
  Menu();
  ~Menu();

  void update(Engine *pEngine);
  void render(sf::RenderWindow *pWindow);
};
