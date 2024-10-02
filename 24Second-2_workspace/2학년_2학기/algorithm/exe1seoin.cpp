#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 10> set; // 크기가 10인 배열 선언
    int n = 10; // 입력횟수에 관한 카운트변수
    int find_val; // 찾고자 하는 값 선언
    cout << "찾고자하는 값을 입력하세요" << endl;
    cin >> find_val; // 찾고자하는 값 입력
    for(int i = 0; i<set.size();i++){
        cout <<"값을 입력하세요 / "<<"남은 입력횟수: "<<n<<endl;
        int temp; // 입력할 값
        cin >> temp;
        set[i] = temp;
        n--; // 입력가능횟수 감소
    }

    int time_complexicity = 0; // 시간복잡도 카운트 -> n으로 표현
    bool isFinded = false; // 값을 찾았는지 여부 확인
 
    for(int i =0; i<set.size();i++){ // 순차탐색
        time_complexicity++;
        if(find_val == set[i]){ // 값을 찾으면
            isFinded = true; // true로 바뀌고
            break; // 반복문 탈출
        }
    }

    cout << "시간복잡도 O(" << time_complexicity << ")" << endl;
    cout << "값을 찾았는지 여부 -> " << isFinded;
    
}