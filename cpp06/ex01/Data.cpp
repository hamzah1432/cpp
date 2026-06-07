#include "Data.hpp"

Data::Data() : x(0), y(0) {}

Data::Data(const Data& src) : x(src.x), y(src.y) {}

Data& Data::operator=(const Data& src)
{
    if (this != &src)
    {
        x = src.x;
        y = src.y;
    }
    return *this;
}

Data::~Data() {}