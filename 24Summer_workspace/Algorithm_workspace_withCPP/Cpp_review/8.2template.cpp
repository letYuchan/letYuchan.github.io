#include <iostream>
using namespace std;

template <typename T>
// 함수에서의 템플릿(타입을 명시적으로 적어주지 않아도 됨)
T add(T num1, T num2) {
    return num1 + num2;
}

template <typename T>
class point {
   private:
    T xpos, ypos;

   public:
    point(T x, T y) : xpos(x), ypos(y) {}
    void showPosition() const { cout << "(" << xpos << "," << ypos << ")" << endl; }
};
int main() {
    cout << add<int>(15, 20) << endl;

    point<float> p(1, 5);
    p.showPosition();
}
