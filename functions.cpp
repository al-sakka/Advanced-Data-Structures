#include "Advanced_DS/Linked_List.cpp"
#include "Advanced_DS/Dynamic_Stack.cpp"
#include "Advanced_DS/Dynamic_Queue.cpp"

#include <iostream>
using namespace std;

void _linkedList()
{
    LinkedList<int> list;

    cout << "You are in a linked list\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) insert end \n 2) insert start\n 3) get data \n 4) delete end \n 5) delete start \n 6) deleteNode \n 7) size \n 8) print data \n 9) clear \n10) back to menu \n";

        int16_t nOfChoices = 10;
        int16_t choice;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter data : \n";

            int data;
            cin >> data;

            list.insertEnd(data);
        }
        else if (choice == 2)
        {

            cout << "Enter data : \n";

            int data;
            cin >> data;

            list.insertStart(data);
        }
        else if (choice == 3)
        {

            cout << "Enter index : \n";

            int index;
            cin >> index;

            list.getData(index);
        }
        else if (choice == 4)
        {
            list.deleteEnd();
        }
        else if (choice == 5)
        {
            list.deleteStart();
        }
        else if (choice == 6)
        {
            cout << "Enter index : \n";

            int index;
            cin >> index;

            list.deleteNode(index);
        }
        else if (choice == 7)
        {
            cout << "size of your linked list : " << list.size() << endl;
        }
        else if (choice == 8)
        {
            list.printData();
        }
        else if (choice == 9)
        {
            list.clear();
        }
        else if (choice == 10)
        {
            break;
        }
        else
        {
            cout << "Enter number between 1 and " << nOfChoices << endl;
        }
    }
}

void _stack()
{
    DynamicStack<int> stack;

    cout << "You are in a dynamic stack\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) push \n 2) pop \n 3) peek \n 4) printAll \n 5) size \n 6) clear \n 7) swap \n 8) shuffle \n 9) back to menu \n";
        
        int16_t nOfChoices = 9;
        int16_t choice;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter data : \n";

            int data;
            cin >> data;

            stack.push(data);
        }
        else if (choice == 2)
        {
            cout << stack.pop() << endl;
        }
        else if (choice == 3)
        {
            cout << stack.peek() << endl;
        }
        else if (choice == 4)
        {
            stack.printAll();
        }
        else if (choice == 5)
        {
            cout << stack.size() << endl;
        }
        else if (choice == 6)
        {
            stack.clear();
        }
        else if (choice == 7)
        {
            cout << "Enter index 1 & index 2 : \n";
            int ind1, ind2;
            cin >> ind1 >> ind2;
            stack.swap(ind1, ind2);
        }
        else if (choice == 8)
        {
            stack.shuffle();
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "Enter number between 1 and " << nOfChoices << endl;
        }
    }
}

void _queue()
{
    DynamicQueue<int> queue;

    cout << "You are in a dynamic queue\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) push \n 2) pop \n 3) peek \n 4) printData \n 5) size \n 6) clear \n 7) back to menu \n";
        
        int16_t nOfChoices = 7;
        int16_t choice;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter data : \n";

            int data;
            cin >> data;

            queue.push(data);
        }
        else if (choice == 2)
        {
            cout << queue.pop() << endl;
        }
        else if (choice == 3)
        {
            cout << queue.peek() << endl;
        }
        else if (choice == 4)
        {
            queue.printData();
        }
        else if (choice == 5)
        {
            cout << queue.size() << endl;
        }
        else if (choice == 6)
        {
            queue.clear();
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Enter number between 1 and " << nOfChoices << endl;
        }
    }
}