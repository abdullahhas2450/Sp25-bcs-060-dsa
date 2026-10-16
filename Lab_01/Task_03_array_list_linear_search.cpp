#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& a, int key) {
    int i = 0;
    while (i < static_cast<int>(a.size())) {
        if (a[i] == key) return i;
        ++i;
    }
    return -1;
}
int main() {
    int n, key;
    cout << "Number of elements: "; cin >> n;
    if (n < 0) return 1;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int& x : a) cin >> x;
    cout << "Value to search: "; cin >> key;
    int pos = linearSearch(a, key);
    if (pos == -1) cout << "Value not found\n";
    else cout << "Found at index " << pos << '\n';
}
