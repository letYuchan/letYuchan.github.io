#include <algorithm>
#include <iostream>
using namespace std;

// 문제 이해: (0,0)과 (w, h), 두 점을 지나는 직사각형이 주어졌을 때 사각형 안쪽 점 (x, y)위치에서
// 직사각형의 경계선에 도달하기 위해 상하좌우 거리 중 어느거리가 최단거리인지 계산

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    if (1 > w || h > 1000 || x < 1 || x > w - 1 || y < 1 || y > h - 1) return 0;
    int temp1 = min(x, y);
    int temp2 = min(w - x, h - y);
    cout << min(temp1, temp2);
}