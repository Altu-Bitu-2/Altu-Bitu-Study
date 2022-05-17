#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int step = 0, ans = 0; //회전 카운트, 청소한 칸 개수 초기화
    while (true) { //청소 반복
        if (board[r][c] == 0) { //빈칸이라면
            board[r][c] = 2; //청소한 것으로 갱신
            ans++; //청소한 칸 개수 증가
        }

        if (step == 4) { //한바퀴 돈 경우(4번 반복)
            if (board[r - dr[d]][c - dc[d]] == 1) { //상하좌우 좌표가 벽이면
                return ans; //청소한 칸 개수 리턴
            }
            //이전 좌표(상하좌우)로 갱신
            r -= dr[d];
            c -= dc[d];
            step = 0; //회전카운트 0으로 초기화
        } else { //한바퀴 돌지 않았다면
            d = (d + 3) % 4; //방향 틀기
            if (board[r + dr[d]][c + dc[d]]) { //탐색하는 좌표가 벽이라면
                step++; //회전카운트 증가
                continue; //다음으로
            }
            //한 칸씩 이동
            r += dr[d];
            c += dc[d];
            step = 0; //회전카운트 초기화
        }
    }
}

/**
 * [로봇 청소기]
 *
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d; //세로, 가로, 좌표(r, x), 방향

    //입력
    cin >> n >> m >> r >> c >> d; //세로, 가로, 좌표(r, x), 방향 입력받음
    vector<vector<int>> board(n, vector<int>(m, 0)); //좌표 저장할 벡터
    for (int i = 0; i < n; i++) { //n만큼 반복
        for (int j = 0; j < m; j++) { //m만큼 반복
            cin >> board[i][j]; //숫자 저장
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}