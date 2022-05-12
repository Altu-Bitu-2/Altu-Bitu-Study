#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq; //우선순위 큐 선언
    vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장

    dist[start] = 0; //시작 정점 초기화
    pq.push({0, start}); //우선순위큐에 푸시
    int cnt = 0, t = 0; //개수, 시간 0으로 초기화
    while (!pq.empty()) { //큐가 비어있지 않는 동안
        int weight = pq.top().first; //현재 정점까지의 경로
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop(); //큐에서 빼줌

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점인 경우
            continue; //계속
        }
        cnt++; //개수 증가
        t = weight; //시간 갱신
        for (int i = 0; i < graph[node].size(); i++) { //그래프의 해당 노트 크기만큼 반복
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 현재 노드를 거쳐 다음 정점까지 가는 경로값
            if (next_weight < dist[next_node]) { //다음 정점까지의 경로값이 더 작으면
                dist[next_node] = next_weight; //최단 경로 값 갱신
                pq.push({next_weight, next_node}); //우선순위큐에 다음 정점, 거리 추가
            }
        }
    }
    return {cnt, t}; //개수, 시간 리턴
}

/**
 * [해킹]
 *
 * - 기본적인 다익스트라 문제
 * - 다익스트라 내에서 이미 더 짧은 경로가 존재하는 정점은 탐색에서 배제하면서, 탐색하는 정점의 수와 마지막 시간을 저장
 *
 * !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
 */

int main() {
    int t, n, d, c, a, b, s; //테스트케이스, 컴퓨터개수, 의존성 개수, 해킹당한 컴퓨터 번호, 반복개수, 정수(의존하는 컴퓨터 정보), 감염되는데 걸린 시간

    //입력
    cin >> t; //테스트케이스 입력
    while (t--) { //테스트케이스 만큼 반복
        cin >> n >> d >> c; //컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터 번호 입력받음
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) { //의존성 개수만큼 반복
            cin >> a >> b >> s; //컴퓨터 입력받음
            graph[b].push_back({a, s}); //그래프에 방향과 함께 감염되는 컴퓨터와 감염 시간 저장
        }

        //연산
        ci ans = dijkstra(c, n, graph); //다익스트라 연산

        //출력
        cout << ans.first << ' ' << ans.second << '\n'; //출력
    }
    return 0; //리턴
}