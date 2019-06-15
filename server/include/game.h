#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <string>

class Group;

class Game {
private:
    std::unique_ptr<Group> players_;    //플레이어 그룹
    std::unique_ptr<Group> mafia_;      //마피아 그룹
    std::unique_ptr<Group> citizen_;    //시민 그룹

public:
    Game();

    ~Game();
};

#endif