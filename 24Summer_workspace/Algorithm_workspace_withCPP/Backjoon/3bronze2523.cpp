#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    for (int i = n; 0 < i; i--) {
        for (int j = i; j < n + 1; j++) cout << "*";
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) cout << "*";
        cout << endl;
    }
    return 0;
}