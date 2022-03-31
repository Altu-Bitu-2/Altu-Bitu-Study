#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int MAX = 7;
vector<int> num(MAX);
vector<bool> check(MAX);
vector<int> answer(MAX);


void backtracking(int cnt) { //인덱스
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) { //숫자가 같지 않고 이전에 선택한 값이 아니라면
            answer[cnt] = num[i]; //answer에 추가
            prev = num[i]; //전 수를 현재 수로 바꿔줌
            check[i] = true;
            backtracking(cnt + 1);
            check[i] = false;
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.begin() + n);
    backtracking(0);
    return 0;
}