#include <iostream>
using namespace std;
void func() {
    static int a = 0;
    a++;
    cout << a << " ";
}

int main() {
    // 열거형
    enum color { red = 2, blue, yellow };
    cout << red << blue << yellow << endl;

    // 타입지정
    typedef double wages;
    wages wage0 = 200;
    cout << sizeof(wage0) << endl;

    // local static variable: 프로그램이 종료될때까지 살아있음, 스코프는 블록내부, 초기화는 딱
    // 한번만 적용,
    for (int i = 0; i < 5; i++) {
        func();  // 11111을 예상했으나 12345(초기화 1번만 적용)
    }
    cout << endl;

    // 조건연산자
    int score;
    cin >> score;
    cout << "The score is " << score << ((score == 1) ? "point" : "points");
}