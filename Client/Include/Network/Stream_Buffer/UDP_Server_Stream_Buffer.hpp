/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Server_Stream_Buffer
*/

#ifndef UDP_SERVER_STREAM_BUFFER_HPP
    #define UDP_SERVER_STREAM_BUFFER_HPP

    #include "A_Stream_Buffer.hpp"
    #include <cstddef>

    // Structure pour stocker les données spécifiques au serveur UDP
    struct UDP_Server_Stream_BufferData {
        int index;
        int spriteX;
        int spriteY;
        int spriteWidth;
        int spriteHeight;
        int x;
        int y;
    };

    class UDP_Server_Stream_Buffer : public A_Stream_Buffer {
    public:
        UDP_Server_Stream_Buffer();
        ~UDP_Server_Stream_Buffer() override = default;

        // Méthode pour écrire les données du serveur dans le tampon
        void write(const UDP_Server_Stream_BufferData &data);

        // Méthode pour lire les données du serveur depuis le tampon
        UDP_Server_Stream_BufferData read(std::size_t size);
    };

#endif // UDP_SERVER_STREAM_BUFFER_HPP
