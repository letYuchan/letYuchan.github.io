#include <iostream>
#include <queue>
#include <random>

int main() {
    // queue 선언
    std::queue<int> myQueue;

    // 난수 생성을 위한 작업
    std::random_device rd;                       // 난수 생성 장치로 시드용으로 사용
    std::mt19937 gen(rd());                      // Mersenne Twister 엔진 초기화
    std::uniform_int_distribution<> dis(0, 99);  // 0~99까지의 균등 분포 정의

    // queue에 난수 추가
    for (int i = 0; i < 10; ++i) {
        int randomValue = dis(gen);
        myQueue.push(randomValue);
        std::cout << "Pushed: " << randomValue << std::endl;
    }

    // queue의 상태 출력
    std::cout << "Size of the queue: " << myQueue.size() << std::endl;
    std::cout << "Is the queue empty?: " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    // queue의 요소 출력 및 제거
    std::cout << "Queue elements: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";  // front 요소 출력
        myQueue.pop();                        // front 요소 제거
    }
    std::cout << std::endl;

    // 최종 상태 확인
    std::cout << "Size of the queue after popping all elements: " << myQueue.size() << std::endl;
    std::cout << "Is the queue empty now?: " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
