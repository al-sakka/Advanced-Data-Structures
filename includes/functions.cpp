#include "functions.hpp"

void _linkedList()
{
    LinkedList<int> list;

    cout << "You are in a linked list\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) insert end \n 2) insert start \n 3) insert \n 4) get data \n 5) delete end \n 6) delete start \n 7) deleteNode \n 8) size \n 9) print data \n 10) clear \n 11) back to menu \n";

        int16_t nOfChoices = 11;
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

            cout << "Enter value : \n";

            int value;
            cin >> value;

            list.insert(index, value);
        }
        else if (choice == 4)
        {

            cout << "Enter index : \n";

            int index;
            cin >> index;

            cout << list.getData(index) << endl;
        }
        else if (choice == 5)
        {
            list.deleteEnd();
        }
        else if (choice == 6)
        {
            list.deleteStart();
        }
        else if (choice == 7)
        {
            cout << "Enter index : \n";

            int index;
            cin >> index;

            list.deleteNode(index);
        }
        else if (choice == 8)
        {
            cout << "size of your linked list : " << list.size() << endl;
        }
        else if (choice == 9)
        {
            list.printData();
        }
        else if (choice == 10)
        {
            list.clear();
        }
        else if (choice == 11)
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

int performUI()
{
    while (1)
    {
        cout << "Choose a data structure : " << endl;
        cout << " 1) Linked List \n 2) Stack \n 3) Queue \n 4) Exit \n ";
        int16_t nOfChoices = 4;

        int16_t choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            _linkedList();
            break;
        case 2:
            _stack();
            break;
        case 3:
            _queue();
            break;
        case 4:
            return 0;
        default:
            cout << "Choose between 1 and " << nOfChoices << endl;
            break;
        }
    }
}