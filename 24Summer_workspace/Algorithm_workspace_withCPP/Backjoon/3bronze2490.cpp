#include <array>
#include <iostream>
using namespace std;
char decideWhatItis(array<int, 4> yut) {
    int count = 0;
    for (auto ele : yut) {
        count += ele;
    }
    switch (count) {
        case 3:
            return 'A';
            break;
        case 2:
            return 'B';
            break;
        case 1:
            return 'C';
            break;
        case 0:
            return 'D';
            break;
        default:
            return 'E';
            break;  // default의 break는 선택사항(미래 확장성과 코드 일관성을 위해 적어두는거 추천)
    }
}
int main() {
    array<array<int, 4>, 3> Yuts;
    array<char, 3> decided;
    for (auto& row : Yuts) {
        for (auto& ele : row) cin >> ele;  // 이차원배열을 초기화 할땐 이중for문 사용할것!
    }

    int index = 0;
    for (auto row : Yuts) {
        char a = decideWhatItis(row);
        decided[index] = a;
        index++;
    }
    for (auto ele : decided) cout << ele << endl;

    return 0;
}
// 나름 여러가지 잘 활용한듯?