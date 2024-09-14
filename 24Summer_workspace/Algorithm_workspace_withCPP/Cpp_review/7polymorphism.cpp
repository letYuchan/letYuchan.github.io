#include <iostream>
using namespace std;
// compile time function overloading
void Func(int one, int two = 2, int three = 3);
void Func(float fv);
void Func(int one, int two, int three) {
    cout << "int one = " << one << endl;
    cout << "int two = " << two << endl;
    cout << "int three = " << three << endl;
    cout << "----------------" << endl;
}

void Func(float fv) {
    cout << "float one = " << fv << endl;
    cout << "----------------" << endl;
}

// 상속관계에서 포인터가 가리키는 객체와 상관없이 포인터 타입의 함수만 사용가능
class First {
   public:
    void MyFunc() { cout << "FirstFunc" << endl; }
};
class Second : public First {
   public:
    void MyFunc() { cout << "SecondFunc" << endl; }
};
class Third : public Second {
   public:
    void MyFunc() { cout << "ThirdFunc" << endl; }
};

// virtual을 쓰는 가상함수를 오버라이딩 한다면 내가 가리키는 객체의 함수를 사용할 수
// 있음(동적바인딩)
class Animal {
   public:
    virtual void eat() { cout << "I eat like a generic Animal.\n"; }
};

class Wolf : public Animal {
   public:
    void eat() { cout << "I eat like a wolf!\n"; }
};

class Fish : public Animal {
   public:
    void eat() { cout << "I eat like a fish\n"; }
};

class OtherAnimal : public Animal {};

class AbstractClass {
   public:
    int num;
    AbstractClass(int n) : num(n) { cout << "num 초기화 " << endl; }
    virtual void print() = 0;
};

class DerivedAbsClass : public AbstractClass {
   public:
    DerivedAbsClass(int dn) : AbstractClass(dn) {};
    void print() { cout << "success overriding!, num: " << num << endl; }
};

// 가상소멸자를 통한 올바른 소멸자 실행
class First2 {
   public:
    int num;
    First2(int n) : num(n) { cout << "First()" << endl; }
    virtual ~First2() { cout << "~First()" << endl; }
};

class Second2 : public First2 {
   public:
    Second2(int sn) : First2(sn) { cout << "Second()" << endl; }
    virtual ~Second2() { cout << "~Second()" << endl; }
};

int main() {
    Func(10, 20, 30);
    Func(1);
    Func(1.9f);

    Third* tptr = new Third();
    Second* sptr = tptr;
    First* fptr = sptr;
    tptr->MyFunc();
    sptr->MyFunc();
    fptr->MyFunc();  // 모두 각각의 타입에 맞는 Myfunc() 실행(가리키는건 모두 tptr이지만!)

    Animal* animal[4];
    animal[0] = new Animal();
    animal[1] = new Wolf();
    animal[2] = new Fish();
    animal[3] = new OtherAnimal();
    for (int i = 0; i < 3; i++) {
        animal[i]->eat();
    }

    DerivedAbsClass drv(8);
    drv.print();

    Second2 obj(5);
    return 0;
}
