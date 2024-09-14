#include <iostream>
using namespace std;

class Box {
   public:
    Box() : height(0), width(0), length(0), area(0), volume(0) {}
    void set(double h, double w, double l) {
        height = h;
        width = w;
        length = l;
        area = 2 * (h * w + w * l + l * h);
        volume = h * w * l;
    }
    // 복사생성자: 객체를 복사(할당)할 때 사용
    Box(const Box& b)
        : width(b.width), height(b.height), length(b.length), area(b.area), volume(b.volume) {
        cout << "Copy constructor is executed" << endl;
    }
    void print() const {
        cout << "Box: (" << height << "," << width << "," << length << ")" << endl;
        cout << "Area: " << area << endl;
        cout << "Volume: " << volume << endl;
    }

    // 은닉화를 통한 데이터 일관성 지킴
   private:
    double height, width, length;
    double area, volume;
};

// friend 활용하기
class X {
   public:
    X() {}
    friend class Y;
    friend int f(void);

   private:
    int a, b, c;
};

class Y {
   public:
    Y() {}
    void func(X& var) {
        var.a = var.b = var.c = 0;
        cout << var.a << " " << var.b << " " << var.c << endl;
    }
};

// 연산자 오버로딩
class Array {
   public:
    // constructor
    Array(size_t num) : size(num) {
        cout << "Constructor 0" << endl;
        ptr = new int[num];
    }
    // copy constructor
    Array(const Array& arr) : size(arr.size) {
        cout << "Copy constructor" << endl;
        ptr = new int[size];
        for (size_t i = 0; i < size; ++i) ptr[i] = arr.ptr[i];
    }
    // destructor
    ~Array() {
        std::cout << "Destructor Start" << std::endl;
        if (ptr != NULL) delete[] ptr;
        std::cout << "Destructor End" << std::endl;
    }
    // assingment operator overloading
    Array& operator=(const Array& arr) {
        std::cout << "Assignment" << std::endl;
        if (ptr != NULL) delete[] ptr;
        size = arr.size;
        ptr = new int[arr.size];
        for (std::size_t i = 0; i < size; ++i) ptr[i] = arr.ptr[i];
        return (*this);
    }
    int* ptr;
    size_t size;
};
int f(void) {
    X x;
    return x.a + x.b + x.c;
};
int main() {
    Box box1;
    box1.set(1, 2, 3);
    box1.print();
    // box1.height = 30; // private -> 접근불가능

    X x;
    Y y;
    y.func(x);
    int sum = f();
    cout << sum << endl;

    Box box2;
    box2.set(5, 5, 5);
    Box box3(box2);  // 복사생성자 실행
    Box box4;
    box4 = box2;      // 끊어치기 하면 할당연산자 실행
    Box box5 = box2;  // 복사생성자 실행

    Array array(5);
    Array array0(10), array1(10);
    array1 = array0 = array;
}