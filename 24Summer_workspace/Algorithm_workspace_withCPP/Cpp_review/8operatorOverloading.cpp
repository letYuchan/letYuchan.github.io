#include <iostream>
using namespace std;

class point {
   private:
    int xpos, ypos;

   public:
    point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void showPosition() const { cout << "(" << xpos << "," << ypos << ")" << endl; }
    point operator+(const point& ref) {
        point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
    point operator++() {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend point& operator--(point& ref);
};

point& operator--(point& ref) {
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main() {
    point pos1(3, 4);
    point pos2(10, 20);
    point pos3 = pos1.operator+(pos2);
    // 위 코드는 다음과 동일한 의미이다. point pos3 = pos1 + pos2;
    pos1.showPosition();
    pos2.showPosition();
    pos3.showPosition();
    point pos4(5, 6);
    ++pos4;
    pos4.showPosition();
    point pos5(3, 4);
    --pos5;
    pos5.showPosition();
    return 0;
}