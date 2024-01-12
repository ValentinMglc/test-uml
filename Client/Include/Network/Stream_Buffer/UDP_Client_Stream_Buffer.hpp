/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Client_Stream_Buffer
*/

#ifndef UDP_CLIENT_STREAM_BUFFER_HPP
#define UDP_CLIENT_STREAM_BUFFER_HPP

#include "A_Stream_Buffer.hpp"
#include <string>

// Structure pour stocker les données spécifiques au client UDP
struct UDP_Client_Stream_BufferData {
    std::string playerName;
    int event;
    int direction;
};

class UDP_Client_Stream_Buffer : public A_Stream_Buffer {
public:
    UDP_Client_Stream_Buffer();
    ~UDP_Client_Stream_Buffer() override = default;

    // Méthode pour écrire les données de client dans le tampon
    void write(const UDP_Client_Stream_BufferData &data);

    // Méthode pour lire les données de client depuis le tampon
    UDP_Client_Stream_BufferData read();
};

#endif // UDP_CLIENT_STREAM_BUFFER_HPP
