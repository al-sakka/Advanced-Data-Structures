/*
    An advanced static stack implementation using array
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
*/

#include <iostream>

template <typename T>
class StaticStack
{
private:
    T *data;
    size_t capacity;
    size_t topIndex;

    void ensureCapacity()
    {
        if (topIndex >= capacity)
        {
            size_t newCapacity = capacity ? (2 * capacity) : 1;
            T *newData = new T[newCapacity];
            std::copy(data, data + capacity, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }

public:
    // Constructor
    StaticStack() : data(nullptr), capacity(0), topIndex(0) {}

    // Destructor
    ~StaticStack()
    {
        // TODO : clear stack data from memory
        clear();
    }

    bool isEmpty() const
    {
        return (!capacity);
    }

    /*
        Add element to the top.
    */
    void push(const T &value)
    // pass by reference to not make a copy of the value.
    // const to not change the value inside the function.
    {
        ensureCapacity();
        data[topIndex++] = value;
    }

    /*
        Returns first element and switch the top to the second element.
    */
    T pop()
    {
        if (!isEmpty())
        {
            T poppedData = data[topIndex - 1];
            --topIndex;
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
            return data[topIndex - 1];
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
        if(isEmpty())
        {
            std::cout << "Stack is empty.\n";
        }
        else
        {
            int topPtr = topIndex;
            for(int i = 0 ; i < topIndex; ++i)
            {
                std::cout << data[topPtr - 1] << " ";
                --topPtr;
            }
            std::cout << std::endl;
        }
    }

    size_t size() const
    {
        return (topIndex);
    }

    void clear()
    {
        delete[] data;
        /*
            while(!isEmpty())
            {
                pop();
            }
        */
    }
};