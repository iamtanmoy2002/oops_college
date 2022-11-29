// 7.	Create a class Distance{feet, inches}: operations- default constructor, one-argument constructor (Distance(int), Distance(float)), two-argument constructor, copy constructor, input, display, add, convert to meter.(use operator overloading). Overload casting operators to convert class Distance to feet (float) or inches (integer) and to another class Meter {mt, cm}. Also implement >, >=, <, <=, <<, >> and != operator

#include<iostream>
using namespace std;
class Meter;
class Distance
{
    int feet,inches;
    public:
        Distance();
        Distance(int feet);
        Distance(float feet);
        Distance(const Meter &rhs);
        Distance(int feet,int inches);
        friend istream& operator>>(istream &in,Distance&ob);
        friend ostream& operator<<(ostream &out,const Distance&ob);
        Distance operator+(Distance a);
        friend bool operator>(Distance a,Meter b);
        friend bool operator<(Distance a,Meter  b);
        friend bool operator<=(Distance a,Meter b);
        friend bool operator>=(Distance a,Meter b);
        friend bool operator!=(Distance a,Meter b);
        operator float();
        operator int();
        operator Meter() const;
        friend  Meter;


};
Distance::Distance()
{
    this->feet=0;
    this->inches=0;


}
Distance::Distance(int feet)
{
    this->feet=feet;
    this->inches=this->feet*12;


}
Distance::Distance(float feet)
{
    this->feet=feet;
    this->inches=feet*12;
}

Distance Distance::operator+(Distance a)
{
    Distance res;
    res.feet=this->feet+a.feet;
    res.inches=this->inches+a.inches;
    return res;
}
Distance::operator float()
{
    return (float)this->feet;
}
Distance::operator int()
{
    return (int)this->inches;
}
Distance::Distance(const Meter& rhs)
{
    this->feet=rhs.mt*3.281;
    this->inches=rhs.cm*2.54;

}
bool operator<(Distance a,Meter b)
{
    return a<b;


}

istream& operator>>(istream&in,Distance&ob)
{
    in >> ob.feet;
    in >> ob.inches;
    return in;
}
ostream& operator<<(ostream&out,const Distance&ob)
{
    out <<ob.feet;
    out << ob.inches;
    return out;
}
class Meter
{
    int mt,cm;
    public:
        Meter();
        Meter(int mt);
        Meter(float mt);
        Meter(int mt,int cm);
        Meter(const Distance& ob);
        friend bool operator>(Meter a,Distance b);
        friend bool operator<(Meter a,Distance b);
        friend bool operator<=(Meter a,Distance b);
        friend bool operator>=(Meter a,Distance b);
        friend bool operator!=(Meter a,Distance b);
        friend istream& operator>>(istream& in,Meter &lhs);
        friend ostream& operator<<(ostream& out,const Meter &rhs);
        friend Distance;


};

Meter::Meter()
{
    this->mt=0;
    this->cm=0;
}
Meter::Meter(int mt)
{
    this->mt=mt;
    this->cm=mt*100;
}
Meter::Meter(float mt)
{
    this->mt=mt;
    this->cm=mt*100;
}
Meter::Meter(int mt,int cm)
{
    this->mt=mt;
    this->cm=cm;
}
Meter::Meter(const Distance& ob)
{
    this->mt=ob.feet/3.281;
    this->cm=ob.inches/2.54;
}
bool operator>(Meter a,Distance b)
{
    return a>b;
}
bool operator<(Meter a,Distance b)
{
    return a<b;
}
bool operator<=(Meter a,Distance b)
{
    return a<=b;
}
bool operator>=(Meter a,Distance b)
{
    return a>=b;
}
bool operator!=(Meter a,Distance b)
{
    return a!=b;
}
istream& operator>>(istream& in,Meter &lhs)
{
    in >> lhs.mt;
    in >> lhs.cm;
    return in;
}
ostream& operator<<(ostream& out,const Meter& rhs)
{
    out << rhs.mt;
    out << rhs.cm;
    return out;
}
int main()
{
    Distance ob(5);
    cout << ob;
    return 0;
}