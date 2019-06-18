#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <string>
#include <vector>

class Player;
class Group;

class Game {
private:
    std::vector<std::shared_ptr<Player> > player_info_; //�÷��̾� ���� 
    std::unique_ptr<Group> players_;                    //�÷��̾� �׷�
    std::unique_ptr<Group> mafia_;                      //���Ǿ� �׷�
    std::unique_ptr<Group> citizen_;                    //�ù� �׷�

    int number_of_mafia_;                               //���Ǿ��� ��

public:
    Game();

    ~Game();

    /*
     * ������ �����Ѵ�.
     */
    void play();

private:
    /*
     * �÷��̾�� ������ �Ҵ��Ѵ�.
     */
    void assignRoles();
};

#endif