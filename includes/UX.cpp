#include "UX.hpp"

// start application for the user
int PerformUX()
{
    while (1)
    {
        std::cout << "Choose a data structure : " << std::endl;
        std::cout << " 1) Linked List \n 2) Stack \n 3) Queue \n 4) Tree \n 5) Exit \n";
        int16_t nOfChoices = 5;

        int16_t choice;
        std::cin >> choice;

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
            _tree();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Choose between 1 and " << nOfChoices << std::endl;
            break;
        }
    }
}