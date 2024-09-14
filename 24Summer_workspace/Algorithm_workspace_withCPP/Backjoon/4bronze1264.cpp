#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countVowelNum(const string& v) {
    int vowelCount = 0;
    for (auto i : v) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' ||
            i == 'I' || i == 'O' || i == 'U')
            vowelCount += 1;
    }
    return vowelCount;
}
int main() {
    string sentence;
    vector<string> vec;
    char stopChar = '#';
    // 문장입력
    while (getline(cin, sentence)) {  // getline은 한줄씩 줄바꿈하며 문자열을 받아온다. 이때
                                      // 줄바꿈은 엔터키이며 \n 전까지 문자열만 변수에 입력된다.
        if (sentence.size() > 255) return 0;
        if (sentence == string(1, stopChar)) {  // 반드시 마지막에는 #하나만 와야함
            break;
        }
        vec.push_back(sentence);
    }

    // 모음 개수 세기
    vector<int> vowelCounter;  // 각 줄의 모음개수를 저장하기 위한 벡터
    for (const auto& str : vec) {
        int vowelNum = countVowelNum(str);
        vowelCounter.push_back(vowelNum);
    }

    // 각 줄마다의 모음 개수 출력
    for (auto ele : vowelCounter) {
        cout << ele << endl;
    }

    // push_back하면 크기가 늘어남으로 고정크기를 사용하고자 할 땐 주의하자
}