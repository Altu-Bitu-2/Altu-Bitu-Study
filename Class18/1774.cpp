#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

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

double kruskal(int v, vector<tp> &edge) {
    double sum = 0; //합 초기화
    int cnt = 0; //간선 개수 초기화

    for (int i = 0; i < edge.size(); i++) { //간선 배열 크기만큼 반복
        double cost = get<0>(edge[i]); //간선 배열의 0번째 인덱스 가져오기
        int x = get<1>(edge[i]); //간선 배열의 1번째 인덱스 가져오기
        int y = get<2>(edge[i]); //간선 배열의 2번째 인덱스 가져오기

        if (!unionNodes(x, y)) { //사이클이 생기면
            continue; //다음 코드 진행
        }
        sum += cost; //합에 비용 추가 갱신
        cnt++; //개수 갱신
        if (cnt == v - 1) {//필요한 간선 모두 찾은 경우
            return sum; //합 리턴
        }
    }
    return 0;
}

/**
 * [우주신과의 교감]
 *
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0; //우주신들의 개수, 통로의 개수, 좌표정보
    double x, y;

    //입력
    cin >> n >> m; //우주신 개수, 통로 개수 입력받기
    parent.assign(n + 1, -1); //부모노드 배열 -1로 초기화
    vector<tp> edge; //간선 배열 선언
    vector<ci> star(n + 1); //

    for (int i = 1; i <= n; i++) { //개수만큼 반복
        cin >> x >> y; //좌표 입력받기
        for (int j = 1; j < i; j++) {
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j}); //간선 배열에 좌표거리 계산 저장
        }
        star[i] = {x, y}; //좌표 저장
    }

    //연산
    while (m--) { //통로 개수만큼 반복
        cin >> a >> b; //이미 연결된 통로 좌표 입력
        if (unionNodes(a, b)) { //이미 연결된 통로
            v++; //개수 증가
        }
    }
    sort(edge.begin(), edge.end()); //간선 배열 정렬

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n - v, edge);
    return 0;
}