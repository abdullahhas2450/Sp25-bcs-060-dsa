
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node* search(Node* h, int key)
{
    while (h != NULL)
    {
        if (h->data == key)
            return h;

        h = h->next;
    }

    return NULL;
}

bool swapNodes(Node*& head, int a, int b)
{
    Node *x = search(head, a);
    Node *y = search(head, b);

    if (x == NULL || y == NULL)
        return false;

    if (x == y)
        return true;

    if (x->next == y)
    {
        Node* p = x->prev;
        Node* n = y->next;

        if (p != NULL)
            p->next = y;
        else
            head = y;

        y->prev = p;
        y->next = x;

        x->prev = y;
        x->next = n;

        if (n != NULL)
            n->prev = x;
    }
    else if (y->next == x)
    {
        Node* p = y->prev;
        Node* n = x->next;

        if (p != NULL)
            p->next = x;
        else
            head = x;

        x->prev = p;
        x->next = y;

        y->prev = x;
        y->next = n;

        if (n != NULL)
            n->prev = y;
    }
    else
    {
        Node *xp = x->prev;
        Node *xn = x->next;
        Node *yp = y->prev;
        Node *yn = y->next;

        if (xp != NULL)
            xp->next = y;
        else
            head = y;

        if (xn != NULL)
            xn->prev = y;

        if (yp != NULL)
            yp->next = x;
        else
            head = x;

        if (yn != NULL)
            yn->prev = x;

        x->prev = yp;
        x->next = yn;

        y->prev = xp;
        y->next = xn;
    }

    return true;
}

int main()
{
    int n, v, a, b;

    Node *head = NULL;
    Node *tail = NULL;

    cout << "Number of nodes: ";
    cin >> n;

    if (n < 0)
        return 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> v;

        Node* p = new Node(v);

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

    cout << "Two values to swap: ";
    cin >> a >> b;

    if (!swapNodes(head, a, b))
    {
        cout << "One or both values not found";
    }
    else
    {
        cout << "\nAfter swapping nodes: ";

        Node* p = head;

        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

    cout << endl;

    while (head != NULL)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }

    return 0;
}

