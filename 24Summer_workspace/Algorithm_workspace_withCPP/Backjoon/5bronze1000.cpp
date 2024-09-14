#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a >= 10 || a >= b) return 0;
    cout << a + b;
    return 0;
}