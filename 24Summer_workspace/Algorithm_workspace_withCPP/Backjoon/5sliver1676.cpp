#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void multiply(vector<int>& result, int num) {
    int carry = 0;
    for (size_t i = 0; i < result.size(); i++) {
        int prod = result[i] * num + carry; // 현재 자릿수 값에 num을 곱하고 올림수 더함
        result[i] = prod % 10; // 결과의 1의 자리수(해당 자리수에 맞는 값만) 저장
        carry = prod / 10; // 올림수를 계산하여 저장
    }
    // 다만 이 계산과정은 result의 사이즈만큼만 작동하므로 마지막 결과 계산 올림수가 존재한다면 새로운 자릿수로 추가
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}
vector<int> factorial(int n) {
    vector<int> result(1, 1);
    for (int i = 2; i <= n; i++) multiply(result, i);

    return result;  // 순서가 뒤집어진 벡터 ex) 5! = 120 -> {0, 2, 1}
}
int main() {
    int n, count = 0;
    cin >> n;
    vector<int> result = factorial(n);
    for (auto ele : result) {
        if (ele == 0)
            count++;
        else if (ele != 0)
            break;
    }
    cout << count;
}
