#include "game.h"
#include "group.h"

Game::Game()
{
    players_ = std::make_unique<Group>();
    mafia_ = std::make_unique<Group>();
    citizen_ = std::make_unique<Group>();
}

Game::~Game()
{
}