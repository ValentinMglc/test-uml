/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Game
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

    #include <SFML/Graphics.hpp>
	#include <boost/asio.hpp>
	#include <queue>
	#include "Network/UDP_Client.hpp"
	#include "Image.hpp"
	#include "Queue.hpp"
	#include "Paralax.hpp"
	#include "Music.hpp"
	#include "Constants/Constants.hpp"

	// Utilisation des chemins définis dans les constantes
	#define PLAYER1_SPRITE	"Client/Assets/player1.png"
    #define PLAYER2_SPRITE	"Client/Assets/player2.png"
    #define PLAYER3_SPRITE	"Client/Assets/player3.png"
    #define PLAYER4_SPRITE	"Client/Assets/player4.png"
	#define ENEMY1_SPRITE	"Client/Assets/enemy1.png"
    #define ENEMY2_SPRITE	"Client/Assets/enemy2.png"
    #define ENEMY3_SPRITE	"Client/Assets/enemy3.png"
    #define ENEMY4_SPRITE	"Client/Assets/enemy4.png"
	#define BULLET_SPRITE	"Client/Assets/bullet.png"

	// Taille standard des sprites et ports UDP
	#define SPRITE_SIZE			64
	#define STD_SERV_UDP_PORT	8080
	#define STD_CLI_UDP_PORT	8081

	class Game {
		public:
			Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso, const std::string &playername);
			~Game();
			void run();

		private:
			bool handleGameEvents();
			void displayGame();
			void processPlayerInput(sf::Event &event);
			void sendPlayerAction();
			void processGameFrame();

			sf::RenderWindow &_window;
			std::string _ip;
			std::unique_ptr<Image> _player1;
            std::unique_ptr<Image> _player2;
            std::unique_ptr<Image> _player3;
            std::unique_ptr<Image> _player4;
			std::unique_ptr<Image> _enemy1;
			std::unique_ptr<Image> _enemy2;
            std::unique_ptr<Image> _enemy3;
            std::unique_ptr<Image> _enemy4;
			std::unique_ptr<Image> _bullet;
			std::string _playerName;
			std::shared_ptr<Queue<struct UDP_Server_Stream_BufferData>> _queueClass;
			boost::asio::ip::udp::endpoint _endpoint;
			std::unique_ptr<UDP_Client> _udpClient;
			Music _shootSound;
			Paralax _parallax;
			std::queue<struct UDP_Client_Stream_BufferData> _playerActions;
	};

#endif /* !GAME_HPP_ */
