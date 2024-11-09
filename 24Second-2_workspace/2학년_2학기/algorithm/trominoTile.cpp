// Tromino Tiling: 2^k * 2^k 격자판에서 한 칸을 비운 상태로, 나머지 칸을 L자 모양의 타일로 덮는 문제
// 전제 격자판을 4등분하고 각 부분을 재귀적으로 트로미노타일링 알고리즘 수행
// 기존에 한칸이 빈 타일을 제외 나머지 세 영역의 각 한 칸씩을 이용하여 전체격자판 중앙에 트로미노 타일 추가


#include <bits/stdc++.h>
using namespace std;
#define MAX 257  // 타일 배열의 최대 크기 (2^8 + 1)

int K, x, y;  // K는 격자 크기, x, y는 비어 있는 칸의 좌표
int cnt;  // 타일에 번호를 매길 카운터 변수
int tiles[MAX][MAX];  // 격자판 배열

// 해당 구역에 구멍(비어있는 칸)이 있는지 확인하는 함수
bool isNotHole(int x, int y, int len) {
    for(int i = x; i < x + len; i++) {  // x ~ x+len 범위의 행 확인
        for(int j = y; j < y + len; j++) {  // y ~ y+len 범위의 열 확인
            if(tiles[i][j] != 0) return false;  // 0이 아닌 값이 있으면 구멍이 아님
        }
    }
    return true;  // 모두 0이면 구멍임
}

// 트로미노 타일을 채우는 재귀 함수
void fillTiles(int x, int y, int len) {
    ++cnt;  // 타일 번호 증가
    int divideLen = len / 2;  // 현재 격자를 4분할

    // 왼쪽 위 부분에 구멍이 없으면 중앙에 타일을 채움
    if(isNotHole(x, y, divideLen)) tiles[x+divideLen-1][y+divideLen-1] = cnt;
    
    // 오른쪽 위 부분에 구멍이 없으면 중앙에 타일을 채움
    if(isNotHole(x, y+divideLen, divideLen)) tiles[x+divideLen-1][y+divideLen] = cnt;
    
    // 왼쪽 아래 부분에 구멍이 없으면 중앙에 타일을 채움
    if(isNotHole(x+divideLen, y, divideLen)) tiles[x+divideLen][y+divideLen-1] = cnt;
    
    // 오른쪽 아래 부분에 구멍이 없으면 중앙에 타일을 채움
    if(isNotHole(x+divideLen, y+divideLen, divideLen)) tiles[x+divideLen][y+divideLen] = cnt;

    // 기저 조건: 격자의 크기가 2가 되면 더 이상 분할하지 않음
    if(len == 2) return;

    // 4분할된 각 구역에 대해 재귀적으로 타일을 채움
    fillTiles(x, y, divideLen);  // 왼쪽 위
    fillTiles(x+divideLen, y, divideLen);  // 왼쪽 아래
    fillTiles(x, y+divideLen, divideLen);  // 오른쪽 위
    fillTiles(x+divideLen, y+divideLen, divideLen);  // 오른쪽 아래
}

int main() {
    ios::sync_with_stdio(0);  // 입출력 성능 향상
    cin.tie(0);  // 입력 스트림과 출력 스트림을 분리하여 출력 버퍼 플러싱 방지
    cout.tie(0);

    cin >> K >> x >> y;  // K는 격자의 크기 (2^K x 2^K), x, y는 비어 있는 칸의 좌표

    tiles[y-1][x-1] = -1;  // (x, y) 위치에 구멍(비어 있는 칸)을 표시

    // K가 1일 경우, 즉 격자 크기가 2x2일 때 예외 처리
    if(K == 1) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                // 비어 있지 않은 칸을 타일 번호로 채움
                if(tiles[i][j] == 0) tiles[i][j] = 1;
            }
        }
    }
    else {
        // 크기가 2^K x 2^K인 격자에 대해 타일을 채움
        fillTiles(0, 0, pow(2, K));
    }

    // 최종 타일 배열을 출력
    for(int i = 0; i < pow(2, K); i++) {
        for(int j = 0; j < pow(2, K); j++) {
            cout << tiles[i][j] << " ";  // 각 타일 번호 출력
        }
        cout << '\n';  // 행 끝에서 줄바꿈
    }

    return 0;
}
