/*
    An advanced dynamic stack implementation
    follows LIFO (last in first out) principle
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

    bool isEmpty() const
    {
        return (top == nullptr);
    }

    /*
        Add element to the top.
    */
    void push(const T& data) 
    // pass by reference to not make a copy of the value.
    // const to not change the value inside the function.
    {

        Element *newEl = new Element(data);
        newEl->next = top;
        top = newEl;

        stackSize++;
    }

    /*
        Returns first element and switch the top to the second element.
    */
    T pop()
    {
        if (!isEmpty())
        {
            Element *temp = top;
            T poppedData = top->data;
            top = top->next;
            delete temp;

            stackSize--;

            return poppedData;
        }
        else
        {
            std::cout << "Stack is already empty." << std::endl;
            return T();
        }
    }

    /*
        Returns first element.
    */
    T peek() const
    // can also named Top()
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

    /*
        Print the whole stack.
    */
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
        while(!isEmpty())
        {
            pop();
        }

        /*
            while (top != nullptr)
            {
                Element *temp = top;
                top = top->next;
                delete temp;
            }
            stackSize = 0;
        */
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