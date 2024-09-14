#include <array>
#include <iostream>
#include <string>
using namespace std;

// 각각의 소문자 대문자 알파벳 개수를 세고 이 둘을 합쳐 총 알파벳의 개수를 센다.
int main() {
    string alphabets;
    array<int, 26> count = {0};
    cin >> alphabets;

    for (auto ch : alphabets) {
        ch = toupper(ch);  // 모두 대문자로 변환 후 개수 카운트

        if (ch >= 'A' && ch <= 'Z')
            count[ch - 'A'] += 1;  // 알파벳을 순서에 맞게 인덱스에 저장하는 쉬운 방법
    }
    // maxVal은 개수비교를 위한 변수, maxVal_char은 최대개수를 갖는 알파벳을 대문자로 출력하기 위한
    // 변수
    int maxVal = count[0];
    char maxVal_char = 'A';
    for (int k = 1; k < 26; k++) {
        if (count[k] > maxVal) {
            maxVal = count[k];
            maxVal_char = 65 + k;
        }
    }
    // 최대개수가 동일한 알파벳이 여럿 존재할 경우
    int max_count = 0;
    for (auto ele : count) {
        if (ele == maxVal) max_count++;
    }
    if (max_count > 1) {
        cout << "?";
    } else
        cout << maxVal_char;
    return 0;
}