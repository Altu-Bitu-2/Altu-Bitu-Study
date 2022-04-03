#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    vector<int> dp(11);
    dp[0] = 0;
    dp[1] = 1; //1
    dp[2] = 2; //1+1, 2
    dp[3] = 4; //1+1+1, 1+2, 2+1, 3
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 4; i < n + 4; i++) {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]); //현재의 dp값은 이전 세개의 dp값을 더한것과 같은 점화식이 나옴
        }
        cout << dp[n] << '\n';
    }
    return 0;
}