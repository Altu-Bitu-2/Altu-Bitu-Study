#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401; //최대 401
typedef pair<int, int> ci; //pair구조체 선언

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    //상하좌우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF; //최솟값 401로 지정
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; //방문여부, 거리 초기화
    q.push(shark); //아기 상어 좌표를 큐에 푸시해줌
    while (!q.empty()) { //큐가 비어있지 않는 동안
        int row = q.front().first; //상어의 x좌표 저장
        int col = q.front().second; //상어의 y좌표 저장
        q.pop(); //해당 좌표 pop

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue; //다음 코드로
        }
        for (int i = 0; i < 4; i++) { //상하좌우 반복하여 확인
            int nr = row + dr[i]; //탐색할 새로운 열
            int nc = col + dc[i]; //탐색할 새로운 행
            //탐색할 좌표가 범위 내에 있지 않거나, 방문을 이미 했거나, 상어의 크기보다 크면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue; //탐색 못함
            }

            dist[nr][nc] = dist[row][col] + 1; //위치 갱신
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //물고기가 있는 좌표 추가
                min_dist = dist[nr][nc]; //최소 거리 갱신
                continue; //다음코드로
            }
            q.push({nr, nc}); //새로운 좌표를 큐에 저장
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //최소거리, 좌표 리턴
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) { //최소 거리가 같다면
            return p1.first < p2.first; //최소거리가 작은 순으로 정렬
        }
        return p1.second < p2.second; //최소거리가 다르면 좌표가 작은대로 정렬
    });
    return {min_dist - 1, list[0]}; //최소 거리에서
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; //시간, 상어의 크기, 물고기 개수
    while (true) { //true인동안 반복(물고기 먹기)
        pair<int, ci> result = nextPos(n, size, shark, board); //bfs탐색한 결과 저장, 물고기 탐색
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //반복문 나가기
        }
        ans += result.first; //시간 더해줌
        cnt++; //먹은 물고기 개수 증가
        if (cnt == size) { //먹은 물고기 수랑 상어 크기가 동일하면
            cnt = 0; //물고기 개수 0개로 초기화
            size++; //상어 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; //해당 위치 물고기 0개로 초기화
        shark = result.second; //상어 위치 갱신
    }
    return ans;
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n;  //공간의 크기
    pair<int, int> shark_pos; //상어의 위치좌표

    //입력
    cin >> n; //공간의 크기 입력받기
    vector<vector<int>> board(n, vector<int>(n)); //공간의 상태 저장할 벡터
    for (int i = 0; i < n; i++) { //n*n 공간 상태 입력받기
        for (int j = 0; j < n; j++) { //반복
            cin >> board[i][j]; //공간 상태 입력받기
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j); //아기 상어의 위치 좌표 저장
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board); //함수 호출하여 출력
    return 0; //리턴
}