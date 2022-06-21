#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

int getMaxBlock(matrix &board) { //최댓값 구하는 함수
    int max_block = 0; //최대 블록 초기화
    for (int i = 0; i < n; i++) { //크기만큼 반복
        for (int j = 0; j < n; j++) { //크기만큼 반복
            max_block = max(max_block, board[i][j]); //최댓값 비교, 저장
        }
    }
    return max_block; //최댓값 리턴
}

matrix transposeMatrix(matrix &board) { //전치행렬 구하는 함수
    matrix board_t(n, vector<int>(n, 0)); //전치행렬 선언
    for (int i = 0; i < n; i++) { //크기만큼 반복
        for (int j = 0; j < n; j++) { //크기만큼 반복
            board_t[i][j] = board[j][i]; //뒤집어 저장
        }
    }
    return board_t; //전치행렬 리턴
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) { //보드 크기만큼 반복
        int idx = 0; //좌표
        int prev = 0; //이전 블록 번호
        for (int i = 0; i < n; i++) { //크기만큼 반복
            if (!board[i][j]) { //해당 좌표가 0이라면
                continue; //진행
            }
            if (board[i][j] == prev) { //해당 좌표가 이전 좌표번호와 동일하면
                temp[idx - 1][j] *= 2; //2를 곱해서 배열에 저장
                prev = 0; //블록 번호 초기화
            } else { //해당 좌표가 이전 좌표번호와 동일하지 않으면
                temp[idx++][j] = board[i][j]; //보드 번호를 배열에 저장
                prev = board[i][j]; //해당 보드 번호가 prev에 저장됨
            }
        }
    }
    return temp; //temp배열 리턴
}

//백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { //5번 모두 이동했을 떄
        ans = max(ans, getMaxBlock(board)); //최댓값을 답에 저장
        return;
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board);  //보드의 전치 행렬 저장
    //상
    backtracking(cnt + 1, upMove(board)); //기존 보드 백트래킹
    //하
    reverse(board.begin(), board.end()); //보드 거꾸로 뒤집음(행)
    backtracking(cnt + 1, upMove(board)); //기존 보드 백트래킹
    //좌
    backtracking(cnt + 1, upMove(board_t)); //전치 행렬 보드 백트래킹
    //우
    reverse(board_t.begin(), board_t.end()); //전치행렬 보드 거꾸로 뒤집기(행)
    backtracking(cnt + 1, upMove(board_t)); //전치 행렬 보드 백트래킹
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력
    cin >> n; //보드의 크기
    matrix board(n, vector<int>(n, 0)); //보드 matrix 벡터 선언
    for (int i = 0; i < n; i++) { //크기만큼 반복
        for (int j = 0; j < n; j++) { //크기만큼 반복
            cin >> board[i][j]; //게임판 초기 상태 입력, 저장
        }
    }

    //연산
    backtracking(0, board); //백트래킹 이용

    //출력
    cout << ans; //정답 출력
    return 0;
}