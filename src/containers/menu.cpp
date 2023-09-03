#include "menu.hpp"

Menu::Menu(Engine *gameEngine) {
  // Loading background
  this->backgroundImage.loadFromFile("assets/imgs/menu.png");
  this->backgroundRect.setPosition(sf::Vector2f(0.f, 0.f));
  this->backgroundRect.setSize(sf::Vector2f(1280.f, 720.f));
  this->backgroundRect.setTexture(&this->backgroundImage);

  // Fonts initialization
  terminalFont.loadFromFile("assets/fonts/Terminal.ttf");

  // ---- Button loadings ----
  // Start Button
  startText.setFont(terminalFont);
  startText.setFillColor(sf::Color::White);
  startText.setCharacterSize(90);
  startText.setString("Start");

  this->startButton.setPosition(sf::Vector2f(190.f, 445.f));
  this->startButton.setText(startText);
  this->startButton.setCallbackFunction(
      [gameEngine]() -> void { gameEngine->setCurrentScene("game"); });
  this->startButton.setColorOnHover(TEXT, sf::Color::Yellow);

  startText.setFillColor(sf::Color::Black);
  startText.setPosition(sf::Vector2f(80.f, 405.f));

  // Settings Button
  settingsText.setFont(terminalFont);
  settingsText.setFillColor(sf::Color::White);
  settingsText.setCharacterSize(90);
  settingsText.setString("Settings");

  this->settingsButton.setPosition(sf::Vector2f(265.f, 535.f));
  this->settingsButton.setText(settingsText);
  this->settingsButton.setCallbackFunction(
      [gameEngine]() -> void { gameEngine->setCurrentScene("settings"); });
  this->settingsButton.setColorOnHover(TEXT, sf::Color::Yellow);

  settingsText.setFillColor(sf::Color::Black);
  settingsText.setPosition(sf::Vector2f(80.f, 495.f));

  // Quit Button
  quitText.setFont(terminalFont);
  quitText.setFillColor(sf::Color::White);
  quitText.setCharacterSize(90);
  quitText.setString("Quit");

  this->quitButton.setPosition(sf::Vector2f(165.f, 625.f));
  this->quitButton.setText(quitText);
  this->quitButton.setCallbackFunction(
      [gameEngine]() -> void { gameEngine->getWindow()->close(); });
  this->quitButton.setColorOnHover(TEXT, sf::Color::Yellow);

  quitText.setFillColor(sf::Color::Black);
  quitText.setPosition(sf::Vector2f(80.f, 585.f));
}

Menu::~Menu() {}

void Menu::update(Engine *pEngine) {}

void Menu::render(sf::RenderWindow *pWindow) {
  pWindow->draw(this->backgroundRect);
  pWindow->draw(startText);
  pWindow->draw(settingsText);
  pWindow->draw(quitText);
  this->startButton.render(pWindow);
  this->settingsButton.render(pWindow);
  this->quitButton.render(pWindow);
}