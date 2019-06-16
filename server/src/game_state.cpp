#include "game_state.h"

GameState::GameState()
{
    state_ = STATE::START;
}

GameState::~GameState()
{
}

void GameState::changeNextState()
{
    switch (state_) {
        case STATE::START: {
            state_ = STATE::DAYTIME;
            break;
        }
        case STATE::DAYTIME: {
            state_ = VOTING;
            break;
        }
        case STATE::VOTING: {
            state_ = STATE::FINAL_STATEMENT;
            break;
        }
        case STATE::FINAL_STATEMENT: {
            state_ = STATE::YEAS_AND_NAYS;
            break;
        }
        case STATE::YEAS_AND_NAYS: {
            state_ = STATE::NIGHT;
            break;
        }
        case STATE::NIGHT: {
            state_ = STATE::MAFIA_KILLING;
            break;
        }
        case STATE::MAFIA_KILLING: {
            state_ = STATE::DAYTIME;
            break;
        }
    }
}