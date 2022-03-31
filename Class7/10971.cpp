#include <iostream>
#include <vector>

using namespace std;
int n;
const int MAX = 11;
vector<vector<int>> W;
int min_cost = 999999999;
vector<bool> check(MAX, false);

void backtracking(int start, int count, int cost) {
    if (cost >= min_cost) { //비용이 최소비용보다 크면 답이 아니므로 리턴
        return;
    }
    if (count == n) { //모두 순회했을 경우
        for (int i = 0; i < n; i++) { //행 체크
            if (W[start][i] != 0) {
                min_cost = min(cost, min_cost); //최소 비용 구하기
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) { //행 체크
        if (W[start][i] != 0 && !check[i]) { //갈 수 있는 도시이면서 들리지 않은 도시라면
            check[i] = true; //들렸다고 체크
            cost += W[start][i]; //비용 더하기
            backtracking(start, count + 1, cost); //다음 도시 체크
            check[i] = false; //들리지 않은 것으로 되돌리기
        }
    }
}

int main() {
    cin >> n;
    W.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }
    for (int i = 0; i < n; i++) {//0번행부터 시작
        check[i] = true;
        backtracking(i, 0, 0);
        check[i] = false;

    }
    cout << min_cost << '\n';
    return 0;

}