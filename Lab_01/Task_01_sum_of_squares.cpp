#include <iostream>
using namespace std;

long long sumOfSquares(int start, int stop) {
    long long total = 0;
    for (long long x = start; x <= stop; ++x) total += x * x;
    return total;
}
int main() {
    int start, stop;
    cout << "Starting value of X: "; cin >> start;
    cout << "Stopping value of X: "; cin >> stop;
    if (start > stop) cout << "Start must not exceed stop.\n";
    else cout << "Sum of X^2: " << sumOfSquares(start, stop) << '\n';
}
