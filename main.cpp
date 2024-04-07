#include "Advanced_DS/Linked_List.cpp"
#include "Advanced_DS/Dynamic_Stack.cpp"
#include "Advanced_DS/Dynamic_Queue.cpp"
#include <iostream>

using namespace std;

int main()
{
    // LinkedList<int> l;

    // DynamicStack<int> s;

    DynamicQueue<int> q;

    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    q.printData();

    q.clear();
    
    q.printData();
}