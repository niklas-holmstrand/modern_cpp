#pragma once
enum class Color{
    Red,
    Green,
    Blue
};


class Shape
{
private:
    Color c_ = Color::Blue;

public:
    Shape(Shape && other) = default;
    Shape() = default;
    Shape(Shape & other) = default;
    Shape(Color c);

    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() { return c_;}
};
