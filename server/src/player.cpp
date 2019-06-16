#include "player.h"

Player::Player(int id, std::string& name) : id_(id), name_(name)
{  
}

Player::~Player()
{
}

void Player::onNotify(const std::string& msg)
{
}