#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    priority_queue<int, vector<int>, greater<>> pq; //최소힙
    vector<int> result; //결과

    for (int i = 1; i <= n; i++) { //크기만큼 반복하면서
        if (!indegree[i]) { //진입차수가 0이면
            pq.push(i); //최소힙에 저장
        }
    }
    while (!pq.empty()) { //최소힙이 비어있지 않으면
        int node = pq.top(); //최솟값(top)을 노드에 저장하고
        pq.pop(); //pop해줌

        result.push_back(node); //정점 순서결과 배열에 저장
        for (int i = 0; i < graph[node].size(); i++) { //노드 크기만큼 반복하면서
            int next_node = graph[node][i]; //다음 노드 정보 저장
            indegree[next_node]--; //진입차수 감소
            if (!indegree[next_node]) { //다음 노드의 진입차수가 0이면
                pq.push(next_node); //최소힙에 다음노드 저장
            }
        }
    }
    return result; //결과 리턴
}

/**
 * [문제집]
 *
 * - 조건 1, 2까지는 평범한 위상정렬
 * - 조건 3 "가능하면 쉬운 문제부터 풀어야 한다." -> 위상정렬 시, 정점이 작은 순서부터
 * - 조건 3을 만족시키기 위해, 진입차수가 0인 정점을 담는 컨테이너로 우선순위 큐 사용
 */

int main() {
    int n, m, a, b; //문제의 수, 좋은 문제에 대한 정보의 개수, 순서쌍

    //입력
    cin >> n >> m; //문제 수, 정보 개수 입력받기
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 배열 선언
    while (m--) { //개수만큼 반복하면서
        cin >> a >> b; //순서쌍 입력받기
        graph[a].push_back(b); //a->b 저장
        indegree[b]++; //진입차수 증가
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph); //위상정렬 결과 저장

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}