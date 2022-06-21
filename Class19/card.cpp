#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//컨트롤로 이동하는 좌표를 리턴하는 함수
ci ctrl(int row, int col, int dir, vector<vector<int>> &tmp) {
    while (true) { //반복하면서
        //상하좌우 행렬 확인
        row += dr[dir]; //열
        col += dc[dir]; //행
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) { //해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동
            return make_pair(row - dr[dir], col - dc[dir]);  //가장 마지막 칸의 좌표쌍 리턴
        }
        if (tmp[row][col] != 0) { //누른 키 방향에 있는 가장 가까운 카드
            return make_pair(row, col); //가장 가까운 카드 좌표쌍 리턴
        }
    }
}

//현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> &tmp) {
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0)); //저장할 거리 배열
    queue<ci> q; //큐 선언
    visited[r1][c1] = 1; //반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    q.push({r1, c1}); //큐에 좌표 저장

    while (!q.empty()) { //큐가 비어있지 않은 동안
        int row = q.front().first; //큐 첫번째 쌍의 x좌표 저장 (x, y)
        int col = q.front().second;//큐 첫번째 쌍의 y좌표 저장
        int dist = visited[row][col]; //거리 저장
        q.pop(); //큐 pop해줌

        if (row == r2 && col == c2) { //목표 카드에 도달했다면
            return dist; //거리 리턴
        }
        for (int i = 0; i < 4; i++) { //컨트롤 입력 이동
            pair<int, int> np = ctrl(row, col, i, tmp); //컨트롤로 이동한 좌표 저장
            if (visited[np.first][np.second]) { //이미 방문한 좌표라면
                continue; //다음 코드 진행
            }
            visited[np.first][np.second] = dist + 1; //거리를
            q.push(np); //큐에 저장
        }

        for (int i = 0; i < 4; i++) { //방향키 입력 이동
            int nr = row + dr[i], nc = col + dc[i]; //새로운 행렬 저장 (상하좌우)
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE || visited[nr][nc]) { //범위 내에 있지 않거나, 이미 방문했다면
                continue; //다음 코드로 진행
            }
            visited[nr][nc] = dist + 1; //방문 배열 거리 증가
            q.push({nr, nc}); //큐에 좌표쌍 저장
        }
    }
    return -1; //목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
}

//조합에 대해 카드를 매칭하는 함수
int matchCard(int bit, int num, int r, int c, int answer, vector<int> &seq, vector<vector<ci>> &cards,
              vector<vector<int>> tmp) {
    int ans = 0; //답 0으로 초기화
    for (int i = 0; i < num; i++) {
        int cur = seq[i]; //이번에 매칭할 캐릭터
        int now = 0; //해당 캐릭터의 0번째 카드부터 선택한다고 가정
        if (bit & (1 << i)) { //만약 해당 위치의 비트가 1을 표시했다면 1번째 카드부터 선택
            now = 1; // 1번 카드부터 선택하도록 갱신
        }
        for (int j = 0; j < 2; j++) {
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp); //현재 커서에서 목표 카드까지 이동하는 비용
            //기존 최솟값보다 큰 경우 -> 더 이상의 탐색 불필요
            if (ans >= answer) {
                return answer;
            }
            //카드 삭제 + 커서 이동
            tmp[nr][nc] = 0;
            r = nr; //x좌표 갱신
            c = nc; //y좌표 갱신
            now = 1 - now; //다음에 매칭할 카드 인덱스
        }
    }
    return ans; //답 리턴
}

//존재하는 모든 카드의 위치를 리턴하는 함수
vector<vector<ci>> findCard(vector<vector<int>> &board) {
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //최대 카드 수
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cnt = max(cnt, board[i][j]);
            if (board[i][j]) { //카드라면 위치 저장
                card_pos[board[i][j]].push_back({i, j});
            }
        }
    }
    card_pos.resize(cnt + 1); //실제 존재하는 카드의 수만큼 크기 조절
    return card_pos;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9; //최댓값으로 선언해줌
    vector<vector<ci>> cards = findCard(board); //존재하는 모든 카드의 위치
    int card_cnt = cards.size() - 1; //카드의 개수

    vector<int> seq(card_cnt); //순열을 위한 배열
    for (int i = 0; i < card_cnt; i++) { //카드 개수만큼 반복하면서
        seq[i] = i + 1; //순열에 인덱스+1 저장
    }
    do { //가능한 모든 카드 순서에 대해
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1번째 카드 중 어떤 카드를 먼저 뒤집을지 결정
            answer = min(answer, matchCard(bit, card_cnt, r, c, answer, seq, cards, board)); //이동 횟수가 가장 적은 값을 저장
        }
    } while (next_permutation(seq.begin(), seq.end()));
    return answer; //답 리턴
}

/**
 * [카드 짝 맞추기]
 *
 * 아이디어
 * 1. 범위가 크지 않음
 * 2. 존재하는 모든 카드의 종류는 6개, 카드 2장이 한 쌍을 이룬다.
 * 3. 뒤집을 카드 순서를 정하는 모든 경우의 수는 6!(카드 순서) * 2^6(2개의 카드 중 어떤 카드를 먼저 뒤집을지) -> 브루트포스 가능
 * 4. 이번에 목표로 하는 카드에 대해 현재 커서에서 목표 카드까지 가는 최단 경로를 구하며 이동 횟수 전부 구하고 최솟값 갱신
 *
 * 구현
 * 1. 존재하는 모든 카드의 위치를 저장하며 카드의 개수 세기 (findCard)
 * 2. 가능한 모든 카드의 순서(next_permutation)와 각 카드를 뒤집을 순서(bitmask)를 결정
 *    ex) seq = {3, 1, 2}, bit = 011 일 때
 *        3번, 1번, 2번 카드의 순서로 뒤집는다.
 *        3번 카드는 1번째 카드부터, 1번 카드는 0번째 카드부터, 2번 카드는 1번째 카드부터 뒤집는다.
 *        bit의 011이 앞에서부터 각각 1, 2, 3번 카드와 대응함
 * 3. 현재 카드 순서와 각 카드를 뒤집는 순서에 대한 커서 이동 횟수 계산 (matchCard)
 *    현재 커서 위치와 목표 카드 위치에 대해 bfs 함수 실행
 *    컨트롤 입력을 고려해야 하기 때문에 4방향에 대한 방향 이동에 추가로 컨트롤 입력도 처리한다.(ctrl)
 * 4. 매 조합에 따라 board가 갱신되므로 board를 복사한 tmp 사용
 * 공식 풀이 : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */
int main() {
    //카드 배열
    vector<vector<int>> board = {{1, 0, 0, 3},
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0}};
    cout << solution(board, 1, 0); //솔루션 함수 실행, 출력
}