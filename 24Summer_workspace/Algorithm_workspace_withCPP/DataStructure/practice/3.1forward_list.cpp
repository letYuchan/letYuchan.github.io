#include <forward_list>
#include <iostream>
using namespace std;

int main() {
    // forward_list 선언 및 초기화
    forward_list<int> fwd_list = {1, 2, 3};

    // 원소 삽입: push_front, insert_after(해당 위치 다음에 삽입)
    fwd_list.push_front(0);        // {0,1,2,3}
    auto it = fwd_list.begin();    // begin()은 첫번째 node를 가리킴
    fwd_list.insert_after(it, 5);  // {0,5,1,2,3}
    fwd_list.insert_after(it, 6);  // {0,6,5,1,2,3}

    // 원소 삽입 단점 보완: emplace_front(), emplace_after()
    fwd_list.emplace_front(-10);      // {-10,0,6,5,1,2,3}
    fwd_list.emplace_after(it, 100);  // {-10,0,100,6,5,1,2,3}

    for (auto ele : fwd_list) {
        cout << ele << " ";
    }
    cout << endl;
    // 원소 삭제: pop_front(), erase_after()
    fwd_list.pop_front();  // {0,100,6,5,1,2,3}

    auto erase_targetPos = fwd_list.begin();  // erase_targetPos은 0을 가리킴
    // 오버로딩1: 해당 위치 다음 원소 삭제
    fwd_list.erase_after(erase_targetPos);  // {0,6,5,1,2,3}

    // 오버로딩2: 처음 위치 다음부터 끝 위치 전까지 삭제
    // erase_targetPos를 이동시켜야 하므로, 다시 초기화 및 이동
    erase_targetPos = fwd_list.begin();  // 다시 0을 가리킴
    auto endPos = erase_targetPos;
    advance(endPos, 3);  // advance(): 반복자의 위치를 증가시킴, 3만큼 증가->1을 가리킴
    fwd_list.erase_after(erase_targetPos, endPos);  // 0이후 1이전까지를 삭제 {0, 1, 2, 3}

    for (auto ele : fwd_list) {
        cout << ele << " ";
    }
    cout << endl;

    // 그 외 함수

    // 정렬함수
    forward_list<int> fwd_list_int = {-3, 5, 1, 20, 5, 8, 7, 9, 9};
    fwd_list_int.sort();  // 오름차순 정렬
    for (auto ele : fwd_list_int) {
        cout << ele << " ";
    }
    
    cout << endl;

    // 역순정렬
    fwd_list_int.reverse();
    for (auto ele : fwd_list_int) {
        cout << ele << " ";
    }
    cout << endl;

    // 유니크화
    fwd_list_int.unique();
    for (auto ele : fwd_list_int) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
