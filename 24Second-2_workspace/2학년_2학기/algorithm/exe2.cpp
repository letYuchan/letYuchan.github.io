#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotHistory;  // 피벗 선택 기록 저장

// 중앙값 피벗 선택 함수: 배열의 첫번째, 중간, 마지막 원소 중 중앙값을 피벗으로 선택
int selectMedianPivot(vector<int>& arr, int start, int end) {
    int middle = start + (end - start) / 2;  // 중간 인덱스 계산

    // 첫번째, 중간, 마지막 원소 중 중앙값 찾기
    if ((arr[start] < arr[middle] && arr[middle] < arr[end]) || (arr[end] < arr[middle] && arr[middle] < arr[start])) {
        return middle;  // 중간값이 중앙에 있을 때
    }
    else if ((arr[middle] < arr[start] && arr[start] < arr[end]) || (arr[end] <= arr[start] && arr[start] < arr[middle])) {
        return start;  // 중앙값이 첫번째 원소일 때
    }
    else {
        return end;  // 중앙값이 마지막 원소일 때
    }
}

// 파티션 함수: 배열을 피벗을 기준으로 두 파티션으로 나눔
int performPartition(vector<int>& arr, int start, int end) {
    int pivotIdx = selectMedianPivot(arr, start, end);  // 중앙값을 피벗으로 선택
    int pivotValue = arr[pivotIdx];  // 선택된 피벗 값
    swap(arr[pivotIdx], arr[end]);  // 피벗을 배열 끝으로 이동
    int smallIndex = start - 1;  // 피벗보다 작은 값들을 가리킬 인덱스, 초기에는 -1 (작은 값이 없다고 가정)

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivotValue) {  // 피벗보다 작은 값이 있으면
            smallIndex++;  // 작은 값이 있으면 smallIndex 증가
            swap(arr[smallIndex], arr[j]);  // 그 값과 smallIndex 위치의 값 교환
        }
    }

    // 피벗을 자기 위치로 이동
    swap(arr[smallIndex + 1], arr[end]);  // smallIndex+1 위치에 피벗을 배치
    return smallIndex + 1;  // 피벗의 최종 위치 반환
}

// 퀵정렬 함수
void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivotIdx = performPartition(arr, start, end);  // 파티션을 통해 피벗 위치 결정
        pivotHistory.push_back(arr[pivotIdx]);  // 피벗 값을 기록
        quickSort(arr, start, pivotIdx - 1);   // 왼쪽 파티션 정렬
        quickSort(arr, pivotIdx + 1, end);  // 오른쪽 파티션 정렬
    }
}

int main() {
    int n;
    cin >> n;  // 배열 크기 입력
    vector<int> arr(n);  // 입력 배열 생성
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 배열 요소 입력
    }

    quickSort(arr, 0, n - 1);  // 퀵 정렬 수행

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 피벗 선택 순서 출력
    for (int i = 0; i < pivotHistory.size(); i++) {
        cout << pivotHistory[i] << " ";
    }
    cout << endl;

    return 0;
}
