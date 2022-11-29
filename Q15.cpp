// 15.	Design a template class Stack. Create a class Expression_Tree using Stack class. Add construct, preorder, inorder and postorder functions. Also add suitable constructors, destructor and operator overloading. 
#include<iostream>
#include<string>
using namespace std;
class ExpressionTree;
class stack;
int precedence(char ch);
class Node
{
    int data;
    Node *left, *right;

    public:
        Node(int value);
        friend stack;
        friend ExpressionTree;
        friend void pop_n_push(stack &s1, stack &s2);
};

Node:: Node(int data):data(data)
{
    this->left = NULL;
    this->right = NULL;
}

class stack
{
    Node **arr;
    int size, tos;

    public:
        stack();
        stack(int S);
        stack(const stack &ob);
        bool isFull();
        bool isEmpty();
        void push(Node* z);
        Node* pop();
        Node* peek();
        friend Node;
        friend ExpressionTree;
};

stack:: stack()
{
    arr = new Node*[10];
    tos = -1;
    size = 10;
}

stack:: stack(int S)
{
    arr = new Node*[S];
    tos = -1;
    size = S;
}

stack:: stack(const stack &ob)
{
    this->tos = ob.tos;
    this->size = ob.size;
    this->arr = new Node*[this->size];

    for(int i = 0; i <= this->tos; ++i)
    {
        this->arr[i] = ob.arr[i];
    }
}

bool stack:: isFull()
{
    if(tos == size-1)
        return true;
    else
        return false;
}

bool stack:: isEmpty()
{
    if(tos == -1)
        return true;
    else
        return false;
}

void stack:: push(Node* z)
{
    if(isFull())
        return;
    else
    {
        arr[++tos] = z;
    }
}

Node* stack:: pop()
{
    if(isEmpty())
        return NULL;
    else
    {
        return arr[tos--];
    }
}

void pop_n_push(stack &s1, stack &s2)
{
    Node* temp, *temp1, *temp2;
    temp = s2.pop();
    temp1 = s1.pop();
    temp2 = s1.pop();

    temp->left = temp2;
    temp->right = temp1;

    s1.push(temp);
}

Node* stack:: peek()
{
    if(isEmpty())
        return NULL;
    else
        return arr[tos];
}

class ExpressionTree
{
    Node* root;
    void inorder(Node* ptr)
    {
        if(ptr == NULL)
            return;
        inorder(ptr->left);
        cout << (char)ptr->data << ' ';
        inorder(ptr->right);
    }

    public:
        ExpressionTree(char *p); 
        void inorder();
        friend stack;
        friend Node;
        friend void pop_n_push(stack &s1, stack &s2);
};

ExpressionTree:: ExpressionTree(char *p)
{
    stack tree, ob;
    Node* temp;


    for(int i = 0; p[i] != '\0'; ++i)
    {
		
        if(p[i] >= '0' && p[i] <= '9')
            tree.push(new Node(p[i]));
        else{
            if(p[i] == '(')
                ob.push(new Node(p[i]));
            else if(p[i] == ')')
            {
                do
                {
                    temp = ob.peek();
                    if(temp->data != '(')
                        pop_n_push(tree, ob);
                }while(temp->data != '(');
				ob.pop();
            }
            else{
                while(!ob.isEmpty() && precedence(ob.peek()->data) >= precedence(p[i]))
				{
					pop_n_push(tree, ob);
				}
				ob.push(new Node(p[i]));
            }
        }
    }

    while(!ob.isEmpty())
    {
        pop_n_push(tree, ob);
    }
	this->root = tree.pop();
}

int precedence(char ch)
{
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

void ExpressionTree:: inorder()
{
    inorder(this->root);
}

int main()
{
    char arr[]="(1+2)*3";
    
    ExpressionTree ob(arr);
    ob.inorder();
    return 0;
}