#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct median {
    priority_queue<int> maxHeap;  // 최대 힙: 중앙값보다 작거나 같은 값들을 저장
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 최소 힙: 중앙값보다 큰 값들을 저장

    // 새로운 데이터를 삽입하는 함수
    void insert(int data) {
        // 최대 힙이 비어있는 경우 데이터를 최대 힙에 추가
        if (maxHeap.size() == 0) {
            maxHeap.push(data);
            return;
        }

        // 최대 힙과 최소 힙의 크기가 같은 경우
        if (maxHeap.size() == minHeap.size()) {
            // 새로운 데이터가 현재 중앙값보다 작거나 같다면 최대 힙에 추가
            if (data <= get())
                maxHeap.push(data);
            else  // 크다면 최소 힙에 추가
                minHeap.push(data);
            return;
        }

        // 최소 힙의 크기가 더 큰 경우
        if (maxHeap.size() < minHeap.size()) {
            // 새로운 데이터가 현재 중앙값보다 크다면 최소 힙의 루트를 최대 힙으로 옮기고, 최소 힙에
            // 새 데이터를 추가
            if (data > get()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            } else  // 작거나 같다면 최대 힙에 새 데이터를 추가
                maxHeap.push(data);
            return;
        }

        // 최대 힙의 크기가 더 큰 경우
        if (data < get()) {
            // 새로운 데이터가 현재 중앙값보다 작다면 최대 힙의 루트를 최소 힙으로 옮기고, 최대 힙에
            // 새 데이터를 추가
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        } else  // 크거나 같다면 최소 힙에 새 데이터를 추가
            minHeap.push(data);
    }

    // 현재 중앙값을 반환하는 함수
    double get() {
        // 최대 힙과 최소 힙의 크기가 같은 경우 중앙값은 두 힙의 루트값의 평균
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        // 최소 힙의 크기가 더 큰 경우 중앙값은 최소 힙의 루트값
        if (maxHeap.size() < minHeap.size()) return minHeap.top();
        // 최대 힙의 크기가 더 큰 경우 중앙값은 최대 힙의 루트값
        return maxHeap.top();
    }
};

int main() {
    median med;
    med.insert(1);  // med가 비어있으므로 maxHeap에 1삽입
    cout << "1 삽입 후 중앙 값; " << med.get() << endl;  // 중앙값 1

    med.insert(5);  // maxHeap.size() > minHeap.size 인데 중앙값보다 5가 더 크므로 minHeap에 5삽입
    cout << "5 삽입 후 중앙 값; " << med.get()
         << endl;  // 사이즈가 같으므로 minHeap.top()+maxHeap.top()/2 == 1+5/2 == 3

    med.insert(2);  // 둘의 사이즈가 같고, 중앙값인 3보다 삽입될 값 2가 더 작으므로 maxHeap에 삽입
    cout << "2 삽입 후 중앙 값; " << med.get()
         << endl;  // maxHeap의 크기가 더 크므로 중앙값은 루트노드인 2

    med.insert(10);  // maxHeap.size() > minHeap.size() 이고, 중앙값보다 10이 더 크기 때문에
                     // minHeap에 10 삽입
    cout << "10 삽입 후 중앙 값; " << med.get()
         << endl;  // 두 힙의 사이즈가 같으므로 중앙값은  2+5/2 = 3.5

    med.insert(40);  // 둘의 사이즈 같고, 40은 중앙값인 3.5보다 더 크기 때문에 minHeap에 삽입
    cout << "40 삽입 후 중앙 값; " << med.get() << endl;  // 최대힙의 루트인 5가 중앙값
}