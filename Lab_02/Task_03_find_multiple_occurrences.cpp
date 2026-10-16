
#include <iostream>
#include <vector>
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

vector<int> findOccurrences(Node* head, int key)
{
    vector<int> positions;

    int pos = 1;

    while (head != NULL)
    {
        if (head->data == key)
        {
            positions.push_back(pos);
        }

        head = head->next;
        pos++;
    }

    return positions;
}

int main()
{
    int n, x, key;

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
        }

        tail = p;
    }

    cout << "Search value: ";
    cin >> key;

    vector<int> positions = findOccurrences(head, key);

    cout << "\nOccurrences: " << positions.size() << endl;

    cout << "Positions (1-based): ";

    for (int i = 0; i < positions.size(); i++)
    {
        cout << positions[i] << " ";
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

