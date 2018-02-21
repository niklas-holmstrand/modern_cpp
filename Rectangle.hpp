#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle(const Rectangle && other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getX() const;
    virtual double getY() const final;
    void print() const override;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
