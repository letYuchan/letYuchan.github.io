#include <iostream>
#include <vector>
using namespace std;

// 행렬 곱셈 함수
vector<vector<int>> matrix_product(const vector<vector<int>>& v1, const vector<vector<int>>& v2) {
    int n = v1.size();     // v1의 행 개수
    int m = v2[0].size();  // v2의 열 개수
    int k = v1[0].size();  // v1의 열 개수 = v2의 행 개수

    vector<vector<int>> result(n, vector<int>(m, 0));  // 결과 행렬 초기화

    for (int i = 0; i < n; i++) { // 바깥 n과 m에 해당하는 for문은 우리가 행렬의 곱셈결과 (mxn과 nxp)일때 mxp가 곱셈의 최종결과 행렬의 크기이므로 result[i][j]를 mxp만큼 실행
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) { // 맨 안쪽 for문은 곱셈의 원리를 적용한 것
                result[i][j] += v1[i][l] * v2[l][j];  // 만약 2*2행렬끼리의 곱셈일때, v1의 행에 해당하는 원소와 v2의 열에 해당하는 원소를 곱해주는데 일단 v1(0,0) v2(0,0)을 곱해주고 result에 집어넣고, v1(0,1) * v2(1,0)을 곱하여 집어넣어준다. 이렇게 l이 곧 v1의 열의 개수만큼 끝났을때 j(v2의 다음 행)가 값이 늘어나고 또 계산을 반복해주면 결국 첫번째 행에 해당하는 모든 result 원소가 완성
            }
        }
    }

    return result;
}

// 행렬 출력 함수
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";  // 원소를 출력하고, 공백으로 구분
        }
        cout << endl;  // 행의 끝에서 줄 바꿈
    }
}

int main() {
    int nA, mA, nB, mB;
    
    // 행렬 A 입력
    cin >> nA >> mA;
    vector<vector<int>> matrixA(nA, vector<int>(mA));  // 크기를 정의하여 초기화
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < mA; j++) {
            cin >> matrixA[i][j];
        }
    }

    // 행렬 B 입력
    cin >> nB >> mB;
    if (mA != nB) {
        return 0;  
    }
    vector<vector<int>> matrixB(nB, vector<int>(mB));  // 크기를 정의하여 초기화
    for (int i = 0; i < nB; i++) {
        for (int j = 0; j < mB; j++) {
            cin >> matrixB[i][j];
        }
    }

    // 행렬 곱셈 수행
    vector<vector<int>> result = matrix_product(matrixA, matrixB);

    print_matrix(result);

    return 0;
}
