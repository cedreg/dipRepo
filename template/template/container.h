#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

template <class T> class container;
template <class T> std::ostream& operator<<( std::ostream&, const container<T>& );

template <class T>
class container
{
private:
    T value;

public:
    container();
    //kein copy / destructor da keine pointerVARS
    void setValue(T newValue);
    T getValue() const;

    // The overloads of operator>> and operator<< that take a std::istream& or std::ostream& as the left hand argument are known as insertion and extraction operators.
    // Since they take the user-defined type as the right argument (b in a@b), they must be implemented as non-members.
    friend std::ostream& operator<< <T>( std::ostream&, const container<T>&);


    //Assignment operator
    container<T> operator=(const container<T>& other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }

    // Typically, once operator< is provided, the other relational operators are implemented in terms of operator<.
    /*
        inline bool operator< (const X& lhs, const X& rhs){ do actual comparison; }
        inline bool operator> (const X& lhs, const X& rhs){ return rhs < lhs; }
        inline bool operator<=(const X& lhs, const X& rhs){ return !(lhs > rhs); }
        inline bool operator>=(const X& lhs, const X& rhs){ return !(lhs < rhs); }
    */
    bool operator< (const container<T>& rhs){ return this->getValue() < rhs.getValue(); }
    bool operator> (const container<T>& rhs){ return rhs < *this; }
    bool operator<=(const container<T>& rhs){ return !(*this > rhs); }
    bool operator>=(const container<T>& rhs){ return !(*this < rhs); }


    // Likewise, the inequality operator is typically implemented in terms of operator==:
    /*
        inline bool operator==(const X& lhs, const X& rhs){ do actual comparison; }
        inline bool operator!=(const X& lhs, const X& rhs){ return !(lhs == rhs); }
    */
    bool operator==(const container<T>& rhs) {return this->getValue() == rhs.getValue(); }
    bool operator!=(const container<T>& rhs) {return !(*this == rhs); }



    //custom Operator ^=
    container<T> operator^= (T power)
    {
        value = testRec(value, power);
        return *this;
    }

    T testRec(T base, T exp)
    {
        return (exp == 0) ? 1 : (base * testRec(base, exp - 1));
    }


    //CAST
    operator T (void) {return value;}
};

template <class T>
container<T>::container()
{
}

template <class T>
void container<T>::setValue(T newValue)
{
    value = newValue;
}

template <class T>
T container<T>::getValue() const
{
    return value;
}

template <class T>
std::ostream& operator<< (std::ostream &os, const container<T> &obj)
{
    os << obj.getValue();
    return os;
}

#endif // CONTAINER_H
