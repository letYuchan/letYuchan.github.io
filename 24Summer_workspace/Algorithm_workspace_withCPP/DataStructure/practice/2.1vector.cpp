#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 크기가 0인 vector
    vector<int> vec;

    // 지정한 초깃값으로 이루어진 크기가 5인 vector
    vector<int> vec2 = {1, 2, 3, 4, 5};

    // 크기가 10인 vector
    vector<int> vec3(10);

    // 크기가 10이고 모든 원소가 5로 초기화된 vector
    vector<int> vec4(10, 5);

    // insert(위치, 값): 원하는 위치에 원소 삽입
    vec2.insert(vec2.begin(), 0);

    for (auto ele : vec2) {
        cout << ele << " ";
    }
    cout << endl;
    // pushback(값): 맨 뒤에 원소 삽입
    vector<int> vec5;

    vec5.push_back(1);
    vec5.push_back(2);
    vec5.push_back(3);
    vec5.push_back(4);
    vec5.push_back(5);

    for (auto ele : vec5) {
        cout << ele << " ";
    }
    cout << endl;

    // pop_back(): 맨 뒤 원소 삭제 후 크기 1줄임
    vec5.pop_back();
    for (auto ele : vec5) {
        cout << ele << " ";
    }
    cout << endl;

    // erase(): 특정 범위의 원소들 삭제 후 원소들을 옮김
    vector<int> vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec6.erase(vec6.begin() + 1, vec6.begin() + 5);
    for (auto ele : vec6) {
        cout << ele << " ";
    }
    cout << endl;
    cout << vec6.capacity();

    // clear(): 빈벡터로 만들어버림
    vec6.clear();
    cout << endl;
    cout << vec6.capacity() << endl;
    for (auto ele : vec6) {
        cout << ele << " ";
    }
    cout << endl;

    // reserve(): 용량지정
    vec6.reserve(15);
    cout << vec6.capacity() << endl; // 15

    // shrink_to_fit(): 여분 용량을 제거하여 용량==크기가 되게 만듦
    vec6.shrink_to_fit();
    cout << vec6.capacity(); // 0
}