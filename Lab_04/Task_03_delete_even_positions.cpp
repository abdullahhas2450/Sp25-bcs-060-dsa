
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int x) {
        value = x;
        next = NULL;
    }
};

void append(Node*& last, int x) {
    Node* p = new Node(x);

    if (last == NULL) {
        last = p;
        p->next = p;
    }
    else {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

void deleteEvenPositions(Node*& last) {
    if (last == NULL)
        return;

    Node* first = last->next;
    Node* odd = first;

    while (odd->next != first) {
        Node* even = odd->next;

        if (even == first)
            break;

        odd->next = even->next;

        if (even == last)
            last = odd;

        delete even;

        odd = odd->next;
    }
}

void display(Node* last) {
    if (last == NULL) {
        cout << "Empty" << endl;
        return;
    }

    Node* p = last->next;

    do {
        cout << p->value << " ";
        p = p->next;
    } while (p != last->next);

    cout << endl;
}

int main() {
    int n, x;
    Node* last = NULL;

    cout << "Number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        append(last, x);
    }

    cout << "Original list: ";
    display(last);

    deleteEvenPositions(last);

    cout << "After deleting even positions: ";
    display(last);

    while (last != NULL) {
        Node* first = last->next;

        if (first == last) {
            delete last;
            last = NULL;
        }
        else {
            last->next = first->next;
            delete first;
        }
    }

    return 0;
}

