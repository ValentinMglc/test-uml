/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(boost::asio::ip::udp::endpoint endpoint, int id) : _endpoint(endpoint), _id(id)
{
}

Player::~Player()
{
}

boost::asio::ip::udp::endpoint Player::getEndpoint() const
{
    return this->_endpoint;
}

void Player::setEndpoint(boost::asio::ip::udp::endpoint endpoint)
{
    this->_endpoint = endpoint;
}

int Player::getId() const
{
    return this->_id;
}
