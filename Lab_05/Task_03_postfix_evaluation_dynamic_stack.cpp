
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Stack {
    struct Node {
        double value;
        Node* next;

        Node(double v, Node* n) {
            value = v;
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

    void push(double x) {
        head = new Node(x, head);
    }

    double pop() {
        if (empty())
            throw runtime_error("Too few operands");

        Node* p = head;
        double x = p->value;
        head = p->next;

        delete p;

        return x;
    }
};

bool isNumber(const string& s, double& value) {
    char* end;
    value = strtod(s.c_str(), &end);

    return end != s.c_str() && *end == '\0';
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;

    istringstream stream(line);
    string token;

    while (stream >> token)
        tokens.push_back(token);

    return tokens;
}

double evaluate(const vector<string>& tokens) {
    if (tokens.empty())
        throw runtime_error("Expression is empty");

    Stack s;

    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];

        if (token.size() == 1 &&
            string("+-*/^%").find(token[0]) != string::npos) {

            double b = s.pop();
            double a = s.pop();
            double result = 0;

            char op = token[0];

            if (op == '+')
                result = a + b;

            else if (op == '-')
                result = a - b;

            else if (op == '*')
                result = a * b;

            else if (op == '/') {
                if (b == 0)
                    throw runtime_error("Division by zero");

                result = a / b;
            }

            else if (op == '%') {
                if (b == 0)
                    throw runtime_error("Division by zero");

                result = fmod(a, b);
            }

            else if (op == '^')
                result = pow(a, b);

            s.push(result);
        }
        else {
            double value;

            if (isNumber(token, value)) {
                s.push(value);
            }
            else {
                cout << "Value for " << token << ": ";

                if (!(cin >> value))
                    throw runtime_error("Invalid variable value");

                s.push(value);
            }
        }
    }

    double answer = s.pop();

    if (!s.empty())
        throw runtime_error("Too many operands");

    return answer;
}

int main() {
    string line;

    cout << "Postfix expression: ";
    getline(cin, line);

    try {
        vector<string> tokens = tokenize(line);

        double result = evaluate(tokens);

        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

