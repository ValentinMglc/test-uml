/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Music
*/

#include "../Include/Music.hpp"
#include <iostream>

Music::Music(const std::string &path) {
    if (!music.openFromFile(path)) {
        throw std::runtime_error("Failed to open music file: " + path);
    }
    music.setLoop(false);
}

Music::~Music() {
    // Destructeur
}

void Music::play() {
    music.play();
}

void Music::replay() {
    music.stop();
    music.play();
}

void Music::stop() {
    music.stop();
}

void Music::setRepeatable(bool repeat) {
    music.setLoop(repeat);
}

void Music::setVolume(float volume) {
    music.setVolume(volume);
}
