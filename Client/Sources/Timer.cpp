/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Timer
*/

#include "../Include/Timer.hpp"
#include <thread>

Timer::Timer() {
    // Constructeur
}

Timer::~Timer() {
    // Destructeur
}

void Timer::waitFrame() noexcept {
    // Attendre jusqu'à ce qu'une certaine durée se soit écoulée
    auto timeSpan = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    while (timeSpan.count() < 41667) { // 41667 microsecondes = 1/24e de seconde
        std::this_thread::sleep_for(std::chrono::microseconds(1000)); // Attendre 1 milliseconde
        end(); // Mettre à jour le temps de fin
        timeSpan = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    }
}
