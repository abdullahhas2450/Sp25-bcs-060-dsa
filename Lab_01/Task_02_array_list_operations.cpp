#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayList {
    vector<int> a;
public:
    void insertEnd(int x) { a.push_back(x); }
    void insertStart(int x) { a.insert(a.begin(), x); }
    bool insertAfter(int key, int x) {
        auto it = find(a.begin(), a.end(), key);
        if (it == a.end()) return false;
        a.insert(it + 1, x); return true;
    }
    bool insertBefore(int key, int x) {
        auto it = find(a.begin(), a.end(), key);
        if (it == a.end()) return false;
        a.insert(it, x); return true;
    }
    bool deleteEnd() {
        if (a.empty()) return false;
        a.pop_back(); return true;
    }
    bool deleteStart() {
        if (a.empty()) return false;
        a.erase(a.begin()); return true;
    }
    bool deleteValue(int key) {
        auto it = find(a.begin(), a.end(), key);
        if (it == a.end()) return false;
        a.erase(it); return true;
    }
    void display() const {
        if (a.empty()) { cout << "List is empty\n"; return; }
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
};
int main() {
    ArrayList a;
    int choice, x, key;
    while (true) {
        cout << "\n1.Insert end 2.Insert start 3.Insert after 4.Insert before\n"
             << "5.Display 6.Delete end 7.Delete start 8.Delete value 0.Exit\nChoice: ";
        if (!(cin >> choice) || choice == 0) break;
        switch (choice) {
            case 1: cout << "Value: "; cin >> x; a.insertEnd(x); break;
            case 2: cout << "Value: "; cin >> x; a.insertStart(x); break;
            case 3: cout << "Key and new value: "; cin >> key >> x;
                    if (!a.insertAfter(key, x)) cout << "Key not found\n"; break;
            case 4: cout << "Key and new value: "; cin >> key >> x;
                    if (!a.insertBefore(key, x)) cout << "Key not found\n"; break;
            case 5: a.display(); break;
            case 6: if (!a.deleteEnd()) cout << "List is empty\n"; break;
            case 7: if (!a.deleteStart()) cout << "List is empty\n"; break;
            case 8: cout << "Value to delete: "; cin >> key;
                    if (!a.deleteValue(key)) cout << "Value not found\n"; break;
            default: cout << "Invalid choice\n";
        }
    }
}
