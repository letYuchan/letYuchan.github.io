#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    // 반복자 무효화

    // vector의 경우 용량을 초과하여 원소를 삽입할 경우 새로운 메모리에 기존 원소를 복사하고 그 다음
    // 새로운 원소를 지정 위치에 삽입하지만 list의 경우 삽입이나 삭제시 따로 반복자의 무효화가
    // 발생하지 않고 삭제한 특정 반복자만 무효화된다

    // vector의 반복자 무효화
    vector<int> vec = {1, 2, 3, 4, 5};
    auto v_it4 = vec.begin() + 4;
    cout << (*v_it4) << endl;
    vec.insert(vec.begin() + 2, 9);
    cout << (*v_it4)
         << endl;  // 반복자 무효화 -> 0출력(컴파일러마다 0을 출력할지 다른걸 출력할지는 다름)

    // list의 반복자 무효화
    list<int> lst = {1, 2, 3, 4, 5};
    auto l_it4 = next(lst.begin(), 4);
    cout << (*l_it4) << endl;
    lst.insert(next(lst.begin(), 2), 0);
    cout << (*l_it4) << endl;  // 정상적으로 출력
}