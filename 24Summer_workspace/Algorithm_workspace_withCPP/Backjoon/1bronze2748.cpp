#include <array>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[91];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n];
    return 0;
}


    // 재귀를 이용한 피보나치 -> 연산속도 매우 느림
    // inline long long fibonacci(int n) {
    //     if (n == 0)
    //         return 0;
    //     else if (n == 1)
    //         return 1;
    //     else
    //         return fibonacci(n-1) + fibonacci(n - 2);
    // }
    // int main() {
    //     long long result;
    //     int n;
    //     cin >> n;
    //     if (n < 1) return 0;
    //     result = fibonacci(n);
    //     cout << result;
    // }

    // 예시
    // F(5)
    // │
    // ├─ F(4)
    // │   ├─ F(3)
    // │   │   ├─ F(2)
    // │   │   │   ├─ F(1) = 1
    // │   │   │   └─ F(0) = 0
    // │   │   └─ F(1) = 1
    // │   └─ F(2)
    // │       ├─ F(1) = 1
    // │       └─ F(0) = 0
    // └─ F(3)
    //     ├─ F(2)
    //     │   ├─ F(1) = 1
    //     │   └─ F(0) = 0
    //     └─ F(1) = 1
