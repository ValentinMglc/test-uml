/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Timer
*/

#include <chrono>

#ifndef TIMER_HPP_
#define TIMER_HPP_

class Timer {
    public:
        Timer();
        ~Timer();
        inline void start() noexcept { _start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()); };
        inline void end() noexcept { _end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()); };
        void waitFrame() noexcept;
    protected:
    private:
        std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::microseconds> _start;
        std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::microseconds> _end;
};

#endif /* !TIMER_HPP_ */
