#include "Ui.hpp"

#include <unistd.h>

namespace Bastet
{

Ui::Ui()
    : _level{0}
    , _points{0}
    , _lines{0}
    , _width{10}
    , _height{20}
    , _wellWin{_height, 2 * _width}
    , _nextWin{5, 14, _wellWin.GetMinY(), _wellWin.GetMaxX() + 1}
    , _scoreWin{11, 14, _nextWin.GetMaxY(), _nextWin.GetMinX()}
{
    _colors.resize(_height, std::vector<Color>(_width, 0));
}

void Ui::RedrawStatic()
{
    erase();
    wrefresh(stdscr);
    _wellWin.RedrawBorder();
    _scoreWin.RedrawBorder();

    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(17));
    mvwprintw(_scoreWin, 1, 0, "Score:");
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(18));
    mvwprintw(_scoreWin, 3, 0, "Lines:");
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(19));
    mvwprintw(_scoreWin, 5, 0, "Level:");
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(18));
    mvwprintw(_scoreWin, 7, 0, "Width:");
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(19));
    mvwprintw(_scoreWin, 9, 0, "Height:");
    wrefresh(_scoreWin);
}

// must be <1E+06, because it should fit into a timeval usec field(see man select)
// FIXME: static const std::array<int, 10> delay = {{999999, 770000, 593000, 457000, 352000, 271000, 208000, 160000,
// 124000, 95000}};

void Ui::DropBlock(BlockType blockType, Well * well)
{
    // assumes nodelay(stdscr,TRUE) has already been called
    BlockPosition blockPosition;

    RedrawWell(*well, blockType, blockPosition);
    RedrawScore();

    while (1)
    {
        // break = tetromino locked
        // keypress
        int ch = getch();
        if (ch == 'a')
            blockPosition.MoveIfPossible(Left, blockType, *well);
        else if (ch == 'd')
            blockPosition.MoveIfPossible(Right, blockType, *well);
        else if (ch == 's')
        {
            bool val = blockPosition.MoveIfPossible(Down, blockType, *well);
            if (val)
            {
            }
            else
                break;
        }
        else if (ch == 'w')
            blockPosition.MoveIfPossible(Up, blockType, *well);
        else if (ch == 'e')
            blockPosition.MoveIfPossible(RotateCW, blockType, *well);
        else if (ch == 'q')
            blockPosition.MoveIfPossible(RotateCCW, blockType, *well);
        else if (ch == 'l')
            break;
        else if (ch == ' ')
        {
            blockPosition.Drop(blockType, *well);
            break;
        }
        else
        {
        } // default...

        // keypress switch
        RedrawWell(*well, blockType, blockPosition);
    } // while(1)

    LinesCompleted lc = well->Lock(blockType, blockPosition);
    // locks also into _colors
    for (const Dot & d : blockPosition.GetDots(blockType))
        if (d.y >= 0)
            _colors[d.y][d.x] = GetColor(blockType);

    RedrawWell(*well, blockType, blockPosition);
    RedrawScore();
}

void Ui::RedrawWell(const Well & w, BlockType b, const BlockPosition & p)
{
    for (int i = 0; i < _width; ++i)
        for (int j = 0; j < _height; ++j)
        {
            Dot d = {i, j};
            _wellWin.DrawDot(d, _colors[j][i]);
        }

    for (const Dot & d : p.GetDots(b))
        _wellWin.DrawDot(d, GetColor(b));

    wrefresh(_wellWin);
}

void Ui::RedrawScore()
{
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(17));
    mvwprintw(_scoreWin, 1, 7, "%6d", _points);
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(18));
    mvwprintw(_scoreWin, 3, 7, "%6d", _lines);
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(19));
    mvwprintw(_scoreWin, 5, 7, "%6d", _level);
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(18));
    mvwprintw(_scoreWin, 7, 7, "%6d", _width);
    wattrset((WINDOW *)_scoreWin, COLOR_PAIR(19));
    mvwprintw(_scoreWin, 9, 7, "%6d", _height);
    wrefresh(_scoreWin);
}

void Ui::CompletedLinesAnimation(const LinesCompleted & completed)
{
    wattrset((WINDOW *)_wellWin, COLOR_PAIR(22));
    for (int i = 0; i < 6; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if (completed._completed[k])
            {
                wmove(_wellWin, completed._baseY + k, 0);
                whline(_wellWin, i % 2 ? ' ' : ':', _width * 2);
            }
            wrefresh(_wellWin);
            usleep(500000 / 6);
        }
    }
}

void Ui::Play()
{
    _level = 0;
    _points = 0;
    _lines = 0;

    RedrawStatic();

    Well w{_width, _height};
    nodelay(stdscr, TRUE);

    try
    {
        int i = 0;
        while (true)
        {
            while (getch() != ERR)
                ; // ignores the keys pressed during the next block calculation
            BlockType current = BlockType(i++ % 7);
            DropBlock(current, &w);
        }
    }
    catch (GameOver & go)
    {
    }
}

} // namespace Bastet
