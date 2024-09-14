#include <iostream>
#include <string>
using namespace std;

int main() {
    string hexVal;
    cin >> hexVal;
    int decimalVal = stoi(hexVal, nullptr, 16);
    cout << decimalVal;
}

// stoi: 주어진 문자열을 정수형으로 바꿔줌
// stoi(string, pos(default: nullptr), base(default: decimal))
// pos는 base를 기준으로 변환이 끝난 문자의 바로 다음 인덱스
// ex) stoi("123abc", &pos, 10) -> abc는 10진수가 아니므로 딱히 변환x, 123은 숫자이므로 10진수로
// 123변환 그 후 인덱스 3반환