#ifndef ROTTESTCLASS_H
#define ROTTESTCLASS_H
#include <utility>

class rotTestClass
{
private:
    int* a;
    int actSize;
    int size;

public:
    rotTestClass(int);
    rotTestClass(const rotTestClass &);
    rotTestClass& operator= (const rotTestClass&);
    ~rotTestClass();
    bool push_back(int val);
    void COUT();

    int getActSize() const;
};

#endif // ROTTESTCLASS_H
