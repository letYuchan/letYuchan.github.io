#include <array>
#include <iostream>
#include <string>
using namespace std;

int main() {
    array<int, 26> alphabets = {0};
    string s;
    cin >> s;
    for (auto i = 0; i < s.size(); i++) {  // 소문자 감별기
        if ((int)s[i] < 97 || (int)s[i] > 122) return 0;
    }
    if (s.size() > 100) return 0;         // 사이즈 감별기
    for (int i = 0; i < s.size(); i++) {  // 일단 각 알파벳을 기준으로
        for (int j = 97; j < 123; j++) {  // 아스키코드를 하나하나 대조할건데
            int ASCII = j;
            if ((int)s[i] == j)
                alphabets[ASCII - 97] += 1;  // 가장 첫번째 알파벳부터 시작해서 아스키코드값하고
                                             // 비교해서 맞는게 있다면 알맞는 인덱스에 +1
        }
    }

    for (auto ele : alphabets) {
        cout << ele << " ";
    }
}

//  아스키코드: a~z  ==> 97~122
//  아스키 코드 - 97 = 알파벳 순서대로 배열에 저장하고자 할 때 인덱스값으로 활용
//  ex) (int)a - 97 = 0 == alphabets[0]에서 활용
