
#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };

    Node *frontNode, *rearNode;

public:
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    ~Queue() {
        int x;
        while (dequeue(x)) {
        }
    }

    bool empty() const {
        return frontNode == NULL;
    }

    void enqueue(int x) {
        Node* p = new Node(x);

        if (rearNode != NULL)
            rearNode->next = p;
        else
            frontNode = p;

        rearNode = p;
    }

    bool dequeue(int& value) {
        if (empty())
            return false;

        Node* p = frontNode;
        value = p->data;

        frontNode = frontNode->next;

        if (frontNode == NULL)
            rearNode = NULL;

        delete p;

        return true;
    }

    bool front(int& value) const {
        if (empty())
            return false;

        value = frontNode->data;
        return true;
    }

    void display() const {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* p = frontNode;

        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int option, x;

    while (true) {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front";
        cout << "\n4. Display";
        cout << "\n0. Exit";
        cout << "\nChoice: ";

        if (!(cin >> option) || option == 0)
            break;

        if (option == 1) {
            cout << "Value: ";
            cin >> x;
            q.enqueue(x);
        }
        else if (option == 2) {
            if (q.dequeue(x))
                cout << "Removed: " << x << endl;
            else
                cout << "Queue is empty" << endl;
        }
        else if (option == 3) {
            if (q.front(x))
                cout << "Front: " << x << endl;
            else
                cout << "Queue is empty" << endl;
        }
        else if (option == 4) {
            q.display();
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

