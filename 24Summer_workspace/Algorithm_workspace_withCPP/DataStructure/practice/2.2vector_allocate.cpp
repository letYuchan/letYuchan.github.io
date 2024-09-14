#include <iostream>
#include <vector>

// 간단한 사용자 정의 할당자
template <typename T>
class MyAllocator {
   public:
    using value_type = T;

    // 기본 생성자
    MyAllocator() = default;

    // 다른 타입의 할당자와 호환성을 위한 템플릿 생성자
    template <typename U>
    MyAllocator(const MyAllocator<U>&) {}

    // 메모리 할당 함수
    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements." << std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));  // 메모리 할당
    }

    // 메모리 해제 함수
    void deallocate(T* p, std::size_t n) {
        std::cout << "Deallocating " << n << " elements." << std::endl;
        ::operator delete(p);  // 메모리 해제
    }
};

// 두 할당자가 동일한지 비교하는 연산자
template <typename T, typename U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&) {
    return true;
}

// 두 할당자가 동일하지 않은지 비교하는 연산자
template <typename T, typename U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&) {
    return false;
}

int main() {
    // 사용자 정의 할당자를 사용하는 벡터
    std::vector<int, MyAllocator<int>> vec = {1, 2, 3, 4, 5};

    std::cout << "Vector elements: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";  // 벡터 요소 출력
    }
    std::cout << std::endl;

    return 0;
}
