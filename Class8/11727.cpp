#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<long long> dp(1001); //1<=n<=1000 dp숫자가 매우 커지므로 long long으로 해야함........!!
    //점화식 초기값들 설정
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    cin >> n;
    for (int i = 3; i < n + 1; i++) { //3부터 반복
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007; //점화식에 문제 조건대로 나누어줌
    }
    cout << dp[n] << '\n'; //문제에서 나온 조건
    return 0;
}