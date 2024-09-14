#include <algorithm>
#include <iostream>  // 표준 출력 및 입력을 위한 스트림 클래스 제공
// cin, cout, cerr, clog, istream, ostream, iostream
#include <sstream>  // 문자열 스트림을 위한 클래스 제공
// stringstream, istringstream, ostreainstream
using namespace std;

// Exercise01: 크기를 동적으로 지정할 수 있는 배열 만들기 -> 학급관리 프로그램에서 활용
template <typename T>
class dynamic_array {
    T* data;
    size_t n;  // C&Cpp 표준 라이브러리에 정의된 데이터 타입으로 stddef.h에 정의되어있음
    // 부호 없는 정수형 값을 나타낼 때 사용->64bit system기준 8byte크기
    // 보통 배열의 크기를 지정하거나 반복문에서 배열의 인덱스를 접근할때 이용

   public:
    // 생성자
    dynamic_array(int n) {
        this->n = n;      // 사이즈의 크기를 매개변수로 받아온 n으로 설정
        data = new T[n];  // 동적으로 data라는 이름의 배열 생성
    }

    // 복사생성자: 객체가 다른객체로부터 초기화될때 호출되는 생성자
    dynamic_array(const dynamic_array<T>& other) {
        n = other.n;
        data = new T[n];  // 새롭게 메모리공간에 할당해줌으로써 깊은복사 구현

        for (int i = 0; i < n; i++) data[i] = other[i];
    }

    // [] 연산자 정의
    T& operator[](int index) { return data[index]; }

    const T& operator[](int index) const { return data[index]; }

    // at함수 정의
    T& at(int index) {
        if (index < n) return data[index];
        throw "Index out of range";
    }

    // 배열 size 반환함수
    size_t size() const { return n; }

    // 메모리 해제하는 소멸자 정의
    ~dynamic_array() {
        delete[] data;  // 메모리 릭 방지
    }

    // 반복자 관련 함수 정의
    // const버전을 한번 더 정의하는 이유는 상수객체와 비상수객체에 대하여 유연하게 동작할 수 있도록
    // 하기 위함
    // 컴파일러가 컴파일 시간에 무엇을 쓸지 결정
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string to_string(const std::string& sep = ", ") {
        if (n == 0) return "";

        std::ostringstream os;  // sstream 헤더에 정의된 class로 문자열 스트림을 관리하는데 사용된다
        os << data[0];  // 첫번째 요소만 단독으로 출력한 이유는 sep을 요소들 사이에서만 사용하기
                        // 위함

        for (int i = 1; i < n; i++) os << sep << data[i];

        return os.str();  // str은 ostringstream 클래스의 멤버함수로 현재 스트림 버퍼의 내용을
                          // string 객체로반환
    }
};

struct student {
    std::string name;
    int standard;
};

ostream& operator<<(std::ostream& os, const student& s) {
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
    int nStudents;
    cout << "1반 학생 수를 입력하세요: ";
    cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++) {
        string name;
        int standard;
        cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    // 배열 크기보다 큰 인덱스의 학생에 접근
    try {
        // 아래 주석을 해제하면 프로그램이 비정상 종료합니다.
        // class1[nStudents] = student {"John", 8}; // 예상할 수 없는 동작

        class1.at(nStudents) = student{"John", 8};  // 예외 발생
    } catch (...) {  // 모든 예외를 잡아내기위해 ...사용 -> catch-all handler
        cout << "예외 발생!" << std::endl;
    }

    // 깊은 복사
    auto class2 = class1;
    cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

    // 두 학급을 합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << std::endl;

    cout << class1[1];
    return 0;
}
