#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if (a < 1 || b < 1 || a > 10000 || b > 10000) return 0;
    cout << fixed;      // 소숫점 아래부터 유효숫자 카운트
    cout.precision(9);  // 유효숫자 9개
    cout << a / b << endl;
    return 0;
}