// 12.	Design a class Array (1D) using template. Provide a function to show the elements of the array. Design another class SparseMatrix using Array. SparseMatrix should provide a function to transpose the matrix. Add other necessary classes if required.
//1D array using templet
#include <iostream>
using namespace std;

template <typename t>
class array
{
    template<typename u>
    friend istream& operator>>(istream &in,array<u> &);
    template<typename v>
    friend ostream& operator<<(ostream &out,array<v> &);
    t *arr; int size;
    public:
    array<t>()
    {
        size=5;
        arr=new t[size];
    }
    array<t>(int a)
    {
        size=a;
        arr=new t[size];
    }
    array<t>(const array<t> &ob)
    {
        int i;
        this->size=ob.size;
        this->arr=new t[this->size];
        for (i=0; i<(this->size); i++)
        {
            (*this)[i]=ob[i];
        }
    }
    ~array<t>()
    {
        delete[] this->arr;
    }
    t& operator[](int i) const
    {
        return arr[i];
    }
    array<t>& operator=(const array<t> &);
    void bubble();
};

template<typename u>
istream& operator>>(istream &in,array<u> &ob)
{
    int i;
    for (i=0; i<ob.size; i++)
    {
        u x;
        in>>x;
        ob[i]=x;
    }
    cout<<endl;
    return in;
}

template<typename v>
ostream& operator<<(ostream &out, array<v> &ob)
{
    int i;
    for (i=0; i<ob.size; i++)
    {
        out<<ob[i]<<"  ";
    }
    cout<<endl;
    return out;
}

template<typename t>
array<t>& array<t>::operator=(const array<t> &ob)
{
    delete[] this->arr;
    this->size=ob.size;
    this->arr=new t[this->size];
    int i;
    for (i=0;i<this->size;i++)
    {
        (*this)[i]=ob[i];
    }
}

template<typename t>
void array<t>::bubble()
{
    int i,j,tmp;
    for (i=0; i<this->size-1; i++)
    {
        for (j=0; j<this->size-i-1; j++)
        {
            if ((*this)[j]>(*this)[j+1])
            {
                tmp=(*this)[j];
                (*this)[j]=(*this)[j+1];
                (*this)[j+1]=tmp;
            }
        }
    }
}

int main()
{
    array<char>a1(7),a3;
    cout<<"Enter the values:"<<endl;
    cin>>a1;
    cout<<"Array 1 is:"<<endl;
    cout<<a1;
    array<char>a2(a1);
    a3=a1;
    a1.bubble();
    cout<<a1;
    cout<<"Array 2 is:"<<endl;
    cout<<a2;
    cout<<"Array 3 is:"<<endl;
    cout<<a3;
    return 0;
}