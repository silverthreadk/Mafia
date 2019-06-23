#ifndef GAME_STATE_H_
#define GAME_STATE_H_

#include <string>

class GameState {
public:
    enum STATE {
        START = 0,
        DAYTIME,
        VOTING,
        FINAL_STATEMENT,
        YEAS_AND_NAYS,
        NIGHT,
        MAFIA_KILLING,
    };

private:
    STATE state_;

public:
    GameState();
    ~GameState();

    /**
     * ���� ���·� �����Ѵ�.
     */
    void changeNextState();

    /**
     * game state�� ���� �ý��� �޽����� �����Ѵ�.
     * @return message
     */
    const std::string& getMessage();

    //getter
    STATE getState() { return state_; }
};
#endif