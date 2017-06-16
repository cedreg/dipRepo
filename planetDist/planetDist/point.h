#ifndef POINT_H
#define POINT_H


class point
{
private:
    int x;
    int y;
public:
    point();
    point(int x, int y);

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // POINT_H
