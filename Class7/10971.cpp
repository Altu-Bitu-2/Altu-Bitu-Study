#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8; //최대 크기 상수로 저장

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요? //cnt: 인덱스, cur_city:현재 도시, cost: 비용
 */
void backtracking(int cnt, int cur_city, int cost) { //백트래킹 함수
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요? 현재 비용이 현재의 최소 비용보다 크면 답이 되지 못하므로
        return; //리턴
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //갈 수 있는 도시라면
            ans = min(ans, cost + matrix[cur_city][0]); //현재 최소비용과 현재 도시와 직전의 비용을 합친 비용 중 더 작은 비용을 최소 비용에 저장한다
        }
        return; //리턴
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문 표시해줌
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //백트래킹 다음 인덱스 탐색
            visited[i] = false; //다시 방문 표시 되돌려놓음
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n; //입력받기
    visited.assign(n, false); //방문 배열의 크기를 n으로, 초기값을 false로 초기화
    matrix.assign(n, vector<int>(n, 0)); //매트릭스 배열을 크기가 n이고 초기값이 0인 벡터로 초기화
    for (int i = 0; i < n; i++) { //n만큼 박복하면서
        for (int j = 0; j < n; j++) { //n만큼 반복하면서
            cin >> matrix[i][j]; //전체 도시의 비용을 입력받는다.
        }
    }

    //연산
    visited[0] = true; //시작지점 방문 표시
    backtracking(1, 0, 0); //백트래킹 함수 호출

    //출력
    cout << ans; //최소비용 출력
    return 0;  //리턴
}