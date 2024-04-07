#include <iostream>
#include "functions.cpp"
using namespace std;

int main()
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