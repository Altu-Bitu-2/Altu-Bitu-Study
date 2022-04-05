#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    vector<int> coin(21); //동전 입력받을 벡터
    while (t--) { //테스트케이스만큼 반복하면서
        cin >> n;
        vector<int> dp(10001);
        dp[0] = 1; //dp[0] = 1로 설정

        for (int i = 0; i < n; i++) { //동전 입력받기
            cin >> coin[i];
        }
        cin >> m; //만들어야하는 금액
        for (int i = 0; i < n; i++) { //동전 가지수만큼 반복
            for (int j = coin[i]; j < m + 1; j++) { //해당 동전 값부터 만들어야하는 금액까지 반복하면서
                dp[j] += dp[j - coin[i]]; //점화식
            }
        }
        cout << dp[m] << '\n';

    }
    return 0;
}