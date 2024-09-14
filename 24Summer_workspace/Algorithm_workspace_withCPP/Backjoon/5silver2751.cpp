#include <iostream>
#include <vector>
using namespace std;

// 병합정렬: 분할정복 알고리즘으로, 모든 경우에 대하여 nLogN의 성능을 보장. 배열이 길이1이 될때까지
// 반복하여 나누고 분할된 배열들을 정렬하며 합치고 마지막엔 두 덩이의 배열을 합쳐 하나의 정렬된
// 배열로 만듦

// 병합 함수: 두 개의 정렬된 부분 배열을 하나로 병합
void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;  // 첫 번째 부분 배열의 길이, 왼쪽배열은 미드를 포함하므로 +1
    int n2 = right - mid;  // 두 번째 부분 배열의 길이

    vector<int> leftArray(n1);   // 왼쪽배열을 담기 위한 크기가 n1인 벡터
    vector<int> rightArray(n2);  // 오른쪽배열을 담기 위한 크기가 n2인 벡터

    for (int i = 0; i < n1; i++) leftArray[i] = nums[left + i];  // 복사시작
    for (int j = 0; j < n2; j++) rightArray[j] = nums[mid + 1 + j];

    int i = 0, j = 0;  // 두 배열의 인덱스 초기화
    int k = left;      // 병합된 배열의 시작 인덱스

    // 두 배열을 비교하여 병합
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            nums[k] = leftArray[i];  // 두 배열의 각 원소들을 앞에서부터 차례대로 비교하며
                                     // 왼쪽배열의 첫번째 원소가 오른쪽배열의 첫번째 원소보다 작다면
                                     // 순서대로 집어넣는 방법, 이후 두 배열의 인덱스를
                                     // 증가시킴(왼쪽이 더 작아서 왼쪽배열의 원소를 삽입했으면
                                     // 더이상 그 원소를 비교할 필요가 없으므로)
            i++;
        } else {
            nums[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 병합
    // 예를들어 [1, 3]과 [2,4,5]가 존재할 때, left에 2가 삽입되어 [1,2,3]이 된다(이 이상은 할 수
    // 없다 n1의 사이즈가 정해져있기 때문)
    while (i < n1) {  // i가 이미 n1의 크기를 벗어났다면 이 반복문은 작동하지 않음
        nums[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {  // j도 마찬가지로, 첫번째 while문에서 비교해가며 삽입했는데도 j가 여전히 n2를
                      // 넘지 못함다면 나머지를 옮김
        nums[k] = rightArray[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 큰 수를 더할때 발생하는 오버플로우를 방지하기 위함
                                              // -> (left+right)/2와 같은 의미
        merge_sort(nums, left,
                   mid);  // 왼쪽배열들은 계속 재귀적으로 함수가 호출되어, 반복하여 쪼개짐, 그
                          // 안에서도 왼쪽 오른쪽 배열로 계속 나뉘며, 배열의 길이가 최소가 되면 아래
                          // merge함수가 실행되고 코드가 끝나므로 호출됐던 부모함수로 돌아감
        merge_sort(nums, mid + 1, right);  // 오른쪽도 마찬가지
        merge(nums, left, mid,
              right);  // 결국 재귀호출되었던 함수들이 종료되고 나면, 마지막엔 정렬된 두 덩어리의
                       // 배열들이 합쳐져 정렬된 한 덩이의 배열이 됨
    }
}

int main() {
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }
    merge_sort(nums, 0, n - 1);
    for (auto ele : nums) {
        cout << ele << "\n";
    }
}

// // 파티션함수: 배열을 피벗을 기준으로 두 파티션으로 나눔
// int partition(vector<int>& nums, int low, int high) {
//     int pivot =
//         nums[high];  // 피벗을 배열의 마지막 원소로 선택 -> 임의의 위치에서 모두 선택가능하지만,
//                      // 제일 단순한 방법(많이 정렬된 상태에선 최악의 시간복잡도)
//     int i = low - 1;  // 피벗보다 작은 원소의 마지막 인덱스

//     for (int j = low; j < high; j++) {
//         if (nums[j] <= pivot) {  // 피벗보다 작은 원소를 찾음
//             i++;  // 초기에는 i가 -1이므로 피벗보다 작은 값을 찾았다면 i=0이고, 0번째 인덱스에
//                   // 해당하는 값을 집어넣음
//             swap(nums[i], nums[j]);  // 원소를 피벗보다 작은 부분으로 이동
//         }
//     }

//     // 피벗 위치 조정
//     swap(nums[i + 1], nums[high]);  // i+1은 피벗의 최종위치로, i가 결국 피벗보다 작은 원소중
//     가장
//                                     // 큰 마지막 인덱스값이기 때문에 피벗은 i+1에 위치하여야함 ->
//                                     // i+1보다 왼쪽으론 작은 수들이 오른쪽으론 큰 수들이 정렬
//     return i + 1;  // 피벗의 최종 위치를 반환합니다.
// }

// // ex)
// // Initial Array: [10, 7, 8, 9, 1, 5]
// // Pivot: 5

// // Step-by-Step Partitioning:

// // 1. [10, 7, 8, 9, 1, 5]    (i = -1, j = 0, 10 > 5, no change)
// // 2. [10, 7, 8, 9, 1, 5]    (i = -1, j = 1, 7 > 5, no change)
// // 3. [10, 7, 8, 9, 1, 5]    (i = -1, j = 2, 8 > 5, no change)
// // 4. [10, 7, 8, 9, 1, 5]    (i = -1, j = 3, 9 > 5, no change)
// // 5. [1, 7, 8, 9, 10, 5]    (i = 0, j = 4, 1 <= 5, swap with nums[0])

// // Swap pivot to correct position:
// // 6. [1, 5, 8, 9, 10, 7]    (swap nums[1] with nums[5])

// // Pivot final position: 1

// void swap(int& n1, int& n2) {
//     int temp = n1;
//     n1 = n2;
//     n2 = temp;
// }

// // 퀵정렬: 시간복잡도 nLogN이자 최악의 경우여도 n^2, 피벗을 기준으로 그 보다 작은 수들의
// 부분배열과
// // 큰 부분배열을 만들고 오름차순 정렬, 이 행위를 반복한다 -> 분할정복기법
// void quick_sort(vector<int>& nums, int low, int high) {
//     // 정렬이 끝나는 시점 -> high가 1보다 같거나 작을때, 즉 부분배열의 크기가 1이하일때 종료
//     if (low < high) {  // log: 현재(부분)배열의 시작 인덱스 & high: 현재(부분) 배열의 끝 인덱스
//         int pivotIndex = partition(nums, low, high);  // 피벗의 위치 잡기

//         quick_sort(nums, low, pivotIndex - 1);   // 좌측 배열 정렬
//         quick_sort(nums, pivotIndex + 1, high);  // 우측 배열 정렬
//     }
// }

// // 버블정렬 -> n^2 정도의 시간복잡도
// // void ascending_sort(vector<int>& nums, int n) {
// //     for (int i = 0; i < n - 1; i++) {
// //         for (int j = i + 1; j < n; j++) {
// //             if (nums[i] > nums[j]) swap(nums[i], nums[j]);
// //         }
// //     }
// // }
// int main() {
//     vector<int> nums;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int val;
//         cin >> val;
//         nums.push_back(val);
//     }
//     quick_sort(nums, 0, n - 1);
//     for (auto ele : nums) cout << ele << "\n";
// }
// // 진짜 쉽게 이해해보고자한다면, 피벗을 정하고 피벗보다 작은 수들을 정렬하지 않은 채 왼쪽으로 큰
// // 수는 오른쪽으로 몰아넣고, 다시 한번 재귀적 호출을 통해 또 왼쪽에 몰아 넣고 오른쪽에 몰아 넣고
// // 하다보면 정렬이 됨