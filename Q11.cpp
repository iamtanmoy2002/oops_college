// 11.	Create a class Array for 1D array. Overload necessary operators including []. Create a class Matrix using Array. Overload necessary operators including [].
#include"class_array.h"


//ARRAY CLASS DEFINITION
Array::Array()
{
    this->size=5;
    this->arr=new int[size];

}
Array::Array(int size)
{
    this->size=size;
    this->arr=new int[size];

}
Array operator+(Array &a,Array &b)
{
    Array res(a.size);
    for(int i=0;i<res.size;++i)
    {
        res[i]=a[i]+b[i];
    }
    return res;

}
int& Array::operator[](int i)
{
    return arr[i];
}
istream &operator>>(istream &in,Array &ob)
{
    for(int i=0;i<ob.size;++i)
        in >> ob.arr[i];
    return in;
}
ostream &operator<<(ostream &out,Array &ob)
{
    for(int i=0;i<ob.size;++i)
        out << ob.arr[i];
    return out;

}
//--------------------------------------------
//MATRIX CLASS DEFINITION
Matrix::Matrix()
{
    
    this->row=2;
    this->col=2;
    //this->arr_object=new Array[5];
    //this->arr_object=new Array[this->row*sizeof(Array)];
    arr_object = (Array*)malloc(this->row*sizeof(Array));
    for(int i=0;i<this->row;++i)
    {
        this->arr_object[i]=Array(this->col);
        cout << *this << endl;
    }
    
    
}
Matrix::Matrix(int r,int c)
{
    this->row=r;
    this->col=c;
    this->arr_object=new Array[r*sizeof(Array)];
    for(int i=0;i<r;++i)
        this->arr_object[i]=Array(this->col);
    cout <<"calling from parameterised"<< *this << endl;
    
}
Array& Matrix::operator[](int i)
{
    return arr_object[i];

}
int& Matrix::operator()(int i,int j)
{
    Array row_ob;
    
    row_ob=arr_object[i];
    return arr_object[i][j];
}
Matrix operator+(Matrix &a,Matrix &b)
{
    Matrix res(a.row,a.col);
    for(int i=0;i<a.row;++i)
    {
        for(int j=0;j<a.col;++j)
        {
            res(i,j)=a(i,j)+b(i,j);
        }
    }
    return res;
}
istream &operator>>(istream &in,Matrix &ob)
{
    for(int i=0;i<ob.row;++i)
    {
        for(int j=0;j<ob.col;++j)
        {
            in >> ob(i,j);
            
        }
       
    }
    return in;
}
ostream &operator<<(ostream &out,Matrix &ob)
{
    for(int i=0;i<ob.row;++i)
    {
        for(int j=0;j<ob.col;++j)
        {
            out << ob(i,j) <<' ';
        }
        out << endl;
    }
    return out;

}