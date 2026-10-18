
#include <iostream>
using namespace std;

class Deque {
    struct Node {
        int value;
        Node *prev, *next;

        Node(int x) {
            value = x;
            prev = NULL;
            next = NULL;
        }
    };

    Node *first, *last;

public:
    Deque() {
        first = NULL;
        last = NULL;
    }

    ~Deque() {
        int x;
        while (popFront(x)) {
        }
    }

    void pushFront(int x) {
        Node* p = new Node(x);

        p->next = first;

        if (first != NULL)
            first->prev = p;
        else
            last = p;

        first = p;
    }

    void pushBack(int x) {
        Node* p = new Node(x);

        p->prev = last;

        if (last != NULL)
            last->next = p;
        else
            first = p;

        last = p;
    }

    bool popFront(int& x) {
        if (first == NULL)
            return false;

        Node* p = first;
        x = p->value;

        first = first->next;

        if (first != NULL)
            first->prev = NULL;
        else
            last = NULL;

        delete p;

        return true;
    }

    bool popBack(int& x) {
        if (last == NULL)
            return false;

        Node* p = last;
        x = p->value;

        last = last->prev;

        if (last != NULL)
            last->next = NULL;
        else
            first = NULL;

        delete p;

        return true;
    }

    void show() const {
        if (first == NULL) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* p = first;

        while (p != NULL) {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;
    int c, x;

    while (true) {
        cout << "\n1. Insert front";
        cout << "\n2. Insert rear";
        cout << "\n3. Delete front";
        cout << "\n4. Delete rear";
        cout << "\n5. Display";
        cout << "\n0. Exit";
        cout << "\nChoice: ";

        if (!(cin >> c) || c == 0)
            break;

        if (c == 1 || c == 2) {
            cout << "Value: ";
            cin >> x;

            if (c == 1)
                dq.pushFront(x);
            else
                dq.pushBack(x);
        }
        else if (c == 3) {
            if (dq.popFront(x))
                cout << "Removed: " << x << endl;
            else
                cout << "Deque is empty" << endl;
        }
        else if (c == 4) {
            if (dq.popBack(x))
                cout << "Removed: " << x << endl;
            else
                cout << "Deque is empty" << endl;
        }
        else if (c == 5) {
            dq.show();
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

