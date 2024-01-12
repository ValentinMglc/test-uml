/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** A_Stream_Buffer
*/

#ifndef A_STREAM_BUFFER_HPP
    #define A_STREAM_BUFFER_HPP

    #include <boost/asio.hpp>
    #include <string>
    #include <ostream>
    #include <istream>

    class A_Stream_Buffer {
    public:
        // Constructeur et destructeur
        A_Stream_Buffer();
        virtual ~A_Stream_Buffer() = default;

        // Méthodes pour écrire dans le tampon de flux
        void write(int i);
        void write(const std::string &str);

        // Accesseur pour obtenir le tampon de flux
        boost::asio::streambuf &getStreamBuffer();

    protected:
        boost::asio::streambuf streamBuffer;
        std::ostream outputStream;
        std::istream inputStream;
    };

#endif // A_STREAM_BUFFER_HPP
