#pragma warning(disable : 4996)
#include <string.h>

#include <iostream>
using namespace std;

// 기본 상속 알아보기
class Person {
   private:
    int age;
    char name[50];

   public:
    Person(int myage, const char* myname) : age(myage) { strcpy(name, myname); }
    void WhatYourName() const { cout << "My Name is " << name << endl; }
    void HowOldAreYou() const { cout << "I am " << age << " years old" << endl; }
};

class Student : public Person {
   private:
    char major[50];

   public:
    Student(const char* myname, int myage, const char* mymajor) : Person(myage, myname) {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const {
        WhatYourName();
        HowOldAreYou();
        cout << "My Major is " << major << endl << endl;
    }
};

// 부모 자식간 생성자 몇 소멸자 구동 순서
class Base {
   public:
    Base(int n) {
        cout << "부모 class의 생성자 실행" << endl;
        baseVal = n;
    }
    ~Base() { cout << "부모 class의 소멸자 실행" << endl; }
    void showBaseData() { cout << "Data: " << baseVal << endl; }

   private:
    int baseVal;
};

class Derived : public Base {
   public:
    Derived(int n) : Base(n) {
        cout << "자식 class의 생성자 실행" << endl;
        derivedVal = n;
    }
    ~Derived() { cout << "자식 class의 소멸자 실행" << endl; }
    void showDerivedData() { cout << "Data: " << derivedVal << endl; }

   private:
    int derivedVal;
};

// 소멸자함수 실행을 확인하기 위해 fn함수를 통해서 객체 생성
void fn() {
    // 생성자는 부모부터 소멸자는 자식부터 실행
    Derived derived(5);
    derived.showDerivedData();
    derived.showBaseData();
}

// class 접근라벨에 따른 상속
class B1 {
   public:
    B1(int n1, int n2, int n3) : num1(n1), num2(n2), num3(n3) { cout << "B1 생성자 실행" << endl; }
    int num1;

   protected:
    int num2;

   private:
    int num3;
};

class D1 : protected B1 {
   public:
    D1(int n1, int n2, int n3) : B1(n1, n2, n3) {};
    void showD1ProtectedNum2() { cout << "num2: " << num2 << endl; }
};
class D2 : private D1 {
   public:
    D2(int n1, int n2, int n3) : D1(n1, n2, n3) {};

    void showD2ProtectedNum2() { cout << "D2.Num2: " << num2 << endl; }
};
class D3 : private B1 {
   public:
    D3(int n1, int n2, int n3) : B1(n1, n2, n3) {}
    void showD3PrivatedNum3() { cout << "D3.num3: " << num3 << endl; }  // num3는 접근불가능 라벨
};
int main() {
    Student std1("lee", 24, "Computer eng.");
    std1.WhoAreYou();
    Student std2("Yoon", 21, "Electronic eng.");
    std2.WhoAreYou();

    fn();

    D1 d1(1, 2, 3);
    d1.showD1ProtectedNum2();  // D1은 B1을 protected으로 상속받았기 때문에 protected 멤버인 num2도
                               // protected로 받아옴
    D2 d2(4, 5, 6);
    d2.showD2ProtectedNum2();  // num2는 private으로 상속되지만 D1에서 num2에 접근가능하므로 자식의
                               // 자식 또한 접근가능
    D3 d3(7, 8, 9);
    d3.showD3PrivatedNum3();
    return 0;
}
