#include <iostream>
using namespace std;

int main() {
    long long s = 0, n = 0;
    cin >> s;
    for (int i = 1; i <= s; i++) {
        n += i;
        if (n > s) {
            n = i - 1;
            break;
        }
    }
    cout << n;
    return 0;
}

// 문제이해: 자연수 n까지의 합 s가 주어질때 n구하기
// 공식: n까지의 합 = n(n+1) / 2