// 9.	Design a class Polynomial. A polynomial is a sequence of terms. A term is a pair (exponent, coefficient) where the exponent is a non-negative integer and the coefficient is a double-precision number. Write a class definition for a Term. Add the following functions:
// i.	Term();
// ii.	Term(double cof,int exp);
// iii.	Term(const Term &o);
// iv.	Term operator+(const Term&) const; //add two terms.
// v.	Term operator*(const Term&) const; //multiply two terms.
// vi.	bool operator>(const Term&) const;//compare two term according their exponent
// vii.	bool operator<(const Term&) const;//compare two term according their exponent
// viii.	bool operator>=(const Term&) const;//compare two term according their exponent
// ix.	bool operator<=(const Term&) const;//compare two term according their exponent
// x.	bool operator==(const Term&) const;//check equality of two term according their exponent
// xi.	bool operator!=(const Term&) const;// check inequality of two term according their exponent
// xii.	friend ostream& operator<<(ostream &out,const Term &o);
// xiii.	friend istream& operator>>(istream &in,Term &o);
// Now design a class Node having a Term object and a self-referential pointer. 
// Finally write a class definition for a Polynomial. Given that polynomials have an arbitrary size, the proper implementation is by means of a linked list having node. 
// i.	Polynomial();
// ii.	Polynomial(const Polynomial&);
// iii.	~Polynomial();
// iv.	void del();
// v.	Polynomial operator+(const Polynomial &o) const;//add two polynomials
// vi.	Polynomial operator+=(const Polynomial &o);//add two polynomials and update the first operand 
// vii.	term operator+=(const term &o);//add a new term at the end of the polynomial
// viii.	Polynomial operator*(const term &o) const;//multiply a term with a polynomial
// ix.	Polynomial operator*(const Polynomial &o) const;//multiply two polynomials
// x.	Polynomial& operator=(const Polynomial &o);//overload = operator with deep copy
// xi.	friend ostream& operator<<(ostream &out,const Polynomial &o);//take input for a polynomial
// xii.	friend istream& operator>>(istream &in,Polynomial &o);//print a polynomial
// Design the above classes. Use friend class and friend function if required. 

#include<iostream>
using namespace std;

class term;
class poly;
class node;

class term
{
    int exp; 
    double coef;

    public:
    term();
    term(double coef,int exp);
    term(const term&o);
    term operator+(const term&)const;
    term operator*(const term&)const;
    bool operator>(const term&)const;
    bool operator<(const term&)const;
    bool operator==(const term&)const;
    bool operator!=(const term&)const;
    term& operator=(const term&);
    friend ostream& operator<<(ostream& out,const term &o);
    friend istream& operator>>(istream& in,term& o);
    friend class poly;
    friend class node;
    
};


class node
{
    node* next;
    term eq;
    public:
    node();
    node(term eq);
    friend istream& operator>>(istream& in, node& ob);
    friend ostream& operator<<(ostream& out, const node& ob);
    ~node();
    friend poly;
    friend term;
};

class poly
{
    term eq;
    node* head;
    void del();

    public:
    poly();
    poly(const poly& ob);
    void append(int exp, double coff);
    poly operator+(const poly& ob)const;
    poly operator+=(const poly& ob);
    term operator+=(const term &ob);
    poly operator*(const poly& ob)const;
    poly operator*(const term& ob)const;
    poly& operator=(const poly& ob);
    friend istream& operator>>(istream& in, poly& ob);
    friend ostream& operator<<(ostream& out,const poly& ob);
    ~poly();
    void del();
    friend term;
    friend node; 


};
