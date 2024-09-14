#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 100) return 0;
    for (int i = n; 1 <= i; i--) {
        for (int j = i - 1; j < n; j++) cout << "*";
        cout << endl;
    }
    return 0;
}
