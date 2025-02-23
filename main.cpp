#include "Bastet/Game.hpp"
#include "Logger.hpp"
#include "Silver/Game.hpp"

int main()
{
    try
    {
        // Bastet::Game{}.Play();
        Silver::Game{}.run();
    }
    catch (std::exception & ex)
    {
        logF << ex.what();
    }

    return 0;
}
