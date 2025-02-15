#pragma once

#include "BorderedWindow.hpp"
#include "Curses.hpp"
#include "Well.hpp"

namespace Bastet
{

class Ui
{
public:
    Ui();

    void RedrawStatic(); // redraws the "static" parts of the screen
    void RedrawWell(const Well * well, BlockType falling, const BlockPosition & pos);
    void RedrawScore();
    void CompletedLinesAnimation(const LinesCompleted & completed);
    void DropBlock(BlockType blockType, Well * well); // returns <score,lines>

    void Play();

private:
    //    difficulty_t _difficulty; //unused for now
    int _level;
    int _points;
    int _lines;

    int _width;
    int _height;

    Curses _curses;
    BorderedWindow _wellWin;
    BorderedWindow _nextWin;
    BorderedWindow _scoreWin;

    std::vector<std::vector<Color>> _colors;
};

} // namespace Bastet
