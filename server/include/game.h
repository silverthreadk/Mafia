#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <string>

class Group;

class Game {
private:
    std::unique_ptr<Group> players_;
    std::unique_ptr<Group> mafia_;
    std::unique_ptr<Group> citizen_;

public:
    Game();

    ~Game();
};

#endif