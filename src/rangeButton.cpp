#include "headers/rangeButton.hpp"

/**
 * Essa classe não é generica e foi feita para uso somente com sounds.hpp
 * This is not and generic class and it was made to use only with souds.hpp
 */

void RangeButton::updatePosition() {
  int volume;

  switch (this->references) {
    case ButtonReference::MASTER:
      volume = SoundControler::getGlobalsVolume();
      break;

    case ButtonReference::EFFECTS:
      volume = SoundControler::getEffectsVolume();
      break;

    case ButtonReference::MUSIC:
      volume = SoundControler::getMusicVolume();
      break;
  }
  this->button.setPosition(
      (this->pos.x - this->background.getLocalBounds().width / 2) +
          ((this->background.getLocalBounds().width * volume) / 100),
      this->pos.y);
}

RangeButton::RangeButton() {}

RangeButton::~RangeButton() {}

/**
 * Set background sprite
 * @param std::string path to background texture
 * @return void
 * @public
 */
void RangeButton::setBackground(std::string path) {
  this->backgroundTexture.loadFromFile(path);

  this->background.setSize(sf::Vector2f(this->backgroundTexture.getSize().x,
                                        this->backgroundTexture.getSize().y));

  this->background.setTexture(&this->backgroundTexture);
  this->background.setOrigin(this->background.getLocalBounds().width / 2,
                             this->background.getLocalBounds().height / 2);
}

/**
 * Set button sprite
 * @param std::string path to button texture
 * @return void
 * @public
 */
void RangeButton::setButton(std::string path) {
  this->buttonTexture.loadFromFile(path);

  this->button.setSize(sf::Vector2f(this->buttonTexture.getSize().x,
                                    this->buttonTexture.getSize().y));
  this->button.setTexture(&this->buttonTexture);
}

/**
 * Set all buton class position
 * @param sf::Vector2f new position
 * @return void
 * @public
 */
void RangeButton::setPosition(sf::Vector2f pos) {
  this->pos = pos;
  this->background.setPosition(pos);
}

/**
 * Set button references
 * @param ButtonReference set reference (MASTER, EFFECTS, MUSIC)
 * @return void
 * @public
 */
void RangeButton::setReference(ButtonReference ref) {
  this->references = ref;
  this->updatePosition();
}

/**
 * Set button sprite origin
 * @param sf::Vector2f new origin
 * @return void
 * @public
 */
void RangeButton::setButtonOrigin(sf::Vector2f pos) {
  this->button.setOrigin(pos);
}

/**
 * Draws button on screen
 * @param sf::RenderWindow window that will recive button
 * @public
 * @return void
 */
void RangeButton::render(sf::RenderWindow *pWindow) {
  sf::Vector2i mousePos = sf::Mouse::getPosition(*pWindow);
  sf::FloatRect backGroundPosition = this->background.getGlobalBounds();

  if (backGroundPosition.contains(mousePos.x, mousePos.y)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      int volume = ((mousePos.x - backGroundPosition.left) /
                    this->background.getSize().x) *
                   100;

      switch (this->references) {
        case ButtonReference::MASTER:
          SoundControler::setGlobalsVolume(volume);
          break;

        case ButtonReference::EFFECTS:
          SoundControler::setEffectsVolume(volume);
          break;

        case ButtonReference::MUSIC:
          SoundControler::setMusicVolume(volume);
          break;
      }

      this->updatePosition();
    }
  }

  pWindow->draw(this->background);
  pWindow->draw(this->button);
}