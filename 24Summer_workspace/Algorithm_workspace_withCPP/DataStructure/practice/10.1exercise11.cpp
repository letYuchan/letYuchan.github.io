#include <iostream>
#include <vector>
using namespace std;
// 인접행렬로 그래프 표현
// 각 나라의 수도를 연결하는 항공 네트워크: 각 도시의 이름이 고유한 ID, 가중 그래프로 표현하여 도시
// 간 가상의 거리값을 표현, 양방향 그래프

// 도시 이름 저장
enum class city : int  // C++11 이후 도입된 enum의 업그레이드 버전 enum class
                       // class 다음에 오는 사용자 정의 이름은 열거형의 값들이 특정 클래스 범위 내에
                       // 존재하도록 하여(마치 namespace처럼) 다른 열거형 클래스나 전역
                       // 네임스페이스와의 이름 충돌을 방지한다.
{
    MOSCOW,
    LONDON,
    SEOUL,
    SEATTLE,
    DUBAI,
    SYDNEY
};

// << 연산자 정의
ostream& operator<<(ostream& os,
                    const city c)  // enum의 class이름은 "const city c"처럼 type과 같이 활용가능
{
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

// 그래프를 정의하는 struct
struct graph {
    vector<vector<int>>
        data;  // 행렬을 표현하기 위해 2차원 벡터를 사용 -> 노드의 개수가 n개일때 n*n 행렬 생성

    // 생성자 함수: n개의 노드를 가진 그래프를 초기화
    graph(int n) {
        data.reserve(n);     // data 벡터의 용량(최대원소개수)을 n으로 예약
        vector<int> row(n);  // n개의 요소를 가진 벡터 row 생성
        fill(row.begin(), row.end(), -1);  // fill함수는 해당범위를 어떠한 값으로 채우는 함수
        // row의 모든 요소를 -1로 초기화: -1은 노드와 노드 사이에
        //  에지가 존재하지 않음을 의미

        // n개의 row를 data에 추가하여 n x n 행렬 생성      // {-1 -1 -1 -1 -1 -1}
        // {-1 -1 -1 -1 -1 -1}
        // {-1 -1 -1 -1 -1 -1}
        // {-1 -1 -1 -1 -1 -1}
        // {-1 -1 -1 -1 -1 -1}
        // {-1 -1 -1 -1 -1 -1}
        for (int i = 0; i < n; i++) {
            data.push_back(row);
        }
    }

    // 에지 추가 함수
    void addEdge(const city c1, const city c2, int dis) {
        cout << "에지 추가: " << static_cast<int>(c1) << "-" << static_cast<int>(c2) << "=" << dis
             << endl;

        auto n1 = static_cast<int>(c1);  // city 열거형을 int로 변환 -> 인덱스로 활용
        auto n2 = static_cast<int>(c2);  // city 열거형을 int로 변환
        data[n1][n2] = dis;              // 에지의 거리 정보를 추가
        data[n2][n1] = dis;  // 무방향 그래프이므로 반대 방향도 동일한 거리 정보 추가
    }

    // 에지 삭제 함수
    void removeEdge(const city c1, const city c2) {
        cout << "에지 삭제: " << static_cast<int>(c1) << "-" << static_cast<int>(c2) << endl;

        auto n1 = static_cast<int>(c1);  // city 열거형을 int로 변환
        auto n2 = static_cast<int>(c2);  // city 열거형을 int로 변환
        data[n1][n2] = -1;               // 에지 삭제를 위해 -1로 설정
        data[n2][n1] = -1;  // 무방향 그래프이므로 반대 방향도 -1로 설정
    }
};

int main() {
    graph g(6);
    g.addEdge(city::LONDON, city::MOSCOW, 2500);
    g.addEdge(city::LONDON, city::SEOUL, 9000);
    g.addEdge(city::LONDON, city::DUBAI, 5500);
    g.addEdge(city::SEOUL, city::MOSCOW, 6600);
    g.addEdge(city::SEOUL, city::SEATTLE, 8000);
    g.addEdge(city::SEOUL, city::DUBAI, 7000);
    g.addEdge(city::SEOUL, city::SYDNEY, 8000);
    g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
    g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
    g.addEdge(city::DUBAI, city::SYDNEY, 1200);

    g.addEdge(city::SEATTLE, city::LONDON, 8000);
    g.removeEdge(city::SEATTLE, city::LONDON);

    return 0;
}
