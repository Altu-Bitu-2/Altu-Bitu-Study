#include <iostream>

using namespace std;

int main() {
    long long dp[1001][10] = {0}; //자리수, 끝자리
    int n;
    long long answer = 0;

    cin >> n;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1; //자리수가 1이고 i로 끝나는 오르막수의 개수 저장
    }
    for (int i = 2; i < n + 1; i++) { //
        for (int j = 0; j < 10; j++) { //j는 0~9까지
            for (int k = 0; k < j + 1; k++) { //k는 j까지만 반복
                //i자리의 j로 끝나는 오르막 수는 i-1자리의 k로 끝나는 모든 오르막수들을 합한 것과 같음, 조건대로 나누기
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        answer += dp[n][i];

    }
    cout << answer % 10007 << '\n';

    return 0;
}