// 1. Create a class node and another class doubly lined list. Write appned, addbeg, insertbefore, insertafter, deleteany, delbeg, delend functions. Overload << & >> operators. Use template. Also add suitable constructors and destructor. Overload = operator.
#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node *prev;
    Node *next;
    template <typename U> friend class DLL;
public:
    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename T>
class DLL
{
private:
    Node<T>* head;

public:
    DLL()
    {
        this->head = NULL;
    }

    void append(T data)
    {
        Node<T> *temp = new Node<T>(data);

        if(this->head == NULL)
        {
            head = temp;
            return;
        }

        Node<T>* iter = this->head;

        while(iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = temp;
        temp->prev = iter;
    }

    void add_beg(T data)
    {
        Node<T> *node = new Node<T>(data);
        if(head == NULL)
        {
            head = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head  = node;
    }

    void insert_before(T data)
    {

    }

    void del_end()
    {
        Node<T> *temp = head, *prev = NULL;
        if(head == NULL)
            return;
        else if(temp->next == NULL)
        {
            head = NULL;
            delete(temp);
            return;
        }
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        delete(temp);
    }

    void del_beg()
    {
        Node<T>* temp = head;
        if(head == NULL)
            return;
        else if(head->next == NULL)
        {
            head = NULL;
            delete(temp);
            return;
        }
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }

    void del_any(T data)
    {
        Node<T>* temp = head;
        if(head== NULL)
            return;
        else if(head->data = data){
            temp = head->next;
            temp->prev = NULL;

        }
    }

    void display()
    {
        Node<T>* iter = this->head;
        if(this->head == NULL)
        {
            cout << "The List is Empty." << endl;
            return;
        }
        while(iter != NULL)
        {
            cout << iter->data << "-->";
            iter = iter->next;
        }
        cout << endl;
    }

};



int main()
{
    DLL<int> A;
    A.display();
    A.append(20);
    A.display();
    A.del_beg();
    A.display();
    return 0;
}
