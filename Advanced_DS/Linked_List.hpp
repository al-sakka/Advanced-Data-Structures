/*

    An advanced double linked list implementation with head & tail
    Created by : Abdallah El-Sakka
    Date : 6/4/2024

    Functions availaible :
        - isEmpty
        - insertEnd
        - insertStart
        - insert
        - getData
        - deleteEnd
        - deleteStart
        - deleteNode
        - size
        - printData
        - clear

*/

#include <iostream>

template <typename T>
class LinkedList
{
private:

    int nOfFunctions = 10;

    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t listSize;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Destructor
    ~LinkedList()
    {
        // This method to just clear the memory after the program is executed.

        clear();
    }

    int getnOfFunctions() const
    {
        return nOfFunctions;
    }

    bool isEmpty() const
    {
        return (head == nullptr);
    }

    void insertEnd(T data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;

            head->next = nullptr;
            head->prev = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
        }
        else
        {
            // O(1)
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = nullptr;
            tail = newNode;

            // O(n)
            /*
                Node *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nullptr;
                tail = newNode;
            */
        }

        listSize++;
    }

    void insertStart(T data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;

            head->next = nullptr;
            head->prev = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }

        listSize++;
    }

    void insert(size_t index, T value)
    {
        if (index > listSize)
            return;

        if (index == 0)
        {
            insertStart(value);
        }
        else if (index == listSize)
        {
            insertEnd(value);
        }
        else
        {
            Node *newNode = new Node(value);
            Node *temp = head;

            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }

            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            listSize++;
        }
    }

    T getData(int index)
    {

        if (index >= listSize || index < 0)
        {
            std::cout << "Index Excedded.\n";
            return T();
        }

        if (index == listSize - 1)
        {
            return (tail->data);
        }

        Node *tempNode = head;

        for (int i = 0; i < index; ++i)
        {
            tempNode = tempNode->next;
        }

        return (tempNode->data);
    }

    void deleteEnd()
    {
        if (!isEmpty())
        {
            Node *temp = tail;

            if (listSize == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {

                tail = tail->prev;
                tail->next = nullptr;
            }

            delete temp;
            listSize--;
        }
    }

    void deleteStart()
    {
        if (!isEmpty())
        {
            Node *tempNode = head;

            if (listSize == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }

            delete tempNode;
            listSize--;
        }
    }

    int deleteNode(int index)
    {
        if (index >= listSize || index < 0)
        {
            std::cout << "Index Excedded.\n";
            return -1;
        }
        else
        {
            Node *deletedNode = head;

            for (int i = 0; i < index; ++i)
            {
                deletedNode = deletedNode->next;
            }

            if (index == 0) // head
            {
                deleteStart();
            }
            else if (index == listSize - 1) // tail
            {
                deleteEnd();
            }
            else // delete from the middle
            {
                deletedNode->prev->next = deletedNode->next;
                deletedNode->next->prev = deletedNode->prev;
                delete deletedNode;
                listSize--;
            }
        }

        return 0;
    }

    size_t size() const
    {
        return (listSize);
    }

    void printData()
    {
        if (isEmpty())
        {
            std::cout << "List is empty." << std::endl;
        }
        else
        {

            Node *tempNode = head;
            for (int i = 0; i < listSize; ++i)
            {
                T data = tempNode->data;
                std::cout << data << " ";
                tempNode = tempNode->next;
            }

            std::cout << std::endl;
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        listSize = 0;
    }
};