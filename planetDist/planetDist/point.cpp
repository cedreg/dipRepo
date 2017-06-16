#include "point.h"

int point::getX() const
{
    return x;
}

void point::setX(int value)
{
    x = value;
}

int point::getY() const
{
    return y;
}

void point::setY(int value)
{
    y = value;
}

point::point()
{

}

point::point(int x, int y)
{
    this->x = x;
    this->y = y;
}
