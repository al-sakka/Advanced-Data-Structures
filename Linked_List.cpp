#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t listSize;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Destructor
    ~LinkedList()
    {
        // This method to just clear the memory after the program is executed.

        while (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void insertEnd(int data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;

            head->next = nullptr;
            head->prev = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nullptr;

            tail = newNode;
        }

        listSize++;
    }

    void insertStart(int data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;

            head->next = nullptr;
            head->prev = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }

        listSize++;
    }

    int getData(int index)
    {

        if (index >= listSize || index < 0)
        {
            cout << "Index Excedded.\n";
            return -1;
        }

        Node *tempNode = head;

        for (int i = 0; i < index; ++i)
        {
            tempNode = tempNode->next;
        }

        return (tempNode->data);
    }

    void deleteEnd()
    {
        if (!isEmpty())
        {
            Node *temp = tail;

            if (listSize == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {

                tail = tail->prev;
                tail->next = nullptr;
            }

            delete temp;
            listSize--;
        }
    }

    void deleteStart()
    {
        if (!isEmpty())
        {
            Node *tempNode = head;

            if (listSize == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }

            delete tempNode;
            listSize--;
        }
    }

    int deleteNode(int index)
    {
        if (index >= listSize || index < 0)
        {
            cout << "Index Excedded.\n";
            return -1;
        }
        else
        {
            Node *deletedNode = head;

            for (int i = 0; i < index; ++i)
            {
                deletedNode = deletedNode->next;
            }

            if (index == 0) // head
            {
                deleteStart();
            }
            else if (index == listSize - 1) // tail
            {
                deleteEnd();
            }
            else // delete from the middle
            {
                deletedNode->prev->next = deletedNode->next;
                deletedNode->next->prev = deletedNode->prev;
                delete deletedNode;
                listSize--;
            }
        }

        return 0;
    }

    int size()
    {
        return (listSize);
    }

    void printData()
    {
        if (isEmpty())
        {
            cout << "List is empty." << endl;
        }
        else
        {

            Node *tempNode = head;
            for (int i = 0; i < listSize; ++i)
            {
                cout << tempNode->data << " ";
                tempNode = tempNode->next;
            }

            cout << endl;
        }
    }
};

int main()
{

    LinkedList list1 = LinkedList();

    list1.insertEnd(5);
    list1.insertStart(6);
    list1.insertEnd(7);
    list1.insertStart(8);
    list1.insertEnd(9);

    // 8 6 5 7 9

    list1.deleteEnd();
    list1.deleteStart();

    list1.printData();

    cout << "Size of list1 : " << list1.size() << endl;

    // cout << "data in index 4 is " << list1.getData(5) << endl;

    return 0;
}