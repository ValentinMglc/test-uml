/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** main
*/

#include "../Include/Window.hpp"

int main() {
    // Création de la fenêtre du jeu avec la taille et le titre définis
    Menu::Window window(sf::VideoMode(MENU_DEFAULT_WIDTH, MENU_DEFAULT_HEIGHT), sf::String(MENU_TITLE));

    // Exécution de la boucle principale de la fenêtre
    window.loop();

    return 0;
}
