#include "Game.hpp"
#include "Logger.hpp"

namespace Bastet
{

Game::Game()
    : _width{50}
    , _height{50}
    , _well{_width, _height}
    , _wellWin{_height, 2 * _width}
{
    // Example usage of the logger
    // logger.log(INFO, "Program started.");
    // logger.log(DEBUG, "Debugging information.");
    // logger.log(ERROR, "An error occurred.");

    // getmaxyx(stdscr, _height, _width);
    // (getmaxx(stdscr) / 2) - 2
    // getmaxy(stdscr) - 2

    logF << "Program started: [" << _width << " " << _height << "][" << getmaxx(stdscr) << " " << getmaxy(stdscr) << "]";

    _colors.resize(_height, std::vector<Color>(_width, 0));

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

            RedrawWell(&_well, BlockType::O, blockPosition);
        }
    }
}

void Game::RedrawWell(const Well * w, BlockType b, const BlockPosition & p)
{
    for (int i = 0; i < _width; ++i)
        for (int j = 0; j < _height; ++j)
            _wellWin.DrawDot(Dot{i, j}, _colors[j][i]);

    for (const Dot & d : p.GetDots(b))
        _wellWin.DrawDot(d, GetColor(b));

    wrefresh(_wellWin);
}

void Game::Play()
{
}

} // namespace Bastet
