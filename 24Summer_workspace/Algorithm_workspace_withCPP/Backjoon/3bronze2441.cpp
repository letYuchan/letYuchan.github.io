#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; 0 < i; i--) {
        for (int j = i; j < n; j++) cout << " ";
        for (int k = i; 0 < k; k--) cout << "*";
        cout << endl;
    }
    return 0;
}