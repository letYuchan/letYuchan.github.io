#include <iostream>
using namespace std;

int main() {
    int n, m, choco, count;
    cin >> n >> m;
    cout << (n - 1) + n * (m - 1);
}

// * *
// * *
// * *
// 3 * 2 (n * m)
// n(가로) 방향으로 n-1번 짜르면
// * *

// * *

// * *
// m * 1(2*1) 크기의 초콜릿이 n(3) 개 생김
// 다시 초콜릿덩어리 한개를 m(세로) 방향으로 m-1(1)번 자르면 1*1 크기의 초콜릿이 나타남 이때 이
// 행위를 n 번 반복해야하므로 (n-1)+n(m-1)
