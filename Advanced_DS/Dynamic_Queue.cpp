/*

    An advanced dynamic queue implementation
    Created by : Abdallah El-Sakka
    Date : 6/4/2024

    Functions availaible :
        - isEmpty
        - push
        - pop
        - peek
        - printData
        - size
        - clear

*/

#include <iostream>

template <typename T>
class DynamicQueue
{
private:
    struct Element
    {
        T data;
        Element *next;
        Element(T d) : data(d), next(nullptr) {}
    };

    Element *Top;
    Element *Tail;
    size_t queueSize;

public:
    DynamicQueue() : Top(nullptr), Tail(nullptr), queueSize(0) {}

    ~DynamicQueue()
    {
        // TODO : clear the queue
        // clear();
    }

    bool isEmpty()
    {
        return (Top == nullptr);
    }

    void push(T data)
    {
        Element *newElem = new Element(data);

        if (isEmpty())
        {
            Top = newElem;
            Tail = newElem;
        }
        else
        {
            Tail->next = newElem;
            Tail = newElem;
        }

        queueSize++;
    }

    void pop()
    {

        if (isEmpty())
        {
            std::cout << "Queue is already empty." << std::endl;
        }
        else
        {
            Element *temp = Top;
            Top = Top->next;
            delete temp;

            if (Top == nullptr)
            {
                Tail = nullptr;
            }

            queueSize--;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }
        else
        {
            return (Top->data);
        }
    }

    void printData()
    {
        if(isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
        }
        else
        {
            Element* temp = Top;
            for(int i = 0 ; i < queueSize ; ++i)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }

            std::cout << std::endl;
        }
    }

    void clear()
    {
        while (!isEmpty())
            pop();
    }

    size_t size()
    {
        return (queueSize);
    }
};