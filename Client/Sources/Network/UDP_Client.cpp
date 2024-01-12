/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** UDP_Client
*/

#include "../../Include/Network/UDP_Client.hpp"
#include <iostream>

UDP_Client::UDP_Client(boost::asio::io_service &ioService, unsigned short port, std::shared_ptr<Queue<UDP_Server_Stream_BufferData>> queue)
    : socket(ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
      queue(queue) {
    this->read();
}

void UDP_Client::send(const UDP_Client_Stream_BufferData &data, const boost::asio::ip::udp::endpoint &endpoint) {
    clientStreamBuffer.write(data);
    socket.send_to(clientStreamBuffer.getStreamBuffer().data(), endpoint);
    clientStreamBuffer.getStreamBuffer().consume(clientStreamBuffer.getStreamBuffer().size());
}

void UDP_Client::read() {
    auto buff = serverStreamBuffer.getStreamBuffer().prepare(512);
    socket.async_receive_from(buff, endpoint, std::bind(&UDP_Client::handleReceive, this, std::placeholders::_1, std::placeholders::_2));
}

void UDP_Client::handleReceive(const boost::system::error_code &error, std::size_t size) {
    if (!error) {
        auto data = serverStreamBuffer.read(size);
        queue->push(data);
        this->read();
    } else {
        std::cerr << "Error on receive: " << error.message() << std::endl;
        socket.close();
    }
}
