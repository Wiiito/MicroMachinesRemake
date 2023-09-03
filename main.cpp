#include <SFML/Graphics.hpp>

#include "src/containers/game.hpp"
#include "src/containers/menu.hpp"
#include "src/headers/engine.hpp"

int main() {
  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  // ---- Creating gameScene ----
  Game *game = new Game;
  Scene gameScene("game");
  gameScene.setInstanceFunction([&game]() -> void {
    delete (game);
    game = new Game;
  });
  gameScene.add([game, pWindow, &gameEngine]() -> void {
    game->update(&gameEngine);
    game->render(pWindow);
  });
  gameEngine.pushScene(&gameScene);

  // ---- Creating menuScene ----
  Menu *menu = new Menu;
  Scene menuScene("menu");
  menuScene.setInstanceFunction([&menu]() -> void {
    delete (menu);
    menu = new Menu;
  });
  menuScene.add([menu, pWindow, &gameEngine]() -> void {
    menu->update(&gameEngine);
    menu->render(pWindow);
  });
  gameEngine.pushScene(&menuScene);

  gameEngine.setCurrentScene("game");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }

  return 0;
}