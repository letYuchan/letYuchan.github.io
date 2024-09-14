#include <iostream>
using namespace std;

// 문제 조건의 해당하는 수는 N+1의 배수가 n-1개
// N = 3 -> 4 8 (3+1의 배수)
int main() {
    long long n;
    cin >> n;
    long long result = 0;
    for (int i = 1; i < n; i++) {
        result += (n + 1) * i;
    }
    cout << result;
}
