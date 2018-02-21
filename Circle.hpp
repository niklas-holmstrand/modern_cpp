#pragma once

#include "Shape.hpp"

class alignas(2) Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other);// = default;
    Circle(const Circle && other);// = default;

    double getArea() const  noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
