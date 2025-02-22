#pragma once

namespace Silver
{

class Ship
{
public:
    Ship();
    ~Ship();

    int getDirection() const;
    int getX() const;
    int getY() const;

private:
    int direction;

    int x;
    int y;
};

} // namespace Silver
