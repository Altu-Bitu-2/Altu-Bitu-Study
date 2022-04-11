#include <iostream>
#include <vector>

using namespace std;

void changeMatrix(int x, int y, vector<vector<int>> &matrix) {
    for (int i = x; i < x + 3; i++) { //행렬 변환 연산 : 3x3 크기만큼 부분행렬 뒤집기
        for (int j = y; j < y + 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

bool checkMatrix(int n, int m, vector<vector<int>> &matrixA, vector<vector<int>> &matrixB) {
    for (int i = 0; i < n; i++) { // 전체 벡터를 다시 돌면서
        for (int j = 0; j < m; j++) {
            if (matrixB[i][j] != matrixA[i][j]) { //행렬 A와 B가 다른 곳이 있으면
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrixA(51, vector<int>(51, 0));
    vector<vector<int>> matrixB(51, vector<int>(51, 0));

    int count = 0;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input; //한 줄씩 입력받고
        for (int j = 0; j < m; j++) {
            matrixA[i][j] = input[j] - '0'; //2차원 벡터에 int로 형변환하여 저장
        }
    }
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            matrixB[i][j] = input[j] - '0';
            if (matrixB[i][j] != matrixA[i][j]) { //만약 행렬A와 다르다면
                changeMatrix(i, j, matrixA); //0,1 뒤집어주고
                count++; //개수 카운트 증가
            }
        }
    }

    //크기가 3보다 작은 행렬인데 서로 같지 않다면 변경 불가능
    if ((n < 3 || m < 3) && !checkMatrix(n, m, matrixA, matrixB)) {
        cout << -1 << '\n';
    }
    //두 행렬이 같다면 개수 출력
    if (checkMatrix(n, m, matrixA, matrixB)) {
        cout << count << '\n';
    }
    return 0;
}