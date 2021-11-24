#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }



    void PostOrder(Node *node)
    {
        if(node == NULL)
            return;
    
        PostOrder(node->left);
        PostOrder(node->right);
        cout<<node->data<<" ";
    }

 

    void InOrder(Node *node)
    {
        if(node == NULL)
            return;
    
        InOrder(node->left);
        cout<<node->data<<" ";
        InOrder(node->right);
    }



    void PreOrder(Node *node)
    {
        if(node == NULL)
            return;

        cout<<node->data<<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
};



int main()
{
    Node *root = new Node(15);
    root->left = new Node(19);
    root->right = new Node(33);
    root->left->left = new Node(48);
    root->left->right = new Node(55);

    cout<<"\nPreOrder Traversal of Binary Tree is \n";
    (*root).PreOrder(root);

    cout<<"\nInOrder Traversal of Binary Tree is \n";
    (*root).InOrder(root);

    cout<<"\nPostOrder Traversal of Binary Tree is \n";
    (*root).PostOrder(root);

    cout<<endl;

    return 0;
}