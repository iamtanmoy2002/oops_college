// 2. Create a class node and another class BST. Add insert, deletenode, preorder, inorder, postoder functions. Also add a function to calculate the height of the tree. Use template. Also add suitable constructors and destructor .overload = operator.
#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node* left, *right;
    template <typename U> friend class BST;

public:
    Node()
    {
        left = right = NULL;
    }

    Node(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

template <typename T>
class BST
{
private:
    Node<T> *root;
public:
    BST<T>()
    {
        root = NULL;
    }

    BST<T>(T data)
    {
        Node<T>* node = new Node<T>(data);
        root = node;
        root->left = root->right = NULL;
    }

    ~BST<T>()
    {
        destroy(this->root);
    }

    void destroy(Node <T> *root)
    {
        if(root)
        {
            if(root->left)
                destroy(root->left);
            if(root->right)
                destroy(root->right);
            delete root;
        }
    }

    T successor(Node<T> *root)
    {
        root = root->right;
        while(root->left)
        {
            root = root->left;
        }
        return root->data;
    }

    void insert_node(T data)
    {
        insert_node_driver(root, data);
    }

    void insert_node_driver(Node<T> *&root, T data)
    {
        if(root == NULL)
        {
            root = new Node<T>(data);
            return;
        }
        else if(data > root->data)
            insert_node_driver(root->right, data);
        else
            insert_node_driver(root->left, data);
    }

    void delete_node(T data)
    {
            delete_node_driver(this->root, data);
    }

    void delete_node_driver(Node<T>*&root, T data)
    {
        if(root == NULL)
            return;

        else if(data < root->data)
            delete_node_driver(root->left, data);

        else if(data > root->data)
            delete_node_driver(root->right, data);

        else
        {
            if(root->left == NULL && root->right == NULL)
                delete root;
            else if(root->left == NULL && root->right != NULL)
            {
                root = root->right;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                root = root->left;
            }
            else
            {
                root->data = successor(root);
                delete_node_driver(root->right, root->data);
            }
        }
    }

    void preorder()
    {
        preorder_driver(this->root);
    }

    void preorder_driver(Node<T> *root)
    {
        if(root)
        {
            cout << root->data << " ";
            if(root->left)
                preorder_driver(root->left);
            if(root->right)
                preorder_driver(root->right);
        }
    }

    void postorder()
    {
        postorder_driver(this->root);
    }
    void postorder_driver(Node<T> *root)
    {
        if(root)
        {
            if(root->left)
                postorder_driver(root->left);
            if(root->right)
                postorder_driver(root->right);
            cout << root->data << " ";
        }
    }

    void inorder()
    {
        inorder_driver(this->root);
    }
    void inorder_driver(Node<T> *root)
    {
        if(root)
        {
            if(root->left)
                inorder_driver(root->left);
            cout << root->data << " ";
            if(root->right)
                inorder_driver(root->right);
        }
    }

    int height(Node<T> *root)
    {
        if(root == NULL)
            return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);

        if(left_height > right_height)
            return 1 + left_height;
        return 1 + right_height;
    }

    BST<T>& operator=(const BST<T> &tree1)
    {
        this->root = NULL;
        copy_tree(this->root, tree1->root);
        return tree1;
    }

    void copy_tree(Node<T> *&dest, const Node<T> *source)
    {
        if(source == NULL)
            return;
        dest = new Node<T>(source->data);
        dest->left = copy_tree(dest->left, source->left);
        dest->right = copy_tree(dest->right, source->right);
    }

};


int main()
{
    BST<int> A(10);

    A.preorder();
    return 0;
}
