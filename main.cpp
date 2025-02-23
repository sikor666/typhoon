#include "Logger.hpp"
#include "Silver/Game.hpp"

int main()
{
    try
    {
        Silver::Game{}.run();
    }
    catch (std::exception & ex)
    {
        dbgC << ex.what();
    }

    return 0;
}
