#include "game.h"
#include "group.h"
#include "player.h"

#include <algorithm>
#include <memory>
#include <random>

Game::Game()
{
    players_ = std::make_unique<Group>();
    mafia_ = std::make_unique<Group>();
    citizen_ = std::make_unique<Group>();
}

Game::~Game()
{
}

void Game::play()
{
    assignRoles();
}

void Game::assignRoles()
{
    std::string mafia_list = "mafia list : ";

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(player_info_.begin(), player_info_.end(), g);

    for (int i = 0; i < number_of_mafia_; ++i) {
        mafia_->addObserver(player_info_[i]);
        players_->addObserver(player_info_[i]);
        mafia_list += (player_info_[i]->getName() + ((i == number_of_mafia_ - 1) ? std::string("") : std::string(", ")));
    }
    for (int i = number_of_mafia_; i < player_info_.size(); ++i) {
        citizen_->addObserver(player_info_[i]);
        players_->addObserver(player_info_[i]);
    }

    mafia_->notifyObservers(std::string("You are a mafia."));
    mafia_->notifyObservers(mafia_list);
    citizen_->notifyObservers(std::string("You are a citizen."));
}