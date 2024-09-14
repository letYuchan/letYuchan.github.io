#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    vector<int> measures;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) measures.push_back(i);
    }
    if (k > measures.size())
        cout << 0;
    else
        cout << measures[k - 1];
    return 0;
}