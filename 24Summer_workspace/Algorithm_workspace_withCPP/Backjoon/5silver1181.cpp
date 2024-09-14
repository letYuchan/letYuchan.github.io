#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> words;
    int n;
    cin >> n;

    set<string> word_set;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() > 50) continue;
        word_set.insert(s);
    }
    words.assign(word_set.begin(), word_set.end());
    sort(words.begin(), words.end(), [](string& s1, string& s2) {
        if (s1.length() == s2.length()) {
            return s1 < s2;  // 길이가 같은 경우
        } else {
            return s1.length() < s2.length();  // 길이가 다른경우
        }
    });
    for (auto ele : words) cout << ele << "\n";
    return 0;
}
// string의 경우 비교연산자는 각 알파벳의 사전순서를 비교하는것임
// sort(시작반복자, 끝반복자(포함x),  cmp함수(기본적으로 <연산 지원)) 기본 오름차순(내림차순인 경우
// cmp함수에서 조건식을 >로 변경)
// 시간복잡도 nlogn

// 시간초과 but 제대로 구현
// void swap(string& s1, string& s2) {
//     string temp = s1;
//     s1 = s2;
//     s2 = temp;
// }
// int main() {
//     vector<string> words;
//     int n;
//     cin >> n;
//     if (n < 1 || n > 20000) return 0;
//     for (int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         if (s.length() > 50) continue;
//         words.push_back(s);
//     }
//     for (int j = 0; j < words.size() - 1; j++) {
//         for (int k = 0; k < words.size() - j - 1; j++) {
//             if (words[k].length() > words[k + 1].length() ||
//                 words[k].length() == words[k + 1].length() && words[k] > words[k + 1])
//                 swap(words[k], words[k + 1]);
//         }
//     }

//     for (auto ele : words) {
//         cout << ele << "\n";
//     }
//     return 0;
// }
// string은 값 입력시 널문자 대입
// string에서 size와 length 둘다 문자열의 길이(널문자 제외)를 나타냄
