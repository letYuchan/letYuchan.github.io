#include <deque>
#include <iostream>
using namespace std;
int main() {
    deque<int> deq = {1, 2, 3, 4, 5};

    // 원소삽입: O(1) * insert는 O(n)
    deq.push_front(0);
    deq.push_back(6);
    deq.insert(deq.begin() + 2, 10);  // 연결된 구조와 다르게 insert_after가 아니기 때문에, 정확히
                                      // 시작위치에 +2 번째 위치에 요소삽입한다
    // 원소삭제: O(1) * erase는 O(n)
    deq.pop_back();
    deq.pop_front();
    deq.erase(deq.begin() + 1);
    deq.erase(deq.begin() + 3, deq.end());  // end()의 위치 전까지(마지막 원소까지) 삭제

    // deque 각 청크별 메모리 주소 확인
    deque<int> deq2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    for (auto it = deq2.begin(); it != deq2.end(); ++it) {
        std::cout << "주소: " << &(*it) << ", 값: " << *it << std::endl;
    }

    deq2.insert(deq2.begin() + 7, 99);
    for (auto it = deq2.begin(); it != deq2.end(); ++it) {
        std::cout << "주소: " << &(*it) << ", 값: " << *it << std::endl;
    }

    deq2.erase(deq2.begin() + 7);
    for (auto it = deq2.begin(); it != deq2.end(); ++it) {
        std::cout << "주소: " << &(*it) << ", 값: " << *it << std::endl;
    }

    deq2.insert(deq2.begin() + 14, 99);
    for (auto it = deq2.begin(); it != deq2.end(); ++it) {
        std::cout << "주소: " << &(*it) << ", 값: " << *it << std::endl;
    }
}