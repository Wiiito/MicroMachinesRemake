#include "loseScreen.hpp"

LoseScreen::LoseScreen(Engine *pEngine) {
  this->backgroundTexture.loadFromFile("assets/imgs/lose.png");
  this->background.setPosition(sf::Vector2f(0, 0));
  this->background.setSize(sf::Vector2f(1280, 720));
  this->background.setTexture(&this->backgroundTexture);

  this->font.loadFromFile("assets/fonts/Terminal.ttf");

  this->playAgainText.setFont(this->font);
  this->playAgainText.setFillColor(sf::Color::White);
  this->playAgainText.setCharacterSize(90);
  this->playAgainText.setString("Play Again");

  this->playAgainButton.setPosition(sf::Vector2f(640.f, 400.f));
  this->playAgainButton.setText(this->playAgainText);
  this->playAgainButton.setCallbackFunction(
      [pEngine]() -> void { pEngine->setCurrentScene("game"); });
  this->playAgainButton.setColorOnHover(TEXT, sf::Color::Yellow);

  this->playAgainText.setFillColor(sf::Color::Black);
  this->playAgainText.setOrigin(
      this->playAgainText.getLocalBounds().width / 2,
      this->playAgainText.getLocalBounds().height / 2);
  this->playAgainText.setPosition(645.f, 405.f);

  this->menuText.setFont(this->font);
  this->menuText.setFillColor(sf::Color::White);
  this->menuText.setCharacterSize(90);
  this->menuText.setString("Menu");

  this->menuButton.setPosition(sf::Vector2f(640.f, 520.f));
  this->menuButton.setText(this->menuText);
  this->menuButton.setCallbackFunction(
      [pEngine]() -> void { pEngine->setCurrentScene("menu"); });
  this->menuButton.setColorOnHover(TEXT, sf::Color::Yellow);

  this->menuText.setFillColor(sf::Color::Black);
  this->menuText.setOrigin(this->menuText.getLocalBounds().width / 2,
                           this->menuText.getLocalBounds().height / 2);
  this->menuText.setPosition(645.f, 525.f);
}

LoseScreen::~LoseScreen() {}

void LoseScreen::update(Engine *pEngine) {}

void LoseScreen::render(sf::RenderWindow *pWindow) {
  pWindow->setView(
      sf::View(sf::Vector2f(pWindow->getSize().x / 2, pWindow->getSize().y / 2),
               sf::Vector2f(pWindow->getSize().x, pWindow->getSize().y)));
  pWindow->draw(this->background);
  pWindow->draw(this->menuText);
  pWindow->draw(this->playAgainText);
  this->playAgainButton.render(pWindow);
  this->menuButton.render(pWindow);
}