
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balanced(const string& input) {
    stack<char> s;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string text;

    cout << "Enter a string of brackets: ";
    getline(cin, text);

    if (balanced(text))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}

