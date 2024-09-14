#include <forward_list>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector를 이용하여 최근 경기 우승자 명단 작성
    vector<string> vec = {"Lewis Hamilton",   "Lewid Hamilton",   "Nico Roseberg",
                          "Sebastian vettel", "Lewis Hamilton",   "Sebastian Vettel",
                          "sebastian vettel", "Sebastian Vettel", "Fernando Alonso"};

    auto it = vec.begin();  // 상수 시간
    cout << "가장 최근 우승자:" << *it << endl;

    it += 8;  // 상수시간 -> 임의 접근 반복자가 제공되므로, 곧바로 해당 위치로 이동가능
    cout << "8년전 우승자: " << *it << endl;
    advance(
        it,
        -3);  // 상수시간 -> 임의 접근 반복자기 때문에 순차접근을 하지 않아도 뒤에서부터 접근가능
    cout << "그후 3년 뒤 우승자: " << *it << endl;

    // 위 기능을 순방향 반복자를 갖는 forward_list로 다시 만들기
    forward_list<string> fwd(vec.begin(), vec.end());
    auto it1 = fwd.begin();
    cout << "가장 최근 우승자: " << *it1 << endl;

    advance(it1, 5);  // 선형 시간 0> 5번째 뒤 반복자에 접근하기 위해서 앞에서부터 순차접근
    cout << "5년 전 우승자: " << *it1 << endl;

    // 아래 코드는 순차접근만 가능한 forward_list에서 에러발생
    // advance(it1, -2);
    // it1 += 2; 
}
