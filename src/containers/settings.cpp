#include "settings.hpp"

Settings::Settings(Engine *pEngine) {
  // Background
  this->backgroundTexture.loadFromFile("assets/imgs/Settings.png");
  this->backgroundRect.setSize(sf::Vector2f(1280.f, 720.f));
  this->backgroundRect.setPosition(sf::Vector2f(0.f, 0.f));
  this->backgroundRect.setTexture(&this->backgroundTexture);

  // Master Button
  this->master.setBackground("assets/imgs/Pista.png");
  this->master.setButton("assets/imgs/Golden Wheel.png");
  this->master.setButtonOrigin(sf::Vector2f(23.5f, 23.5f));
  this->master.setPosition(sf::Vector2f(905.f, 254.f));
  this->master.setReference(MASTER);

  // Effects Button
  this->effects.setBackground("assets/imgs/Pista.png");
  this->effects.setButton("assets/imgs/Silver Wheel.png");
  this->effects.setButtonOrigin(sf::Vector2f(23.5f, 23.5f));
  this->effects.setPosition(sf::Vector2f(905.f, 376.f));
  this->effects.setReference(EFFECTS);

  // Music Button
  this->music.setBackground("assets/imgs/Pista.png");
  this->music.setButton("assets/imgs/Golden Wheel.png");
  this->music.setButtonOrigin(sf::Vector2f(23.5f, 23.5f));
  this->music.setPosition(sf::Vector2f(905.f, 498.f));
  this->music.setReference(MUSIC);

  this->terminalFont.loadFromFile("assets/fonts/Terminal.ttf");

  this->MasterText.setFont(this->terminalFont);
  this->MasterText.setCharacterSize(90);
  this->MasterText.setFillColor(sf::Color::Black);
  this->MasterText.setString("Master");
  this->MasterText.setPosition(sf::Vector2f(145.f, 174.f));

  this->EffectsText.setFont(this->terminalFont);
  this->EffectsText.setCharacterSize(90);
  this->EffectsText.setFillColor(sf::Color::Black);
  this->EffectsText.setString("Effects");
  this->EffectsText.setPosition(sf::Vector2f(145.f, 296.f));

  this->MusicText.setFont(this->terminalFont);
  this->MusicText.setCharacterSize(90);
  this->MusicText.setFillColor(sf::Color::Black);
  this->MusicText.setString("Music");
  this->MusicText.setPosition(sf::Vector2f(145.f, 418.f));

  this->backText.setFont(this->terminalFont);
  this->backText.setCharacterSize(40);
  this->backText.setFillColor(sf::Color::White);
  this->backText.setString("< Back");

  this->backButton.setPosition(sf::Vector2f(75.f, 25.f));
  this->backButton.setText(this->backText);
  this->backButton.setColorOnHover(TEXT, sf::Color::Yellow);
  this->backButton.setCallbackFunction(
      [pEngine]() -> void { pEngine->setCurrentScene("menu"); });

  this->backText.setFillColor(sf::Color::Black);
  this->backText.setPosition(15.f, 10.f);
}

Settings::~Settings() {}

void Settings::update(Engine *gameEngine) {}

void Settings::render(sf::RenderWindow *pWindow) {
  pWindow->draw(this->backgroundRect);

  pWindow->draw(MasterText);
  pWindow->draw(MusicText);
  pWindow->draw(EffectsText);

  this->master.render(pWindow);
  this->effects.render(pWindow);
  this->music.render(pWindow);

  pWindow->draw(this->backText);
  this->backButton.render(pWindow);
}