/*

    An advanced dynamic stack implementation
    Created by : Abdallah El-Sakka
    Date : 6/4/2024

    Functions availaible :
        - isEmpty
        - push
        - pop
        - peek
        - printAll
        - size

*/

#include <iostream>

template <typename T>
class DynamicStack
{

private:
    struct Element
    {
        T data;
        Element *next;
        Element(T d) : data(d), next(nullptr) {}
    };

    Element *current;
    size_t stackSize;

public:
    DynamicStack() : current(nullptr), stackSize(0) {}

    ~DynamicStack()
    {
        // TODO :
    }

    bool isEmpty()
    {
        return (current == nullptr);
    }

    void push(T data)
    {

        Element *newSt = new Element(data);
        newSt->next = current;
        current = newSt;

        stackSize++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Element *temp = current;
            current = current->next;
            delete temp;

            stackSize--;
        }
        else
        {
            std::cout << "Stack is already empty." << std::endl;
        }
    }

    T peek()
    {
        return (current->data);
    }

    void printAll()
    {
        Element *temp = current;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    size_t size() const
    {
        return (stackSize);
    }
};