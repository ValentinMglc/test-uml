/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** A_Stream_Buffer
*/

#include "../../../Include/Network/Stream_Buffer/A_Stream_Buffer.hpp"

A_Stream_Buffer::A_Stream_Buffer()
    : outputStream(&streamBuffer), inputStream(&streamBuffer) {
    // Constructeur initialise les flux de sortie et d'entrée
}

void A_Stream_Buffer::write(int i) {
    outputStream.write(reinterpret_cast<char *>(&i), sizeof(int));
    // Écrit un entier dans le flux de sortie
}

void A_Stream_Buffer::write(const std::string &str) {
    outputStream.write(str.c_str(), str.length());
    // Écrit une chaîne de caractères dans le flux de sortie
}

boost::asio::streambuf &A_Stream_Buffer::getStreamBuffer() {
    return streamBuffer;
    // Retourne le buffer de flux pour des opérations supplémentaires
}
