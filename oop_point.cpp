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

class Circle: public Point
{
private:
    int r;
    int OutlineColor;
public:
    Circle() : Point()
    {
        r = OutlineColor = 0;
    }

    Circle(Point p, int _r, int _outlinecolor) : Point(p)
    {
        r = _r;
        OutlineColor = _outlinecolor;
    }

    void Draw()
    {
        cout << "Circle: Center point(" << (*this)[1] << "," << (*this)[2] << ") -- radius = " << r << endl;
    }

    int getOutlineColor()
    {
        return OutlineColor;
    }
};

//------------------------------------------
class Disk : public Circle
{
private:
    int FillColor;
public:
    Disk() : Circle()
    {
        FillColor = 0;
    }

    Disk(Point p, int _r, int _fillcolor, int _outlinecolor) : Circle(p, _r, _outlinecolor)
    {
        FillColor = _fillcolor;
    }

    void Draw()
    {
        cout << "Disk: ";
        Circle::Draw();
        cout << "--Fill with color: " << FillColor << endl;
        cout << "--Outlined with color: " << this->getOutlineColor() << endl;
    }
};

//-------------------------------------------
class Line
{
private:
    Point p1, p2;
    int OutlineColor;

public:
    Line() : p1(), p2()
    {
        OutlineColor = 0;
    }

    Line(Point _p1, Point _p2, int _outlinecolor)
    {
        p1 = _p1;
        p2 = _p2;
        OutlineColor = _outlinecolor;
    }

    void Draw()
    {
        cout << "Line: from (" << p1[1] << "," << p1[2] << ") to (" << p2[1] << "," << p2[2] << ")";
        cout << " with color: " << OutlineColor << endl;
    }
};

//-------------------------------------------
class Triangle
{
private:
    Point p1, p2, p3;
    int OutlineColor, FillColor;

public:
    Triangle() : p1(), p2(), p3()
    {
        OutlineColor = FillColor = 0;
    }

    Triangle(Point _p1, Point _p2, Point _p3, int _outlinecolor, int _fillcolor)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        OutlineColor = _outlinecolor;
        FillColor = _fillcolor;
    }

    void Draw()
    {
        cout << "Triangle:" << endl;
        cout << "--";
        Line(p1, p2, OutlineColor).Draw();
        cout << "--";
        Line(p2, p3, OutlineColor).Draw();
        cout << "--";
        Line(p3, p1, OutlineColor).Draw();

        cout << "--Fill with color: " << FillColor << endl;
    }
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
    /*
    RectangleArray ra;
    ra.Input();
    
    Rectangle maxArea;
    maxArea = ra.MaxAreaRect();
    maxArea.Output();

    Rectangle* maxPeri = ra.MaxPeriRect();
    maxPeri->Output();
    */

    Point A(100,100);
    Circle c(A, 80, 81);

    Point B(400,100);
    Disk d(B, 80, 78, 79);

    Line l(A, B, 5);
 
    Point C(250,150);
    Point D(100,400);
    Point E(400,400);
    Triangle t(C, D, E, 6, 6);

    c.Draw();
    d.Draw();
    l.Draw();
    t.Draw();

    return 0;

}