#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <string>
#include <vector>

class Player;
class Group;

class Game {
private:
    std::vector<std::shared_ptr<Player> > player_info_; //플레이어 정보 
    std::unique_ptr<Group> players_;                    //플레이어 그룹
    std::unique_ptr<Group> mafia_;                      //마피아 그룹
    std::unique_ptr<Group> citizen_;                    //시민 그룹

    int number_of_mafia_;                               //마피아의 수

public:
    Game();

    ~Game();

    /*
     * 게임을 시작한다.
     */
    void play();

private:
    /*
     * 플레이어에게 역할을 할당한다.
     */
    void assignRoles();
};

#endif