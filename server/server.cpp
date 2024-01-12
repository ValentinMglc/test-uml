/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Server
*/

#include "includes/server.hpp"

Server::Server(boost::asio::io_service& io_service, std::shared_ptr<std::list<ClientData>> clientDataList) :
_socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080)),
_timer(io_service), _clientActions(clientDataList), _lobbyManager() {

    std::cout << "Server listening on : " << _socket.local_endpoint().address().to_string() <<
    ":" << _socket.local_endpoint().port() << std::endl;

    start_receive();
}

Server::~Server()
{
}

void Server::start_receive() {
    _socket.async_receive_from(
        boost::asio::buffer(_recv_buffer), _remote_endpoint,
        [this](auto error, auto bytes_recvd) {
            if (!error) {
                handle_receive(error, bytes_recvd);
            } else {
                std::cerr << "Receive error: " << error.message() << std::endl;
                _socket.close();
            }
        });
}

void Server::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred) {
    ClientData clientData;
    std::istringstream archive_stream(std::string(_recv_buffer.data(), bytes_transferred));
    boost::archive::text_iarchive archive(archive_stream);
    archive >> clientData;

    std::cout << "Received " << bytes_transferred << " bytes from " << _remote_endpoint.address().to_string() << ":" << _remote_endpoint.port() << std::endl;
    std::cout << "Event: " << clientData.event << std::endl;
    std::cout << "Direction: " << clientData.direction << std::endl;

    if (clientData.event == TypeEnum::Actions::CREATE) {
        _lobbyManager.createLobby(_remote_endpoint);
        std::cout << "Player create new lobby" << std::endl;
        start_receive();
    }

    // Traitez la commande pour le lobby correspondant
    std::shared_ptr<Lobby> lobby = _lobbyManager.findLobbyByPlayerEndpoint(_remote_endpoint);

    printf("Lobby found: %d\n", lobby->getId());

    clientData.playerId = ( lobby->getId() * 10 ) + lobby->getPlayerByEndpoint(_remote_endpoint)->getId();

    TypeEnum::Actions action = static_cast<TypeEnum::Actions>(clientData.event);

    if (lobby) {
        // Commandes ne concernant que le serveur
        if (clientData.event >= 0 && clientData.event <= 102) {

            switch (clientData.event) {
                case TypeEnum::Actions::JOIN:
                    if (_lobbyManager.addPlayerToLobby(_remote_endpoint, clientData.direction)) {
                        std::cout << "Player joined lobby " << clientData.direction << std::endl;
                    } else {
                        std::cout << "Player failed to join lobby " << clientData.direction << std::endl;
                    }
                    break;
                case TypeEnum::Actions::READY:
                    std::cout << "A player is ready in lobby : " << lobby->getId() << std::endl;
                    break;
                default:
                    std::cerr << "Invalid event " << clientData.event << std::endl;
                    break;
            }

        } else if (clientData.event >= 200 && clientData.event <= 202) {
            // Commandes concernant une partie en cours
            if (clientData.direction < 300 || clientData.direction > 303) {
                std::cerr << "Invalid direction for event " << clientData.event << std::endl;
            } else {
                _clientActions->push_back(clientData);
            }
        }
    } else {
        std::cerr << "No lobby found for player with endpoint " << _remote_endpoint.address().to_string() << ":" << _remote_endpoint.port() << std::endl;
    }
    start_receive();
}

void Server::send(ServerData data) {
    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);
    archive << data;
    std::string message = archive_stream.str();

    for (auto lobby : _lobbyManager.getLobbies() ) {
        for (auto player : lobby->getPlayers()) {
            _socket.async_send_to(boost::asio::buffer(message), player->getEndpoint(),
            [this](auto error, auto bytes_sent) {
                if (!error) {
                    std::cout << "Sent " << bytes_sent << " bytes" << std::endl;
                } else {
                    std::cerr << "Send error: " << error.message() << std::endl;
                    _socket.close();
                }
            });
        }
    }
}
