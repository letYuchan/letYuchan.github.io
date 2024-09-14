#include <iostream>
#include <queue>  // priority_queue를 사용하기 위한 헤더 파일

using namespace std;

int main() {
    // 정수형 우선순위 큐 선언 (기본적으로 최대 힙)
    priority_queue<int> pq;

    // 요소 추가
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(7);

    cout << "현재 우선순위 큐의 크기: " << pq.size() << endl;

    // 가장 우선순위가 높은 요소 확인 및 제거
    cout << "가장 우선순위가 높은 요소: " << pq.top() << endl;
    pq.pop();  // 가장 우선순위가 높은 요소 제거

    cout << "한 번 요소를 제거한 후의 우선순위 큐의 크기: " << pq.size() << endl;

    // 모든 요소 출력
    cout << "현재 우선순위 큐의 모든 요소:";
    while (!pq.empty()) {
        cout << " " << pq.top();
        pq.pop();
    }
    cout << endl;

    return 0;
}
