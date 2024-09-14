#include <array>
#include <iostream>
using namespace std;

int main() {
    int peopleWhoIsInParty, area;
    array<int, 5> articles;
    array<int, 5> error_count;
    cin >> peopleWhoIsInParty >> area;
    if (peopleWhoIsInParty < 1 || peopleWhoIsInParty > 10 || area < 1 || area > 1000)
        return 0;  // 사람 수 및 넓이에 관한 조건 검사
    // 각 신문별 파티참여자 수 입력
    for (int i = 0; i < articles.size(); i++) {
        int peopleWhoIsInParty_article;
        cin >> peopleWhoIsInParty_article;
        articles[i] = peopleWhoIsInParty_article;
    }
    // 오차범위 계산
    for (int i = 0; i < error_count.size(); i++) {
        error_count[i] = articles[i] - (area * peopleWhoIsInParty);
    }
    // 오차 출력
    for (auto ele : error_count) {
        cout << ele << " ";
    }
}