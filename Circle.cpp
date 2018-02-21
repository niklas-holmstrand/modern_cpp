#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r, Color::Blue)
{
    static_assert ( M_PI != 3.14 , "PI only approx" );
}


Circle::Circle(double r, Color c)
    :r_(r), Shape(c)
{
}



Circle::Circle(const Circle && other) :
    r_(std::move(other.r_))
{
}

double Circle::getArea() const  noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
