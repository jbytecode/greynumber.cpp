#ifndef greynumber
#define greynumber

#include <algorithm>
#include <cmath>

template <typename T>
class GreyNumber
{
private:
    T a;
    T b;

public:
    GreyNumber<T>()
    {
        this->a = 0;
        this->b = 0;
    };
    GreyNumber<T>(T a){
        this->a = a;
        this->b = a;
    }
    GreyNumber<T>(T a, T b)
    {
        this->a = std::min(a, b);
        this->b = std::max(a, b);
    };

    T A() const
    {
        return this->a;
    };

    T B() const
    {
        return this->b;
    };

    T operator[](int index) const 
    {
        assert(index == 0 || index == 1);
        if (index == 0){
            return this->a;
        }else{
            return this->b;
        }
    }
};


template <typename T>
GreyNumber<T> operator+(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    return GreyNumber<T>(g1.A() + g2.A(), g1.B() + g2.B());
}

template <typename T>
GreyNumber<T> operator-(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    return GreyNumber<T>(g1.A() - g2.A(), g1.B() - g2.B());
}

template <typename T>
GreyNumber<T> operator-(GreyNumber<T> const &g)
{
    return GreyNumber<T>(-g.B(), -g.A());
}

template <typename T>
GreyNumber<T> operator*(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    T vals[] = {
        g1.A() * g2.A(),
        g1.A() * g2.B(),
        g1.B() * g2.A(),
        g1.B() * g2.B()};
    T *minval = std::min_element(std::begin(vals), std::end(vals));
    T *maxval = std::max_element(std::begin(vals), std::end(vals));
    return GreyNumber<T>(*minval, *maxval);
}

template <typename T>
GreyNumber<T> operator*(T k, GreyNumber<T> const &g)
{
    return GreyNumber<T>(k * g.A(), k * g.B());
}

template <typename T>
GreyNumber<T> operator*(GreyNumber<T> const &g, T k)
{
    return GreyNumber<T>(k * g.A(), k * g.B());
}

template <typename T>
extern GreyNumber<T> operator/(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    T vals[] = {
        g1.A() / g2.A(),
        g1.A() / g2.B(),
        g1.B() / g2.A(),
        g1.B() / g2.B()};
    T *minval = std::min_element(std::begin(vals), std::end(vals));
    T *maxval = std::max_element(std::begin(vals), std::end(vals));
    return GreyNumber<T>(*minval, *maxval);
}

template <typename T>
bool operator==(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    return (g1.A() == g2.A()) && (g1.B() == g2.B());
}

template <typename T>
bool operator<(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    if (g1[0] < g2[0])
    {
        return true;
    }
    else if (g1[0] == g2[0])
    {
        return g1[1] < g2[1];
    }
    else
    {
        return false;
    }
}

template <typename T>
bool operator>(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    if (g1[0] > g2[0])
    {
        return true;
    }
    else if (g1[0] == g2[0])
    {
        return g1[1] > g2[1];
    }
    else
    {
        return false;
    }
}

template <typename T>
bool operator<=(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    if (g1[0] <= g2[0])
    {
        return true;
    }
    else if (g1[0] == g2[0])
    {
        return g1[1] <= g2[1];
    }
    else
    {
        return false;
    }
}

template <typename T>
bool operator>=(GreyNumber<T> const &g1, GreyNumber<T> const &g2)
{
    if (g1[0] >= g2[0])
    {
        return true;
    }
    else if (g1[0] == g2[0])
    {
        return g1[1] >= g2[1];
    }
    else
    {
        return false;
    }
}


template <typename T>
GreyNumber<double> sqrt(GreyNumber<T> const &g){
    return GreyNumber<double>(std::sqrt(g.A()), std::sqrt(g.B()));
}

#endif