#include "rottestclass.h"
#include <QDebug>
#include <iostream>
int rotTestClass::getActSize() const
{
    return actSize;
}

rotTestClass::rotTestClass(int maxSize)
{
    actSize = 0;
    size = maxSize;
    a = new int [size];
}

rotTestClass::rotTestClass(const rotTestClass &other)
{
    if(this != &other)
    {
        if(other.size != size)
        {
            delete a;
            size = other.size;
            a = new int [size];
        }
        actSize = other.actSize;
        for(int i = 0; i < actSize; i++)
        {
            a[i] = other.a[i];
        }
    }
}

rotTestClass& rotTestClass::operator=(const rotTestClass &other)
{
    if(this != &other)
    {
        if(other.size != size)
        {
            delete a;
            size = other.size;
            a = new int [size];
        }
        actSize = other.actSize;
        for(int i = 0; i < actSize; i++)
        {
            a[i] = other.a[i];
        }
    }
    return *this;
}

rotTestClass::~rotTestClass()
{
}

bool rotTestClass::push_back(int val)
{

    if (actSize < size)
    {
        a[actSize++] = val;
        return true;
    }
    else
    {
        return false;
    }
}

void rotTestClass::COUT()
{
    for (int i = 0; i < actSize; i++)
    {
        qDebug() << a[i];
    }
}
