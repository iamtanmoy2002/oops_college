// 6.	Create a class Fraction {numerator, denominator} to implement addition, subtraction, multiplication and compare of two proper fractions. This class also contains a private method minimize which can minimizes 2/4 to ½. Overload +, −,*, ==, =, +=, −=, *=, operators. Also write suitable functions for input and output.
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a < 0)
        return gcd(-a, b);
    else if(b < 0)
        return gcd(a, -b);
    else if(a < 0 && b < 0)
        return gcd(-a, -b);
    else if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

class Fraction
{
    int numerator, denominator;
    void minimise();

public:
    Fraction();
    Fraction(int nume, int deno);
    Fraction(const Fraction &ob);
    Fraction operator+(const Fraction &ob);
    Fraction operator-(const Fraction &ob);
    Fraction operator*(const Fraction &ob);
    Fraction operator/(const Fraction &ob);
    Fraction operator=(const Fraction &ob);
    Fraction operator+=(const Fraction &ob);
    Fraction operator-=(const Fraction &ob);
    Fraction operator*=(const Fraction &ob);
    bool operator==(const Fraction &ob);
    friend istream &operator>>(istream &in, Fraction &ob);
    friend ostream &operator<<(ostream &out, const Fraction &ob);
};

void Fraction::minimise()
{
    int common_factor = gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / common_factor;
    this->denominator = this->denominator / common_factor;
}

Fraction::Fraction()
{
    this->numerator = this->denominator = 1;
}

Fraction::Fraction(int nume, int deno)
{
    this->numerator = nume;
    this->denominator = deno;
}

Fraction::Fraction(const Fraction &ob)
{
    this->numerator = ob.numerator;
    this->denominator = ob.denominator;
}

Fraction Fraction::operator=(const Fraction &ob)
{
    this->numerator = ob.numerator;
    this->denominator = ob.denominator;

    return *this;
}

Fraction Fraction::operator+(const Fraction &ob)
{
    Fraction ans(this->numerator * ob.denominator + this->denominator * ob.numerator, this->denominator * ob.denominator);
    ans.minimise();
    return ans;
}

Fraction Fraction::operator-(const Fraction &ob)
{
    Fraction ans((this->numerator * ob.denominator) - (this->denominator * ob.numerator), this->denominator * ob.denominator);
    ans.minimise();
    return ans;
}

Fraction Fraction::operator*(const Fraction &ob)
{
    Fraction ans(this->numerator * ob.numerator, this->denominator * ob.denominator);
    ans.minimise();
    return ans;
}

Fraction Fraction::operator/(const Fraction &ob)
{
    Fraction ans(this->numerator * ob.denominator, this->denominator * ob.numerator);
    ans.minimise();
    return ans;
}

Fraction Fraction::operator+=(const Fraction &ob)
{
    Fraction ans(this->numerator * ob.denominator + this->denominator * ob.numerator, this->denominator * ob.denominator);
    ans.minimise();
    *this = ans;
    return *this;
}

Fraction Fraction::operator-=(const Fraction &ob)
{
    Fraction ans((this->numerator * ob.denominator) - (this->denominator * ob.numerator), this->denominator * ob.denominator);
    ans.minimise();
    *this = ans;
    return *this;
}

Fraction Fraction::operator*=(const Fraction &ob)
{
    Fraction ans(this->numerator * ob.numerator, this->denominator * ob.denominator);
    ans.minimise();
    *this = ans;
    return *this;
}

bool Fraction::operator==(const Fraction &ob)
{
    return (this->numerator == ob.numerator || this->denominator == ob.denominator);
}

istream &operator>>(istream &in, Fraction &ob)
{
    cout << "Enter the value of numerator and denominator of Fraction : " << endl;
    in >> ob.numerator >> ob.denominator;
    return in;
}

ostream &operator<<(ostream &out, const Fraction &ob)
{
    out << "Displaying the Fraction : " << endl;
    if (ob.numerator == 0)
        out << "0" << endl;
    else
        out << ob.numerator << "/" << ob.denominator << endl;
    return out;
}

int main()
{
    Fraction f1(2, 6), f2(5, 12), ans;

    cout<<"Working of Operator '+' after overloading for Fraction : "<<endl;
    ans = f1 + f2;
    cout<<ans<<endl;
    cout << "Working of Operator '-' after overloading for Fraction : " << endl;
    ans = f1 - f2;
    cout << ans << endl;
    cout << "Working of Operator '*' after overloading for Fraction : " << endl;
    ans = f1 * f2;
    cout << ans << endl;
    cout << "Working of Operator '/' after overloading for Fraction : " << endl;
    ans = f1 / f2;
    cout << ans << endl;
    cout<<"Working of Operator '-=' after overloading for Fraction : "<<endl;
    Fraction f1_copy(f1);
    f1 -= f1_copy;
    cout<<f1<<endl;
    cout<<"Working of Operator '+=' after overloading for Fraction : "<<endl;
    f1 += f2;
    cout<<f1<<endl;

    return 0;
}