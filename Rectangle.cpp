#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y, Color color)
    : Shape(color),
      x_(x),
      y_(y)
{}

Rectangle::Rectangle(const Rectangle &other)
    : Shape(other.getColor())
{
    x_ = other.getX();
    y_ = other.getY();
}

double Rectangle::getArea() const
{
    return x_ * y_;
}

double Rectangle::getPerimeter() const
{
    return 2 * (x_ + y_);
}

double Rectangle::getX() const
{
    return x_;
}

double Rectangle::getY() const
{
    return y_;
}

std::string Rectangle::getName() const
{
    return "Rectangle";
}

void Rectangle::print() const
{
    std::cout << getName() << ": x: " << getX()
              << ", y: " << getY()
              << ", area: " << getArea()
              << ", perimeter: " << getPerimeter() << std::endl;
}
