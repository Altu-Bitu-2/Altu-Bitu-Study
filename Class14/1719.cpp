#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

//플로이드 워셜
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) { //1부터 n까지 반복
        for (int i = 1; i <= n; i++) { //1부터 n까지 반복
            for (int j = 1; j <= n; j++) { //1부터 n까지 반복
                int new_dist = graph[i][k] + graph[k][j]; //i->k->j까지의 거리 저장
                if (new_dist < graph[i][j]) { //i->j까지의 거리보다 i->k->j까지의 거리가 짧다면
                    graph[i][j] = new_dist; //i->j 거리 갱신
                    table[i][j] = table[i][k]; //i->k의 중간 경로로 갱신
                }
            }
        }
    }
}

/**
 * [택시]
 *
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 14을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */

int main() {
    int n, m, s, d, c; //집하장의 개수, 집하장 간 경로 개수, 두개의 집하장 번호, 필요한 시간

    //입력
    cin >> n >> m; //집하장 개수, 경로 개수 입력받기
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //그래프 선언
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //경로표 선언
    for (int i = 1; i <= n; i++) {//1부터 n까지 반복하면서
        graph[i][i] = 0; //그래프에 경로값 0으로 초기화
    }

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //두개의 집하장 번호, 필요한 시간 입력받기
        //간선 정보
        graph[s][d] = graph[d][s] = c; //무뱡향이므로 양쪽에 같은 값(시간) 저장

        //경로 정보
        table[s][d] = d; //경로표 번호 저장
        table[d][s] = s; //경로표 번호 저장
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) {//행렬 1부터 n까지 반복하면서
        for (int j = 1; j <= n; j++) { //1부터 n까지 반복하면서
            if (i == j) { // i와 j가 같으면
                cout << "- "; //- 출력
            } else { //다르면
                cout << table[i][j] << ' '; //해당 경로표값 출력
            }
        }
        cout << '\n';
    }
    return 0;
}