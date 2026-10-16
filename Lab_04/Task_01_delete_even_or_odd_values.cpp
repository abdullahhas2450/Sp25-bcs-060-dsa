
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(Node*& last, int x)
{
    Node* p = new Node(x);

    if (last == NULL)
    {
        last = p;
        p->next = p;
    }
    else
    {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

void deleteParity(Node*& last, bool removeEven)
{
    if (last == NULL)
        return;

    Node* current = last->next;
    Node* previous = last;

    int length = 1;

    Node* p = current->next;

    while (p != current)
    {
        length++;
        p = p->next;
    }

    for (int i = 0; i < length && last != NULL; i++)
    {
        Node* next = current->next;

        if ((current->data % 2 == 0) == removeEven)
        {
            if (current == next)
            {
                delete current;
                last = NULL;
                break;
            }

            previous->next = next;

            if (current == last)
            {
                last = previous;
            }

            delete current;
        }
        else
        {
            previous = current;
        }

        current = next;
    }
}

void show(Node* last)
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* p = last->next;

    do
    {
        cout << p->data << " ";
        p = p->next;
    }
    while (p != last->next);

    cout << endl;
}

int main()
{
    int n, x, choice;

    Node* last = NULL;

    cout << "Number of nodes: ";
    cin >> n;

    if (n < 0)
        return 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;

        append(last, x);
    }

    cout << "\nOriginal circular linked list: ";
    show(last);

    cout << "\nDelete 1. Even values or 2. Odd values? ";
    cin >> choice;

    if (choice == 1)
    {
        deleteParity(last, true);
    }
    else if (choice == 2)
    {
        deleteParity(last, false);
    }
    else
    {
        cout << "Invalid choice";
    }

    cout << "\nUpdated circular linked list: ";
    show(last);

    while (last != NULL)
    {
        Node* head = last->next;

        if (head == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            last->next = head->next;
            delete head;
        }
    }

    return 0;
}

