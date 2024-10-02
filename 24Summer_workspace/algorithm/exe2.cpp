#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotSequence;  // 피벗 선택 순서를 저장하는 벡터

// 중앙값 피벗 선택 함수: 배열의 첫번째, 중간, 마지막 원소 중 중앙값을 피벗으로 선택
int medianPivot(vector<int>& nums, int low, int high) {
    int mid = low + (high - low) / 2;

    // 첫번째, 중간, 마지막 원소 중 중앙값 찾기
    if ((nums[low] < nums[mid] && nums[mid] < nums[high]) || (nums[high] < nums[mid] && nums[mid] < nums[low])) {
        return mid;
    }
    else if ((nums[mid] < nums[low] && nums[low] < nums[high]) || (nums[high] <= nums[low] && nums[low] < nums[mid])) {
        return low;
    }
    else {
        return high;
    }
}

// 파티션 함수: 배열을 피벗을 기준으로 두 파티션으로 나눔
int partition(vector<int>& nums, int low, int high) {
    int pivotIndex = medianPivot(nums, low, high);  // 중앙값을 피벗으로 선택
    int pivot = nums[pivotIndex];  // 피벗 값
    swap(nums[pivotIndex], nums[high]);  // 피벗을 마지막으로 이동
    int i = low - 1;  // 피벗보다 작은 원소의 마지막 인덱스 -> 처음에는 -1 즉 피버값보다 작은 값은 없다고 가정

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {  // 피벗보다 작은 원소를 찾음
            i++; // 피버값보다 작은 값을 발견한다면 i 다음 위치에 스왑(0부터 차례대로)
            swap(nums[i], nums[j]);  // 원소를 피벗보다 작은 부분으로 이동
        }
    }

    // 피벗 위치 조정
    swap(nums[i + 1], nums[high]);  // 피벗을 최종 위치로 이동
    return i + 1;  // 피벗의 최종 위치 반환 -> 피벗보다 작은 값들을 차례대로 왼쪽부터 삽입 한 다음 그 다음 위치가 결국 피벗이 위치해야할 위치니깐 i+1임
}

// 퀵정렬 함수
void quick_sort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(nums, low, high);  // 피벗의 위치 잡기
        pivotSequence.push_back(nums[pivotIndex]);  // 피벗 값을 기록
        quick_sort(nums, low, pivotIndex - 1);   // 좌측 배열 정렬
        quick_sort(nums, pivotIndex + 1, high);  // 우측 배열 정렬
    }
}

int main() {
    int n;
    cin >> n;  // 배열 크기 입력
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // 배열 요소 입력
    }

    quick_sort(nums, 0, n - 1);  // 퀵 정렬 수행

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // 피벗 선택 순서 출력
    for (int i = 0; i < pivotSequence.size(); i++) {
        cout << pivotSequence[i] << " ";
    }
    cout << endl;

    return 0;
}

// 정리하자면 low, high, middle 값 중 중앙값(셋 중 두번째로 큰 값)을 pivot으로 잡은 후
// 그 pivot을 배열 맨 마지막 위치로 옮기고, 
// pivot보다 작은 값을 왼쪽으로 차례대로(0부터) 옮긴다.
// 더이상 작은값이 없다면, pivot을 마지막으로 옮긴 값의 바로 뒤 인덱스로 옮긴다.
// 왼쪽정렬한다
// 오른쪽정렬하낟
