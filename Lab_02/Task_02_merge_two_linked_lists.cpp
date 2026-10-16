
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

void append(Node*& h, int value)
{
    Node* p = new Node(value);

    if (h == NULL)
    {
        h = p;
        return;
    }

    Node* cur = h;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = p;
}

Node* mergeLists(Node* first, Node* second)
{
    Node* third = NULL;

    Node* p = first;

    while (p != NULL)
    {
        append(third, p->data);
        p = p->next;
    }

    p = second;

    while (p != NULL)
    {
        append(third, p->data);
        p = p->next;
    }

    return third;
}

void show(Node* p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

void clear(Node*& h)
{
    while (h != NULL)
    {
        Node* p = h;
        h = h->next;
        delete p;
    }
}

int main()
{
    Node *a = NULL, *b = NULL;

    int n, x;

    cout << "First list size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        append(a, x);
    }

    cout << "Second list size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        append(b, x);
    }

    Node* merged = mergeLists(a, b);

    cout << "\nFirst list: ";
    show(a);

    cout << "Second list: ";
    show(b);

    cout << "Third list (Merged): ";
    show(merged);

    clear(a);
    clear(b);
    clear(merged);

    return 0;
}

