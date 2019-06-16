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
    std::string name_;      //�̸�
    int role_;              //����
    int death_;             //����

public:
    Player(int id, std::string& name);

    ~Player();

    /**
     * player msg�� �����Ѵ�.
     * @param msg �޽���
     */
    virtual void onNotify(const std::string& msg);

    //getter
    std::string& getName() { return name_; }
};

#endif