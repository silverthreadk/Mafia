#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Observer {
public:
    virtual ~Observer() {}

    virtual void onNotify(std::string msg) = 0;
};

class Player: public Observer {
private:
    int id_;
    int name_;
    int role_;
    int death_;

public:
    Player();

    ~Player();

    virtual void onNotify(std::string msg);
};

#endif