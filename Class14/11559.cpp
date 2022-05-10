#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //int pair 선언
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6; //열
const int COL = 12; //행

bool bfs(int r, int c, vector<vector<char>> &board) {
    //상하좌우 위치
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q; //int pair 큐 선언
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false)); //방문 체크 벡터

    //시작 초기화
    q.push({r, c});
    puyo.push({r, c}); //포함된 좌표에 현재 좌표 추가
    visited[r][c] = true; //방문으로 체크
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) { //큐가 비어있지 않을 동안
        int cr = q.front().first; //현재 front의 열
        int cc = q.front().second; //현재 front의 행
        q.pop(); //큐에서 빼줌

        for (int i = 0; i < 4; i++) { //상하좌우 확인
            int nr = cr + dr[i]; //확인할 열
            int nc = cc + dc[i]; //확인할 열
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) { //방문을 했거나, 현재 보드 밖에 위치하는 경우 (부합X)
                continue; //계속 진행
            }
            if (board[nr][nc] == board[cr][cc]) { //상하좌우에 모두 같은 색이라면
                q.push({nr, nc}); //큐에 해당 좌표 푸시
                puyo.push({nr, nc}); //포함된 좌표에 해당 좌표 푸시
                visited[nr][nc] = true; //방문체크 true로 변경
                cnt++; //모여있는 뿌요 개수 증가
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false; //false리턴
    }
    while (!puyo.empty()) { //큐가 비어있지 않을 동안
        int cr = puyo.front().first; //열
        int cc = puyo.front().second; //행
        puyo.pop(); //큐에서 빼줌

        board[cr][cc] = '.'; //보드 해당 좌표를 비워줌
    }
    return true; //true 리턴
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.')); //새로운 보드 선언
    for (int i = 0; i < ROW; i++) { //row만큼 반복
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { //col만큼 반복하면서
            if (board[i][j] != '.') { //뿌요가 비어있지 않다면
                temp.push(board[i][j]); //남아있는 뿌요에 해당 위치 추가
            }
        }
        int index = 0; //인덱스는 0으로 초기화
        while (!temp.empty()) { //남아있는 뿌요가 없을때까지
            new_board[i][index++] = temp.front(); //front를 새로운 보드에 추가, 인덱스 증가
            temp.pop(); //큐에서 빼줌
        }
    }
    return new_board;//새로 작성된 보드 리턴
}

int simulation(vector<vector<char>> &board) {
    int answer = 0; //답 변수 선언
    while (true) { //true인동안 반복
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) { //row만큼 반복
            for (int j = 0; j < COL; j++) { //col만큼 반복
                if (board[i][j] == '.') { //비어있으면
                    continue; //진행
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true; //true로 바꿔줌
                }
            }
        }
        if (!flag) { //flag가 false이면
            break; //while문 나가기
        }
        board = makeNewBoard(board); //새 필드 작성한 것을 board로 다시 저장
        answer++; //답 개수 증가
    }
    return answer; //답 리턴
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input; //입력받을 문자
    vector<vector<char>> board(ROW, vector<char>(COL)); //입력값 저장할 벡터
    for (int i = 0; i < COL; i++) { //행만큼 반복
        for (int j = 0; j < ROW; j++) { //열만큼 반복
            cin >> input; //입력받기
            board[j][COL - i - 1] = input; //보드에 입력값 저장 (행열바꿔줌)
        }
    }

    //연산 & 출력
    cout << simulation(board); //연산, 출력
    return 0; //리턴
}