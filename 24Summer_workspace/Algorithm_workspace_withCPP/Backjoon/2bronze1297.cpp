#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int real_d, ratio_h, ratio_w;
    double real_h, real_w, ratio_d;
    cin >> real_d >> ratio_h >> ratio_w;
    ratio_d = sqrt(pow(ratio_h, 2) + pow(ratio_w, 2));
    real_h = real_d * ratio_h / ratio_d;
    real_w = real_d * ratio_w / ratio_d;
    cout << (int)real_h << " " << (int)real_w;
}
// 실제 변의 길이 = 대각선길이 * 실제 변의 비율 / 대각선 비율
// 실수형을 int형으로 형변환시켜주면 소숫점자리를 다 버리고 내림을 해버림