#include <iostream>
#include "functions.cpp"
using namespace std;

int main()
{

    cout << "Choose a data structure to make operations to : " << endl;
    cout << " 1) Linked List \n 2) Stack \n 3) Queue \n";
    int16_t nOfChoices = 3;

    int16_t choice;

    while (1)
    {
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
        default:
            cout << "Choose between 1 and " << nOfChoices << endl;
            break;
        }
    }

    return 0;
}