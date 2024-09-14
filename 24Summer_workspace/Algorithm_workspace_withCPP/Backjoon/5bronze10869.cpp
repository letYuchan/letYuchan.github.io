#include <iostream>
using namespace std;

int add(int& a, int& b) { return a + b; }

int sub(int& a, int& b) { return a - b; }

int mul(int& a, int& b) { return a * b; }

int div(int& a, int& b) { return a / b; }

int rem(int& a, int& b) { return a % b; }

int main() {
    typedef int (*funcptr)(int&, int&);
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 < 1 || n2 < 1 || n1 > 10000 || n2 > 10000) return 0;
    funcptr funcArray[] = {add, sub, mul, div, rem};
    for (int i = 0; i < 5; i++) {
        int result = funcArray[i](n1, n2);
        cout << result << endl;
    }

    return 0;
}