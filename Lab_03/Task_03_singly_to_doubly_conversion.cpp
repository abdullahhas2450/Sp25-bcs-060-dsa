
#include <iostream>
using namespace std;

struct Single
{
    int data;
    Single* next;

    Single(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Double
{
    int data;
    Double *prev, *next;

    Double(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Double* convert(Single* head)
{
    Double *first = NULL, *last = NULL;

    Single* p = head;

    while (p != NULL)
    {
        Double* node = new Double(p->data);

        if (first == NULL)
        {
            first = node;
        }
        else
        {
            last->next = node;
            node->prev = last;
        }

        last = node;
        p = p->next;
    }

    return first;
}

int main()
{
    int n, x;

    Single *head = NULL, *tail = NULL;

    cout << "Number of singly linked nodes: ";
    cin >> n;

    if (n < 0)
        return 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;

        Single* p = new Single(x);

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }

        tail = p;
    }

    Double* doubly = convert(head);

    cout << "\nDoubly linked list forward: ";

    Double* last = NULL;

    Double* p = doubly;

    while (p != NULL)
    {
        cout << p->data << " ";
        last = p;
        p = p->next;
    }

    cout << "\nBackward: ";

    p = last;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->prev;
    }

    cout << endl;

    while (head != NULL)
    {
        Single* temp = head;
        head = head->next;
        delete temp;
    }

    while (doubly != NULL)
    {
        Double* temp = doubly;
        doubly = doubly->next;
        delete temp;
    }

    return 0;
}

