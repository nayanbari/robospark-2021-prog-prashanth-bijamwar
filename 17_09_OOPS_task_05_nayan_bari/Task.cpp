#include <iostream>
using namespace std;

class Rectangle
{
public:
    double length, breath;
    Rectangle()
    {
        length = 0;
        breath = 0;
    }
    Rectangle(double length, double breath)
    {
        this->length = length;
        this->breath = breath;
    }
    Rectangle(double side)
    {
        this->length = side;
        this->breath = side;
    }
    int areaOfRectangle()
    {
        return length * breath;
    }
};

int main()
{
    Rectangle obj1;
    Rectangle obj2(6, 4);
    Rectangle obj3(4);
    cout << "The area of rectangle with zero sides is " << obj1.areaOfRectangle() << endl;
    cout << "The area of rectangle with lenght 6m and breath 4m is " << obj2.areaOfRectangle() << endl;
    cout << "The area of rectangle with side 4m is " << obj3.areaOfRectangle() << endl;
    return 0;
}