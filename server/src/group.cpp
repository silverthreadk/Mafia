#include "group.h"
#include "player.h"

void Subject::addObserver(std::shared_ptr<Observer> observer)
{
    observers_.insert(observer);
}

void Subject::removeObserver(std::shared_ptr<Observer> observer)
{
    observers_.erase(observer);
}

void Subject::notify(const std::string& msg)
{
    for (auto observer : observers_) {
        observer->onNotify(msg);
    }
}


void Group::notifyObservers(const std::string& msg) {
    notify(msg);
}
