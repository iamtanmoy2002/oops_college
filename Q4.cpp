// 4.	WAP to add, multiply and transpose two matrices using operator overloading. Use dynamic memory allocation: new, delete. Also overload suitable input and output operators.
#include<iostream>
using namespace std;

class matrix
{

    int rows;
    int cols;
    int **arr;
    public:
    matrix();
    matrix(int rows,int cols);
    matrix(int order);
    matrix(const matrix& ob);
    ~matrix();
    matrix operator+(const matrix& ob);
    matrix operator-(const matrix& ob);
    matrix operator*(const matrix& ob);
    matrix operator=(const matrix& ob);
    void transpose();
    friend istream& operator>>(istream& in,matrix& ob);
    friend ostream& operator<<(ostream& out,matrix& ob);
};

matrix :: matrix()
{
    this->rows=0;
    this->arr=0;
    this->arr=NULL;
}
matrix :: matrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
    
    this->arr=new int*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
       this->arr[i]=new int [this->cols];
    }
}

matrix :: matrix(int order)
{
    this->rows=order;
    this->cols=order;
    this->arr=new int*[order];
    for (int i = 0; i < order; i++)
    {
        this->arr[i]=new int [order];
    }  
}

matrix::matrix(const matrix& ob)
{
    if (this->arr!=NULL&&this->cols!=0&&this->rows!=0)
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] this->arr[i];
        }
        this->arr=NULL;
        this->cols=this->rows=0;
    }
    this->rows=ob.rows;
    this->cols=ob.cols;
    this->arr=new int*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->arr[i]=new int[this->cols];
    }
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->arr[i][j]=ob.arr[i][j];
        }
    }    
}

matrix matrix::operator+(const matrix& ob)
{
    matrix res(this->rows,this->cols);
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            res.arr[i][j]=this->arr[i][j]+ob.arr[i][j];
        }
    }
    return res;
}

matrix matrix::operator-(const matrix& ob)
{
    matrix res(this->rows,this->cols);
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            res.arr[i][j]=this->arr[i][j]-ob.arr[i][j];
        }
    }
    return res;
}

matrix matrix::operator*(const matrix& ob)
{
    matrix res(this->rows,this->cols);
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            res.arr[i][j]=this->arr[i][j]*ob.arr[i][j];
        }
    }
    return res;
}

matrix matrix::operator=(const matrix& ob)
{
    if (this->arr!=NULL&&this->cols!=0&&this->rows!=0)
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] this->arr[i];
        }
        this->arr=NULL;
        this->cols=this->rows=0;
    }
    this->rows=ob.rows;
    this->cols=ob.cols;
    this->arr=new int*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->arr[i]=new int[this->cols];
    }
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->arr[i][j]=ob.arr[i][j];
        }
    }  
    return *this;  
}

matrix::~matrix()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->arr[i];
    }
    this->arr=NULL;
    this->rows=this->cols=0;
}

istream& operator>>(istream& in,matrix& ob)
{
    if (ob.cols==0&&ob.rows==0&&ob.arr==NULL)
    {
        cout<<"enter the rows and cols"<<endl;
        in>>ob.rows>>ob.cols;
        ob.arr=new int*[ob.rows];
        for (int i = 0; i < ob.rows; i++)
        {
            ob.arr[i]=new int [ob.cols];
        }
    }
    cout<<"enter the elements"<<endl;

    for (int i = 0; i < ob.rows; i++)
    {
        for(int j=0;j<ob.cols;j++)
        {
            in>>ob.arr[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream &out, matrix &ob)
{
    out<<"Displaying the Matrix :"<<endl;
    for(int i = 0; i < ob.rows; i++)
    {
        for(int j = 0; j < ob.cols; j++)
        {
            out<<ob.arr[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}


int main()
{
    matrix m1(3);
    cin>>m1;
    cout<<m1;

    matrix m2(3,3);
    cin>>m2;
    cout<<m2;

    matrix res;
    cout<<endl;
    cout<<"Working of Operator '+' after overloading for matrix :"<<endl;
    res = m1 + m2;
    cout<<res;


    cout<<endl;
    cout<<"Working of Operator '-' after overloading for matrix :"<<endl;
    res = m1 - m2;
    cout<<res;

    cout<<endl;
    cout<<"Working of Operator '*' after overloading for matrix :"<<endl;
    res = m1 * m2;
    cout<<res;

    cout<<"Working of Operator '=' after overloading for matrix :"<<endl;
    matrix copy;
    copy = res = m2;
    cout<<copy;

    cout<<"Working of Copy Constructor for Matrix :"<<endl;
    matrix m3(m1);
    cout<<m3;

    return 0;
}
