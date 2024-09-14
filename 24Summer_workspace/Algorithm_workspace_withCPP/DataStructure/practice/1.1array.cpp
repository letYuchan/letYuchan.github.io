#include <algorithm>
#include <array>
#include <iostream>

using namespace std;
void print(array<int, 5> arr) {  // 문제점: 배열의 크기가 고정
    for (auto ele : arr) cout << ele << ", ";
}
int main() {
    // 배열 생성 및 초기화, 출력
    array<int, 10> arr1;

    arr1[0] = 1;
    cout << "arr1의 첫 번째 원소: " << arr1[0] << endl;

    array<int, 4> arr2 = {1, 2, 3, 4};
    cout << "arr2의 모든 원소: ";

    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
        cout << endl;
    }

    // at함수를 이용한 기존 배열의 단점(인덱스값이 배열의 크기를 넘어가진 않는지 검사하지 않는
    // 문제를 보완
    array<int, 4> arr3 = {1, 2, 3, 4};

    try {
        cout << arr3.at(3) << endl;  // 에러x
        cout << arr3.at(4) << endl;  // out_of_range 예외발생
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // 배열을 인자로 전달하는 방법: 기본 데이터 타입과 유사->값/참조/const
    array<int, 5> arr4 = {1, 2, 3, 4, 5};
    print(arr4);
    cout << endl;

    // 범위기반 for문의 작동 메커니즘구현
    for (auto it = arr4.begin(); it != arr4.end(); it++) {
        auto element = (*it);
        cout << element << ' ';
    }
    cout << endl;

    // front(): 첫번째 원소에 대한 참조 반환, back(): 배열의 마지막 원소에 대한 참조 반환, data():
    // 배열의 실제 데이터 메모리 버퍼를 가리키는 포인터 반환
    cout << arr4.front() << endl;        // 1
    cout << arr4.back() << endl;         // 5
    cout << *(arr4.data() + 1) << endl;  // 2

    // std::array의 깊은 비교와 복사
    array<int, 5> arr5 = {1, 5, 10, 15, 20};
    if (arr5 != arr4) {  // 배열의 크기가 같아야 비교연산자 사용가능 아니면 컴파일 에러 발생
        cout << "두 배열은 다릅니다" << endl;
    }
    cout << "두배열은 같습니다" << endl;
    copy(arr5.begin(), arr5.end(), arr4.begin());  // copy함수는 헤더파일 <algorithm>에 존재
    for (auto it = arr5.begin(); it != arr5.end(); it++) {
        auto element = (*it);
        cout << element << ' ';
    }
}
