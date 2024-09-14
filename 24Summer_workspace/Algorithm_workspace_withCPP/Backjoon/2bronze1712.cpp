#include <iostream>
using namespace std;

int main() {
    int annual_fixed_cost, production_cost, sales_amount, break_even_point;
    cin >> annual_fixed_cost >> production_cost >> sales_amount;
    if (production_cost >= sales_amount) {
        cout << -1;
    } else if (sales_amount - production_cost > 0) {
        break_even_point = annual_fixed_cost / (sales_amount - production_cost) + 1;
        cout << break_even_point;
    }
    return 0;
}
// 이 문제는 실행시간 제한이 있기 때문에 반복문 사용불가
// 수학적 방법을 이용
// 결국 판매비용 - 생산비용은 곧 수입이고 이 수입이 고정비용을 넘어서면 됨
// long long 최대숫자: 9000조
// ing 최대숫자: 21억

// 처음 내가 짠 코드
// while (sales_amount * sales_num <= annual_fixed_cost + production_cost * sales_num) {
//     sales_num;
// }

// 왜 계속 틀리나 봤더니 생산비용과 판매비용이 동일할때도 손익분기점이 생기지 않음!
