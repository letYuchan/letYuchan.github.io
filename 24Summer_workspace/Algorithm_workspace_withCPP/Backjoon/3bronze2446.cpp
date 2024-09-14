#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    int z = 2 * n - 1;
    for (int i = n; 0 < i; i--) {
        for (int j = i; j < n; j++) cout << " ";
        for (int k = 0; k < i * 2 - 1; k++) cout << "*";
        cout << endl;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j < z / 2; j++) cout << " ";
        for (int k = 0; k < i * 2 + 1; k++) cout << "*";
        cout << endl;
    }
    return 0;
}
