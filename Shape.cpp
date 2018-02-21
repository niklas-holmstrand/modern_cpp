#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}


Shape::Shape(Color c)
    : c_(c)
{}
