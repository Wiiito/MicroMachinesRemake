#include <SFML/Graphics.hpp>

#include "src/containers/game.hpp"
#include "src/containers/loseScreen.hpp"
#include "src/containers/menu.hpp"
#include "src/containers/settings.hpp"
#include "src/containers/winScreen.hpp"
#include "src/headers/engine.hpp"
#include "src/headers/sound.hpp"

int SoundControler::effectsVolume = 50;
int SoundControler::musicVolume = 50;
int SoundControler::globalVolume = 50;

sf::Music SoundControler::menuMusic;

int main() {
  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  SoundControler::initGlobalMusic();

  // ---- Creating gameScene ----
  Game *game = new Game;
  Scene gameScene("game");
  gameScene.setInstanceFunction([&game]() -> void {
    delete game;
    game = new Game;
  });
  gameScene.add([game, pWindow, &gameEngine]() -> void {
    game->update(&gameEngine);
    game->render(pWindow);
  });
  gameEngine.pushScene(&gameScene);

  // ---- Creating menuScene ----
  Menu *menu = new Menu(&gameEngine);
  Scene menuScene("menu");
  menuScene.setInstanceFunction([&menu, &gameEngine]() -> void {
    delete (&menu);
    menu = new Menu(&gameEngine);
  });
  menuScene.add([menu, pWindow, &gameEngine]() -> void {
    menu->update(&gameEngine);
    menu->render(pWindow);
  });
  gameEngine.pushScene(&menuScene);

  // ---- Creating settingsScene ----
  Settings *settings = new Settings(&gameEngine);
  Scene settingsScene("settings");
  settingsScene.setInstanceFunction([&settings, &gameEngine]() -> void {
    delete (&settings);
    settings = new Settings(&gameEngine);
  });
  settingsScene.add([settings, pWindow, &gameEngine]() -> void {
    settings->update(&gameEngine);
    settings->render(pWindow);
  });
  gameEngine.pushScene(&settingsScene);

  // ---- Creating winScene ----
  WinScreen *winScreen = new WinScreen(&gameEngine);
  Scene winScreenScene("winScreen");
  winScreenScene.setInstanceFunction([&winScreen, &gameEngine]() -> void {
    delete (&winScreen);
    winScreen = new WinScreen(&gameEngine);
  });
  winScreenScene.add([winScreen, pWindow, &gameEngine]() -> void {
    winScreen->update(&gameEngine);
    winScreen->render(pWindow);
  });
  gameEngine.pushScene(&winScreenScene);

  // ---- Creating loseScene ----
  LoseScreen *loseScreen = new LoseScreen(&gameEngine);
  Scene loseScreenScene("loseScreen");
  loseScreenScene.setInstanceFunction([&loseScreen, &gameEngine]() -> void {
    delete (&loseScreen);
    loseScreen = new LoseScreen(&gameEngine);
  });
  loseScreenScene.add([loseScreen, pWindow, &gameEngine]() -> void {
    loseScreen->update(&gameEngine);
    loseScreen->render(pWindow);
  });
  gameEngine.pushScene(&loseScreenScene);

  gameEngine.setCurrentScene("menu");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }

  return 0;
}