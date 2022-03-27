#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int> s, int n, int m) {
    int sum;
    int answer = 0;
    for (int i = 0; i < n; i++) { //삼중 반복해야하므로 n-2까지만 반복
        for (int j = i + 1; j < n; j++) { //j는 i+1부터 시작
            for (int k = j + 1; k < n; k++) { //k는 j+1부터 시작
                sum = s[i] + s[j] + s[k]; //더해줌
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
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++) { //입력받기
        cin >> numbers[i];
    }
    cout << findNumbers(numbers, n, m) << '\n';
    return 0;
}
