#include <iostream>
#include <list>  // 양방향 반복자
using namespace std;

int main() {
    // push_back, insert, pop_back
    list<int> list1 = {1, 2, 3, 4, 5};
    list1.push_back(6);                    // {1,2,3,4,5,6}
    list1.insert(next(list1.begin()), 0);  // {1,0,2,3,4,5,6}
    list1.insert(list1.end(), 7);          // {1,0,2,3,4,5,6,7}
    // 여기서 드는 의문!: 연속된 자료구조에서 end()는 자료형의 크기만큼의 다음 메모리 공간을
    // 가리키지만 연속된 자료구조에선 어떻게 "마지막노드 다음 위치"를 지정할까요?
    // -> 더미 노드를 이용합니다!

    list1.pop_back();  // {1,0,2,3,4,5,6}
    cout << "삽입 & 삭제 후 리스트: ";
    for (auto i : list1) cout << i << " ";

    return 0;
}