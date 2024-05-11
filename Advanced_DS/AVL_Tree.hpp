/*
    An advanced AVL Tree implementation
    Created by : Abdallah El-Sakka
    Date : 11/5/2024

    Functions availaible :
        -
*/

#include <iostream>
#include <algorithm>

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    int height;
    Node(T d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

template <class T>
class AVLTree
{
private:
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFact(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node *node)
    {
        if (node == nullptr)
            return;
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node<T> *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node<T> *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node<T> *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node<T>(key);
        }

        if (key < (node->data))
        {
            node->left = insert(node->left, key);
        }
        else if (key > (node->data))
        {
            node->right = insert(node->right, key);
        }
        else
        {
            // key is already exist
            return node;
        }

        updateHeight(node);

        int balance = balanceFact(node);

        if (balance > 1 && key < (node->left->data))
        {
            return rotateRight(node);
        }

        if (balance < -1 && key > (node->right->data))
        {
            return rotateLeft(node);
        }

        if (balance > 1 && key > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < (node->right->data))
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    Node *<T> root;

public:
    AVLTree() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
    }
};