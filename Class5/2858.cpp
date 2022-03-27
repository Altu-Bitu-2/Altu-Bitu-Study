#include <iostream>

using namespace std;

int main() {
    int r, b;
    cin >> r >> b;
    int l, m; //가로, 세로
    int total; //전체 타일의 개수
    total = r + b; //전체 타일의 개수는 빨간 타일과 갈새 타일의 합
    //    for (int i = 3; i < 5000; i++) { //3*3부터 가능하므로, 가로가 3일때부터 반복
    //        for (int j = 3; j < 5000; j++) { //세로도 3일때부터 반복
    //            if ((i - 2) * (j - 2) == b && i * j == total) { //갈색 타일의 개수와 전체 타일의 개수를 확인
    //                l = max(i, j); //큰 숫자가 가로
    //                m = min(i, j); //작은 숫자가 세로
    //                break;
    //            }
    //        }
    //    }

    //수정한 코드
    for (int i = 3; i < 5000; i++) { //3*3부터 가능하므로, 가로가 3일때부터 반복
        int temp = total / i; // 세로는 전체 넓이를 가로로 나눈것과 같음
        if (((i - 2) * (temp - 2) == b) && i * temp == total) { //개수 및 곱 확인
            l = max(i, (total / i)); //큰 숫자가 가로
            m = min(i, (total / i)); //작은 숫자가 세로
            break;
        }
    }

    cout << l << " " << m << '\n';
    return 0;
}
