#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;
    string nums;
    int sum = 0;
    cin >> size;
    cin >> nums;
    for (int i = 0; i < size; i++) {
        sum += (int)(nums[i]) - 48;
    }
    cout << sum;
}
// ASCII: 0~9 ==> 48~57