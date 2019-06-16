#ifndef GROUP_H_
#define GROUP_H_

#include <memory>
#include <set>
#include <string>

class Observer;

class Subject {
private:
    std::set<std::shared_ptr<Observer> > observers_;

public:
    void addObserver(std::shared_ptr<Observer> observer);

    void removeObserver(std::shared_ptr<Observer> observer);

protected:
    void notify(const std::string& msg);
};


class Group : public Subject { 
public:
    /**
     * 옵저버들에게 msg를 알린다.
     * @param msg 메시지
     */
    void notifyObservers(const std::string& msg);
};
#endif