#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 26;
vector<vector<bool>> visited;
vector<vector<int>> m;

int cnt = 0;

void dfs(int x, int y, int n) {
    int dr[] = {-1, +1, 0, 0};
    int dc[] = {0, 0, -1, +1};
    visited[x][y] = true; //방문체크
    cnt++; //단지 집 개수 증가
    for (int i = 0; i < 4; i++) { //상하좌우 체크
        int new_r = x + dr[i];
        int new_c = y + dc[i];
        if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && m[new_r][new_c] == 1 && !visited[new_r][new_c]) { //범위 내이고 방문하지 않은 곳이라면
            dfs(new_r, new_c, n); //다시 탐색
        }
    }
}

int main() {
    int n;
    cin >> n;
    m.assign(MAX, vector<int>(MAX, 0));
    visited.assign(MAX, vector<bool>(MAX, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            m[i][j] = s[j] - '0';
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 1 && !visited[i][j]) {//집이 있고 방문을 하지 않은 위치라면
                visited[i][j] = true; //방문체크
                cnt = 0; //단지 집 개수 초기화
                dfs(i, j, n); //탐색
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end()); //조건에 따라 오름차순 정렬
    cout<<ans.size()<<"\n";
    for (auto i: ans) {
        cout << i << '\n';
    }
    return 0;

}