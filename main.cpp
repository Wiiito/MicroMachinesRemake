#include <SFML/Graphics.hpp>

#include "src/containers/game.hpp"
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

  gameEngine.setCurrentScene("game");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }

  return 0;
}