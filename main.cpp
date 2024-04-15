#include "observer/Observer.h"
#include "observer/Subject.h"

#include <iostream>
#include <memory>

int Observer::static_number_ = 0;

void ClientCode()
{
    auto subject = std::make_shared<Subject>();
    auto observer1 = std::make_unique<Observer>(subject);
    auto observer2 = std::make_unique<Observer>(subject);
    auto observer3 = std::make_unique<Observer>(subject);

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    auto observer4 = std::make_unique<Observer>(subject);

    observer2->RemoveMeFromTheList();
    auto observer5 = std::make_unique<Observer>(subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();
}

int main()
{
    ClientCode();
}
