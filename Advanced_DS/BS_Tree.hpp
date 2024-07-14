/*
    An advanced binary search tree implementation
    Created by : Abdallah El-Sakka
    Date : 27/4/2024

    Functions availaible :
        - insert
        - remove
        - in order traversal
        - pre order traversal
        - post order traversal
        - level order traversal
*/

#include <iostream>
#include <queue>

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    // int height;
    Node(T d) : data(d), left(nullptr), right(nullptr) {}
};

template <class T>
class BSTree
{
private:

    int noOfFunctions = 6;

    Node<T> *insertRec(Node<T> *node, T data)
    // Recursive function to insert a new node into the BST.
    {
        if (node == nullptr)
        {
            return new Node<T>(data);
        }
        if (data < (node->data))
        {
            node->left = insertRec((node->left), data);
        }
        else if (data > (node->data))
        {
            node->right = insertRec((node->right), data);
        }
        // Useless
        return node;
    }

    Node<T> *removeRec(Node<T> *node, T data)
    {
        if(node == nullptr)
        {
            return node;
        }

        if(data < (node->data))
        {
            node->left = removeRec(node->left, data);
        }
        else if(data > (node->data))
        {
            node->right = removeRec(node->right, data);
        }
        else
        {
            if((node->left) == nullptr)
            {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if((node->right) == nullptr)
            {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            Node<T>* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);

        }

        return node;
    }

    Node<T>* minValueNode(Node<T>* node)
    {
        Node<T>* current = node;

        while(current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void inOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            std::cout << (node->data) << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            std::cout << (node->data) << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << (node->data) << " ";
        }
    }

    void levelOrder(Node<T> *node)
    {
        if (!node)
            return;

        std::queue<Node<T> *> queue;

        queue.push(node);

        while (!queue.empty())
        {
            Node<T> *temp = queue.front();
            queue.pop();
            std::cout << (temp->data) << ' ';

            if (temp->left)
            {
                queue.push(temp->left);
            }

            if (temp->right)
            {
                queue.push(temp->right);
            }
        }
    }

    Node<T> *root;

public:
    BSTree() : root(nullptr){};

    int getnOfFunctions() const
    {
        return noOfFunctions;
    }

    void insert(T data)
    {
        root = insertRec(root, data);
    }

    void remove(T data)
    {
        root = removeRec(root, data);
    }

    void inOrderTraversal()
    {
        std::cout << "In-order Traversal : ";
        inOrder(root);
        std::cout << std::endl;
    }

    void preOrderTraversal()
    {
        std::cout << "Pre-order Traversal : ";
        preOrder(root);
        std::cout << std::endl;
    }

    void postOrderTraversal()
    {
        std::cout << "post-order Traversal : ";
        postOrder(root);
        std::cout << std::endl;
    }

    void levelOrderTraversal()
    {
        std::cout << "Level-order Traversal : ";
        levelOrder(root);
        std::cout << std::endl;
    }
};