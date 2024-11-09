// ClosestPair: 가장 가까운 두 점 문제를 해결하기 위한 분할-정복 아록리즘
// 2차원 평면에 있는 N개의 점 중 가장 가까운 두점 사이의 거리를 구한다.
// 두 부분으로 나누고, 각 부분에서 가장 가까운 두 점을 찾은 후, 두 부분의 경계에 걸친 점들 사이에도 가까운 두 점이 있는지 검사
// O(NlogN)



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>  // 소수점 출력을 위한 헤더 파일

using namespace std;

// Point 구조체: 각 점을 나타냄 (x, y 좌표)
struct Point {
    int x, y;
};

// 두 점 사이의 거리 계산 함수
// Euclidean distance formula를 사용하여 거리 계산
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// 브루트포스 방식으로 점들 간의 최소 거리 계산
// 점의 개수가 적을 때(일반적으로 4개 이하) 호출됨
// 시간 복잡도는 O(N^2)
double bruteForce(const vector<Point>& points, int left, int right) {
    double minDist = 1e9;  // 초기값을 매우 큰 값으로 설정
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            // 두 점 간의 거리 계산 후 최소 거리로 업데이트
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

// 중간 경계 영역에서의 최소 거리 계산 함수
// 중간 영역의 점들은 x축을 기준으로 분할된 후,
// 경계선에 가까운 점들로 구성됨 (strip)
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;  // 현재 최소 거리 값
    int n = strip.size();
    
    // y 좌표를 기준으로 점들을 정렬
    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });
    
    // 각 점에서 최대 7개의 인접 점만 검사 (y 축 차이가 minDist보다 작을 때까지만)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist; ++j) {
            // 두 점 간의 거리 계산 후 최소 거리로 업데이트
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

// 분할 정복 방식으로 가장 가까운 두 점 간의 거리 계산
// 시간 복잡도: O(N log N)
double closestUtil(vector<Point>& points, int left, int right) {
    // 기저 조건: 점의 개수가 4개 이하인 경우 브루트포스 호출
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    // 중간 인덱스 계산
    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    // 왼쪽과 오른쪽 부분에서 각각 최소 거리를 찾음
    double dl = closestUtil(points, left, mid);       // 왼쪽 구간의 최소 거리
    double dr = closestUtil(points, mid + 1, right);  // 오른쪽 구간의 최소 거리

    // 두 구간 중 더 작은 거리 선택
    double d = min(dl, dr);

    // 중간 영역(strip)에 있는 점들을 저장
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        // 중간 영역에 속하는 점들만 strip에 추가 (x좌표 차이가 d 미만인 점들)
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    // 중간 영역과 양쪽 경계선에 걸친 점들 간의 거리도 고려하여 최소 거리 반환
    return min(d, stripClosest(strip, d));
}

// 분할 정복 방식으로 가장 가까운 두 점을 찾는 메인 함수
// 1. 입력된 점들을 x 좌표 기준으로 정렬
// 2. closestUtil 함수를 호출하여 최소 거리 계산
double closestPair(vector<Point>& points) {
    // x 좌표를 기준으로 점들을 정렬
    sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    
    // 분할 정복을 사용하여 가장 가까운 두 점 간의 거리 계산
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    int N;  // 점의 개수
    cin >> N;  // 점의 개수 입력받기
    if (N < 2) {
        cout << "Invalid number of points" << endl;
        return 1;  // 점의 개수가 2개 미만인 경우 예외 처리
    }

    vector<Point> points(N);  // N개의 점을 저장할 벡터

    // 점 좌표를 입력받음 (형식: x,y)
    for (int i = 0; i < N; ++i) {
        char comma;  // ',' 문자를 받기 위한 변수
        cin >> points[i].x >> comma >> points[i].y;
    }

    // 가장 가까운 두 점 사이의 거리 출력 (소수점 6자리)
    cout << fixed << setprecision(6) << closestPair(points) << endl;

    return 0;
}
