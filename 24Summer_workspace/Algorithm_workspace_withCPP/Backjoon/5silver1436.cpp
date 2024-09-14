#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt = 0, end_num = 666;
    string str;
    cin >> n;

    while (1) {
        str = to_string(end_num);
        if (str.find("666") != string::npos)
            cnt++;  // npos == -1, 문자열 검색함수에서 활용 -> 찾지못하면 -1을 반환하는 find함수와
        // 연계하여 활용
        if (cnt == n) break;
        ++end_num;
    }
    cout << end_num;

}
// 최소 6이 연달아 3개이상 존재하는 숫자들 중 n번째 숫자 (최소 666부터 시작)
