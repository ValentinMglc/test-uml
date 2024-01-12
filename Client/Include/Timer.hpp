/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Timer
*/

#ifndef TIMER_HPP_
    #define TIMER_HPP_

    #include <chrono>

    class Timer {
    public:
        Timer();
        ~Timer();

        // Démarrer le chronomètre
        void start() noexcept {
            startTime = std::chrono::high_resolution_clock::now();
        }

        // Arrêter le chronomètre
        void end() noexcept {
            endTime = std::chrono::high_resolution_clock::now();
        }

        // Attendre jusqu'à la fin de la frame (implémentation spécifique au jeu)
        void waitFrame() noexcept;

        // Calculer la durée écoulée en microsecondes
        long long elapsedMicroseconds() const noexcept {
            return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        }

    private:
        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point endTime;
    };

#endif // TIMER_HPP_
