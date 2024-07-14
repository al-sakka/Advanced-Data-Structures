#include "functions.hpp"

void _linkedList()
{
    LinkedList<int> list;

    cout << "You are in a linked list\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) insert end \n 2) insert start \n 3) insert \n 4) get data \n 5) delete end \n 6) delete start \n 7) deleteNode \n 8) size \n 9) print data \n 10) clear \n 11) back to menu \n";

        int16_t nOfFunctions = list.getnOfFunctions();
        int16_t nOfChoices = nOfFunctions + 1;
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
} // Linked List

void _stack()
{
    DynamicStack<int> stack;

    cout << "You are in a dynamic stack\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) push \n 2) pop \n 3) peek \n 4) printAll \n 5) size \n 6) clear \n 7) swap \n 8) shuffle \n 9) back to menu \n";

        int16_t nOfFunctions = stack.getnOfFunctions();
        int16_t nOfChoices = nOfFunctions + 1;
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
} // Stack

void _queue()
{
    DynamicQueue<int> queue;

    cout << "You are in a dynamic queue\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) push \n 2) pop \n 3) peek \n 4) printData \n 5) size \n 6) clear \n 7) back to menu \n";

        int16_t nOfFunctions = queue.getnOfFunctions();
        int16_t nOfChoices = nOfFunctions + 1;
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
} // Queue

void _tree()
{
    BSTree<int> tree;
    cout << "You are in a tree\n";

    while (1)
    {
        cout << "Choose an operation to do : \n";
        cout << " 1) insert \n 2) remove \n 3) in order traversal \n 4) pre order traversal \n 5) post order traversal \n 6) level order traversal \n 7) back to menu \n";

        int nOfFunctions = tree.getnOfFunctions();
        int16_t nOfChoices = nOfFunctions + 1;
        int16_t choice;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter data to insert: \n";

            int data;
            cin >> data;

            tree.insert(data);
        }
        else if (choice == 2)
        {

            cout << "Enter data to remove: \n";

            int data;
            cin >> data;

            tree.remove(data);
        }
        else if (choice == 3)
        {
            tree.inOrderTraversal();
        }
        else if (choice == 4)
        {
            tree.preOrderTraversal();
        }
        else if (choice == 5)
        {
            tree.postOrderTraversal();
        }
        else if (choice == 6)
        {
            tree.levelOrderTraversal();
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
} // Tree
