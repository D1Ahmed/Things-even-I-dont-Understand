#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
        next = nullptr;
    }
};

void InsertAtEnd(node *&head, int val)
{
    node *n = new node(val);
    node *counter = head;

    if (head == nullptr)
    {
        head = n;
    }

    else
    {
        while (counter->next != nullptr) // checks whether the 'next' member of the node pointed to by counter is not nullptr
        {
            counter = counter->next; // it will give the address of the 2nd node to the counter
        } // this while loop wont run in 2nd function call bcz next member is already pointing twrds null
        counter->next = n; // it will only make the 1st node to point towards 2nd, but the counter will still point to the 1st
    }
}
void InsertAtStart(node *&head, int val)
{
    node *n = new node(val);
    node *counter = head;
    head = n;
    head->next = counter;
}

void InsertAny(node *&head, int val, int index)
{
    int count = 1;
    node *slider = head;
    node *n = new node(val);
    node *counter = head;

    int size = 1;
    while (counter->next != nullptr)
    {
        counter = counter->next;
        size++;
    }
    if (index < size + 1)
    {

        if (index == 1)
        {
            n->next = counter;
            head = n;
        }
        else
        {
            while (count != index)
            {
                counter = counter->next;
                count++;
            }
            n->next = counter;
            count = 1; // must include it, to reset count.
            while (count != index - 1)
            {
                slider = slider->next;
                count++;
            }
            slider->next = n;
        }
    }

    else
    {

        cout << "Index out of range. Can't insert " << val << " at index " << index << endl;
    }
}

void display(node *head)
{
    node *counter = head;
    while (counter != nullptr)
    {
        cout << counter->data << "->";
        counter = counter->next; // it will traverse counter to next node
    }
    cout << "NULL";
}

int main()
{
    node *head = nullptr;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtStart(head, 69);
    InsertAny(head, 699, 1);

    display(head);
}