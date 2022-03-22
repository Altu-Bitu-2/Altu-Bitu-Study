#include <iostream>

using namespace std;
string chess[50]; //입력을 담을 배열 정의
// w먼저 시작하는 체스판
char white[8][8] =
    {
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
// b먼저 시작하는 체스판
char black[8][8] =
    {
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
        'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
        'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};
// w먼저인 경우로 체크
int white_board(int a, int b) {
    int count = 0;
    for (int i = a; i < a + 8; i++) { // 8*8크기 검증
        for (int j = b; j < b + 8; j++) {
            if (chess[i][j] != white[i - a][j - b]) { //입력받은 체스판 색이 원래 체스판 색과 다르면
                count++;                              //카운트 증가
            }
        }
    }
    return count;
}
// b먼저인 경우로 체크
int black_board(int a, int b) {
    int count = 0;
    for (int i = a; i < a + 8; i++) {
        for (int j = b; j < b + 8; j++) {
            if (chess[i][j] != black[i - a][j - b]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chess[i][j]; // 2차원 배열로 각 체스판 입력받음
        }
    }
    int white_res, black_res;
    int result = 64; // 8*8 체스판 전체를 바꾸는 것이 최대
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            white_res = white_board(i, j);
            black_res = black_board(i, j);
            result = min(result, min(white_res, black_res)); //최솟값 비교
        }
    }
    cout << result << '\n';
    return 0;
}
