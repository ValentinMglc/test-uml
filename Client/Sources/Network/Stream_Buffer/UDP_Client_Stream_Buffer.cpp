/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Client_Stream_Buffer
*/

#include "../../../Include/Network/Stream_Buffer/UDP_Client_Stream_Buffer.hpp"
#include <iostream>

UDP_Client_Stream_Buffer::UDP_Client_Stream_Buffer()
    : A_Stream_Buffer() {
    // Constructeur initialise l'objet parent AStreamBuffer
}

void UDP_Client_Stream_Buffer::write(const UDP_Client_Stream_BufferData &data) {
    A_Stream_Buffer::write(data.playerName);
    A_Stream_Buffer::write(data.event);
    A_Stream_Buffer::write(data.direction);
}

UDP_Client_Stream_BufferData UDP_Client_Stream_Buffer::read() {
    UDP_Client_Stream_BufferData data = {"", -1, -1};

    std::getline(inputStream, data.playerName, '\0');
    if (!inputStream.eof()) {
        inputStream.read(reinterpret_cast<char *>(&data.event), sizeof(data.event));
    }
    if (!inputStream.eof()) {
        inputStream.read(reinterpret_cast<char *>(&data.direction), sizeof(data.direction));
    }

    return data;
}
