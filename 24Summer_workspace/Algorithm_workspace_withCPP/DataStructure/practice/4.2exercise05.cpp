#include <algorithm>
#include <iostream>

// 사용자 정의 forward_list 확장 컨테이너 만들기

// 단일 노드 클래스 정의
struct singly_11_node {
    int data;
    singly_11_node* next;
};

// singly_11 구현
class singly_11 {
   public:
    using node = singly_11_node;  // using: C++11부터 도입된 일종의 템플릿 키워드(==tyoedef) 긴
                                  // 형식의 이름을 짧게 별칭으로 만듦
    using node_ptr = node*;

    // 반복자 구현 -> 생성자 & 접근자
    // 주의: C언어처럼 선언이 사용할 시점보다 먼저 앞서야함(node_ptr이
    struct singly_11_iterator {
       private:
        node_ptr ptr;

       public:
        singly_11_iterator(node_ptr p) : ptr(p) {}  // 생성자함수
        int& operator*() { return ptr->data; }      // *연산자 사용시 해당하는 data 반환
        node_ptr get() { return ptr; }              // 반복자 반환
        // 증감연산자 구현
        singly_11_iterator operator++()  // 선행
        {
            ptr = ptr->next;
            return *this;
        }

        singly_11_iterator operator++(int) {  // int -> 후위와 전위를 구분시키기 위한 용도
            singly_11_iterator result = *this;
            ++(*this);      // 증가는 시키고
            return result;  // 본래 상태를 반환
        }

        // 관계 연산자 정의
        friend bool operator==(const singly_11_iterator& left, const singly_11_iterator& right) {
            return left.ptr == right.ptr;
        }

        friend bool operator!=(const singly_11_iterator& left, const singly_11_iterator& right) {
            return left.ptr != right.ptr;
        }
    };
    // push_front와 pop_front 구현하기

    void push_front(int val) {
        auto new_node = new node{val, NULL};
        if (head != NULL)           // 빈 리스트가 아니라면
            new_node->next = head;  // 새롭게 추가한 노드의 포인터를 head노드에 연결
        head = new_node;            // head를 새롭게 갱신
    }

    void pop_front() {
        auto first = head;  // 첫번째 노드를 가리키는 포인터 저장
        // 만약 헤더노드가 비어있지 않다면
        if (head) {
            head = head->next;  // head는 첫번째 노드를 가리킴, 그것의 next()는 두번째 노드임 즉,
                                // 헤드는 두번째 노드를 가리킴
            delete first;  // 첫번째 노드를 가리키던 포인터의 메모리 해제 -> memory leak 방지
        }
    }

    // begin(), end()
    singly_11_iterator begin() { return singly_11_iterator(head); }
    singly_11_iterator end() { return singly_11_iterator(NULL); }
    singly_11_iterator begin() const { return singly_11_iterator(head); }
    singly_11_iterator end() const { return singly_11_iterator(NULL); }

    singly_11() = default;  // 기본생성자를 명시적으로 선언

    // 복사 생성자
    singly_11(const singly_11& other) : head(NULL) {  // 복사전 리스트를 빈 상태로 만듦
        // 복사하고자 하는 리스트가 빈 리스트가 아니라면
        if (other.head) {
            // 헤더를 새롭게 만들어 초기화하고, 첫 번째 노드를 준비
            head = new node{0, NULL};

            // 현재 리스트의 현재 노드를 가리키는 포인터(새 리스트의 현재 노드를 추적)
            auto cur = head;

            // 복사할 리스트의 시작을 가리키는 반복자
            auto it = other.begin();

            // 복사 시작
            while (true) {
                // 현재 노드(첫번째 노드)에 other의 첫번째 노드 복사
                cur->data = *it;

                // 다음 노드로 이동하기 위해 반복자 증가
                auto tmp = it;
                ++tmp;

                // 복사할 리스트의 끝에 도달하면 루프 종료
                if (tmp == other.end()) break;

                // 다음 노드를 새롭게 할당하고 현재 노드를 다음 노드로 이동
                cur->next = new node{0, NULL};
                cur = cur->next;

                // 복사할 리스트의 다음 노드를 가리키도록 반복자 이동
                it = tmp;
            }
        }
    }
    singly_11(const std::initializer_list<int>& ilist) : head(NULL) {
        for (auto it = ilist.begin(); it != ilist.end(); ++it) {
            push_front(*it);
        }
    }

   private:
    node_ptr head;  // 첫번째 노드를 가리키기 위한 시작 포인터(얘 자체론 실질적인 값이 없음)
};

int main() {
    singly_11 sll = {1, 2, 3};
    sll.push_front(0);

    std::cout << "첫 번째 리스트: ";
    for (auto i : sll) std::cout << i << " ";  // 출력: 0 3 2 1
    std::cout << std::endl;

    auto sll2 = sll;
    sll2.push_front(-1);
    std::cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
    for (auto i : sll2) std::cout << i << ' ';  // 출력: -1 0 1 2 3
    std::cout << std::endl;

    std::cout << "깊은 복사 후 첫 번째 리스트: ";

    for (auto i : sll) std::cout << i << ' ';  // 출력: 0 3 2 1
    std::cout << std::endl;
}