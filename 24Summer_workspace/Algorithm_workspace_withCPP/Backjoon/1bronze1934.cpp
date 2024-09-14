#include <algorithm>
#include <iostream>
using namespace std;

// 최소공배수 = a * b / 최대공약수
// 최대공약수 => 유클리드 호제법으로 구함

int GCD(int a, int b) {
    if (b == 0)
        return a;  // 항상 어떤조건에 반환되어진다면 그 조건을 젤 위에 적는 습관을 들일것
    else
        return GCD(b, a % b);
}

int main() {
    int lines, a, b;
    cin >> lines;
    for (int i = 0; i < lines; i++) {
        cin >> a >> b;
        cout << a * b / GCD(a, b) << endl;
    }
}