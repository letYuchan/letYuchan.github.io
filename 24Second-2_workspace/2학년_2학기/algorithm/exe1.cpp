#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> data_set; // 임의로 사용할 테스트 데이타 셋 선언
    int wanted_val; // 내가 찾고자하는 값
    int complexicity = 0; // 시간복잡도, 초깃값 0 -> 반복문이 한 번 끝날때마다 늘어날 예정
    bool isFind = false; // 찾았는지 여부를 알려주는 flag 변수
    cin >> wanted_val; // 원하는 값 입력
    while(true){ // data_set에 아무 값이나 입력
        int temp;
        cin >> temp; // 원소 입력
        if(temp == -1) break; // 반복문 탈출을 위해 조건으로 -1을 삽입하면 break
        data_set.push_back(temp);
    }
    for(int i = 0; data_set.size(); i++){ // 순차탐색 시작

        complexicity++;  // 시간복잡도 증가
        if(data_set[i] == wanted_val) { // 같다면
            isFind = true; // true로 바꾸고
            break; // 반복문 탈출
        }
    }
    cout << "성공여부: " << isFind << "\n";
    cout << "시간복잡도 O(" << complexicity <<")";

    
}