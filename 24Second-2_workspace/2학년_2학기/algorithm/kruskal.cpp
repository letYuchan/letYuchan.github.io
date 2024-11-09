#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 간선을 저장하는 구조체
struct Edge {
    int u, v, weight; // u: 시작점, v: 끝점, weight: 해당 점을 잇는 간선의 가중치
    
    // 간선의 가중치를 기준으로 비교하는 함수(연산자 오버로딩)
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 부모 노드를 찾는 함수 (경로 압축 기법 사용)
// 대표노드(루트노드)를 찾는 함수로서, 같은 집합(트리)에 속하는지 확인
// 경로압축으로 탐색을 더 빠르게
// ex) 1(root)->2->3->4 의 트리모양일 때, findParent(4)를 실행하면 4에서부터 1까지 거슬러 올라가 
// 4의 루트노드를 확인하고 그 중간과정의 노드(2, 3)들도 자동으로 부모노드를 1로 기록하게끔 만듦
int findParent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]); // 재귀적 호출을 통한 u의 부모노드를 찾음
    }
    return parent[node];
}

// 두 노드를 같은 집합으로 합치는 함수 (유니온 바이 랭크) -> 랭크(깊이)가 작은 트리를 랭크(깊이)가 큰 트리에 붙임 
// 만일 두 트리의 랭크가 같다면, 하나를 다른 트리에 붙이고 랭크를 1증가
// ex) 노드 1, 노드 2(뚤다 랭크 0) -> 노드1에 노드2를 붙임 -> 노드1의 랭크+1, 2는 여전히 0 but 노드1에 속함
// 이 과정을 통해서 가중치가 작은 간선들을 순환이 없도록 하는 MST(최소신장트리)를 제작
void unionNodes(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    
    // 두 집합의 랭크를 비교해 작은 집합을 큰 집합에 연결
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // 정점의 개수와 간선의 개수 입력 받음
    
    vector<Edge> edges(m);  // 간선들을 저장하는 벡터
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;  // 간선 정보 입력
    }
    
    // 가중치 순으로 간선 정렬
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n);  // 각 노드의 부모 노드 저장
    vector<int> rank(n, 0); // 각 집합의 랭크(트리의 높이) 저장 (처음엔 모두 0), 랭크가 높으면 깊이가 깊어 탐색시 많은 시간이 걸림
    // 시각적으로 우리가 트리구조를 만든다고 보면 됨

    // 모든 노드를 자기 자신을 부모로 초기화
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int totalWeight = 0;  // 최소 신장 트리의 총 가중치
    vector<Edge> mst;     // 최소 신장 트리에 포함된 간선을 저장할 벡터
    
    // 간선들을 하나씩 확인하면서 최소 신장 트리를 만듦
    for (Edge& edge : edges) {
        int rootU = findParent(parent, edge.u); 
        int rootV = findParent(parent, edge.v); // 두 정점 U, V가 서로 다른 집합에 속해있는지 확인 -> 루트노드를 찾아서 판별
        
        // 사이클이 생기지 않으면 간선을 최소 신장 트리에 추가
        if (rootU != rootV) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionNodes(parent, rank, rootU, rootV);
        }
    }
    
    // 간선을 출력
    for (Edge& edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
    
    // 최소 신장 트리의 총 가중치 출력
    cout << totalWeight << endl;
    
    return 0;
}
