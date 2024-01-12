/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Server_Stream_Buffer
*/

#include "../../../Include/Network/Stream_Buffer/UDP_Server_Stream_Buffer.hpp"

UDP_Server_Stream_Buffer::UDP_Server_Stream_Buffer()
    : A_Stream_Buffer() {
    // Constructeur initialise l'objet parent AStreamBuffer
}

void UDP_Server_Stream_Buffer::write(const UDP_Server_Stream_BufferData &data) {
    A_Stream_Buffer::write(data.index);
    A_Stream_Buffer::write(data.spriteX);
    A_Stream_Buffer::write(data.spriteY);
    A_Stream_Buffer::write(data.spriteWidth);
    A_Stream_Buffer::write(data.spriteHeight);
    A_Stream_Buffer::write(data.x);
    A_Stream_Buffer::write(data.y);
}

UDP_Server_Stream_BufferData UDP_Server_Stream_Buffer::read(std::size_t size) {
    UDP_Server_Stream_BufferData data = {-1, -1, -1, -1, -1, -1, -1};

    streamBuffer.commit(size);
    inputStream.read(reinterpret_cast<char *>(&data.index), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.spriteX), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.spriteY), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.spriteWidth), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.spriteHeight), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.x), sizeof(int));
    inputStream.read(reinterpret_cast<char *>(&data.y), sizeof(int));
    return data;
}
