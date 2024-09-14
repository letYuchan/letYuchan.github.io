#include <deque>
#include <iostream>
#include <random>
#include <stack>
using namespace std;

int main() {
    // 암묵적으로 deque을 사용하는 스택 선언
    stack<int> stk;

    // 벡터로 선언
    stack<int, vector<int>> stk2;

    // 명시적으로 deque을 사용하는 스택 선언
    stack<int, deque<int>> dequeStack;

    // 난수 생성을 위한 작업
    random_device rd;                       // 난수 생성 장치로 시드용으로 사용
    mt19937 gen(rd());                      // Mersenne Twister 엔진 초기화
    uniform_int_distribution<> dis(0, 99);  // 0~99까지의 균등 분포 정의

    // 스택에 난수 추가
    for (int i = 0; i < 10; ++i) {  // 임의로 10개의 난수를 생성
        int randomValue = dis(gen);
        dequeStack.push(randomValue);
    }

    cout << "사이즈: " << dequeStack.size() << endl;
    cout << "Is it empty?: " << (dequeStack.empty() ? "Yes" : "No") << endl;
    cout << "What is at TOP: " << dequeStack.top() << endl;

    // 스택에서 요소를 제거하며 출력
    while (!dequeStack.empty()) {
        cout << dequeStack.top() << " ";
        dequeStack.pop();
    }
    cout << endl;

    cout << "스택이 비었습니다!" << endl;

    return 0;
}
