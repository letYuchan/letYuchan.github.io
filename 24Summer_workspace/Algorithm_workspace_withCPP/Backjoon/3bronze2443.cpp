#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    for (int i = n; 0 < i; i--) {
        for (int j = i; j < n; j++) cout << " ";
        for (int k = 0; k < 2 * i - 1; k++) cout << "*";
        cout << endl;
    }
    return 0;
}