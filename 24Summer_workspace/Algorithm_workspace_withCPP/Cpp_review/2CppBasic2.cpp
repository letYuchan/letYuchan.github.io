#include <fstream>
#include <iostream>

#include "2box_2.h"
#include "2box_3.h"

using namespace std;

// default parameter: 뒤에서부터 적어주기
int add(int a, int b = 0, int c = 0) { return a + b + c; }

// 피보나치수열
int fibonacciNum(int n = 1) {
    int sum = 0;
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacciNum(n - 1) + fibonacciNum(n - 2);

    return sum;
}
int main() {
    // ASCII 코드 이해하기
    int c0 = 'a';
    cout << c0 << endl;
    cout << (char)c0 << endl;

    // EOF를 이용한 Typical input loop
    int ival, sum = 0;
    while (cin >> ival,
           !cin.eof()) {  // cin.eof(): 파일의 끝인 EOF(맥에선 ctrl+d)을 만나면 true반환
        sum += ival;
    }

    cout << "Sum : " << sum << endl;

    // file management
    // ifstream: 파일을 읽어올 때
    // ofstream: 파일을 기록할 때
    // fstream: 둘 다 가능
    // ifstream fs_1("a.txt");                    // 파일이 존재하지 않음
    // ofstream fs_1("b.txt");                    // 파일을 새로 생성
    // fstream out_fs("test.txt", fstream::out);  // 파일 새로 생성

    // // fs_1 >> i;
    // fs_2 << "ABCD";
    // out_fs << "EFG";
    // if (fs_1.is_open())
    //     cout << i << endl;
    // else
    //     cout << "File is not found" << endl;
    // // fs_1.close();
    // fs_2.close();
    // out_fs.close();

    // 헤더파일 핸들링
    Box box;
    box.height = 3;
    box.width = 5;
    box.length = 7;
    box.print();

    // default parameter
    cout << add(1) << endl;
    cout << add(1, 2, 3) << endl;

    // 재귀함수: 피보나치 수열
    cout << fibonacciNum(10) << endl;

    return 0;
}