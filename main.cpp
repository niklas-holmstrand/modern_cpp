#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<std::shared_ptr<Shape>>;

bool sortByArea(std::shared_ptr<Shape> first, std::shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}


//bool perimeterBiggerThan20(std::shared_ptr<Shape> s)
//{
//    if(s)
//    {
//        return (s->getPerimeter() > 20);
//    }
//    return false;
//}

//bool areaLessThan10(std::shared_ptr<Shape> s)
//{
//    if(s)
//    {
//        return (s->getArea() < 10);
//    }
//    return false;
//}


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
                                     std::function<bool (std::shared_ptr<Shape> s)> predicate,
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

template<class T, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return make_shared<T>(forward<Arguments>(args)...);
}

int main()
{

    Collection shapes = {
        make_shape<Circle>(2.0),
        make_shape<Circle>(3.0),
        nullptr,
        make_shape<Circle>(4.0),
        make_shape<Rectangle>(10.0, 5.0),
        make_shape<Square>(3.0),
        make_shape<Circle>(4.0)
    };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

//    auto square = new Square(4.0);
    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    auto circle = new Circle(4.0);
    shapes.emplace_back(std::move(circle));

    auto rectangle = new Rectangle(4.0, 2.6);
//    std::shared_ptr<Rectangle> rectangle make_shared(Rectangle(4.0, 2.6))
    delete rectangle;
//    shapes.emplace_back(std::move(rectangle));

    int x = 15;
    auto perimeterBiggerThan20 = [](std::shared_ptr<Shape> s){ if(s) { return (s->getPerimeter() > 20); } return false; };
    auto areaLessThanX = [x](std::shared_ptr<Shape> s){ if(s) { return (s->getArea() < x); } return false; };
    //auto areaLessThan10 = [](std::shared_ptr<Shape> s){ if(s) { return (s->getArea() < 10); } return false; };


    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    cout << "alignof circle" << alignof(Circle) << std::endl;

    return 0;
}

