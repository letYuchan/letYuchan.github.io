#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

struct bst {
    node* root = nullptr;  // 포인터타입에서만 사용되는 NULL값, NULL과 다르게 정수형 0으로
                           // 정의되어있지 않아 모호성문제 예방

    node* find(int value) { return find_impl(root, value); }  // 실제 구현은 find_impl로 구현

    void deleteValue(int value) { root = delete_impl(root, value); }
    `  // 실제 구현은 delete_impl로 구현

        public :
        // root노드에 삽입함수
        void
        insert(int value) {
        if (!root)                               // root노드가 비어있다면
            root = new node{value, NULL, NULL};  // root노드에 삽입
        else
            insert_impl(root, value);
    }
    void inorder() { inorder_impl(root); }  // 실제 구현은 private으로

    // 후속 노드 찾는 함수: 삭제할 노드 다음으로 큰 숫자를 가진 노드를 찾는 함수
    node* successor(node* start) {
        auto current = start->right;  // 오른쪽 서브트리로 이동한 후
        while (current && current->left)
            current = current->left;  // 왼쪽 원소가 존재할 때까지 계속 왼쪽으로 이동
        return current;               // 가장 작은 값의 노드를 반환
    }

   private:
    // 임의의 위치에 원소 삽입함수
    void insert_impl(node* current, int value) {
        if (value < current->data) {  // BST의 특징: 현재노드보다 값이 작으면 왼쪽으로 이동
            if (!current->left)  // 만약 왼쪽 자식이 존재하지 않는다면
                current->left = new node{value, NULL, NULL};
            else  // 만약 왼쪽 자식노드가 존재한다면 다시한번 왼쪽으로 이동
                insert_impl(current->left, value);
        } else {  // BST의 특징: 햔제 노드보다 값이 크다면 오른쪽으로 이동
            if (!current->right)  // 만약 오른쪽 자식이 존재하지 않는다면
                current->right = new node{value, NULL, NULL};
            else  // 만약 오른쪽 자식노드가 존재한다면 다시한번 오른쪽으로 이동
                insert_impl(current->right, value);
        }
    }
    // find함수
    node* find_impl(node* current, int value) {
        if (!current) {  // 애초에 root node조차 존재하지 않는다면
            cout << endl;
            return NULL;
        }

        if (current->data == value) {  // 찾고자하는 값이 root node라면
            cout << value << "을(를) 찾았습니다. " << endl;
            return current;
        }

        if (value < current->data) {  // value 값이 현재 노드 왼쪽에 있는 경우
            cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }
        cout << current->data
             << "에서 오른쪽으로 이동: ";  // value 값이 현재 노드 오른쪽에 있는 경우
        return find_impl(current->right, value);
    }

    // 중위순회 함수
    void inorder_impl(node* start) {
        if (!start) return;
        inorder_impl(start->left);   // 왼쪽 서브트리 탐색
        cout << start->data << " ";  // 현재노드 출력
        inorder_impl(start->right);  // 오른쪽 서브트리 탐색
    }

    // 원소 삭제 함수
    node* delete_impl(node* start, int value) {
        if (!start) return NULL;

        if (value < start->data)
            start->left = delete_impl(start->left, value);
        else if (value > start->data)
            start->right = delete_impl(start->right, value);
        else {
            if (!start->left)  // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            if (!start->right)  // 오른쪽 자식 노드만 없는 경우
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            // 자식 노드가 둘 다 있는 경우
            auto succNode = successor(start);
            start->data = succNode->data;

            // 오른쪽 하위 트리에서 후계자(successor)를 찾아 삭제
            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

int main() {
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "중위 순회: ";
    tree.inorder();  // BST의 모든 원소를 오름차순으로 출력합니다.
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder();  // BST의 모든 원소를 오름차순으로 출력합니다.
    std::cout << std::endl;

    if (tree.find(12))
        std::cout << "원소 12는 트리에 있습니다." << std::endl;
    else
        std::cout << "원소 12는 트리에 없습니다." << std::endl;
}
