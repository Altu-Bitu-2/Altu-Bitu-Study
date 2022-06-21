#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

//위상정렬
vector<int> topologicalSort(int t, int n, vector<int> &indegree, matrix &resources, matrix &graph) {
    queue<pair<int, int>> q; //first:진입차수가 0인 건물, second:시간
    vector<bool> check(n + 1, false); //생산 자원 체크 배열
    vector<int> result; //결과

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //진입 차수가 0이라면
            q.push({i, 0}); //큐에 쌍으로 저장
        }
    }
    while (!q.empty()) { //큐가 비어있지 않는 동안
        int x = q.front().first; //큐 맨 앞 쌍의 첫번째 원소 저장
        int curr_t = q.front().second; //큐 맨 앞 쌍의 두번째 원소 저장
        q.pop(); //맨 앞 쌍 pop

        if (curr_t > t) { //t보다 크면
            break; //while문 탈출
        }
        result.push_back(x); //x값을 결과 배열에 저장
        for (int i = 0; i < resources[x].size(); i++) { //자원 배열의 크기만큼
            int resource = resources[x][i]; //건물의 자원번호 저장
            if (check[resource]) { //이미 해당 자원이 체크되어있으면 (이미 true)
                continue; //다음 코드 진행
            }
            check[resource] = true; //자원을 체크해줌(true)
            for (int j = 0; j < graph[resource].size(); j++) {
                int building = graph[resource][j]; //건물 정보 저장
                indegree[building]--;//연결된 정점의 진입차수를 1씩 감소
                if (!indegree[building]) { //연결된 정점의 진입차수가 0이 되었다면
                    q.push({building, curr_t + 1}); //큐에 쌍으로 저장해줌
                }
            }
        }
    }
    return result;
}

/**
 * [쿠키런 킹덤]
 *
 * 건물마다 필요로 하는 자원의 관계를 그래프로 표현하여 위상정렬을 사용해 제한 시간(t) 이내에 지을 수 있는 건물들을 구함
 * - 그래프 관계: 필요로 하는 자원 -> 건물
 * - 이때, 각 건물마다 생산하는 자원이 여러 개이므로 위상정렬에서 연결된 정점의 진입차수를 감소하는 부분에서 생산하는 자원을 모두 검사해야 함
 * - 위 과정에서 서로 다른 건물끼리 생산하는 자원이 겹칠 수 있으므로, 이미 생산한 자원은 체크를 해줌
 * - 위상정렬하다 제한 시간을 넘으면 종료
 */
int main() {
    //속도 증가
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, cnt, resource, building; //자원의 가짓수, 이미 지어진 건물의 개수, 제한 시간, 자원 번호, 지어지지 않은 건물

    //입력
    cin >> n >> m >> t; //자원의 가짓수, 이미 지어진 건물의 개수, 제한 시간 입력
    vector<int> indegree(n + 1, 0); //각 정점의 진입 차수
    matrix graph(n + 1, vector<int>(0)); //그래프 선언
    matrix resources(n + 1, vector<int>(0)); //각 건물이 생산하는 자원들
    for (int i = 0; i < m; i++) { //이미 지어진 건물
        cin >> building; //입력
    }
    for (int i = 1; i <= n; i++) { //건물이 생산하는 자원
        cin >> cnt; //자원의 가짓수
        while (cnt--) {
            cin >> resource; //자원 번호 입력
            resources[i].push_back(resource); //자원배열에 번호 저장
        }
    }
    for (int i = 0; i < n - m; i++) { //건물마다 필요한 자원
        cin >> building >> cnt; //아직 지어지지 않은 건물, 필요로 하는 자원 가짓수 입력
        indegree[building] = cnt; //진입차수 갱신
        while (cnt--) {
            cin >> resource; //자원 번호 입력
            graph[resource].push_back(building); //그래프에 저장
        }
    }

    //연산
    vector<int> result = topologicalSort(t, n, indegree, resources, graph); //위상정렬 결과 저장
    sort(result.begin(), result.end()); //오름차순 정렬

    //출력
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}