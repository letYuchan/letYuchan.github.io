#include <iostream>
#include <queue>
using namespace std;

// 회사 조직도 만들기 문제
// 한 상상는 두명의 부하직원을 거느릴 수 있음 -> 자식이 최대 2명이다 == 이진 트리 구조

// 노드
struct node {
    string position;
    node* first;
    node* second;
};

// root node == CEO
struct org_tree {
    node* root;

    // function of making root node
    static org_tree create_org_structure(const string& pos) {
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;
    }
    // 특정 직책에 해당하는 노드 반환 함수
    static node* find(node* root, const string& value) {
        if (root == NULL) return NULL;                         // root가 비었다면?
        if (root->position == value) return root;              // 찾고자하는게 CEO라면?
        auto firstFound = org_tree::find(root->first, value);  // 왼쪽 서브트리 탐색
        if (firstFound != NULL) return firstFound;
        return org_tree::find(root->second, value);  // 오른쪽 서브트리 탐색
    }
    // 부하직원 추가 함수
    bool addSubordinate(const string& manager,
                        const string& subordinate)  // 상사 직책과 부하직원 직책을 인자로 갖는 함수
    {
        auto managerNode = org_tree::find(root, manager);
        if (!managerNode) {
            cout << manager << "을(를) 찾을 수 없습니다: " << endl;
            return false;
        }
        if (managerNode->first && managerNode->second) {
            cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << endl;
            return false;
        }
        if (!managerNode->first)  // first노드가 없다면
            managerNode->first = new node{subordinate, NULL, NULL};
        else
            managerNode->second = new node{subordinate, NULL, NULL};
        cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << endl;

        return true;
    }

    // 레벨순서순회
    static void levelOrder(node* start) {
        if (!start) return;  // 트리가 비어있는 경우 함수를 종료

        queue<node*> q;  // 큐를 생성
        q.push(start);   // 시작 노드를 큐에 추가

        while (!q.empty()) {      // 큐가 비어있지 않은 동안 반복
            int size = q.size();  // 현재 레벨의 노드 수를 저장

            for (int i = 0; i < size; i++) {  // 현재 레벨의 모든 노드를 처리
                auto current = q.front();     // 큐의 앞에 있는 노드를 가져옴
                q.pop();                      // 큐에서 해당 노드를 제거

                cout << current->position << ", ";  // 현재 노드의 값을 출력

                if (current->first)
                    q.push(current->first);  // 현재 노드의 왼쪽 자식이 있다면 큐에 추가
                if (current->second)
                    q.push(current->second);  // 현재 노드의 오른쪽 자식이 있다면 큐에 추가
            }

            cout << endl;  // 현재 레벨의 노드 처리가 끝나면 줄바꿈을 출력
        }
    }
};

// 전위순회: VLR
static void preOrder(node* start) {
    if (!start) return;               // 비었으면 NULL이기 때문에 if(!NULL) == if(true)
    cout << start->position << ", ";  // 현재노드 출력
    preOrder(start->first);           // 왼쪽 서브트리를 VLR로 출력
    preOrder(start->second);          // 오른쪽 서브트리를 VLR로 출력
}

// 중위순회: LVR
static void inOrder(node* start) {
    if (!start) return;
    inOrder(start->first);            // 왼쪽 서브트리를 LVR로 출력
    cout << start->position << ", ";  // 현재노드 출력
    inOrder(start->second);           // 오른쪽 서브트리를 LVR로 출력
}

// 후위순회: LRV
static void postOrder(node* start) {
    if (!start) return;
    postOrder(start->first);          // 왼쪽 서브트리를 LRV로 출력
    postOrder(start->second);         // 오른쪽 서브트리를 LRV로 출력
    cout << start->position << ", ";  // 현재노드 출력
}

int main() {
    auto tree = org_tree::create_org_structure("CEO");
    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    preOrder(tree.root);
    cout << endl;
    inOrder(tree.root);
    cout << endl;
    postOrder(tree.root);
    cout << endl;
    org_tree::levelOrder(tree.root);
}