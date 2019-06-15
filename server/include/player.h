#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Observer {
public:
    virtual ~Observer() {}

    virtual void onNotify(const std::string& msg) = 0;
};

class Player: public Observer {
private:
    int id_;                //id
    std::string name_;      //이름
    int role_;              //역할
    int death_;             //죽음

public:
    Player(int id, std::string& name);

    ~Player();

    /**
     * player msg를 전달한다.
     * @param msg 메시지
     */
    virtual void onNotify(const std::string& msg);

    //getter
    std::string& getName() { return name_; }
};

#endif