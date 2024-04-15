#pragma once

#include "IObserver.h"
#include "ISubject.h"

#include "Logger.h"

#include <iostream>
#include <memory>

class Observer : public IObserver
{
public:
    Observer(std::shared_ptr<ISubject> subject)
        : subject_{std::move(subject)}
    {
        subject_->Attach(this);
        logI << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".";
        number_ = Observer::static_number_;
    }

    ~Observer() override { logI << "Goodbye, I was the Observer \"" << number_ << "\"."; }

    void Update(const std::string & message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void RemoveMeFromTheList()
    {
        subject_->Detach(this);
        logI << "Observer \"" << number_ << "\" removed from the list.";
    }

    void PrintInfo()
    {
        logI << "Observer \"" << number_ << "\": a new message is available --> " << message_from_subject_ << ".";
    }

private:
    std::shared_ptr<ISubject> subject_;
    std::string message_from_subject_;

    static int static_number_;
    int number_;
};
