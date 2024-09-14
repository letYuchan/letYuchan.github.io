#include <forward_list>
#include <iostream>
#include <string>
using namespace std;

// citizen 정보에 관한 구조체 정의 및 출력스트림 오버라이딩
struct citizen {
    string name;
    int age;
};

ostream &operator<<(ostream &os, const citizen &c) {
    return (os << "[" << c.name << "," << c.age << "]");
}

int main() {
    forward_list<citizen> citizens = {{"kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}};

    auto citizens_copy = citizens;  // 깊은 복사

    cout << "전체 시민들: ";
    for (const auto &c : citizens) cout << c << " ";
    cout << endl;

    citizens.remove_if([](const citizen &c) {
        // 나이가 19세보다 작으면 리스트에서 제거
        return (c.age < 19);
    });

    cout << "투표권이 있는 시민들: ";
    for (const auto &c : citizens) cout << c << " ";
    cout << endl;

    // 내년에 새로 투표권이 생기는 사람을 알아보기
    citizens_copy.remove_if([](const citizen &c) { return (c.age != 18); });

    std::cout << "내년에 투표권이 생기는 시민: ";
    for (const auto &c : citizens_copy) std::cout << c << " ";
    std::cout << std::endl;
}
