#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { //현재 열부터 열+2까지 반복
        for (int j = col; j < col + 3; j++) { //현재 행부터 행+2까지 반복하면서
            if (matrix_a[i][j] == '1') { //행렬 원소가 1이면
                matrix_a[i][j] = '0'; //0으로 변경
            }
            else { //행렬 원소가 0이면
                matrix_a[i][j] = '1'; //1로 변경
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) { //행렬의 크기만큼
        for (int j = 0; j < m; j++) { //행렬의 크기만큼 반복하면서
            if (matrix_a[i][j] != matrix_b[i][j]) { //행렬이 같지 않으면
                return false; //false리턴
            }
        }
    }
    return true; //같다면 true 리턴
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m; //행렬의 크기

    //입력
    cin >> n >> m; //행렬 크기 입력받기
    vector<string> matrix_a(n); //행렬A
    vector<string> matrix_b(n); //행렬B
    for (int i = 0; i < n; i++) { //반복하면서
        cin >> matrix_a[i]; //행렬A의 원소를 입력받음
    }

    for (int i = 0; i < n; i++) { //반복하면서
        cin >> matrix_b[i]; //행렬B의 원소를 입력받음
    }

    //연산
    int ans = 0; //문제의 정답 개수
    for (int i = 0; i <= n - 3; i++) { //n-3까지 반복
        for (int j = 0; j <= m - 3; j++) { //m-3까지 반복
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); //1->0, 0->1 뒤집는 함수 호출
                ans++; //정답 개수 증가
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) { //뒤집는 연산을 했을 때 두 행렬이 같지 않다면
        ans = -1; //-1 출력
    }
    cout << ans; //정답 출력
    return 0; //리턴
}