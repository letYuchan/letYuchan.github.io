#include <iostream>
using namespace std;

int main() {
    int n;
    int primeNum_count = 0;
    bool isPrimeNum = true;
    cin >> n;
    if (n < 0 || n > 100) return 0;
    for (int i = 0; i < n; i++) {
        isPrimeNum = true;
        int val;
        cin >> val;
        if (val < 2 || val > 1000) {
            continue;
        } else if (val == 2)
            primeNum_count++;
        else {
            for (int j = 2; j < val; j++) {
                if (val % j == 0) {
                    isPrimeNum = false;
                    break;
                }
            }
            if (isPrimeNum) primeNum_count++;
        }
    }
    cout << primeNum_count;
    return 0;
}
// 소수: 약수로 1과 자신만 갖는 수(1제외, 자연수만 해당)