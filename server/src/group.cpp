#include "group.h"
#include "player.h";

void Group::addObserver(std::shared_ptr<Observer> observer)
{
    observers_.insert(observer);
}

void Group::removeObserver(std::shared_ptr<Observer> observer)
{
    observers_.erase(observer);
}

void Group::notify(std::string msg)
{
    for (auto observer : observers_) {
        observer->onNotify(msg);
    }
}