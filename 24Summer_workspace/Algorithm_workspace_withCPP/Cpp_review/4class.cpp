#include <iostream>

#include "4Box_2D.h"
#include "4Box_3D.h"

using namespace std;
template <typename T>
T minimum(T a, T b) {
    return (a > b) ? a : b;
}

// class 배워보기
class Box {
   public:
    Box() {}
    void set(int h, int w, int l) {
        this->height = h;  // this는 객체 자신을 가리키는 포인터
        this->width = w;
        this->length = l;
    }
    double volume() const {
        return height * width * length;
    }  // 상수 멤버 함수: 함수 body 속 변수값들 변경 불가능

    void print();  // 선언과 정의 분리

   private:
    double height, width, length;
};

// 생성자와 소멸자
class Lotto {
   public:
    Lotto() : num(new int[6]{0, 0, 0, 0, 0, 0}) {
        cout << "생성자 함수 실행" << endl;
        for (int i = 0; i < 6; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < 6; i++) {
            cout << num[i] << " ";
        }
    }

    ~Lotto() { delete[] num; }

   private:
    int* num;
};

inline void Box::print() {
    cout << height << " " << width << " " << length << endl;
}  // 함수의 선언과 정의를 분리할 때, inline을 써줘야 함(원래는 inline은 기본적으로 할당됨)

int main() {
    // 템플릿 활용
    int i0 = 3, i1 = 5;
    float f0 = -5.1f, f1 = 3.0f;
    cout << minimum(i0, i1) << endl;
    cout << minimum(f0, f1) << endl;

    // class활용
    Box box;
    box.set(10, 20, 30);  // 일반적으로 set함수를 통해 private 멤버 초기화
    float box_volume = box.volume();
    cout << box_volume << endl;
    box.print();

    // 동적 객체 생성
    Box* dynamic_box = new Box();
    dynamic_box->set(
        30, 50, 40);  // 포인터로 생성한 객체의 멤버함수나 변수에 접근 할 경우, 화살표연산자 사용
    dynamic_box->print();

    // namespace
    two_dim::Box_ box2;
    box2.length = 3;
    box2.width = 4;
    box2.print();

    // 생성자 소멸자
    Lotto lotto;
}