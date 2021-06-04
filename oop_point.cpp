#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = y = 0;
    }

    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    Point(Point &p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    
    int operator[](int i)
    {
        if (i == 1)
            return x;
        else
            return y;
    }

    void InputPoint();
    void Display();
    void Hide();

    double Distance(Point p2);

    void DrawLine(Point p2);
    void DrawTriangle(Point p2, Point p3);
    double Perimeter(Point p2, Point p3);

};

//----------------------------
class Rectangle
{
private:
    int length, width;

public:
    void Input();
    void Output();
    int Area();
    int Perimeter();

};

//---------------------------
class RectangleArray
{
private:
    int n; // number of elements
    Rectangle* rect;

public:
    void Input();
    Rectangle MaxAreaRect();
    Rectangle* MaxPeriRect();
};

//--------------------------------------------
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
void Rectangle::Input()
{
    cout << "Input the length and the width of the rectangle: ";
    cin >> length >> width;
}

void Rectangle::Output()
{
    cout << "Length = " << length << "-- Width = " << width << endl;
}

int Rectangle::Area()
{
    return length * width;
}

int Rectangle::Perimeter()
{
    return 2 * (length + width);
}

//-----------------------------
void RectangleArray::Input()
{
    cout << "Input the number of rectangles: ";
    cin >> n;

    rect = new Rectangle[n];
    for (int i = 0; i < n; i++)
    {
        rect[i].Input();        
    }
}

Rectangle RectangleArray::MaxAreaRect()
{
    Rectangle maxRect;

    maxRect = rect[0];
    for (int i = 1; i < n; i++)
    {
        if (rect[i].Area() > maxRect.Area())
        {
            maxRect = rect[i];
        }
    }

    return maxRect;
}

Rectangle* RectangleArray::MaxPeriRect()
{
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (rect[i].Perimeter() > rect[max_index].Perimeter())
        {
            max_index = i;
        }
    }

    return (rect + max_index);
}


//---------------------------

int main()
{
    /*
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

    */

    //-------------------------
    RectangleArray ra;
    ra.Input();
    
    Rectangle maxArea;
    maxArea = ra.MaxAreaRect();
    maxArea.Output();

    Rectangle* maxPeri = ra.MaxPeriRect();
    maxPeri->Output();

    return 0;

}