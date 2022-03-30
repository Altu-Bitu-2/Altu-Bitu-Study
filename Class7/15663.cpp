#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int MAX = 7;
vector<int> num(MAX);
vector<bool> check(MAX);
vector<int> answer(MAX);

bool checkSame(int i) {//중복인지 확인
    for (int j = 0; j < answer.size(); j++) {
        if (answer[j] == num[i]) //중복이 있다면
            return true;
    }
    return false;

}

void backtracking(int cnt) { //인덱스

    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
             cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check[i] && !checkSame(i)) { //중복이 아니면서 이전에 선택한 값이 아니라면
            answer[cnt] = num[i]; //answer에 추가
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
    sort(num.begin(), num.end());
    backtracking(0);
    return 0;
}