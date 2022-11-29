#include <iostream>
using namespace std;

#define item int

class doubly_Linked_List;

class Node
{
    item data;
    Node* next;
    Node* prev;
    
    public:
        Node();
        Node(item value);
        friend doubly_Linked_List;
        friend istream& operator>>(istream& in, doubly_Linked_List& ob);
        friend ostream& operator<<(ostream& out, const doubly_Linked_List& ob);
        friend ostream& operator<<(ostream& out, const Node& ob);
};


class doubly_Linked_List
{
    Node* head, *tail;

    public:
        doubly_Linked_List();
        void append(item value);
        void addbeg(item value);
        void insert_after(item value, int n);
        void insert_before(item value , int n);
        void delbeg();
        void delany(int n);
        void delend();
        friend istream& operator>>(istream& in, doubly_Linked_List& ob);
        friend ostream& operator<<(ostream& out, const doubly_Linked_List& ob);
        ~doubly_Linked_List();
        friend Node;
};

Node::Node()
{
    this->next = NULL;
    this->prev = NULL;
}

Node::Node(item value)
{
    this->next = NULL;
    this->prev = NULL;
    this->data = value;
}

ostream& operator<<(ostream& out, const Node& ob)
{
    out << ob.data;

    return out;
}

doubly_Linked_List:: doubly_Linked_List()
{
    this->head = NULL;
}

istream& operator>>(istream& in, doubly_Linked_List& ob)
{
    item value;

    in >> value;

    return in;
}

void doubly_Linked_List:: append(item value)
{
    Node* temp = new Node(value);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;

}

void doubly_Linked_List:: addbeg(item value)
{
    Node* temp = new Node(value);
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    head->prev = temp;
    temp->next = head;
    head = temp;

}

void doubly_Linked_List:: insert_after(item value, int n)
{
    Node* temp = new Node(value);
    Node* current = head , *store;
    int i = 1;

    while(n>0)
    {
        if(i == n)
        {
            store = current->next;
            current->next = temp;
            temp->next = store;
            return;
        }
        else
        {
            current = current->next;
            i++;
        }
    }
}

void doubly_Linked_List:: insert_before(item value , int n)
{
    Node* temp = new Node(value);
    Node* current = head , *store;
    int i = 1;

    while(n>0)
    {
        if(i == n-1)
        {
            store = current->next;
            current->next = temp;
            temp->next = store;
            return;
        }
        else
        {
            current = current->next;
            i++;
        }
    }
}

void doubly_Linked_List:: delbeg()
{
    Node* store;

    if(head == NULL)
        return;

    store = head;
    head->next->prev = NULL;
    head = head->next;
    delete store;
}

void doubly_Linked_List:: delany(int n)
{
    Node* current = head, *temp;
    int i=1;

    while(i < n-1)
    {
        current = current->next;
        i++;
    } 
    temp = current->next;
    current->next = temp->next;
    delete temp;
}

void doubly_Linked_List:: delend()
{
    Node* store;

    if(tail == NULL)
        return;

    store = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    delete store;
}

ostream& operator<<(ostream& out, const doubly_Linked_List& ob)
{
    Node* current = ob.head;

    while (current != NULL)
    {
        out << current->data << " ";

        current = current->next;
    }
    out << endl;

    return out;
}

doubly_Linked_List:: ~doubly_Linked_List()
{
    Node* temp = head;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int n;
    doubly_Linked_List ll;
    item value;

    cout << "Enter the number of elements to be inserted :" << endl;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> value;
        ll.append(value);
    }

    cout << ll;
    // cout << "Node item " << n1;

    return 0;
}