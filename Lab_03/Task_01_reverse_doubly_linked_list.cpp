
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node* reverseList(Node* head)
{
    Node* current = head;
    Node* newHead = NULL;

    while (current != NULL)
    {
        Node* temp = current->prev;

        current->prev = current->next;
        current->next = temp;

        newHead = current;

        current = current->prev;
    }

    return newHead;
}

void display(Node* p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    int n, x;

    Node *head = NULL, *tail = NULL;

    cout << "Number of nodes: ";
    cin >> n;

    if (n < 0)
        return 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;

        Node* p = new Node(x);

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            tail->next = p;
            p->prev = tail;
        }

        tail = p;
    }

    cout << "\nOriginal list: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    display(head);

    while (head != NULL)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }

    return 0;
}

