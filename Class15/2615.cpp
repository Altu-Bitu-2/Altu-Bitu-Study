#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1}; //세로, 우하향, 우상향
    int dc[4] = {1, 0, 1, 1}; //가로, 우하향, 우상향

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) { //가장 왼쪽위인지 확인
        return false; //이어지는 돌이 있으면 false리턴
    }
    int cnt = 0; //같은 방향에 놓인 개수를 0으로 초기화
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수, 5개이하여야하고, 위쪽으로 더 없는 경우
        cnt++; //개수 하나씩 증가
        r += dr[d]; //다음 열 확인
        c += dc[d]; //다음 행 확인
    }
    return cnt == 5; //개수가 5개이면 true 반환
}

bool isEnd(int r, int c, vector<vector<int>> &board) { //승부 판별
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) { //유효한 방향인지 확인
            return true; //유효하면 true 리턴
        }
    }
    return false; //유효하지 않으면 false리턴
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //바둑판 선언

    //입력
    for (int i = 0; i < SIZE; i++) { //SIZE만큼 반복
        for (int j = 0; j < SIZE; j++) { //반복
            cin >> board[i][j]; //바둑판 상태 입력받기
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) { //바둑판 전체 반복
        for (int j = 0; j < SIZE; j++) { //반복
            if (!board[i][j]) { //돌이 없음
                continue; //다음 코드로
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //가장 왼쪽에 있는 바둑알의 가로줄 번호, 세로줄 번호 출력
                return 0; //끝
            }
        }
    }
    cout << 0; //승부 결정 안되었다면 0 출력
    return 0; //리턴
}