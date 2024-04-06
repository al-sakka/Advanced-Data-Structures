#include"Advanced_DS/Linked_List.cpp"
#include"Advanced_DS/Dynamic_Stack.cpp"
#include"Advanced_DS/Dynamic_Queue.cpp"
#include<iostream>

using namespace std;

int main()
{
    // LinkedList<int> list;
    DynamicStack<int> stack;

    stack.push(50);
    stack.push(40);
    stack.push(30);
    stack.push(60);

    stack.printAll();

    stack.swap(1,2);

    stack.printAll();


}