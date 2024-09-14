#include <iostream>
using namespace std;

// call by value
void swap_value(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// call by ptr
void swap_ptr(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// call by ref
void swap_ref(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void doubleIt(int* p, int x) { *p = x * 2; }
int main() {
    // 포인터 기본
    int a = 100;
    int* p = &a;
    cout << "a의 값: " << a << " a의 주소: " << &a << endl;
    cout << "p의 값: " << p << " p가 가리키는 값 p*: " << *p << endl;
    cout << "p의 주소: " << &p << endl;

    // 이중포인터
    int** q = &p;
    cout << "q가 가리키는 주소: " << q << endl;
    cout << "q 자체의 주소: " << &q << endl;
    cout << "q의 실질적인 값(q가 가리키는 p에 할당된 a변수의 주소): " << *q << endl;
    cout << "q가 가리키는 p의 실제 값: " << *(*q) << endl;

    // 매개변수에서 활용되는 포인터
    int it = 5;
    doubleIt(&it, 9);
    cout << it << endl;

    // 포인터와 상수화
    int* const p_a = &a;
    // p_a = &it; // 주소를 상수화 했으므로 주소변경은 불가능 -> 컴파일 에러
    *p_a = 50;          // 값은 변경 가능
    cout << a << endl;  // 역참조연산자로 변경한 값은 실제 변수에도 영향을 미침
    cout << *p_a << endl;

    const int* p_it = &it;
    // *p_it = 50;  // 값을 상수화 했으므로 값 변경 불가능
    p_it = &a;  // 주소는 변경 가능
    cout << *p_it;

    // 참조변수 활용
    int m = 10;
    int& j = m;  // 초기화
    cout << "value of m = " << m << endl;
    cout << "value of j = " << j << endl;
    cout << "address of m = " << &m << endl;
    cout << "address pf k = " << &j << endl;

    // call by value/pointer/reference
    int u, v;
    u = 1, v = 2;
    swap_value(u, v);
    cout << u << " " << v << endl;
    swap_ptr(&u, &v);
    cout << u << " " << v << endl;
    swap_ref(u, v);
    cout << u << " " << v;

    // 배열과 배열명
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "a[0]의 주소: " << &arr[0] << endl;
    cout << "배열명의 주소: " << arr << endl;  // arr == int* arr = &arr[0]

    // 배열명이 포인터와 비슷하다면 역참조연산자도 사용가능할까? -> 가능하다
    cout << "*arr: " << *arr << " " << "arr[0]: " << arr[0] << endl;

    // 포인터와 배열 활용
    int* p_arr = &arr[1];  // p는 이제부터 배열 a랑 동일함
    cout << arr[1] << " " << p_arr[-1] << endl;

    // 배열명에 자연수를 더한다면?
    cout << *(p_arr + 2) << endl;

    // 포인터배열: 주소값을 담는 배열
    int pA = 1, pB = 2, pC = 3;
    int* pointArr[5];
    pointArr[0] = &pA;
    pointArr[1] = &pB;
    pointArr[2] = &pC;
    for (int i = 0; i < 3; i++) {
        cout << i << "번째 인덱스 값" << pointArr[i] << endl;
    }

    // NULL포인터 만들기
    int* nullPtr;
    nullPtr = 0;
    cout << nullPtr << endl;
    cout << &nullPtr << endl;
    // cout << *nullPtr << endl;  // zsh: segmentation fault -> 허용되지 않은 메모리 영역 접근시
    // 발생

    // 2차원 배열
    int twod[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};  // 3행4열
    int oned[12];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            oned[i * 4 + j] = twod[i][j];
        }
    }

    for (int i = 0; i < 12; i++) {
        cout << oned[i] << " ";
    }
    cout << endl;
    // 만약 배열연산을 통해 출력한다면?
    for (int i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            cout << *(twod[i] + j) << " ";
        }
    }
    cout << endl;

    // 동적 할당
    int* dynamic_arr = new int;         // size 1
    int* dynamic_bigArr = new int[10];  // size 1 이상

    int val;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        dynamic_bigArr[i] = val;
        cout << i + 1 << "번째 값: " << dynamic_bigArr[i] << endl;
    }

    // 동적메모리 해제
    delete dynamic_arr;
    delete[] dynamic_bigArr;

    // 2차원 배열 동적할당(3행4열)
    int** dynamic_table;
    dynamic_table = new int*[3];
    for (int i = 0; i < 3; i++) {
        dynamic_table[i] = new int[4];
    }

    dynamic_table[0][0] = 1;
    dynamic_table[0][1] = 2;
    dynamic_table[0][2] = 3;
    dynamic_table[0][3] = 4;
    dynamic_table[1][0] = 5;
    dynamic_table[1][1] = 6;
    dynamic_table[1][2] = 7;
    dynamic_table[1][3] = 8;
    dynamic_table[2][0] = 9;
    dynamic_table[2][1] = 10;
    dynamic_table[2][2] = 11;
    dynamic_table[2][3] = 12;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << *(dynamic_table[i] + j) << endl;
        }
    }

    // 2차원 동적 배열 해제
    for (int i = 0; i < 3; i++) {
        delete[] dynamic_table[i];  // 각 행에 대해 해제
    }
    delete[] dynamic_table;
    dynamic_table = nullptr;
    return 0;
}