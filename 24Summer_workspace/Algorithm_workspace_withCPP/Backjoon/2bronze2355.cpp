#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long a, b, sigma_a, sigma_b;
    cin >> a >> b;
    if (a > 2147483647 || b > 2147483647 || a < -2147483648 || b < -2147483648) return 0;
    sigma_a = a * (a + 1) / 2;
    sigma_b = b * (b + 1) / 2;
    if ((sigma_b - sigma_a + a > 2147483647) || (sigma_b - sigma_a + a < -2147483648)) {
        return 0;
    }
    if (a > b) {
        cout << sigma_a - sigma_b + b;
    } else
        cout << sigma_b - sigma_a + a;
    return 0;
}