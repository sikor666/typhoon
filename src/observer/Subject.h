/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

#pragma once

#include "ISubject.h"

#include <iostream>
#include <list>

class Subject : public ISubject
{
public:
    Subject() { logW << "Hi, I'm the Subject."; }

    ~Subject() override { logW << "Goodbye, I was the Subject."; }

    /**
     * The subscription management methods.
     */
    void Attach(IObserver * observer) override { list_observer_.push_back(observer); }
    void Detach(IObserver * observer) override { list_observer_.remove(observer); }
    void Notify() override
    {
        HowManyObserver();

        for (auto * observer : list_observer_)
        {
            observer->Update(message_);
        }
    }

    void CreateMessage(const std::string & message)
    {
        message_ = message;
        Notify();
    }

    void HowManyObserver() { logW << "There are " << list_observer_.size() << " observers in the list."; }

    /**
     * Usually, the subscription logic is only a fraction of what a Subject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic()
    {
        message_ = "change message message";
        Notify();
        logW << "I'm about to do some thing important.";
    }

private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};
