#pragma once

#include <SFML/Audio.hpp>

class SoundControler {
 private:
  SoundControler() {}

 public:
  static sf::Music menuMusic;
  static int effectsVolume;
  static int musicVolume;
  static int globalVolume;

  static int getEffectsVolume() { return effectsVolume; }
  static int getMusicVolume() { return musicVolume; }
  static int getGlobalsVolume() { return globalVolume; }

  static int getFormatedEffectsVolume() {
    return effectsVolume * globalVolume / 100.f;
  }
  static int getFormatedMusicVolume() {
    return musicVolume * globalVolume / 100.f;
  }

  static void setEffectsVolume(int value) { effectsVolume = value; }
  static void setMusicVolume(int value) {
    musicVolume = value;
    menuMusic.setVolume(getFormatedMusicVolume());
  }
  static void setGlobalsVolume(int value) {
    globalVolume = value;
    menuMusic.setVolume(getFormatedMusicVolume());
  }

  static void initGlobalMusic() {
    menuMusic.openFromFile("assets/sounds/music.ogg");
    menuMusic.setVolume(SoundControler::getFormatedMusicVolume());
    menuMusic.setLoop(true);
    menuMusic.play();
  }
};
