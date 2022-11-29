#include "Q9.h"

term::term()
{
    this->coef=0.0;
    this->exp=0;
}

term::term(double coef,int exp)
{
    this->coef=coef;
    this->exp=exp;
}

term::term(const term&ob)
{
    this->exp=ob.exp;
    this->coef=ob.coef;
}

term term :: operator+(const term& ob)const
{
    term res;

    res.coef=this->coef+ob.coef;
    res.exp=ob.exp;
 
    return res;
}

term term:: operator*(const term& ob)const
{
    term res;
    res.exp=this->exp+ob.exp;
    res.coef=this->coef*ob.coef;

    return res;
}

bool term :: operator<(const term& ob)const
{
    return this->exp < ob.exp;
}

bool term:: operator>(const term& ob)const
{
    return this->exp > ob.exp;
}

bool term:: operator==(const term& ob)const
{
    return ((this->exp == ob.exp) && (this->coef == ob.coef));
}

bool term:: operator!=(const term& ob)const
{
    return ((this->exp != ob.exp) && (this->coef != ob.coef));
}

term& term:: operator=(const term& ob)
{
    if(this != &ob)
    {
        this->coef = ob.coef;
        this->exp = ob.exp;
    }

    return *this;
}

istream& operator >>(istream& in ,term& ob)
{
    in>>ob.coef>>ob.exp;
    return in;
}

ostream& operator<<(ostream& out,const term& ob)
{
    out<<ob.coef<<"^"<<ob.exp;
}

node :: node(term eq)
{
    this->next=NULL;
    this->eq=eq;
}

istream& operator>>(istream& in,node& ob)
{
    in >> ob.eq;

    return in;
}

ostream& operator<<(ostream& out,const node& ob)
{
    out << ob.eq;

    return out;
}

node :: ~node()
{
    delete next;
}

poly :: poly()
{
    this->head=NULL;
}

poly :: poly(const poly& ob)
{
    node *curr = ob.head, *t = this->head;

    while(curr != NULL)
    {
        t->eq = curr->eq;
        curr = curr->next;
        t = t->next;
    }
}

poly poly :: operator+=(const poly& ob)
{
    poly& p1= *this;
    p1=p1+ob;
    return p1;
}

term poly:: operator+=(const term& ob)
{
    node* add= new node(ob);
    node* curr =head;
    if(head==NULL)
    {
        head=add;
        return;
    }
    else
    {
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=add;
    }
}

poly poly:: operator+(const poly& ob)const
{
    node* h1=this->head, *h2=ob.head;
    poly h3;

    while (h1!=NULL&&h2!=NULL)
    {
        if (h1->eq>h2->eq)
        {
            h3+=h1->eq;
            h1=h1->next;
        }
        else if(h2->eq>h1->eq)
        {
            h3+=h2->eq;
            h2=h2->next;
        }
        else
        {
            h3+=h1->eq;
            h1=h1->next;
            h2=h2->next;
        }
        
    }
    while (h1!=NULL)
    {
        h3+=h1->eq;
        h1=h1->next;
    }
    while (h2!=NULL)
    {
        h3+=h2->eq;
        h2=h2->next;
    }
    return h3;
}

void poly:: del()
{
    node* h=this->head,*temp;
    while (h!=NULL)
    {
        temp=h->next;
        delete(h);
        h=temp;
    }
}

poly poly:: operator*(const poly& ob)const
{
    poly temp,res;
    node* h1=this->head,*h2=ob.head,*curr;
    while (h1!=NULL)
    {
        curr=h2;
        while (curr)
        {
            term new_term=(h1->eq)*(curr->eq);
            temp+=new_term;
            curr = curr->next;
        }
        res=res+temp;
        temp.del();
        h1=h1->next;
    }
    return res;
}

poly poly::operator*(const term& ob)const
{
    node* ptrhead=this->head;
    poly res;
    while(ptrhead!=NULL)
    {
        res+=ptrhead->eq*ob;
        ptrhead=ptrhead->next;
    }
    return res;
}

poly& poly:: operator=(const poly& rhs)
{
    node* from=rhs.head,*to=this->head;
    while (from!=NULL)
    {
        to->eq=from->eq;
        to=to->next;
        from=from->next;
    }
    return *this;
}

istream& operator>>(istream& in,poly &ob)
{
    in>>ob.eq;
    return in;
}

ostream& operator<<(ostream& out,const poly &ob)
{
    out<<ob.eq;
    return out;
}
poly:: ~poly()
{
    this->del();
}

void poly :: del()
{
    node * h=this->head,*temp;
    while(h!=NULL)
    {
        temp=h->next;
        delete(h);
        h=temp;

    }

}



