#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - i; 0 < j; j--) cout << "*";
        cout << endl;
    }
    return 0;
}