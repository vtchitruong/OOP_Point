#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Point
{
private:
    int x, y;

public:
    void InputPoint();
    void Display();
    void Hide();

    double Distance(Point p2);

    void DrawLine(Point p2);
    void DrawTriangle(Point p2, Point p3);
    double Perimeter(Point p2, Point p3);

};

void Point::InputPoint()
{
    cout << "Input the coordinate: (x, y) = ";
    cin >> x >> y;
}

void Point::Display()
{
    cout << "Display: (" << x << ", " << y << ")" << endl;
}
    
void Point::Hide()
{
    cout << "Hide: (" << x << ", " << y << ")" << endl;
}

//--------------------------------------------
double Point::Distance(Point p2)
{
    Point p = *this;
    return sqrt(pow(p.x - p2.x, 2) + pow(p.y - p2.y, 2));
}

//-------------------------------------------------------
void Point::DrawLine(Point p2)
{
    cout << "Line: from (" << this->x << "," << this->y << ") to (" << p2.x << "," << p2.y << ")" << endl;
}

void Point::DrawTriangle(Point p2, Point p3)
{
    cout << "Triangle: " << endl;
    cout << "-- "; (*this).DrawLine(p2);
    cout << "-- "; p2.DrawLine(p3);
    cout << "-- "; p3.DrawLine(*this);
}

//------------------------------------------------------
double Point::Perimeter(Point p2, Point p3)
{
    double res;
    res = (*this).Distance(p2) + p2.Distance(p3) + p3.Distance(*this);
    return res;
}

//------------------------------------------

int main()
{
    Point p1, p2, p3;
    p1.InputPoint();
    p2.InputPoint();
    p3.InputPoint();

    p1.Display();
    p2.Display();
    p3.Display();

    p1.DrawTriangle(p2, p3);

    double peri = p1.Perimeter(p2, p3);
    cout << fixed << setprecision(2) << "The perimeter is "<< peri;

    cout << "Check when deleting master branch";
    return 0;

}