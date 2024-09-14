#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    string s;
    bool isWord = false;
    getline(cin, s);

    for (int i = 0; i < s.size() + 1; i++) {
        if (s[i] == ' ') {
            if (isWord == true) count++;
            isWord = false;
        } else if (s[i] == '\0') {
            if (isWord == true) count++;
        } else
            isWord = true;
    }
    cout << count << '\n';
}
//   cin은 공백문자나 엔터키로 입력구분
//  getline은 엔터키로 구분

// 문자를 만나면 isWord = true, 이 상태에서 공백이나 널문자를 만나면 count++ 이때 공백을 만나면
// isWord는 false 널문자를 만나면 끝
