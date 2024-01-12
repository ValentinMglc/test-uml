/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Client
*/

#ifndef UDP_CLIENT_HPP
    #define UDP_CLIENT_HPP

    #include <boost/asio.hpp>
    #include <functional>
    #include "Queue.hpp"
    #include "Stream_Buffer/UDP_Server_Stream_Buffer.hpp"
    #include "Stream_Buffer/UDP_Client_Stream_Buffer.hpp"

    class UDP_Client {
    public:
        // Constructeur pour initialiser le client UDP
        UDP_Client(boost::asio::io_service &ioService, unsigned short port, std::shared_ptr<Queue<UDP_Server_Stream_BufferData>> queue);

        // Destructeur par défaut
        ~UDP_Client() = default;

        // Méthode pour envoyer des données via UDP
        void send(const UDP_Client_Stream_BufferData &data, const boost::asio::ip::udp::endpoint &endpoint);

    private:
        boost::asio::ip::udp::socket socket;
        boost::asio::ip::udp::endpoint endpoint;
        UDP_Server_Stream_Buffer serverStreamBuffer;
        UDP_Client_Stream_Buffer clientStreamBuffer;
        std::shared_ptr<Queue<UDP_Server_Stream_BufferData>> queue;

        // Méthode privée pour la lecture asynchrone des données
        void read();

        // Routine de traitement des données reçues
        void handleReceive(const boost::system::error_code &error, std::size_t bytesTransferred);
    };

#endif // UDPCLIENT_HPP
