#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) cout << " ";
        for (int k = i; 0 < k; k--) cout << "*";
        cout << endl;
    }
    for (int i = n; 0 < i; i--) {
        for (int j = i - 1; j < n; j++) cout << " ";
        for (int k = i; 1 < k; k--) cout << "*";
        cout << endl;
    }
}