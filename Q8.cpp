// 8.	A Vertex represents an ordered pair of x-coordinate and y-coordinate describing a position in XY-plane. Add suitable get and set operations and add a method to calculate the distance between two vertices. Create another class Line. Provide suitable get and set methods.  The responsibilities of Line class are: 
// Computing the length of the Line.
// Computing the slope of the Line.
// Create another class Triangle. Add a method to calculate the area of Triangle, provide suitable get and set methods.

#include<iostream>
#include<cmath>
using namespace std;

class Vertex
{
    int x_coordinate, y_coordinate;

    public :
        Vertex();
        Vertex(int x, int y);
        Vertex(const Vertex &ob);
        int getX_coordinate();
        int getY_coordinate();
        void setX_coordinate(int x);
        void setY_coordinate(int y);
        float distance_btw_two_vertices(const Vertex &ob);
        friend istream& operator>>(istream &in, Vertex &ob);
        friend ostream& operator<<(ostream &out, const Vertex &ob);
};

Vertex::Vertex()
{
    this->x_coordinate = this->y_coordinate = 0;
}

Vertex::Vertex(int x, int y)
{
    this->x_coordinate = x;
    this->y_coordinate = y;
}

Vertex::Vertex(const Vertex &ob)
{
    this->x_coordinate = ob.x_coordinate;
    this->y_coordinate = ob.y_coordinate;
}

int Vertex::getX_coordinate()
{
    return this->x_coordinate;
}

int Vertex::getY_coordinate()
{
    return this->y_coordinate;
}

void Vertex::setX_coordinate(int x)
{
    this->x_coordinate = x;
}

void Vertex::setY_coordinate(int y)
{
    this->y_coordinate = y;
}

float Vertex::distance_btw_two_vertices(const Vertex &ob)
{
    float distance = sqrt(pow(this->x_coordinate - ob.x_coordinate, 2) + pow(this->y_coordinate - ob.y_coordinate, 2));
    return distance;
}

istream& operator>>(istream &in, Vertex &ob)
{
    cout<<"Enter the x-coordinate of the Vertex :"<<endl;
    in>>ob.x_coordinate;
    cout<<"Enter the y-coordinate of the Vertex :"<<endl;
    in>>ob.y_coordinate;

    return in;
}

ostream& operator<<(ostream &out, const Vertex &ob)
{
    out<<"Displaying the Vertex :"<<endl;
    out<<"Vertex ->"<<endl; 
    out<<"("<<ob.x_coordinate<<", "<<ob.y_coordinate<<")"<<endl;

    return out;
}

class Line
{
    Vertex A, B;

    public :
        Line();
        Line(Vertex X, Vertex Y);
        Line(const Line &ob);
        void setVertexA(Vertex X);
        void setVertexB(Vertex B);
        Vertex getVertexA();
        Vertex getVertexB(); 
        float length();
        float slope();
        friend istream& operator>>(istream &in, Line &ob);
        friend ostream& operator<<(ostream &out, const Line &ob);
};

Line::Line()
{
    Vertex X(0, 0), Y(0, 0);
    this->A = X;
    this->B = Y;
}

Line::Line(Vertex X, Vertex Y)
{
    this->A = X;
    this->B = Y;
}

Line::Line(const Line &ob)
{
    this->A = ob.A;
    this->B = ob.B;
}

void Line::setVertexA(Vertex X)
{
    this->A = X;
}

void Line::setVertexB(Vertex Y)
{
    this->B = Y;
}

Vertex Line::getVertexA()
{
    return this->A;
}

Vertex Line::getVertexB() 
{
    return this->B;
}

float Line::length()
{
    float len = A.distance_btw_two_vertices(B);
    return len;
}

float Line::slope()
{
    Vertex v1(this->A), v2(this->B);
    float slope_m = (v1.getY_coordinate() - v2.getY_coordinate())/(v1.getX_coordinate() - v2.getX_coordinate());
    return slope_m;
}


class Triangle
{
    Vertex A, B, C;

    public :
        Triangle();
        Triangle(Vertex X, Vertex Y, Vertex Z);
        Triangle(const Triangle &ob);
        void setVertexA(Vertex X);
        void setVertexB(Vertex Y);
        void setVertexC(Vertex Z);
        Vertex getVertexA();
        Vertex getVertexB();
        Vertex getVertexC();
        float Area();
        friend istream& operator>>(istream &in, Triangle &ob);
        friend ostream& operator<<(ostream &out, const Triangle &ob);
};

Triangle::Triangle()
{
    Vertex X(0, 0), Y(0, 0), Z(0, 0);
    this->A = X;
    this->B = Y;
    this->C = Z;
}

Triangle::Triangle(Vertex X, Vertex Y, Vertex Z)
{
    this->A = X;
    this->B = Y;
    this->C = Z;
}

Triangle::Triangle(const Triangle &ob)
{
    this->A = ob.A;
    this->B = ob.B;
    this->C = ob.C;
}

void Triangle::setVertexA(Vertex X)
{
    this->A = X;
}

void Triangle::setVertexB(Vertex Y)
{
    this->B = Y;
}

void Triangle::setVertexC(Vertex Z)
{
    this->C = Z;
}

Vertex Triangle::getVertexA()
{
    return this->A;
}

Vertex Triangle::getVertexB()
{
    return this->B;
}
    
Vertex Triangle::getVertexC()
{
    return this->C;
}

float Triangle::Area()
{
    Vertex v1(this->A), v2(this->B), v3(this->C);
    float area = (v1.getX_coordinate() * (v2.getY_coordinate() - v3.getY_coordinate()) + v2.getX_coordinate() * (v3.getY_coordinate() - v1.getY_coordinate()) - v3.getX_coordinate() * (v1.getY_coordinate() - v2.getY_coordinate()));
    if(area < 0)
        return -area/2;
    else
        return area/2;
} 

int main()
{
    Vertex v1(1, 4), v2(2, 3);

    cout<<v1.distance_btw_two_vertices(v2)<<endl;

    Line l1(v1, v2);

    cout<<l1.length()<<endl;

    Vertex v3, v4(0,3), v5(3, 0);
    Triangle t1(v3, v4, v5);

    cout<<t1.Area()<<endl;
    return 0;
}