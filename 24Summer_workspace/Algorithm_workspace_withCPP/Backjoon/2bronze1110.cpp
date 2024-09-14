#include <iostream>
using namespace std;

int main() {
    int n, count = 0, update = 0, temp = 0;
    cin >> n;
    temp = n;
    if (n < 0 || n > 99) return 0;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    while (update != n) {
        update = temp;
        update = (update / 10 + update % 10) % 10 + update % 10 * 10;
        temp = update;
        count++;
    }
    cout << count;
    return 0;
}