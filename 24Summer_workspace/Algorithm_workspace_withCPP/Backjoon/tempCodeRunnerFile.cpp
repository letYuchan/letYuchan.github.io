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