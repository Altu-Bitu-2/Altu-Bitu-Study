#include <iostream>

using namespace std;
string chess[50]; //입력을 담을 배열 정의
int result = 64;

int black_board(int a, int b) {
    int count = 0;
    for (int i = a; i < a + 8; i++) {
        for (int j = b; j < b + 8; j++) {
            if ((i + j) % 2 == 0 && chess[i][j] != 'B') { //b자리에 b가 아니라면
                count++;
            } else if ((i + j) % 2 != 0 && chess[i][j] != 'W') { //w자리에 w가 아니라면
                count++;
            }
        }
    }
    return count;
}

int white_board(int a, int b) {
    int count = 0;
    for (int i = a; i < a + 8; i++) {
        for (int j = b; j < b + 8; j++) {
            if ((i + j) % 2 == 0 && chess[i][j] != 'W') {
                count++;
            } else if ((i + j) % 2 != 0 && chess[i][j] != 'B') {
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
        cin >> chess[i]; // 2차원 배열로 각 체스판 입력받음

    }
    int white, black = 0;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            result = min(result, min(white_board(i, j), black_board(i, j)));
        }
    }
    cout << result << '\n';
    return 0;
}
