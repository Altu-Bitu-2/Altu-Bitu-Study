#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, answer = 0;
    vector<int> dp(1001); //dp벡터
    vector<int> arr(1001); //수열을 받을 벡터
    cin >> n;

    for (int i = 0; i < n; i++) {// 입력받기
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1; //처음 길이
        for (int j = 0; j < i; j++) { //i번 반복하면서
            if (arr[j] < arr[i]) { //arr[i]가 arr[j]보다 크면
                dp[i] = max(dp[i], dp[j] + 1); //dp는 dp[i]와 dp[j]+1 중 작은 값임
            }
        }
        answer = max(dp[i], answer); //최댓값 저장
    }
    cout << answer << '\n';

    return 0;
}