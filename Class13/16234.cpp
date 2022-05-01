#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) {
        int row = union_cord[i].first, col = union_cord[i].second;
        board[row][col] = population;
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) { //bfs탐색
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); //연합의 위치 저장
    queue<ci> q; //쌍으로 된 큐 선언
    q.push({cr, cc}); //큐에 위치 저장
    int sum = board[cr][cc], cnt = 1; //sum, cnt 초기화
    while (!q.empty()) {//큐가 비어있지 않는 동안 반복
        cr = q.front().first; //큐의 front의 행
        cc = q.front().second; //큐의 front의 열
        q.pop(); //pop해서 큐에서 제외

        for (int i = 0; i < 4; i++) {//상하좌우 반복하면서 검사
            int nr = cr + dr[i]; //새로운 열
            int nc = cc + dc[i]; //세로운 행
            //현재 위치 기준으로 상하좌우가 범위안에 있고, 방문한 곳이 아니라면 계속
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {
                continue;
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); //인구 차이 저장해줌
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc}); //해당 위치 큐에 추가
                visited[nr][nc] = day; //방문 일자 업데이트
                union_cord.push_back({nr, nc}); //연합에 추가
                sum += board[nr][nc]; //연합의 인구수합
                cnt++; //연합 개수 증가
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true; //인구 이동했다고 true표시
    }
    return false; //인구 이동이 없었으므로 false
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) { //반복
        day++; //일수 먼저 증가시킴
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) { //크기가 0이 될때까지
            int row = countries.front().first; //입력받은 쌍의 첫번째 원소 = 열
            int col = countries.front().second; //입력받은 쌍의 두번째 원소 = 행
            countries.pop(); //큐에서 pop해줌
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue; //계속
            }
            visited[row][col] = day; //방문체크에 현재 일수 저장
            if (bfs(n, l, r, row, col, day)) { //bfs탐색결과가 true이면
                is_move = true; //인구 이동도 true
            }
        }
        if (!is_move) {//인구 이동이 false라면
            return day - 1; //증가시킨 일수에서 다시 감소
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r; //땅 크기, 인구 차이 l명 이상 r명 이하 변수 선언

    //입력
    cin >> n >> l >> r; //입력받기
    board.assign(n, vector<int>(n, 0)); //땅 크기 선언
    visited.assign(n, vector<int>(n, 0)); //방문체크 크기 선언
    for (int i = 0; i < n; i++) { //i : 0 ~ n-1
        for (int j = 0; j < n; j++) { //j : 0 ~ n-1
            cin >> board[i][j]; //정사각형 땅 입력받기
            countries.push({i, j}); // 위치 쌍으로 입력받기
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r); //simulation함수 호출, 출력
    return 0; //리턴
}