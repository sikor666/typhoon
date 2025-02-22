#pragma once

namespace Silver
{

class Ship
{
public:
    Ship();
    ~Ship();

    void setPosition(int posx, int posy);

    int getDirection() const;
    int getX() const;
    int getY() const;

private:
    int direction;

    int x;
    int y;
};

} // namespace Silver
