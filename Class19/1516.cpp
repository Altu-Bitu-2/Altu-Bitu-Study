#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int> &t, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q; //진입차수가 0인 정점 관리
    vector<int> dp(n + 1, 0); //각 건물을 완성하는데 걸리는 최소 시간

    for (int i = 1; i <= n; i++) {
        dp[i] = t[i]; //dp 배열 초기화
        if (!indegree[i]) { //진입 차수가 0이면
            q.push(i); //큐에 푸시
        }
    }
    while (!q.empty()) { //큐가 비어있지 않는 동안
        int node = q.front(); //큐의 front를 노드에 저장
        q.pop(); //front값 pop해줌

        for (int i = 0; i < graph[node].size(); i++) { //노드 크기만큼 반복하면서
            int next_node = graph[node][i]; //다음 노드값 저장
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]); //다음 정점의 최소 시간 계산

            indegree[next_node]--; //연결된 정점의 진입차수 1씩 감소
            if (!indegree[next_node]) { //진입차수가 0이면
                q.push(next_node); //큐에 푸시
            }
        }
    }
    return dp; //dp배열 리턴
}

/**
 * [게임 개발]
 *
 * - ACM Craft (1005) 와 동일한 문제
 * - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
 */

int main() {
    int n, input; //건물 종류의 수

    //입력
    cin >> n; //건물 종류의 수 입력
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 배열 선언
    for (int i = 1; i <= n; i++) { //건물 수만큼 반복하면서
        cin >> t[i]; //각 건물을 짓는데 걸리는 시간
        while (cin >> input) { //숫자 입력받기
            if (input == -1) { //-1이면
                break; //끝
            }
            graph[input].push_back(i); //먼저 지어저야하는 건물들 수 그래프에 저장
            indegree[i]++; //정점의 진입차수 증가
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph); //위상정렬 결과 저장

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}