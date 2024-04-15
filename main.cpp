#include "observer/Observer.h"
#include "observer/Subject.h"

#include "fold_expressions.hpp"

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

void FoldExpressions()
{
    printer(1, 2, 3, "abc");

    std::vector<int> v;
    push_back_vec(v, 6, 2, 45, 12);
    push_back_vec(v, 1, 2, 9);
    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    static_assert(bswap<std::uint16_t>(0x1234u) == 0x3412u);
    static_assert(bswap<std::uint64_t>(0x0123456789abcdefull) == 0xefcdab8967452301ULL);
}

int main()
{
    ClientCode();
    FoldExpressions();
}
