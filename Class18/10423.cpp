#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp; //튜플 선언

vector<int> parent; //부모 노드 배열

//Find 연산
int findParent(int x) { //부모 노드 찾기
    if (parent[x] < 0) { //부모 노드가 0보다 작으면
        return x; //x리턴
    }
    return parent[x] = findParent(parent[x]); //부모 노드 찾아서 리턴
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x); //정점의 부모 노드 찾기
    int py = findParent(y); //정점의 부모 노드 찾기

    if (px == py) { //부모 노드가 같으면
        return false; //사이클 발생
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py]; //루트에 추가
        parent[py] = px; //루트 갱신
    } else { //새로운 루트 py
        parent[py] += parent[px]; //루트에 추가
        parent[px] = py; //루트 갱신
    }
    return true;
}

int kruskal(int n, vector<tp> &edges) {
    int sum = 0, cnt = 0; //합, 간선 개수 초기화
    for (int i = 0; i < edges.size(); i++) { //간선 벡터 크기만큼 반복
        int w = get<0>(edges[i]); //간선 배열의 첫번째 인덱스
        int u = get<1>(edges[i]); //간선 배열의 두번째 인덱스
        int v = get<2>(edges[i]); //간선 배열의 세번째 인덱스
        if (!unionNodes(u, v)) { //사이클 생기는 경우
            continue; //다음 코드 진행
        }
        sum += w; //합 갱신
        cnt++; //개수 갱신
        if (cnt == n - 1) { //필요한 간선 모두 찾은 경우
            return sum; //합 리턴
        }
    }
    return 0;
}

/**
 * [전기가 부족해]
 *
 * 모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
 * 이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸
 *
 * -> 한번의 크루스칼 알고리즘으로 해결 가능
 */
int main() {
    int n, m, k, u, v, w; //도시의 수, 설치 가능한 케이블의 수, 발전소의 개수, 케이블의 정보

    //입력
    cin >> n >> m >> k; //도시의 수, 설치 가능한 케이블 수, 발전소 개수 입력
    vector<tp> edge; //간선 저장
    parent.assign(n + 1, -1);
    for (int i = 0; i < k; i++) { //발전소 개수만큼 반복하면서
        cin >> u; //케이블 정보 입력(도시)
        parent[u] = 0; //0번 정점과 연결됐다고 생각
    }
    while (m--) {
        cin >> u >> v >> w; //케이블 정보 입력
        edge.push_back({w, u, v}); //간선에 케이블 정보 저장
    }

    //연산
    sort(edge.begin(), edge.end()); //정렬

    //연산 & 출력
    cout << kruskal(n - k + 1, edge); //k개의 정점은 이미 연결된 상태이므로 n - k개의 간선만 선택해도 됨
    return 0;
}