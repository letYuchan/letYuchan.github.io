#include <iostream>
#include <string>
using namespace std;
// 핵심포인트: 10의 1000승이란 숫자를 어떻게 처리할것인가? -> cpp의 기본자료형으론 불가능
// 숫자를 문자열을 통해 저장하고 이를 처리하자

// 나누는수와 나눠지는 수를
pair<string, string> bigNumDiv(const string& currency, const string& population) {
    string remainder = "0";
    string quotient = "";
    string carry = "";
}
int main() {
    string currency;
    string population;
    cin >> currency >> population;
    if (population == "0") return 0;  // 0으로 나눌 수 없음
}