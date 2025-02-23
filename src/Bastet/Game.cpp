#include "Game.hpp"
#include "Logger.hpp"

#include <algorithm>
#include <random>

namespace Bastet
{

Game::Game()
    : _screen{}
    , _well{_screen.getWidth() / 2, _screen.getHeight()}
{
    // logF << "Program started: [" << _width << " " << _height << "]";
}

void Game::Play()
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    while (true)
    {
        BlockType blockType = static_cast<BlockType>(distrib(gen));

        // assumes nodelay(stdscr,TRUE) has already been called
        BlockPosition blockPosition;

        // 🡠 🡡 🡢 🡣 🡤 🡥 🡦 🡧
        std::string str = "  ";

        while (true)
        {
            // break = tetromino locked

            auto keys = _screen.getKeys();

            if (std::ranges::contains(keys, 'a'))
            {
                str = "🡠🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Left, blockType, _well);
            }
            else if (std::ranges::contains(keys, 'd'))
            {
                str = "🡢🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Right, blockType, _well);
            }
            else if (std::ranges::contains(keys, 's'))
            {
                str = "🡣🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Down, blockType, _well);
            }
            else if (std::ranges::contains(keys, 'w'))
            {
                str = "🡡🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Up, blockType, _well);
            }
            else if (std::ranges::contains(keys, 'e'))
            {
                str = "🡥🕱";
            }
            else if (std::ranges::contains(keys, 'q'))
            {
                str = "🡤🕱";
            }
            else if (std::ranges::contains(keys, 'l'))
            {
                break;
            }
            else if (std::ranges::contains(keys, ' '))
            {
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.Drop(blockType, _well);
                break;
            }

            // keypress switch
            RedrawWell(blockType, blockPosition, str);
        }

        _well.Lock(blockType, blockPosition);

        RedrawWell(blockType, blockPosition, str);
    }
}

void Game::RedrawWell(BlockType b, const BlockPosition & p, const std::string & str)
{
    for (const auto & d : p.GetDots(b))
        _screen.draw(d.x, d.y, GetColor(b), str);

    _screen.refresh();
}

} // namespace Bastet
