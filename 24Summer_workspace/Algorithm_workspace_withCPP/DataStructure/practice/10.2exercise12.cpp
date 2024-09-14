#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

enum class city : int { MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY };

// 도시 열거형(city)을 문자열로 출력하기 위한 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const city c) {
    switch (c) {
        case city::LONDON:
            os << "런던";
            return os;
        case city::MOSCOW:
            os << "모스크바";
            return os;
        case city::SEOUL:
            os << "서울";
            return os;
        case city::SEATTLE:
            os << "시애틀";
            return os;
        case city::DUBAI:
            os << "두바이";
            return os;
        case city::SYDNEY:
            os << "시드니";
            return os;
        default:
            return os;
    }
}

// 그래프 구조를 표현하는 클래스
struct graph {
    // pair: 템플릿 클래스로 두 개의 요소를 하나의 객체단위로 관리하는데 사용
    vector<vector<pair<int, int>>>  // 2차원으로 활용하는 이유: data[i][j]에서 i는 해당하는 도시
                                    // j는 그 도시와 연결된 다른 도시의 인덱스와 둘 사이의 거리를
                                    // 나타냄
        data;  // 인접 리스트 형식의 그래프 데이터, pair의 두
               // int형은 도시별 인덱스와 거리를 의미

    // 그래프 초기화 및 인접 리스트 생성
    graph(int n) {
        // n개의 빈 벡터(vector<pair<int, int>>)로 초기화된 2차원 벡터 생성
        data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    }

    // 두 도시 간의 에지(간선) 추가
    void addEdge(const city c1, const city c2, int dis) {
        cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        // 각 도시 간의 거리(dis)를 pair로 묶어서 각 도시의 인접 리스트에 추가
        data[n1].push_back({n2, dis});
        data[n2].push_back({n1, dis});
    }

    // 두 도시 간의 에지(간선) 삭제
    void removeEdge(const city c1, const city c2) {
        cout << "에지 삭제: " << c1 << "-" << c2 << endl;

        auto n1 = static_cast<int>(c1);
        auto n2 = static_cast<int>(c2);

        // 각 도시의 인접 리스트에서 특정 도시와 연결된 에지(간선) 제거
        // remove_if 함수를 사용하여 조건을 만족하는 요소들을 범위의 끝으로 밀어내고 해당 범위를
        // 반환받음, erase로 실제 요소 삭제(일종의 테크닉)
        // * forward_list는 remove_if가 완전히 요소를 삭제함
        data[n1].erase(remove_if(data[n1].begin(), data[n1].end(),
                                 [n2](const pair<int, int>& pair) { return pair.first == n2; }),
                       data[n1].end());

        data[n2].erase(remove_if(data[n2].begin(), data[n2].end(),
                                 [n1](const pair<int, int>& pair) { return pair.first == n1; }),
                       data[n2].end());
    }
};

int main() {
    graph g(6);  // 6개의 도시로 이루어진 그래프 객체 생성

    // 다양한 도시 간의 에지(간선) 추가
    g.addEdge(city::LONDON, city::SEOUL, 9000);
    g.addEdge(city::LONDON, city::DUBAI, 5500);
    g.addEdge(city::SEOUL, city::MOSCOW, 6600);
    g.addEdge(city::SEOUL, city::SEATTLE, 8000);
    g.addEdge(city::SEOUL, city::DUBAI, 7000);
    g.addEdge(city::SEOUL, city::SYDNEY, 8000);
    g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
    g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
    g.addEdge(city::DUBAI, city::SYDNEY, 1200);

    // 시각화
    /*     (9000)
        런던 ---- 서울
         | \        | \ \ \
    (2500)|  (5500) |(6600) (7000) (8000)
         |    \     |   |    \    \
      모스크바 (5500) 시드니 (12000) 시애틀
          \        \     \       \     /
          (8400)   (8000)(8000)   (12000)
           시애틀     두바이 ---- 시드니
               (1200) */

    // 에지(간선) 추가 후, 에지(간선) 삭제
    g.addEdge(city::SEATTLE, city::LONDON, 8000);
    g.removeEdge(city::SEATTLE, city::LONDON);

    return 0;
}

// data구조 이해하기

/* 런던 (인덱스 1)과 서울 (인덱스 2) 사이의 간선을 추가한 후의 data 구조를 설명합니다:

data 구조
data[0]: 모스크바와 연결된 도시들
data[1]: 런던과 연결된 도시들
data[1][0]: {2, 9000} (서울, 9000km)
data[1][1]: {3, 5500} (두바이, 5500km)
data[2]: 서울과 연결된 도시들
data[2][0]: {0, 6600} (모스크바, 6600km)
data[2][1]: {1, 9000} (런던, 9000km)
data[2][2]: {4, 8000} (시애틀, 8000km)
data[2][3]: {3, 7000} (두바이, 7000km)
data[2][4]: {5, 8000} (시드니, 8000km)
data[3]: 두바이와 연결된 도시들
data[3][0]: {1, 5500} (런던, 5500km)
data[3][1]: {2, 7000} (서울, 7000km)
data[3][2]: {5, 1200} (시드니, 1200km)
data[4]: 시애틀과 연결된 도시들
data[4][0]: {2, 8000} (서울, 8000km)
data[4][1]: {5, 12000} (시드니, 12000km)
data[5]: 시드니와 연결된 도시들
data[5][0]: {2, 8000} (서울, 8000km)
data[5][1]: {3, 1200} (두바이, 1200km)
data[5][2]: {4, 12000} (시애틀, 12000km) */
