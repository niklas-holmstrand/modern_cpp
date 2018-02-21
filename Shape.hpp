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
//    Shape(Shape && other);
//    Shape() = defalt;
//    Shape(Shape & other) = defalt;
//    Shape() = defalt;

    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() { return c_;}
};
