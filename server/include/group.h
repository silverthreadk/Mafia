#ifndef GROUP_H_
#define GROUP_H_

#include <memory>
#include <set>
#include <string>

class Observer;

class Group {
private:
    std::set<std::shared_ptr<Observer> > observers_;

public:
    void addObserver(std::shared_ptr<Observer> observer);

    void removeObserver(std::shared_ptr<Observer> observer);

protected:
    void notify(std::string msg);
};

#endif