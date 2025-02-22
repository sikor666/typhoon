#include "Game.hpp"
#include "Logger.hpp"

#include <curses.h>

#include <random>

namespace Bastet
{

Game::Game()
    : _width{getmaxx(stdscr) / 2}
    , _height{getmaxy(stdscr)}
    , _well{_width, _height}
    , _screen{_height, _width * 2, 0, 0}
{
    logF << "Program started: [" << _width << " " << _height << "]";
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
            // keypress
            int ch = getch();

            if (ch == 'a')
            {
                str = "🡠🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Left, blockType, _well);
            }
            else if (ch == 'd')
            {
                str = "🡢🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Right, blockType, _well);
            }
            else if (ch == 's')
            {
                str = "🡣🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Down, blockType, _well);
            }
            else if (ch == 'w')
            {
                str = "🡡🕱";
                RedrawWell(BlockType::O, blockPosition, "  ");
                blockPosition.MoveIfPossible(Up, blockType, _well);
            }
            else if (ch == 'e')
            {
                str = "🡥🕱";
                blockPosition.MoveIfPossible(RotateCW, blockType, _well);
            }
            else if (ch == 'q')
            {
                str = "🡤🕱";
                blockPosition.MoveIfPossible(RotateCCW, blockType, _well);
            }
            else if (ch == 'l')
            {
                break;
            }
            else if (ch == ' ')
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
        _screen.draw(d, GetColor(b), str);

    _screen.refresh();
}

} // namespace Bastet
