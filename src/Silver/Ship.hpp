#pragma once

namespace Silver
{

class Ship
{
public:
    Ship();
    ~Ship();

    void setPosition(int x, int y);

    int getDirection() const;
    int getX() const;
    int getY() const;

private:
    int _direction;

    int _x;
    int _y;
};

} // namespace Silver
