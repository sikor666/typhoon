#pragma once

class ISubject
{
public:
    virtual ~ISubject() = default;

    virtual void Attach(IObserver * observer) = 0;
    virtual void Detach(IObserver * observer) = 0;
    virtual void Notify() = 0;
};
