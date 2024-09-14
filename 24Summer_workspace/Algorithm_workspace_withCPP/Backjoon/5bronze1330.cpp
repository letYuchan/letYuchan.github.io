#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if ((-10000 > a || a > 10000) || (-10000 > b || b > 10000)) return 0;
    if (a > b)
        cout << ">";
    else if (a < b)
        cout << "<";
    else
        cout << "==";
    return 0;
}