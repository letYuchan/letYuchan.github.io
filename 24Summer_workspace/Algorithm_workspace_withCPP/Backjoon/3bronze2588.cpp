#include <array>
#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    array<int, 3> carryNum;
    cin >> num1 >> num2;
    if (num1 < 0 || num2 < 0) return 0;
    carryNum[0] = num2 % 10;
    carryNum[1] = (num2 / 10) % 10;
    carryNum[2] = num2 / 100;
    for (auto ele : carryNum) {
        cout << num1 * ele << endl;
    }
    cout << num1 * num2;
}

// 일의 자리 구하기: n % 10
// 십의 자리 구하기: n/10 % 10
// 백의 자리 구하기: n/100
// 핵심포인트: 원하는 자리수를 일의자리수자로 끌어내린다. 이때 원하는 자리수보다 더 큰 자리수가 남아
// 있다면 나머지연산을 한다. ex) 372/10 == 37.2고 7을 얻고싶은데 7보다 자리수가 큰 3이 있으므로
// 나머지연산진행