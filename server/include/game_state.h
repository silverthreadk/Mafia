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
     * 다음 상태로 변경한다.
     */
    void changeNextState();

    /**
     * game state에 따른 시스템 메시지를 전달한다.
     * @return message
     */
    const std::string& getMessage();

    //getter
    STATE getState() { return state_; }
};
#endif