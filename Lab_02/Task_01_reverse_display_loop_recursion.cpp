

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void showReverseRecursive(Node* p)
{
    if (p == NULL)
        return;

    showReverseRecursive(p->next);

    cout << p->data << " ";
}

void showReverseLoop(Node* head, int arr[], int n)
{
    Node* p = head;
    int i = 0;

    while (p != NULL)
    {
        arr[i] = p->data;
        i++;
        p = p->next;
    }

    for (int j = n - 1; j >= 0; j--)
    {
        cout << arr[j] << " ";
    }
}

int main()
{
    int n, value;

    cout << "Number of nodes: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number";
        return 1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    int arr[1000];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        Node* p = new Node;

        p->data = value;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    cout << "\nReverse using loop: ";
    showReverseLoop(head, arr, n);

    cout << "\nReverse using recursion: ";
    showReverseRecursive(head);

    cout << endl;

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

