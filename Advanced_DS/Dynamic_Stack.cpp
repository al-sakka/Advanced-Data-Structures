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
        - clear
        - swap
        - shuffle

*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>

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

    Element *top;
    size_t stackSize;

public:

    // Constructor
    DynamicStack() : top(nullptr), stackSize(0) {}

    // Destructor
    ~DynamicStack()
    {
        // TODO : clear stack data from memory
        clear();
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(T data)
    {

        Element *newSt = new Element(data);
        newSt->next = top;
        top = newSt;

        stackSize++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Element *temp = top;
            top = top->next;
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
        if (!isEmpty())
        {
            return (top->data);
        }
        else
        {
            std::cout << "Stack is already empty." << std::endl;
            return T();
        }
    }

    void printAll()
    {
        Element *temp = top;

        for (int i = 0; i < stackSize; ++i)
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

    void clear()
    {
        while (top != nullptr)
        {
            Element *temp = top;
            top = top->next;
            delete temp;
        }

        stackSize = 0;
    }

    void swap(int ind1, int ind2)
    {
        Element *temp1 = top;
        Element *temp2 = top;

        for (int i = 0; i < ind1; ++i)
        {
            temp1 = temp1->next;
        }

        for (int i = 0; i < ind2; ++i)
        {
            temp2 = temp2->next;
        }

        int data1 = temp1->data;
        int data2 = temp2->data;

        temp1->data = data2;
        temp2->data = data1;
    }

    void shuffle()
    {
        // rondom value from (0) --> (stack size - 1)
        std::srand(std::time(nullptr));
        int random_number = std::rand() % (stackSize - 1);

        for (int i = 0; i < stackSize; ++i)
        {
            swap(i, random_number);
        }
    }
};