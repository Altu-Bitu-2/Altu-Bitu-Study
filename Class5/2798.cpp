#include <iostream>
#include <vector>

using namespace std;

int findNumbers(string s, int n, int m) {
    int sum;
    int answer = 0;
    for (int i = 0; i < n; i++) { //삼중 반복해야하므로 n-2까지만 반복
        for (int j = i + 1; j < n; j++) { //j는 i+1부터 시작
            for (int k = j + 1; k < n; k++) { //k는 j+1부터 시작
                sum = s[i] - '0' + s[j] - '0' + s[k] - '0'; //숫자로 변환하여 더해줌
                if (sum <= m && sum > answer) { //m보다 작거나 같고, 이전 합보다 크면 답이 됨
                    answer = sum;
                }
            }
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers;
    string input;
    for (int i = 0; i < n; i++) { //입력받기
        cin >> input[i];
    }
    cout << findNumbers(input, n, m) << '\n';
    return 0;
}
