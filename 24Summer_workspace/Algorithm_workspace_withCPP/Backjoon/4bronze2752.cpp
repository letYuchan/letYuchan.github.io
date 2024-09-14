#include <array>
#include <iostream>
using namespace std;
void swap(int& p1, int& p2) {
    int temp = p1;
    p1 = p2;
    p2 = temp;
}
int main() {
    array<int, 3> numbers;
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        numbers[i] = n;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (numbers[i] > numbers[j]) swap(numbers[i], numbers[j]);
        }
    }
    for (auto ele : numbers) {
        cout << ele << " ";
    }
    return 0;
}