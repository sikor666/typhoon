#include "Game.hpp"
#include "Logger.hpp"

#include <random>

namespace Bastet
{

Game::Game()
    : _width{getmaxx(stdscr) / 2}
    , _height{getmaxy(stdscr)}
    , _well{_width, _height}
    , _screen{_height, _width * 2, 0, 0}
{
    // Example usage of the logger
    // logger.log(INFO, "Program started.");
    // logger.log(DEBUG, "Debugging information.");
    // logger.log(ERROR, "An error occurred.");

    logF << "Program started: [" << _width << " " << _height << "]";

    _colors.resize(_height, std::vector<Color>(_width, 0));

    /*
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            // assumes nodelay(stdscr,TRUE) has already been called
            BlockPosition blockPosition{Dot{x, y}};

            LinesCompleted lc = _well.Lock(BlockType::O, blockPosition);
            // locks also into _colors
            for (const Dot & d : blockPosition.GetDots(BlockType::O))
                if (d.y >= 0)
                    _colors[d.y][d.x] = GetColor(BlockType::O);

            RedrawWell(&_well, BlockType::O, blockPosition, "  ");
        }
    }
    */
}

void Game::DropBlock(Well * well, BlockType blockType)
{
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
            blockPosition.MoveIfPossible(Left, blockType, well);
        }
        else if (ch == 'd')
        {
            str = "🡢🕱";
            blockPosition.MoveIfPossible(Right, blockType, well);
        }
        else if (ch == 's')
        {
            str = "🡣🕱";
            blockPosition.MoveIfPossible(Down, blockType, well);
        }
        else if (ch == 'w')
        {
            str = "🡡🕱";
            blockPosition.MoveIfPossible(Up, blockType, well);
        }
        else if (ch == 'e')
        {
            str = "🡥🕱";
            blockPosition.MoveIfPossible(RotateCW, blockType, well);
        }
        else if (ch == 'q')
        {
            str = "🡤🕱";
            blockPosition.MoveIfPossible(RotateCCW, blockType, well);
        }
        else if (ch == 'l')
        {
            break;
        }
        else if (ch == ' ')
        {
            blockPosition.Drop(blockType, well);
            break;
        }

        // keypress switch
        RedrawWell(well, blockType, blockPosition, str);
    }

    LinesCompleted lc = well->Lock(blockType, blockPosition);
    // locks also into _colors
    for (const Dot & d : blockPosition.GetDots(blockType))
        if (d.y >= 0)
            _colors[d.y][d.x] = GetColor(blockType);

    RedrawWell(well, blockType, blockPosition, str);
}

void Game::RedrawWell(Well * w, BlockType b, const BlockPosition & p, const std::string & str)
{
    /*
    for (int i = 0; i < _width; ++i)
        for (int j = 0; j < _height; ++j)
            _screen.DrawDot(Dot{i, j}, _colors[j][i], "  ");
    */

    for (const Dot & d : p.GetDots(b))
        _screen.DrawDot(d, GetColor(b), str);

    wbkgd(_screen, COLOR_PAIR(6));
    wrefresh(_screen);
}

void Game::Play()
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    while (true)
    {
        // ignores the keys pressed during the next block calculation
        while (getch() != ERR)
            ;

        auto current = static_cast<BlockType>(distrib(gen));

        logF << "Current block type: " << current;

        DropBlock(&_well, current);
    }
}

} // namespace Bastet
