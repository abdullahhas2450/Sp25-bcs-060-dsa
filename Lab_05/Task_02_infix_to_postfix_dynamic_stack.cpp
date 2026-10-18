
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

class Stack {
    struct Node {
        char ch;
        Node* next;

        Node(char c, Node* n) {
            ch = c;
            next = n;
        }
    };

    Node* head;

public:
    Stack() {
        head = NULL;
    }

    ~Stack() {
        while (head != NULL)
            pop();
    }

    bool empty() const {
        return head == NULL;
    }

    void push(char c) {
        head = new Node(c, head);
    }

    char top() const {
        if (empty())
            throw runtime_error("Empty stack");

        return head->ch;
    }

    char pop() {
        char c = top();

        Node* p = head;
        head = head->next;

        delete p;

        return c;
    }
};

int precedence(char c) {
    if (c == '^')
        return 3;

    if (c == '*' || c == '/' || c == '%')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '%' || c == '^';
}

string toPostfix(const string& infix) {
    Stack ops;
    string result;

    for (int i = 0; i < infix.length();) {
        char c = infix[i];

        if (isspace((unsigned char)c)) {
            i++;
            continue;
        }

        if (isalnum((unsigned char)c) || c == '.' || c == '_') {
            string operand;

            while (i < infix.length() &&
                  (isalnum((unsigned char)infix[i]) ||
                   infix[i] == '.' || infix[i] == '_')) {
                operand += infix[i];
                i++;
            }

            result += operand + " ";
            continue;
        }

        if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                result += ops.pop();
                result += " ";
            }

            if (ops.empty())
                throw runtime_error("Mismatched parentheses");

            ops.pop();
        }
        else if (isOperator(c)) {
            while (!ops.empty() && ops.top() != '(' &&
                  (precedence(ops.top()) > precedence(c) ||
                  (precedence(ops.top()) == precedence(c) && c != '^'))) {
                result += ops.pop();
                result += " ";
            }

            ops.push(c);
        }
        else {
            throw runtime_error("Invalid character in expression");
        }

        i++;
    }

    while (!ops.empty()) {
        if (ops.top() == '(')
            throw runtime_error("Mismatched parentheses");

        result += ops.pop();
        result += " ";
    }

    if (!result.empty())
        result.erase(result.length() - 1);

    return result;
}

int main() {
    string infix;

    cout << "Infix expression: ";
    getline(cin, infix);

    try {
        cout << "Postfix: " << toPostfix(infix) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

