#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A, B, P;
    int n;
    cin >> n;

    // A와 P 초기화
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        A.push_back(ele);
        P.push_back(0);
    }

    // B는 A의 복사본
    B = A;

    // B 배열 오름차순 정렬
    sort(B.begin(), B.end());

    // P 배열 계산
    for (int i = 0; i < n; i++) {
        // A[i]가 B의 어디에 위치하는지 찾고, 그 인덱스를 P[i]에 저장
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) { // B[P[i]] == A[i]
                P[i] = j;
                B[j] = -1;  // 동일한 값이 다시 사용되지 않도록 표시
                break;
            }
        }
    }

    // P 배열 출력
    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }

    return 0;
}

// 어떤 배열 A가 주어졌고, 이때 배열 B는 B[P[i]] = A[i]의 방법으로 만들어진 배열임. 이때 B배열의
// 값을 오름차순으로 정렬했을때 P배열의 0부터 n-1까지의 인덱스의 값들이 순서대로 어떻게
// 출력되느냐 문제

// ex) 입력값: 3 \n 2 3 1 -> A[0] == 2, A[1] == 3, A[2] == 1
// B[P[0]] = A[0] = 2
// B[P[1]] = A[1] = 3
// B[P[2]] = A[2] = 1
//  오름차순으로 정렬 후
// B[P[2]] = A[2] = 1
// B[P[0]] = A[0] = 2
// B[P[1]] = A[1] = 3
//  우리가 구해야하는 P의 값
// P[2] == 0
// P[0] == 1
// P[1] == 2
// P를 순서대로 출력: 2 1 0
