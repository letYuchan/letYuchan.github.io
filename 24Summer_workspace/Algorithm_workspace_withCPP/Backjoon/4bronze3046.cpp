#include <iostream>
using namespace std;

int main() {
    int r1, r2, avg;
    cin >> r1 >> avg;
    if (r1 < -10000 || avg < -10000 || r1 > 10000 || avg > 10000) return 0;
    r2 = avg * 2 - r1;
    cout << r2;
    return 0;
}