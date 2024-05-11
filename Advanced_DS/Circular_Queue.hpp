/*
    An advanced circular queue using array implementation
    follows FIFO (first in first out) principle
    Created by : Abdallah El-Sakka
    Date : 24/4/2024

    Functions availaible :
        - isEmpty
        - push
        - enqueue
        - dequeue
        - printQueue
        - size
        - clear
*/

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    void resize(int new_capacity)
    {
        T *new_arr = new T[new_capacity];

        for (int i = 0; i < _size; i++)
        {
            // Copy all data from old array to the new one
            new_arr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;
        arr = new_arr;
        front = 0;
        rear = _size - 1;
        capacity = new_capacity;
        cout << "new capacity = " << capacity << endl;
    }

    T *arr;
    int front;
    int rear;

    // number of elements
    int _size;

    // actual size of the array
    int capacity;

public:
    Queue(int cap = 10) : _size(0), front(0), rear(-1) , capacity(cap)
    {
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    int size() const
    {
        return (_size);
    }

    bool isEmpty() const
    {
        return (_size == 0);
    }

    bool isFull() const
    {
        return (_size == capacity);
    }

    void enqueue(T value)
    // PUSH
    {
        if (isFull())
        {
            resize(2 * capacity);
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        ++(_size);
    }

    T dequeue()
    // POP
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }

        T value = arr[front];
        front = (front + 1) % capacity;
        --(_size);

        if (_size > 0 && _size == capacity / 4)
        {
            resize(capacity / 2);
        }

        return value;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw new runtime_error("FULL !!");
        }

        return arr[front];
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    void clear()
    {
        _size = 0;
        rear = -1;
        front = -1;
    }
};