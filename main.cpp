#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<Shape*>;

bool sortByArea(Shape* first, Shape* second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(Shape* s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(Shape* s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it != nullptr)
        {
            (*it)->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(auto item:collection)
    {
        if(item != nullptr)
        {
            cout << item->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{

    Collection shapes = {
        new Circle(2.0),
        new Circle(3.0),
        nullptr,
        new Circle(4.0),
        new Rectangle(10.0, 5.0),
        new Square(3.0),
        new Circle(4.0)
    };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = new Square(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    cout << "alignof circle" << alignof(Circle) << std::endl;

    return 0;
}

