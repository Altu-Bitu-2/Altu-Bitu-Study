#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

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
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() {
    int n, m, a, b, c; //집의 개수, 길의 개수, 길의 정보

    //입력
    cin >> n >> m; //집의 개수, 길의 개수
    vector<tp> edge; //간선 배열 선언
    parent.assign(n + 1, -1); //부모 노드 배열 -1로 초기화 선언
    while (m--) { //길의 개수 만큼 반복
        cin >> a >> b >> c; //길의 정보 입력
        edge.push_back({c, a, b}); //간선배열에 길 정보 추가
    }

    //연산
    sort(edge.begin(), edge.end()); //정렬

    //연산&출력
    cout << kruskal(n - 1, edge); //크루스칼 알고리즘
    return 0;
}